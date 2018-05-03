/******************************************************************************
*  $MCD Módulo de definição: 2L		Segunda Camada
*
*  Arquivo gerado:              secondLayer.h
*  Letras identificadoras:      2L
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores:	 CJ - Ana Carolina Junger
*			 TS - Tiago Simões	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*
*  $HA Históico de evolução:
*     Versão  Autor    Data     Observações
*		2.0   TS      30/04/18  Código refatorado
*		0.1   TS	  20/04/18   Início do código
*  $ED Descrição do módulo
*		Implementa 2 Camada do Cubo mágico.
******************************************************************************/
#include "CUBO.h"
#include "2camada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55
#define MAX 600

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

/* STRING GLOBAL QUE GUARDA OS COMANDOS */
char execute[MAX]= "";

/**************************
*  $FC Função: 2C  PecaDeCimaTrocada
*
*  $ED Descrição da função
*		checa se a cor da peca esta trocada
*  $EParâmetros
*		$P face
        $P faceAresta
        $P linhaAresta
        $P colunaAresta
        $P resolvidoPraCima
*				
*  $FV Valor retornado
*		1- esta trocada
*       0- sucesso
**************************/

int pecaDeCimaTrocada(int face, int faceAresta, int linhaAresta, int colunaAresta, int resolvidoPraCima) {

	if (face == DIREITA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 2 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 1 && colunaAresta == 2 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == TRASEIRA) {
		if (faceAresta == CIMA && linhaAresta == 0 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 2 && colunaAresta == 1 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == ESQUERDA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 0 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 1 && colunaAresta == 0 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == FRENTE) {
		if (faceAresta == CIMA && linhaAresta == 2 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 0 && colunaAresta == 1 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	return 0;
}

/**************************
*  $FC Função: 2C  resolveArestaDeFace
*
*  $ED Descrição da função
*		Checa aonde pecas podem estar e chama o algoritmo certo
*  $EParâmetros
*		$P cubo
*       $P face
*       $P resolvidoPraCima
*				
*  $FV Valor retornado
*		restantes - numero de pecas que nao estao no lugar
**************************/

int resolveArestaDeFace(CUB_tppCUBO cubo, int face, int resolvidoPraCima) {
	int restantes = 2;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;
	int faceDireitaRelativa = 0, faceEsquerdaRelativa = 0;

	int faceArestaD, linhaArestaD, colunaArestaD, cor1ArestaD, cor2ArestaD;
	int faceArestaE, linhaArestaE, colunaArestaE, cor1ArestaE, cor2ArestaE;

	char * algoDireita;
	char * algoEsquerda;
	char * algoIntermediario;


	if (cubo == NULL)
		return -1;

	if (CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE) != 0) { exit(1); }
	if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(2); }
	if (CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA) != 0) { exit(3); }
	if (CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA) != 0) { exit(4); }
	if (CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA) != 0) { exit(5); }
	if (CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO) != 0) { exit(6); }

	switch (face) {
	case(FRENTE): {
		cor1ArestaD = corFrente;
		cor1ArestaE = corFrente;

		cor2ArestaD = corDireita;
		cor2ArestaE = corEsquerda;

		if (resolvidoPraCima) {
			algoDireita = "D' R' D R D F D' F'";
			algoEsquerda = "D L D' L' D' F' D F";
			algoIntermediario = "D D";
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
			algoDireita = "D' B' D B D R D' R'";
			algoEsquerda = "D F D' F' D' R' D R"; 
			algoIntermediario = "D D";

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
			algoDireita = "D' F' D F D L D' L'";
			algoEsquerda = "D B D' B' D' L' D L";
			algoIntermediario = "D D";

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
			algoDireita = "D R D' R' D' B' D B";
			algoEsquerda = "D' L' D L D B D' B'";
			algoIntermediario = "D D";

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

	if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaD, &linhaArestaD, &colunaArestaD, cubo, cor1ArestaD, cor2ArestaD) != 0) { exit(8); }
	if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaE, &linhaArestaE, &colunaArestaE, cubo, cor1ArestaE, cor2ArestaE) != 0) { exit(9); }

	(face + 1) == 5 ? faceDireitaRelativa = 1 : (faceDireitaRelativa = (face + 1));
	(face - 1) == 0 ? faceEsquerdaRelativa = 4 : (faceEsquerdaRelativa = (face - 1));


	if (faceArestaD == face && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {
			// Cubo está resolvido para cima
			if (faceArestaD == face && linhaArestaD == 2 && colunaArestaD == 1) {
				// Algoritmo "Baixo" -> Direita
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

			else if (faceArestaD == faceDireitaRelativa && linhaArestaD == 1 && colunaArestaD == 0) {
				// Algoritmo de trocar a orientação da aresta do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaD, linhaArestaD, colunaArestaD, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Direita + Trocar orientação do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}
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

			if (faceArestaE == face && linhaArestaE == 2 && colunaArestaE == 1) {
				// Algoritmo "Baixo" -> Esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;
			}

			else if (faceArestaE == faceEsquerdaRelativa && linhaArestaE == 1 && colunaArestaE == 2) {
				// Algoritmo de trocar a orientação da aresta do lado esquerdo
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaE, linhaArestaE, colunaArestaE, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Esquerda + Trocar orientação do lado esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;
			}

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

/**************************
*  $FC Função: 2C  executaAlgoritmo
*
*  $ED Descrição da função
*    Executa algoritmo recebido pela string
*		
*  $EParâmetros
*		$P cubo = estrutura CUB_tppCUBO populada
*       $P algoritmo = string de no máximo ALG elementos com comandos no estilo: "U R U' R' U' F' U U F F"
*  $FV Valor retornado
*       0 - sucesso
*       1 - entrada inválida
**************************/

int executaAlgoritmo(CUB_tppCUBO cubo, char* algoritmo) {

	

	int i = 0;
	int jump = 2;
	
	char comandos[ALG];

	strcat(execute, algoritmo);
	printf("Excute %s \n", algoritmo);


	
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

		if (CUB_GirarFace(cubo, face, 1, rot) != 0) { exit(10); }

		i += jump;
	}

	return 0;
}

/**************************
*  $FC Função: 2C  resolvidoAcima
*
*  $ED Descrição da função
*	Verifica se cubo está com a face branca para cima	
*  $EParâmetros
*		$P cubo			
*  $FV Valor retornado
*		1- cubo para baixo
*       0- sucesso
**************************/

// (cubo) -> 1 | 0
int resolvidoAcima(CUB_tppCUBO cubo) {
	int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

	if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(11); }

	if (CUB_ChecarCorDaFace(&aux1, cubo, 0, 0, CIMA) != 0) { exit(11); }
	if (CUB_ChecarCorDaFace(&aux2, cubo, 0, 1, CIMA) != 0) { exit(12); }
	if (CUB_ChecarCorDaFace(&aux3, cubo, 0, 2, CIMA) != 0) { exit(13); }

	if (CUB_ChecarCorDaFace(&aux4, cubo, 1, 0, CIMA) != 0) { exit(14); }
	if (CUB_ChecarCorDaFace(&aux5, cubo, 1, 2, CIMA) != 0) { exit(15); }

	if (CUB_ChecarCorDaFace(&aux6, cubo, 2, 0, CIMA) != 0) { exit(16); }
	if (CUB_ChecarCorDaFace(&aux7, cubo, 2, 1, CIMA) != 0) { exit(17); }
	if (CUB_ChecarCorDaFace(&aux8, cubo, 2, 2, CIMA) != 0) { exit(18); }

	if (corCima == aux1 && aux1 == aux2 && aux2 == aux3 && aux3 == aux4 && aux4 == aux5 && aux5 == aux6 && aux6 == aux7 && aux7 == aux8) {
		return 1;
	}
	else {
		return 0;
	}
}

/**************************
*  $FC Função: 2C  aux
*
*  $ED Descrição da função
*		Funcao auxiliar
*  $EParâmetros
*		 $P a
*        $P b
*        $P c
*        $P d
*  $FV Valor retornado
*		1- nao sao todas iguais
*       0- se a=b=c=d
**************************/
int aux(int a, int b, int c, int d) {
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		return 0;
	}

	return 1;
}

/**************************
*  $FC Função: 2C  forcaCuboFrente
*
*  $ED Descrição da função
*		Cuida do caso de pacas presas
*  $EParâmetros
*		$P face
        $P faceAresta
        $P linhaAresta
        $P colunaAresta
        $P resolvidoPraCima
*				
*  $FV Valor retornado
*		1- n executou movimento
*       0- sucesso
**************************/

int forcaCuboFrente(CUB_tppCUBO cubo, int resolvidoPraCima) {

	int alterado = 0;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
	int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

	if (CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE) != 0) { exit(18); }
	if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(19); }
	if (CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA) != 0) { exit(20); }
	if (CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA) != 0) { exit(21); }
	if (CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA) != 0) { exit(22); }
	if (CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO) != 0) { exit(23); }

	/* Cuidando da Face da Frente! */
	cor1Aresta1 = corFrente;
	cor1Aresta2 = corFrente;

	cor2Aresta1 = corDireita;
	cor2Aresta2 = corEsquerda;

	if (CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1) != 0) { exit(24); }
	if (CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2) != 0) { exit(25); }



	if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U B U' B' U' R' U R");
		}
		else {
			// Algoritmo Baixo <> Direita [da Direita]
			executaAlgoritmo(cubo, "D' B' D B D R D' R'");
		}
		

		return 1;
	}

	else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
		// Aresta da Direita está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' B' U B U L U' L'");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "D B D' B' D' L' D L");
		}
		

		return 1;
	}

	else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Esquerda
		// Algorima Cima <> Direita [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U F U' F' U' L' U L");
		}
		else {
			// Algorima Baixo <> Direita [da Esquerda]
			executaAlgoritmo(cubo, "D' F' D F D L D' L'");
		}
		
		return 1;
	}

	else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
		// Aresta da Direita está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' R' U R U B U' B'");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "D' L' D L D B D' B'");
		}
		

		return 1;
	}

	else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 2) {
		// Aresta da Direita está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U L U' L' U' B' U B");
		}
		else {
			// Algoritmo Baixo <> Direita [da Traseira]
			executaAlgoritmo(cubo, "D R D' R' D' B' D B");
		}
		

		return 1;
	}

	else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Direita
		// Algoritmo Cima <> Esquerda [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' F' U F U R U' R'");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Direita]
			executaAlgoritmo(cubo, "D F D' F' D' R' D R");
		}
		

		return 1;
	}

	else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
		// Aresta da Esquerda está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U B U' B' U' R' U R");
		}
		else {
			// Algoritmo Baixo <> Direita [da Direita]
			executaAlgoritmo(cubo, "D' B' D B D R D' R'");
		}
		

		return 1;
	}

	else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' B' U B U L U' L'");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "D B D' B' D' L' D L");
		}
		

		return 1;
	}

	else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 0) {
		// Aresta da Esquerda está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' R' U R U B U' B'");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "D' L' D L D B D' B'");
		}
		
		return 1;
	}

	else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
		// Aresta da Esquerda está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U L U' L' U' B' U B");
		}
		else {
			// Algoritmo Baixo <> Direita [da Traseira]
			executaAlgoritmo(cubo, "D R D' R' D' B' D B");
		}

		return 1;
	}

	return 0;
}

