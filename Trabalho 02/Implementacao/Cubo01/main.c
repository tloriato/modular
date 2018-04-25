#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

// (config) ~> inteiro
//	config = vetor de 54 inteiros
//	inteiro =
//		0 -> sucesso
int populaCubo(int *config) {

	// 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

	// Up Face 0
	config[0] = 5;
	config[1] = 5;
	config[2] = 5;

	config[3] = 5;
	config[4] = 5; // White Face
	config[5] = 5;

	config[6] = 5;
	config[7] = 5;
	config[8] = 5;

	// Left Face 4
	config[9] = 6;
	config[10] = 6;
	config[11] = 6;

	config[21] = 4;
	config[22] = 6;	// Orange Face
	config[23] = 2;

	config[33] = 3;
	config[34] = 3;
	config[35] = 6;

	// Front Face 1
	config[12] = 1;
	config[13] = 1;
	config[14] = 1;

	config[24] = 4;
	config[25] = 1;  // Gren Face
	config[26] = 2;

	config[36] = 1;
	config[37] = 2;
	config[38] = 1;

	// Right Face 2
	config[15] = 2;
	config[16] = 2;
	config[17] = 2;

	config[27] = 1;
	config[28] = 2; // Red Face
	config[29] = 1;

	config[39] = 2;
	config[40] = 3;
	config[41] = 3;

	// Back Face 3
	config[18] = 4;
	config[19] = 4;
	config[20] = 4;

	config[30] = 6;
	config[31] = 4;  // Blue Face
	config[32] = 6;

	config[42] = 4;
	config[43] = 3;
	config[44] = 4;

	// Down Face 5
	config[45] = 3;
	config[46] = 3;
	config[47] = 3;

	config[48] = 1;
	config[49] = 3; // Yellow Face
	config[50] = 6;

	config[51] = 2;
	config[52] = 4;
	config[53] = 6;

	return 0;

}

// (cubo, algoritmo) ~> inteiro
//	cubo = estrutura CUB_tppCUBO populada
//	algoritmo = string de no máximo ALG elementos com comandos no estilo:
//		"U R U' R' U' F' U U F F"
//	inteiro =
//		0 -> sucesso
//		-1 -> entradas invalidas (TODO)
int executaAlgoritmo(CUB_tppCUBO cubo, char* algoritmo) {

	int i = 0;
	int jump = 2;

	char comandos[ALG];
	memset(comandos, '\0', sizeof(comandos));
	strcpy(comandos, algoritmo);

	while (comandos[i]) {

		char rot;
		int face;
			
		if (comandos[i + 1] == '\'') {
			rot = 'a';
			jump = 3;
		}
		else {
			rot = 'h';
			jump = 2;
		}

		switch (comandos[i]) {
		case 'U':
			face = 0;
			break;
		case 'L':
			face = 4;
			break;
		case 'F':
			face = 1;
			break;
		case 'R':
			face = 2;
			break;
		case 'B':
			face = 3;
			break;
		case 'D':
			face = 5;
			break;
		default:
			face = -1;
			break;
		}

		if (face < 0)
			return -1;

		CUB_GirarFace(cubo, face, 1, rot);

		i += jump;
	}

	return 0;
}

// (cubo) -> Bool
int resolvidoAcima(CUB_tppCUBO cubo) {
	int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

	CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);

	CUB_ChecarCorDaFace(&aux1, cubo, 0, 0, CIMA);
	CUB_ChecarCorDaFace(&aux2, cubo, 0, 1, CIMA);
	CUB_ChecarCorDaFace(&aux3, cubo, 0, 2, CIMA);

	CUB_ChecarCorDaFace(&aux4, cubo, 1, 0, CIMA);
	CUB_ChecarCorDaFace(&aux5, cubo, 1, 2, CIMA);

	CUB_ChecarCorDaFace(&aux6, cubo, 2, 0, CIMA);
	CUB_ChecarCorDaFace(&aux7, cubo, 2, 1, CIMA);
	CUB_ChecarCorDaFace(&aux8, cubo, 2, 2, CIMA);

	if(corCima == aux1 == aux2 == aux3 == aux4 == aux5 == aux6 == aux7 == aux8) {
		return 1;
	} else {
		return 0;
	}
}

// (cubo) -> Int Restante
// Restante: Número de peças fora de posição:
//	- 0
//	- 1
// 	- 2
int resolveFrente(CUB_tppCUBO cubo) {

	int restantes = 2;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
	int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

	CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
	CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
	CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
	CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
	CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
	CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

	cor1Aresta1 = corFrente;
	cor1Aresta2 = corFrente;

	cor1Aresta1 = corDireita;
	cor1Aresta2 = corEsquerda;

	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita Resolvida
		restantes--;
	} else {
			// Tenta resolver a Aresta da Direita

			if(resolvidoAcima(cubo)) {
				// Face resolvida está para cima

				if(faceAresta1 == FRENTE && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
					// pois o cubo está de cabeça pra baixo
					executaAlgoritmo(cubo, "CIMA DIREITA INVERTIDO");
					restantes--;
				} else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar de orientação do lado direito invertido
					executaAlgoritmo(cubo, "CIMA DIREITA INVERTIDO"); // 1x pra Direita
					executaAlgoritmo(cubo, "D D"); // Gira a face
					executaAlgoritmo(cubo, "CIMA DIREITA INVERTIDO"); // 2x pra Direita
				}
			} else {
				// Face resolvida está para baixo
				
				if(faceAresta1 == FRENTE && linhaAresta1 == 0 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita
					executaAlgoritmo(cubo, "U R U' R' U' F' U F");
					restantes--;
				} else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 2x pra Direita
				}
			}
	}

	if (faceAresta2 == FRENTE && linhaAresta2 == 1 & colunaAresta2 == 0) {
		// Aresta da Esquerda Resolvida
		restantes--;
	} else {
			// Tenta resolver a Aresta da Esquerda

			if(resolvidoAcima(cubo)) {
				// Face resolvida está para cima
				if(faceAresta2 == FRENTE && linhaAresta2 == 2 && colunaAresta2 == 1){
					// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
					// pois o cubo está de cabeça para baixo
					executaAlgoritmo(cubo, "CIMA ESQUERDA INVERTIDO");
					restantes--;
				} else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar de orientação do lado esquerdo invertido
					executaAlgoritmo(cubo, "CIMA ESQUERDA INVERTIDO"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "D D"); // Gira a face
					executaAlgoritmo(cubo, "CIMA ESQUERDA INVERTIDO"); // 2x pra Esquerda	
				}

			} else {
				// Face resolvida está para baixo
				if(faceAresta2 == FRENTE && linhaAresta2 == 0 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda
					executaAlgoritmo(cubo, "U' L' U L U F U' F'");
					restantes--;
				} else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 2x pra Esquerda
				}
			}
	}
	
	return restantes;
}

void main() {

	int i, fd;
	int config[54];

	char * algoritmoDireita = "U R U' R' U' F' U F";
	char * algoritmoEsquerda = "U' L' U L U F U' F'";
	char * algoritmoOrientacao = "U R U' R' U' F' U F U U U R U' R' U' F' U F";

	CUB_tppCUBO cubo;

	populaCubo(config);

	CUB_CriarCUBO(&cubo, config);

	CUB_ExibirCUBO(cubo);

	system("pause");
}


