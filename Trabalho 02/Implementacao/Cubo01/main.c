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

#define VERDE 1
#define VERMELHO 2
#define AMARELO 3
#define AZUL 4
#define BRANCO 5
#define LARANJA 6

// (config) ~> inteiro
//	config = vetor de 54 inteiros
//	inteiro =
//		0 -> sucesso
int populaCubo(int *config) {


	// 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

	// Up Face 0
	config[0] = LARANJA;
	config[1] = LARANJA;
	config[2] = VERDE;

	config[3] = AZUL;
	config[4] = AMARELO;
	config[5] = AMARELO;

	config[6] = VERDE;
	config[7] = AMARELO;
	config[8] = VERMELHO;

	// Left Face 4
	config[9] = AMARELO;
	config[10] = AMARELO;
	config[11] = AMARELO;

	config[21] = VERDE;
	config[22] = VERMELHO;
	config[23] = VERMELHO;

	config[33] = VERMELHO;
	config[34] = VERMELHO;
	config[35] = VERMELHO;

	// Front Face 1
	config[12] = VERMELHO;
	config[13] = VERMELHO;
	config[14] = AMARELO;

	config[24] = VERDE;
	config[25] = VERDE;
	config[26] = VERMELHO;

	config[36] = VERDE;
	config[37] = VERDE;
	config[38] = VERDE;

	// Right Face 2
	config[15] = AZUL;
	config[16] = VERDE;
	config[17] = LARANJA;

	config[27] = AZUL;
	config[28] = LARANJA;
	config[29] = LARANJA;

	config[39] = LARANJA;
	config[40] = LARANJA;
	config[41] = LARANJA;

	// Back Face 3
	config[18] = AMARELO;
	config[19] = AMARELO;
	config[20] = AZUL;

	config[30] = AZUL;
	config[31] = AZUL;
	config[32] = LARANJA;

	config[42] = AZUL;
	config[43] = AZUL;
	config[44] = AZUL;

	// Down Face 5
	config[45] = BRANCO;
	config[46] = BRANCO;
	config[47] = BRANCO;

	config[48] = BRANCO;
	config[49] = BRANCO;
	config[50] = BRANCO;

	config[51] = BRANCO;
	config[52] = BRANCO;
	config[53] = BRANCO;

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

	if (corCima == aux1 == aux2 == aux3 == aux4 == aux5 == aux6 == aux7 == aux8) {
		return 1;
	}
	else {
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

	cor2Aresta1 = corDireita;
	cor2Aresta2 = corEsquerda;

	printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
		corFrente, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Direita

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima

			if (faceAresta1 == FRENTE && linhaAresta1 == 2 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
				// pois o cubo está de cabeça pra baixo
				// Later
			}
			else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar de orientação do lado direito invertido
				// Later
			}
		}
		else {
			// Face resolvida está para baixo

			if (faceAresta1 == FRENTE && linhaAresta1 == 0 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, "U R U' R' U' F' U F");
				restantes--;
			}
			else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 2x pra Direita
			}
			else if (faceAresta1 == CIMA && linhaAresta1 == 2 && colunaAresta1 == 1) {
				// É um caso onde a peça está com orientação errada na posição de cima. Nós vamos mover ela para a posição certa na orientação errada, 
				// depois iremos trazer ela de volta para a posição cima com a orientação certa, e ai movermos de novo para o lugar e orientação certos.
				// Algoritmo Direita -> Algoritmo de Troca de Orientação do Lado direito, ou seja: Direita -> Direita -> U U -> Direita
				// ps: uma solução mais elegante seria apenas realizar a primeira mudança, deixando a segunda para o próximo loop ou função :)
				executaAlgoritmo(cubo, "U R U' R' U' F' U F");
				executaAlgoritmo(cubo, "U R U' R' U' F' U F");
				executaAlgoritmo(cubo, "U U");
				executaAlgoritmo(cubo, "U R U' R' U' F' U F");
				restantes--;

			}
		}
	}

	if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Esquerda

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima
			if (faceAresta2 == FRENTE && linhaAresta2 == 2 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
				// pois o cubo está de cabeça para baixo
				// Later
			}
			else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar de orientação do lado esquerdo invertido
				// Later
			}

		}
		else {
			// Face resolvida está para baixo
			if (faceAresta2 == FRENTE && linhaAresta2 == 0 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, "U' L' U L U F U' F'");
				restantes--;
			}
			else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 2x pra Esquerda
				restantes--;
			}
			else if (faceAresta2 == CIMA && linhaAresta2 == 2 && colunaAresta2 == 1) {
				executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 2x pra Esquerda
				restantes--;
			}
		}
	}

	return restantes;
}

