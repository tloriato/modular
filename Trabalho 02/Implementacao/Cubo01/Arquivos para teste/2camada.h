/******************************************************************************
*
*  $MCD Módulo de definição: 2L		Segunda Camada
*
*  Arquivo gerado:              2camada.h
*  Letras identificadoras:      2C
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: 
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações

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

	C2C_CondRetNenhumMovPossivel,
	/* Nào tem movimento que possa ser realizado */

} C2C_tpCondRet;


/**************************************************************************
*
*  $FC Função: 2L  &Criar Cubo
*
*  $ED Descrição da função
*		
*
*  $EParâmetros
*				
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   memória.
*
**************************************************************************/

C2C_tpCondRet resolve2camada (CUB_tppCUBO cubo);
C2C_tpCondRet resolveArestaDeFace(CUB_tppCUBO cubo, int face, int resolvidoPraCima);
