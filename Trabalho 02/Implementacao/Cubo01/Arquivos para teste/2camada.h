/******************************************************************************
*
*  $MCD M�dulo de defini��o: 2L		Segunda Camada
*
*  Arquivo gerado:              2camada.h
*  Letras identificadoras:      2C
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: 
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es

*
*  $ED Descri��o do m�dulo
*		Implementa 2 Camada do Cubo m�gico.
*
*		
*
******************************************************************************/

/* Tipo refer�ncia para um Cubo */

typedef struct CUB_tagCUBO * CUB_tppCUBO;

/**************************************************************************
*
*  $TC Tipo de dados: CUB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do Cubo
*
**************************************************************************/

typedef enum {

	C2C_CondRetOK,
	/* Concluiu corretamente */

	C2C_CondRetNenhumMovPossivel,
	/* Nào tem movimento que possa ser realizado */

} C2C_tpCondRet;


/**************************************************************************
*
*  $FC Fun��o: 2L  &Criar Cubo
*
*  $ED Descri��o da fun��o
*		
*
*  $EP Par�metros
*				
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   mem�ria.
*
**************************************************************************/

C2C_tpCondRet resolve2camada (CUB_tppCUBO cubo);