// (cubo) -> Int Restante
// Restante: Número de peças fora de posição:
//	- 0
//	- 1
// 	- 2
int resolveEsquerda(CUB_tppCUBO cubo) {

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

	cor1Aresta1 = corEsquerda;
	cor1Aresta2 = corEsquerda;

	cor2Aresta1 = corFrente;
	cor2Aresta2 = corTraseira;

	printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
		corEsquerda, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Direita

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima

			if (faceAresta1 == ESQUERDA && linhaAresta1 == 2 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
				// pois o cubo está de cabeça pra baixo
				// Later
			}
			else if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar de orientação do lado direito invertido
				// Later
			}
		}
		else {
			// Face resolvida está para baixo

			if (faceAresta1 == ESQUERDA && linhaAresta1 == 0 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, "U F U' F' U' L' U L");
				restantes--;
			}
			else if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
				restantes--;
			}

			else if (faceAresta1 == CIMA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
				executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
				restantes--;
			}
		}
	}

	if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Esquerda

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima
			if (faceAresta2 == ESQUERDA && linhaAresta2 == 2 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
				// pois o cubo está de cabeça para baixo
				// Later
			}
			else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar de orientação do lado esquerdo invertido
				// Later
			}

		}
		else {
			// Face resolvida está para baixo
			if (faceAresta2 == ESQUERDA && linhaAresta2 == 0 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, "U' B' U B U L U' L'");
				restantes--;
			}
			else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 2x pra Esquerda
				restantes--;
			}

			else if (faceAresta2 == CIMA && linhaAresta2 == 1 && colunaAresta2 == 0) {
				executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
															   // Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
				restantes--;
			}
		}
	}

	return restantes;
}

// (cubo) -> Int Restante
// Restante: Número de peças fora de posição:
//	- 0
//	- 1
// 	- 2
int resolveDireita(CUB_tppCUBO cubo) {

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

	cor1Aresta1 = corDireita;
	cor1Aresta2 = corDireita;

	cor2Aresta1 = corTraseira;
	cor2Aresta2 = corFrente;

	printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
		corDireita, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Direita

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima

			if (faceAresta1 == DIREITA && linhaAresta1 == 2 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
				// pois o cubo está de cabeça pra baixo
				// Later
			}
			else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar de orientação do lado direito invertido
				// Later
			}
		}
		else {
			// Face resolvida está para baixo

			if (faceAresta1 == DIREITA && linhaAresta1 == 0 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, "U B U' B' U' R' U R");
				restantes--;
			}
			else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 2x pra Direita
				restantes--;
			}

			else if (faceAresta1 == CIMA && linhaAresta1 == 1 && colunaAresta1 == 2) {
				executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
															   // Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 2x pra Direita
				restantes--;
			}
		}
	}

	if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Esquerda

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima
			if (faceAresta2 == DIREITA && linhaAresta2 == 2 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
				// pois o cubo está de cabeça para baixo
				// Later
			}
			else if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar de orientação do lado esquerdo invertido
				// Later
			}

		}
		else {
			// Face resolvida está para baixo
			if (faceAresta2 == DIREITA && linhaAresta2 == 0 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, "U' F' U F U R U' R'");
				restantes--;
			}
			else if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 2x pra Esquerda
				restantes--;
			}

			else if (faceAresta2 == CIMA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
															   // Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 2x pra Esquerda
				restantes--;
			}
		}
	}

	return restantes;
}

// (cubo) -> Int Restante
// Restante: Número de peças fora de posição:
//	- 0
//	- 1
// 	- 2
int resolveTraseira(CUB_tppCUBO cubo) {

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

	cor1Aresta1 = corTraseira;
	cor1Aresta2 = corTraseira;

	cor2Aresta1 = corEsquerda;
	cor2Aresta2 = corDireita;

	printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
		corTraseira, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);


	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Direita

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima

			if (faceAresta1 == TRASEIRA && linhaAresta1 == 2 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
				// pois o cubo está de cabeça pra baixo
				// Later
			}
			else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar de orientação do lado direito invertido
				// Later
			}
		}
		else {
			// Face resolvida está para baixo

			if (faceAresta1 == TRASEIRA && linhaAresta1 == 0 && colunaAresta1 == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, "U L U' L' U' B' U B");
				restantes--;
			}
			else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 2x pra Direita
				restantes--;
			}

			else if (faceAresta1 == CIMA && linhaAresta1 == 0 && colunaAresta1 == 1) {
				executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
															   // Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
				executaAlgoritmo(cubo, "U U"); // Gira a peça
				executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 2x pra Direita
				restantes--;
			}
		}
	}

	if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda Resolvida
		restantes--;
	}
	else {
		// Tenta resolver a Aresta da Esquerda

		if (resolvidoAcima(cubo)) {
			// Face resolvida está para cima
			if (faceAresta2 == TRASEIRA && linhaAresta2 == 2 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
				// pois o cubo está de cabeça para baixo
				// Later
			}
			else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar de orientação do lado esquerdo invertido
				// Later
			}

		}
		else {
			// Face resolvida está para baixo
			if (faceAresta2 == TRASEIRA && linhaAresta2 == 0 && colunaAresta2 == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, "U' R' U R U B U' B'");
				restantes--;
			}
			else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 2x pra Esquerda
				restantes--;
			}

			else if (faceAresta2 == CIMA && linhaAresta2 == 0 && colunaAresta2 == 1) {
				executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
															   // Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
				executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
				executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 2x pra Esquerda
				restantes--;

			}
		}
	}

	return restantes;
}

