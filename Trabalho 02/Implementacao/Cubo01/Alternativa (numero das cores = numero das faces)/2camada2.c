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
*		2.0   CJTSMMABHL      30/04/18  Código refatorado
*		0.1   CJTSMMABHL	  20/04/18   Início do código
*  $ED Descrição do módulo
*		Implementa 2 Camada do Cubo mágico.
******************************************************************************/
#include "CUBO.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "2camada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55
#define MAX 600

#define CIMA 0
#define ESQUERDA 1
#define FRENTE 2
#define DIREITA 3
#define BAIXO 4
#define TRASEIRA 5

#define BRANCO 0
#define LARANJA 1
#define VERDE 2
#define VERMELHO 3
#define AMARELO 4
#define AZUL 5

/* STRING GLOBAL QUE GUARDA OS COMANDOS */

char instrucoes[MAX] = "";

int descobrePeca (int face, int *coresPeca, char *algDir, char *algEsq)
{
	switch (face) {
		case(ESQUERDA): {
			coresPeca[0] = ESQUERDA;
			coresPeca[1] = FRENTE;

			algDir = "D B' D' B D' R D R'";
			algEsq = "D' F D F' D R' D' R";
		
			break;
		}
		case(FRENTE): {
			coresPeca[0] = FRENTE;
			coresPeca[1] = DIREITA;

			algDir = "D R' D' R D' F D F'";
			algEsq = "D' L D L' D F' D' F";
		
			break;
		}
		case(DIREITA): {
			coresPeca[0] = DIREITA;
			coresPeca[1] = TRASEIRA;
				
			algDir = "D F' D' F D' L D L'";
			algEsq = "D' B D B' D L' D' L";

			break;
		}
		case(TRASEIRA): {
			coresPeca[0] = TRASEIRA;
			coresPeca[1] = ESQUERDA;

			algDir = "D L' D' L D' B D B'";
			algEsq = "D' R D R' D B' D' B";

			break;
		}
		default: {
			return -1;
		}
	}
	return 0;
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
*	Assertiva de Entrada
*	cubo != NULL
*	algoritmo != ""
*
*	Assertivas de Saida
*	executa algoritmo passado
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
*	Assertiva de Entrada
*	cubo != NULL
*	algoritmo != ""
*
*	Assertivas de Saida
*	executa algoritmo passado
**************************/
int resolveDireitaFace(int face, CUB_tpCubo *cubo)
{
	tpPeca *p;
	int coresPeca[2], numCores;
	char *algDir, *algEsq;
	
	//Primeiro, descobrimos a pe�a que queremos:
	descobrePeca(face, coresPeca, algDir, algEsq);
	
	//Segundo, descobrimos onde ela est�
	buscaPeca(p, &cubo, coresPeca, 2);

	//
	if(p->coord[0] == 1) //Est� na camada inferior
	{
		if(p->coord[1] == 2 && p->coord[2] == 1) //Na face frontal
		if(p->coord[1] == 3 && p->coord[2] == 2) //Na face direita
		if(p->coord[1] == 2 && p->coord[2] == 3) //Na face traseira
		if(p->coord[1] == 2 && p->coord[2] == 2) //Na face esquerda
	}

}
C2C_tpCondRet resolve2camada (CUB_tpCubo* cubo){

	if (cubo == NULL){
		return C2C_CondRetCuboVazio;
	}

	imprimeCubo(&cubo);

	//Resolve aresta direita da esquerda:
	resolveDireitaFace(1, &cubo);
	//Resolve aresta direita da frente:
	resolveDireitaFace(2, &cubo);
	//Resolve aresta direita da direita:
	resolveDireitaFace(3, &cubo);
	//Resolve aresta direita de tr�s:
	resolveDireitaFace(5, &cubo);

	imprimeCubo(&cubo);

	printf("\n%s\n", instrucoes);
	strcpy(execute, "" );

	return C2C_CondRetOK;

}

/*if(p->coord[0] == 1) //Est� na camada inferior
{
if(p->coord[1] == 2 && p->coord[2] == 1) //Na face frontal
if(p->coord[1] == 3 && p->coord[2] == 2) //Na face direita
if(p->coord[1] == 2 && p->coord[2] == 3) //Na face traseira
if(p->coord[1] == 2 && p->coord[2] == 2) //Na face esquerda
}

if(p->coord[0]==2) //Est� na camada do meio
{
*/