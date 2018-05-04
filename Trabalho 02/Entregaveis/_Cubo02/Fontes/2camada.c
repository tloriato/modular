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
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
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

char instrucoes[MAX] = "";

/**************************************************************************
*
*  $FC Função: 2L  ResolvidoAcima
*
*  $ED Descrição da função
*		checa se cubo esta com face branca para cima
*  $EParâmetros
*		$P Cubo- Recebe um ponteiro para cubo
*				
*  $FV Valor retornado
*		1- cubo para cima
*		0- cubo normal
**************************************************************************/


int resolvidoAcima(CUB_tpCubo** cubo) {
	int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

	CUB_ChecarCorDaFace(&aux1, *cubo, 0, 0, 0);
	CUB_ChecarCorDaFace(&aux2, *cubo, 0, 0, 1);
	CUB_ChecarCorDaFace(&aux3, *cubo, 0, 0, 2);

	CUB_ChecarCorDaFace(&aux4, *cubo, 0, 1, 0);
	CUB_ChecarCorDaFace(&corCima, *cubo, 0, 1, 1);
	CUB_ChecarCorDaFace(&aux5, *cubo, 0, 1, 2);

	CUB_ChecarCorDaFace(&aux6, *cubo, 0, 2, 0);
	CUB_ChecarCorDaFace(&aux7, *cubo, 0, 2, 1);
	CUB_ChecarCorDaFace(&aux8, *cubo, 0, 2, 2);

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
*
**************************/
int resolveArestaDeFace(CUB_tpCubo** cubo, int face, int resolvidoPraCima) {

	if (cubo == NULL)
		return -1;

	int restantes = 2;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	int faceDireitaRelativa = 0, faceEsquerdaRelativa = 0;

	int faceArestaD, linhaArestaD, colunaArestaD, cor1ArestaD, cor2ArestaD;
	int faceArestaE, linhaArestaE, colunaArestaE, cor1ArestaE, cor2ArestaE;
	int faceAux, faceCorAux;

	char * algoDireita;
	char * algoEsquerda;
	char * algoIntermediario;

	CUB_ChecarCorDaFace(&corCima, *cubo, 0, 1, 1);
	CUB_ChecarCorDaFace(&corEsquerda, *cubo, 4, 1, 1);
	CUB_ChecarCorDaFace(&corFrente, *cubo, 1, 1, 1);
	CUB_ChecarCorDaFace(&corDireita, *cubo, 2, 1, 1);
	CUB_ChecarCorDaFace(&corTraseira, *cubo, 3, 1, 1);
	CUB_ChecarCorDaFace(&corBaixo, *cubo, 5, 1, 1);

	switch (face) {
	case(FRENTE): {
		cor1ArestaD = corFrente;
		cor1ArestaE = corFrente;

		cor2ArestaD = corDireita;
		cor2ArestaE = corEsquerda;

		if (resolvidoPraCima) {
			algoDireita = "D R' D' R D' F D F'";
			algoEsquerda = "D' L D L' D F' D' F";
			algoIntermediario = "D' D'";
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
			algoDireita = "D F' D' F D' L D L'";
			algoEsquerda = "D' B D B' D L' D' L";
			algoIntermediario = "D' D'";;

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
			algoDireita = "D B' D' B D' R D R'";
			algoEsquerda = "D' F D F' D R' D' R";
			algoIntermediario = "D' D'";

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
			algoDireita = "D L' D' L D' B D B'";
			algoEsquerda = "D' R D R' D B' D' B";
			algoIntermediario = "D' D'";

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
	
	int achado = 0;

	// Checa todas as peças do Cubo em busca da Aresta da Direita da [face]
	// Muito obrigado ao trabalho original
	for (int o = 0; o < 6; o++) {
		if (achado) {
			break;
		}
		for (int l = 0; l < 3; l++) {
			if (achado) {
				break;
			}
			for (int c = 0; c < 3; c++) {
				CUB_ChecarCorDaFace(&faceCorAux, *cubo, o, l, c);
				if (faceCorAux == cor1ArestaD) {
					if (o == 0) { // Se estiver na face de cima
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 1) { // Se estiver na face da frente
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 2) { // Se estiver na face direita
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 3) { // Se estiver na face traseira
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 4) { // Se estiver na face esquerda
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 5) { // Se estiver na face debaixo
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
								faceArestaD = o;

								achado = 1;
								break;
							}
						}
					}
				}
			}
		}
	}

	achado = 0;

	// Checa todas as peças do Cubo em busca da Aresta da Esquerda da [face]
	for (int o = 0; o < 6; o++) {
		if (achado) {
			break;
		}
		for (int l = 0; l < 3; l++) {
			if (achado) {
				break;
			}
			for (int c = 0; c < 3; c++) {
				CUB_ChecarCorDaFace(&faceCorAux, *cubo, o, l, c);
				if (faceCorAux == cor1ArestaE) {
					if (o == 0) { // Se estiver na face de cima
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 1) { // Se estiver na face da frente
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 2) { // Se estiver na face direita
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 3) { // Se estiver na face traseira
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 4) { // Se estiver na face esquerda
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
					else if (o == 5) { // Se estiver na face debaixo
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
								faceArestaE = o;

								achado = 1;
								break;
							}
						}
					}
				}
			}
		}
	}


	//if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaD, &linhaArestaD, &colunaArestaD, cubo, cor1ArestaD, cor2ArestaD) != 0) { exit(8); }
	//if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaE, &linhaArestaE, &colunaArestaE, cubo, cor1ArestaE, cor2ArestaE) != 0) { exit(9); }

	if (face == FRENTE) {
		faceDireitaRelativa = DIREITA;
		faceEsquerdaRelativa = ESQUERDA;
	}
	else if (face == DIREITA) {
		faceDireitaRelativa = TRASEIRA;
		faceEsquerdaRelativa = FRENTE;
	}
	else if (face == TRASEIRA) {
		faceDireitaRelativa = ESQUERDA;
		faceEsquerdaRelativa = DIREITA;
	}
	else if (face == ESQUERDA) {
		faceDireitaRelativa = FRENTE;
		faceEsquerdaRelativa = TRASEIRA;
	}

	
	if (faceArestaD == face && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {
			// Cubo está resolvido para cima
			if (faceArestaD == face && linhaArestaD == 2 && colunaArestaD == 1) {
				// Algoritmo "Baixo" -> Direita
				restantes--;
			}

			else if (faceArestaD == faceDireitaRelativa && linhaArestaD == 1 && colunaArestaD == 0) {
				// Algoritmo de trocar a orientação da aresta do lado direito
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaD, linhaArestaD, colunaArestaD, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Direita + Trocar orientação do lado direito
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
				restantes--;
			}

			else if (faceArestaE == faceEsquerdaRelativa && linhaArestaE == 1 && colunaArestaE == 2) {
				// Algoritmo de trocar a orientação da aresta do lado esquerdo
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaE, linhaArestaE, colunaArestaE, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Esquerda + Trocar orientação do lado esquerda
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
**************************/
int executaAlgoritmo(CUB_tpCubo* cubo, char* algoritmo)
{
	strcat(instrucoes, algoritmo);

	int i = 0;

	char comandos[ALG];
	memset(comandos, '\0', sizeof(comandos));
	strcpy(comandos, algoritmo);

	while (comandos[i]) {

		if (comandos[i] == 'U') {
			if (comandos[i + 1] == '\'') {
				CUB_giraTrasDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraTopoEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}

		else if (comandos[i] == 'B') {
			if (comandos[i + 1] == '\'') {
				CUB_giraTopoDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraTrasEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}

		else if (comandos[i] == 'D') {
			if (comandos[i + 1] == '\'') {
				CUB_giraBaixoDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraBaixoEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		else if (comandos[i] == 'F') {
			if (comandos[i + 1] == '\'') {
				CUB_giraFrenteDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else
				CUB_giraFrenteEsquerda(cubo, 1);
			//executa sentido horario
			i += 2;
		}
		else if (comandos[i] == 'R') {
			if (comandos[i + 1] == '\'') {
				CUB_giraDireitaFrente(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraDireitaTras(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		else if (comandos[i] == 'L') {
			if (comandos[i + 1] == '\'') {
				CUB_giraEsquerdaTras(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraEsquerdaFrente(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}



	}

	return 0;
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
*
**************************/
int forcaCuboFrente(CUB_tpCubo** cubo, int resolvidoPraCima) {

	int alterado = 0;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	int faceArestaD, linhaArestaD, colunaArestaD, cor1ArestaD, cor2ArestaD;
	int faceArestaE, linhaArestaE, colunaArestaE, cor1ArestaE, cor2ArestaE;

	int faceAux;

	CUB_ChecarCorDaFace(&corCima, *cubo, 0, 1, 1);
	CUB_ChecarCorDaFace(&corEsquerda, *cubo, 4, 1, 1);
	CUB_ChecarCorDaFace(&corFrente, *cubo, 1, 1, 1);
	CUB_ChecarCorDaFace(&corDireita, *cubo, 2, 1, 1);
	CUB_ChecarCorDaFace(&corTraseira, *cubo, 3, 1, 1);
	CUB_ChecarCorDaFace(&corBaixo, *cubo, 5, 1, 1);

	/* Cuidando da Face da Frente! */
	cor1ArestaD = corFrente;
	cor1ArestaE = corFrente;

	cor2ArestaD = corDireita;
	cor2ArestaE = corEsquerda;

	// Checa todas as peças do Cubo em busca da Aresta da Direita da [face]
	// Muito obrigado ao trabalho original
	for (int o = 0; o < 6; o++) {
		for (int l = 0; l < 3; l++) {
			for (int c = 0; c < 3; c++) {
				CUB_ChecarCorDaFace(&faceArestaD, *cubo, o, l, c);
				if (faceArestaD == cor1ArestaD) {
					if (o == 0) { // Se estiver na face de cima
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
					else if (o == 1) { // Se estiver na face da frente
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
					else if (o == 2) { // Se estiver na face direita
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
					else if (o == 3) { // Se estiver na face traseira
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 0, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
					else if (o == 4) { // Se estiver na face esquerda
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 2);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 1;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 0);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
					else if (o == 5) { // Se estiver na face debaixo
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 0;
								colunaArestaD = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 1;
								colunaArestaD = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 2, 1);
							if (faceAux == cor2ArestaD) {
								linhaArestaD = 2;
								colunaArestaD = 1;
							}
						}
					}
				}
			}
		}
	}

	// Checa todas as peças do Cubo em busca da Aresta da Esquerda da [face]
	for (int o = 0; o < 6; o++) {
		for (int l = 0; l < 3; l++) {
			for (int c = 0; c < 3; c++) {
				CUB_ChecarCorDaFace(&faceArestaE, *cubo, o, l, c);
				if (faceArestaE == cor1ArestaE) {
					if (o == 0) { // Se estiver na face de cima
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
					else if (o == 1) { // Se estiver na face da frente
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
					else if (o == 2) { // Se estiver na face direita
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
					else if (o == 3) { // Se estiver na face traseira
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 0, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
					else if (o == 4) { // Se estiver na face esquerda
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 0, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 1, 2);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 1;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 5, 1, 0);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
					else if (o == 5) { // Se estiver na face debaixo
						if (l == 0 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 1, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 0;
								colunaArestaE = 1;
							}
						}
						if (l == 1 && c == 0) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 4, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 0;
							}
						}
						if (l == 1 && c == 2) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 2, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 1;
								colunaArestaE = 2;
							}
						}
						if (l == 2 && c == 1) {
							CUB_ChecarCorDaFace(&faceAux, *cubo, 3, 2, 1);
							if (faceAux == cor2ArestaE) {
								linhaArestaE = 2;
								colunaArestaE = 1;
							}
						}
					}
				}
			}
		}
	}



	if (faceArestaD == DIREITA && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U B U' B' U' R' U R ");
		}
		else {
			// Algoritmo Baixo <> Direita [da Direita]
			executaAlgoritmo(cubo, "D' B' D B D R D' R' ");
		}


		return 1;
	}

	else if (faceArestaD == ESQUERDA && linhaArestaD == 1 && colunaArestaD == 0) {
		// Aresta da Direita está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' B' U B U L U' L' ");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "D B D' B' D' L' D L ");
		}


		return 1;
	}

	else if (faceArestaD == ESQUERDA && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita está na Direita da Face Esquerda
		// Algorima Cima <> Direita [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U F U' F' U' L' U L ");
		}
		else {
			// Algorima Baixo <> Direita [da Esquerda]
			executaAlgoritmo(cubo, "D' F' D F D L D' L' ");
		}

		return 1;
	}

	else if (faceArestaD == TRASEIRA && linhaArestaD == 1 && colunaArestaD == 0) {
		// Aresta da Direita está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' R' U R U B U' B' ");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "D' L' D L D B D' B' ");
		}


		return 1;
	}

	else if (faceArestaD == TRASEIRA && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U L U' L' U' B' U B ");
		}
		else {
			// Algoritmo Baixo <> Direita [da Traseira]
			executaAlgoritmo(cubo, "D R D' R' D' B' D B ");
		}


		return 1;
	}

	else if (faceArestaE == DIREITA && linhaArestaE == 1 && colunaArestaE == 0) {
		// Aresta da Esquerda está na Esquerda da Face Direita
		// Algoritmo Cima <> Esquerda [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' F' U F U R U' R' ");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Direita]
			executaAlgoritmo(cubo, "D F D' F' D' R' D R ");
		}


		return 1;
	}

	else if (faceArestaE == DIREITA && linhaArestaE == 1 && colunaArestaE == 2) {
		// Aresta da Esquerda está na Direita da Face Direita
		// Algoritmo Cima <> Direita [da Direita]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U B U' B' U' R' U R ");
		}
		else {
			// Algoritmo Baixo <> Direita [da Direita]
			executaAlgoritmo(cubo, "D' B' D B D R D' R' ");
		}


		return 1;
	}

	else if (faceArestaE == ESQUERDA && linhaArestaE == 1 && colunaArestaE == 0) {
		// Aresta da Esquerda está na Esquerda da Face Esquerda
		// Algoritmo Cima <> Esquerda [da Esquerda]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' B' U B U L U' L' ");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "D B D' B' D' L' D L ");
		}


		return 1;
	}

	else if (faceArestaE == TRASEIRA && linhaArestaE == 1 && colunaArestaE == 0) {
		// Aresta da Esquerda está na Esquerda da Face Traseira
		// Algoritmo Cima <> Esquerda [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U' R' U R U B U' B' ");
		}
		else {
			// Algoritmo Baixo <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "D' L' D L D B D' B' ");
		}

		return 1;
	}

	else if (faceArestaE == TRASEIRA && linhaArestaE == 1 && colunaArestaE == 2) {
		// Aresta da Esquerda está na Direita da Face Traseira
		// Algoritmo Cima <> Direita [da Traseira]
		if (!resolvidoPraCima) {
			executaAlgoritmo(cubo, "U L U' L' U' B' U B ");
		}
		else {
			// Algoritmo Baixo <> Direita [da Traseira]
			executaAlgoritmo(cubo, "D R D' R' D' B' D B ");
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
*	Assertiva de Entrada
*	cubo != NULL
*
*	Assertivas de Saida
*	executa algoritmo de resolucao do cubo
*
**************************/
int resolveCubo(CUB_tpCubo* cubo) {
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

			//forcaCuboFrente(cubo);
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

	printf("Acabou mesmo?");
	return 0;
}



C2C_tpCondRet resolve2camada (CUB_tpCubo* cubo){

	if (cubo == NULL){
		return C2C_CondRetCuboVazio;
	}

	imprimeCubo(&cubo);
	resolveCubo(&cubo);
	imprimeCubo(&cubo);

	printf("\n%s\n", execute);
	strcpy(execute, "" );

	return C2C_CondRetOK;

}