/**************************
*  $FC Função: 2C  resolveCubo
*
*  $ED Descrição da função
*		Resolve 2 camada
*  $EParâmetros
*		$P face
        $P faceAresta
        $P linhaAresta
        $P colunaAresta
        $P resolvidoPraCima
*				
*  $FV Valor retornado
*		
**************************/

int resolveCubo(CUB_tppCUBO cubo) {
	int r = 1, j = 1, i = 0;
	int resolvidoPraCima = resolvidoAcima(cubo);
	int primeiraFrente = 2, segundaFrente = 2;
	int primeiraDireita = 2, segundaDireita = 2;
	int primeiraTraseira = 2, segundaTraseira = 2;
	int primeiraEsquerda = 2, segundaEsquerda = 2;

	

	while (r) {

		if (i == 3) {
			// força o cubo
			i = 0;

			forcaCuboFrente(cubo, resolvidoPraCima);
		}

		if (j == 0) {
			j++;

			primeiraFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			primeiraDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			primeiraTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			primeiraEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
			r = aux(primeiraFrente, primeiraDireita, primeiraTraseira, primeiraEsquerda);
		}
		else if (j == 1) {
			j++;

			segundaFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			segundaDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			segundaTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			segundaEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
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
	

	if (cubo == NULL){
		return C2C_CondRetCuboVazio;
	}

	printf("\n");
	CUB_ExibirCUBO(cubo);

	resolveCubo(cubo);

	printf("\n%s\n", execute);
	printf("\n");
	CUB_ExibirCUBO(cubo);

	strcpy(execute, "" );

	

	return C2C_CondRetOK;
}