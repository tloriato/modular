/******************************************************************************
*
*  $MCD Módulo de definição: 2L		Segunda Camada
*
*  Arquivo gerado:              secondLayer.h
*  Letras identificadoras:      2L
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: 
*
*  $HA Históico de evoluçãoo:
*     Versão  Autor    Data     Observações
*		0.1   MA      1/05/18   Código refatorado
*  $ED Descrição do módulo
*		Implementa 2 Camada do Cubo m�gico.
*
*		
*
******************************************************************************/
#include "CUBO.h"
#include "2camada.h"
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

int pecaDeCimaTrocada(int face, int faceAresta, int linhaAresta, int colunaAresta, int resolvidoPraCima) {

	if (face == DIREITA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 2 && resolvidoPraCima == 0) {
			return 1;
		}
	}

	else if (face == TRASEIRA) {
		if (faceAresta == CIMA && linhaAresta == 0 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
	}

	else if (face == ESQUERDA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 0 && resolvidoPraCima == 0) {
			return 1;
		}
	}

	else if (face == FRENTE) {
		if (faceAresta == CIMA && linhaAresta == 2 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
	}

	return 0;
}

int resolveArestaDeFace(CUB_tppCUBO cubo, int face, int resolvidoPraCima) {
	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;
	int faceDireitaRelativa = 0, faceEsquerdaRelativa = 0;

	int faceArestaD, linhaArestaD, colunaArestaD, cor1ArestaD, cor2ArestaD;
	int faceArestaE, linhaArestaE, colunaArestaE, cor1ArestaE, cor2ArestaE;

	char * algoDireita;
	char * algoEsquerda;
	char * algoIntermediario;

	int restantes = 2;


	if (cubo == NULL)
		return -1;

	CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
	CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
	CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
	CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
	CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
	CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

	switch (face) {
	case(FRENTE): {
		cor1ArestaD = corFrente;
		cor1ArestaE = corFrente;

		cor2ArestaD = corDireita;
		cor2ArestaE = corEsquerda;

		if (resolvidoPraCima) {
			return -1;

		}
		else {
			algoDireita = "U R U' R' U' F' U F";
			algoEsquerda = "U' L' U L U F U' F'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(DIREITA): {
		cor1ArestaD = corDireita;
		cor1ArestaE = corDireita;

		cor2ArestaD = corTraseira;
		cor2ArestaE = corFrente;

		if (resolvidoPraCima) {
			return -1;

		}
		else {
			algoDireita = "U B U' B' U' R' U R";
			algoEsquerda = "U' F' U F U R U' R'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(ESQUERDA): {
		cor1ArestaD = corEsquerda;
		cor1ArestaE = corEsquerda;

		cor2ArestaD = corFrente;
		cor2ArestaE = corTraseira;

		if (resolvidoPraCima) {
			return -1;

		}
		else {
			algoDireita = "U F U' F' U' L' U L";
			algoEsquerda = "U' B' U B U L U' L'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(TRASEIRA): {
		cor1ArestaD = corTraseira;
		cor1ArestaE = corTraseira;

		cor2ArestaD = corEsquerda;
		cor2ArestaE = corDireita;

		if (resolvidoPraCima) {
			return -1;

		}
		else {
			algoDireita = "U L U' L' U' B' U B";
			algoEsquerda = "U' R' U R U B U' B'";
			algoIntermediario = "U U";
		}

		break;
	}
	default: {
		return -1;
	}
	}

	CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaD, &linhaArestaD, &colunaArestaD, cubo, cor1ArestaD, cor2ArestaD);
	CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaE, &linhaArestaE, &colunaArestaE, cubo, cor1ArestaE, cor2ArestaE);

	(face + 1) == 5 ? faceDireitaRelativa = 1 : (faceDireitaRelativa = (face + 1));
	(face - 1) == 0 ? faceDireitaRelativa = 4 : (faceDireitaRelativa = (face - 1));


	if (faceArestaD == face && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {
			// Cubo está resolvido para cima
		}
		else {

			if (faceArestaD == face && linhaArestaD == 0 && colunaArestaD == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
				
			}

			else if (faceArestaD == faceDireitaRelativa && linhaArestaD == 1 && colunaArestaD == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaD, linhaArestaD, colunaArestaD, resolvidoPraCima)) {
				// Algoritmo Cima -> Direita + Trocar orientação do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

		}

	}

	if (faceArestaE == face && linhaArestaE == 1 && colunaArestaE == 0) {
		// Aresta da Esquerda de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {

		}

		else {

			if (faceArestaE == face && linhaArestaE == 0 && colunaArestaE == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;

			}

			else if (faceArestaE == faceEsquerdaRelativa && linhaArestaE == 1 && colunaArestaE == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;

			}

			else if (pecaDeCimaTrocada(face, faceArestaE, linhaArestaE, colunaArestaE, resolvidoPraCima)) {
				// Algoritmo Cima -> Esquerda + Trocar orientação do lado esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;
			}

		}

	}

	return restantes;
	
}

