/******************************************************************************
*
*  $MCD M�dulo de defini��o: Primeira camada cubo m�gico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC

/******************************************************************************
*
*  $MCD M�dulo de defini��o: Primeira camada cubo m�gico
*
*  Arquivo gerado:              Camada1.c
*  Letras identificadoras:      PCC
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: bl    Bruno Le�o
		    ms    Mariana Salgueiro
		    pf    Pilar Fernandez
	     	gf    Gabriel Faria   
*
*  $HA Hist�rico de evolu��o:
*	Vers�o		Autor          Data			Observa��es
*	  3       pf ms bl gf     02/mai/2018   t�rmino
*	  2		  pf ms bl gf     01/mai/2018   ajustes e continua��o do desenvolvimento
*     1       pf ms bl gf     30/abr/2018   in�cio 
*
*
*  $ED Descri��o do m�dulo
*		Implementa a primeira camada para a resolu��o de um cubo m�gico
*
*		O m�dulo implementa a representa��o de cubos m�gicos de posi��o fixa
*			que s�o manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face ter� sempre o mesmo valor.
*
******************************************************************************/

#include <stdio.h>
#include "CUBO.h"


 /***********************************************************************
*
*  $FC Fun��o: PCC Faz Camada 1
*
*  $EP Par�metros
*     $P Comandos[] - lista de comandos preenchidas pela fun��o
*
*  $ED Descri��o da fun��o
*		Resolve a primera camada do cubo m�gico.
*
***********************************************************************/
CUB_tpCondRet fazCamada1(char Comandos[]);