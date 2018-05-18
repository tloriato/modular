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
*     Vers�o  Autor    Data       Observa��es
*      1.0	  MMA      29/04/18   Separar .h
*
*  $ED Descri��o do m�dulo
*		Implementa 2 Camada do Cubo m�gico.
*
*		
*
******************************************************************************/

/* Tipo refer�ncia para um Cubo */

typedef struct tpCubo CUB_tpCubo;

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

	C2C_CondRetCuboVazio,
	/* Cubo Vazio */

	C2C_CondRetFaltouMemoria
	/* Faltou Mem�ria */

} C2C_tpCondRet;


/**************************************************************************
*
*  $FC Fun��o: 2L  Resolve 2 camada
*
*  $ED Descri��o da fun��o
*		Resolve 2 camada
*  $EPar�metros
*		$P Cubo- Recebe um ponteiro para cubo
*				
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*       C2C_CondRetCuboVazio     - Criou vazio.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   mem�ria.
*
**************************************************************************/

C2C_tpCondRet resolve2camada (CUB_tpCubo* cubo);