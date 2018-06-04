/******************************************************************************
*
*  $MCD M�dulo de defini��o: 2C		Segunda Camada
*
*  Arquivo gerado:              2camada.h
*  Letras identificadoras:      2C
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  CJ - Ana Carolina Junger
*			 TS - Tiago Sim�es	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*
*  $HA Hist�rico de evolu��o:
*	Vers�o  Autor		Data		Observa��es
*	3.0		TSMMABHL	02/06/18	C�digo refeito para melhor atender o m�dulo do cubo 1	
*	2.0		CJTSMMABHL	30/04/18	C�digo refatorado
*	1.0		MMA			29/04/18	Separar .h
*
*  $ED Descri��o do m�dulo
*		Este m�dulo visa resolver a 2a camada do cubo m�gico usando o m�todo de 
*		iniciante (m�todo das camadas) tendo o m�dulo do cubo 1 como base.
******************************************************************************/
#include "CUBO.h"
/**************************************************************************
*
*  $TC Tipo de dados: C2C Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do Cubo
*
**************************************************************************/

typedef enum {

	C2C_CondRetOK,
	/* Concluiu corretamente */

	C2C_CondRetCuboVazio
	/* Cubo Vazio */

} C2C_tpCondRet;


/**************************
*  $FC Fun��o: C2C  resolve 2� camada
*
*  $ED Descri��o da fun��o
*		Resolve a segunda camada de um cubo m�gico com a primeira camada resovida,
*		seguindo os passos de resolu��o do m�todo de iniciantes (m�todo das camadas)
*		
*  $EPar�metros
*		$P cubo = estrutura CUB_tppCUBO populada
*		$P instrucoes = string vazio que abrigar� os comandos de giro obtidos na fun��o
*       
*  $FV Valor retornado
*       C2C_CondRetCuboVazio - O cubo recebido est� vazio
*		C2C_CondRetOK - A segunda camada foi resolvida com sucesso
*
*	Assertiva de Entrada
*	- cubo != NULL
*	- instrucoes est� vazio
*
*	Assertivas de Saida
*	- O cubo est� com a segunda camada resolvida
*	- O vetor de instru��es est� com o tamanho certo e com os comandos para resolver
*	a segunda camada para o cubo dado
*	
**************************/
C2C_tpCondRet resolve2camada (CUB_tppCubo cubo, char *instrucoes);