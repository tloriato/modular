/******************************************************************************
*
*  $MCD Módulo de definição: 2C		Segunda Camada
*
*  Arquivo gerado:              2camada.h
*  Letras identificadoras:      2C
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  CJ - Ana Carolina Junger
*			 TS - Tiago Simões	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data       Observações
*      1.0	  MMA      29/04/18   Separar .h
*
*  $ED Descrição do módulo
*		Implementa 2 Camada do Cubo mágico.
*
*		
*
******************************************************************************/

/* Tipo referência para um Cubo */

typedef struct CUB_tagCUBO * CUB_tppCUBO;

/**************************************************************************
*
*  $TC Tipo de dados: CUB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do Cubo
*
**************************************************************************/

typedef enum {

	C2C_CondRetOK,
	/* Concluiu corretamente */

	C2C_CondRetCuboVazio,
	/* Cubo Vazio */

	C2C_CondRetFaltouMemoria
	/* Faltou Memória */

} C2C_tpCondRet;


/**************************************************************************
*
*  $FC Função: 2L  Resolve 2 camada
*
*  $ED Descrição da função
*		Resolve 2 camada
*  $EParâmetros
*		$P Cubo- Recebe um cubo
*				
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*       C2C_CondRetCuboVazio     - Criou vazio.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   memória.
*
**************************************************************************/

C2C_tpCondRet resolve2camada (CUB_tppCUBO cubo);

