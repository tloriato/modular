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
*	Versão  Autor		Data		Observações
*	3.0		TSMMABHL	02/06/18	Código refeito para melhor atender o módulo do cubo 1	
*	2.0		CJTSMMABHL	30/04/18	Código refatorado
*	1.0		MMA			29/04/18	Separar .h
*
*  $ED Descrição do módulo
*		Este módulo visa resolver a 2a camada do cubo mágico usando o método de 
*		iniciante (método das camadas) tendo o módulo do cubo 1 como base.
******************************************************************************/
#include "CUBO.h"
/**************************************************************************
*
*  $TC Tipo de dados: C2C Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do Cubo
*
**************************************************************************/

typedef enum {

	C2C_CondRetOK,
	/* Concluiu corretamente */

	C2C_CondRetCuboVazio
	/* Cubo Vazio */

} C2C_tpCondRet;


/**************************
*  $FC Função: C2C  resolve 2ª camada
*
*  $ED Descrição da função
*		Resolve a segunda camada de um cubo mágico com a primeira camada resovida,
*		seguindo os passos de resolução do método de iniciantes (método das camadas)
*		
*  $EParâmetros
*		$P cubo = estrutura CUB_tppCUBO populada
*		$P instrucoes = string vazio que abrigará os comandos de giro obtidos na função
*       
*  $FV Valor retornado
*       C2C_CondRetCuboVazio - O cubo recebido está vazio
*		C2C_CondRetOK - A segunda camada foi resolvida com sucesso
*
*	Assertiva de Entrada
*	- cubo != NULL
*	- instrucoes está vazio
*
*	Assertivas de Saida
*	- O cubo está com a segunda camada resolvida
*	- O vetor de instruções está com o tamanho certo e com os comandos para resolver
*	a segunda camada para o cubo dado
*	
**************************/
C2C_tpCondRet resolve2camada (CUB_tppCubo cubo, char *instrucoes);