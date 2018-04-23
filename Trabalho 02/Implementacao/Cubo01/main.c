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

// Melhor approach por cor ou por face?
int resolveFrente(CUB_tppCUBO cubo) {

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

	// Fazer...

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