// (config) ~> inteiro
//	config = vetor de 54 inteiros
//	inteiro =
//		0 -> sucesso
int populaCubo(int *config) {

	// 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

	// Up Face 0
	config[0] = AMARELO;
	config[1] = LARANJA;
	config[2] = AZUL;

	config[3] = VERMELHO;
	config[4] = AMARELO; 
	config[5] = VERMELHO;

	config[6] = VERDE;
	config[7] = AZUL;
	config[8] = AMARELO; 

	// Left Face 4
	config[9] = VERDE;
	config[10] = AMARELO;
	config[11] = LARANJA;

	config[21] = LARANJA;
	config[22] = VERMELHO;	
	config[23] = AZUL;

	config[33] = VERMELHO;
	config[34] = VERMELHO;
	config[35] = VERMELHO;

	// Front Face 1
	config[12] = AMARELO;
	config[13] = VERMELHO;
	config[14] = AZUL;

	config[24] = AMARELO;
	config[25] = VERDE;  
	config[26] = AMARELO;

	config[36] = VERDE;
	config[37] = VERDE;
	config[38] = VERDE;

	// Right Face 2
	config[15] = VERMELHO;
	config[16] = VERDE;
	config[17] = AMARELO;

	config[27] = LARANJA;
	config[28] = LARANJA; 
	config[29] = AMARELO;

	config[39] = LARANJA;
	config[40] = LARANJA;
	config[41] = LARANJA;

	// Back Face 3
	config[18] = LARANJA;
	config[19] = AZUL;
	config[20] = VERMELHO;

	config[30] = VERDE;
	config[31] = AZUL;  
	config[32] = VERDE;

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
	printf("%s\n", algoritmo);

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

	printf("\nExecute %s\n", algoritmo);

	return 0;
}

// (cubo) -> 1 | 0
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

	else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 2) {
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

int resolveCubo(CUB_tppCUBO cubo) {
	int r = 1, j = 1, i = 0;

	int primeiraFrente = 2, segundaFrente = 2;
	int primeiraDireita = 2, segundaDireita = 2;
	int primeiraTraseira = 2, segundaTraseira = 2;
	int primeiraEsquerda = 2, segundaEsquerda = 2;

	int resolvidoPraCima = resolvidoAcima(cubo);

	while (r) {


		if (i == 3) {
			// força o cubo
			i = 0;

			forcaCuboFrente(cubo);
		}

		if (j == 0) {
			j++;

			printf("Frente: \n");
			primeiraFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			printf("Restantes: %d\n", primeiraFrente);

			printf("Direita: \n");
			primeiraDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			printf("Restantes: %d\n", primeiraDireita);

			printf("Traseira: \n");
			primeiraTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			printf("Restantes: %d\n", primeiraTraseira);

			printf("Esquerda: \n");
			primeiraEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
			printf("Restantes: %d\n", primeiraEsquerda);

			r = aux(primeiraFrente, primeiraDireita, primeiraTraseira, primeiraEsquerda);
		}
		else if (j == 1) {
			j++;

			printf("Frente: \n");
			segundaFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			printf("Restantes: %d\n", segundaFrente);

			printf("Direita: \n");
			segundaDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			printf("Restantes: %d\n", segundaDireita);

			printf("Traseira: \n");
			segundaTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			printf("Restantes: %d\n", segundaTraseira);

			printf("Esquerda: \n");
			segundaEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
			printf("Restantes: %d\n", segundaEsquerda);

			r = aux(segundaFrente, segundaDireita, segundaTraseira, segundaEsquerda);
		}
		else if (j == 2) {
			// Move o layer de cima/baixo do cubo
			j = 0;
			i++;

			if (resolvidoPraCima) {
				executaAlgoritmo(cubo, "D");
			}
			else {
				executaAlgoritmo(cubo, "U");
			}
		}
	}
}

C2C_tpCondRet resolve2camada(CUB_tppCUBO cubo){


	int i, j = 0;
	int config[54];

	//CUB_tppCUBO cubo;

	populaCubo(config);

	CUB_CriarCUBO(&cubo, config);

	CUB_ExibirCUBO(cubo);

	resolveCubo(cubo);

	CUB_ExibirCUBO(cubo);

	return C2C_CondRetOK;



}