int aux(int a, int b, int c, int d) {
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		return 0;
	}

	return 1;
}

int forcaCuboFrente(CUB_tppCUBO cubo) {
	
	int alterado = 0;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
	int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

	CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
	CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
	CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
	CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
	CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
	CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

	/* Cuidando da Face da Frente! */
	cor1Aresta1 = corFrente;
	cor1Aresta2 = corFrente;

	cor2Aresta1 = corDireita;
	cor2Aresta2 = corEsquerda;

	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

	if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		executaAlgoritmo(cubo, "U B U' B' U' R' U R");

		return 1;
	}

	else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
		// Aresta da Direita está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		executaAlgoritmo(cubo, "U' B' U B U L U' L'");

		return 1;
	}

	else if (faceAresta1 == ESQUERDA &&  linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Esquerda
		// Algorima Cima <> Direita [da Esquerda]
		executaAlgoritmo(cubo, "U F U' F' U' L' U L");
		return 1;
	}

	else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
		// Aresta da Direita está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		executaAlgoritmo(cubo, "U' R' U R U B U' B'");
		
		return 1;
	}

	else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		executaAlgoritmo(cubo, "U L U' L' U' B' U B");

		return 1;
	}

	else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Direita
		// Algoritmo Cima <> Esquerda [da Direita]
		executaAlgoritmo(cubo, "U' F' U F U R U' R'");
		
		return 1;
	}

	else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
		// Aresta da Esquerda está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		executaAlgoritmo(cubo, "U B U' B' U' R' U R");

		return 1;
	}

	else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		executaAlgoritmo(cubo, "U' B' U B U L U' L'");

		return 1;	
	}

	else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		executaAlgoritmo(cubo, "U' R' U R U B U' B'");
		return 1;
	}

	else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
		// Aresta da Esquerda está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		executaAlgoritmo(cubo, "U L U' L' U' B' U B");
		return 1;
	}



	return 0;
}

void main() {

	int i, j = 0;
	int config[54];

	CUB_tppCUBO cubo;

	populaCubo(config);

	CUB_CriarCUBO(&cubo, config);

	CUB_ExibirCUBO(cubo);

	int r = 1, a = 0, b = 0, c = 0, d = 0;
	int oldA = 2, oldB = 2, oldC = 2, oldD = 2;

	int primeiraFrente = 2, segundaFrente = 2;
	int primeiraDireita = 2, segundaDireita = 2;
	int primeiraTraseira = 2, segundaTraseira = 2;
	int primeiraEsquerda = 2, segundaEsquerda = 2;

	i = 0;
	j = 1;
	while (r) {
		

		if (i == 3) {
			// força o cubo
			i = 0;

			forcaCuboFrente(cubo);
		}

		if (j == 0) {
			j++;

			printf("Frente: \n");
			primeiraFrente = resolveFrente(cubo);
			printf("Restantes: %d\n", primeiraFrente);

			printf("Direita: \n");
			primeiraDireita = resolveDireita(cubo);
			printf("Restantes: %d\n", primeiraDireita);

			printf("Traseira: \n");
			primeiraTraseira = resolveTraseira(cubo);
			printf("Restantes: %d\n", primeiraTraseira);

			printf("Esquerda: \n");
			primeiraEsquerda = resolveEsquerda(cubo);
			printf("Restantes: %d\n", primeiraEsquerda);

			r = aux(primeiraFrente, primeiraDireita, primeiraTraseira, primeiraEsquerda);
		}
		else if (j == 1) {
			j++;

			printf("Frente: \n");
			segundaFrente = resolveFrente(cubo);
			printf("Restantes: %d\n", segundaFrente);

			printf("Direita: \n");
			segundaDireita = resolveDireita(cubo);
			printf("Restantes: %d\n", segundaDireita);

			printf("Traseira: \n");
			segundaTraseira = resolveTraseira(cubo);
			printf("Restantes: %d\n", segundaTraseira);

			printf("Esquerda: \n");
			segundaEsquerda = resolveEsquerda(cubo);
			printf("Restantes: %d\n", segundaEsquerda);
			
			r = aux(segundaFrente, segundaDireita, segundaTraseira, segundaEsquerda);
		}
		else if (j == 2) {
			// Move o layer de cima/baixo do cubo
			j = 0;
			i++; 

			if (segundaFrente == primeiraFrente && segundaDireita == primeiraDireita && segundaTraseira == primeiraTraseira && segundaEsquerda == primeiraEsquerda) {
				executaAlgoritmo(cubo, "U");
			}	
		}
	}

	CUB_ExibirCUBO(cubo);
	printf("Loops: %d\n", i);

	system("pause");

}
