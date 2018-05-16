/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC

/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: bl    Bruno Leão
		    ms    Mariana Salgueiro
		    pf    Pilar Fernandez
	     	gf    Gabriel Faria   
*
*  $HA Histórico de evolução:
*	Versão		Autor          Data			Observações
*	  3       pf ms bl gf     02/mai/2018   término
*	  2		  pf ms bl gf     01/mai/2018   ajustes e continuação do desenvolvimento
*     1       pf ms bl gf     30/abr/2018   início 
*
*
*  $ED Descrição do módulo
*		Implementa a primeira camada para a resolução de um cubo mágico
*
*		O módulo implementa a representação de cubos mágicos de posição fixa
*			que são manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face terá sempre o mesmo valor.
*
******************************************************************************/

#include <stdio.h>
#include "CUBO.h"


 /***********************************************************************
*
*  $FC Função: PCC Faz Camada 1
*
*  $EP Parâmetros
*     $P Comandos[] - lista de comandos preenchidas pela função
*
*  $ED Descrição da função
*		Resolve a primera camada do cubo mágico.
*
***********************************************************************/
CUB_tpCondRet fazCamada1(char Comandos[]);