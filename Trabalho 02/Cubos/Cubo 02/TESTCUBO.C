/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTCUBO.C
*  Letras identificadoras:      TCUB
*
*  Nome da base de software:	Teste automatizado para o cubo
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: hbpdm - Hugo de Barros Pimentel Dutra Machado
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data			Observações
*		4.00   hbpdm   28/mar/2018 Atualização e finalizalçao das funções
*		3.00   hbpdm   25/mar/2018 Atualização e correção das funções
*       2.00   hbpdm   22/mar/2018 Prototipo para as funções do teste
*       1.00   hbpdm   19/mar/2018 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo cubo.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo cubo:
*
*	  "=criar"				- chama a função CUB_CriarCUBO() cria cubo
*     "=destroi"			- chama a função CUB_DestruirCUBO() destroi cubo
*	  "=girar"				- chama a função CUB_GirarFace() e gira o cubo de acordo com a face escolhida
*	  "=checar"				-chama a função CUB_ChecarCorDaFace() e passa por referencia a cor
*	  "=encontrararesta"	-chama a função CUB_EncontrarPosicaoDePecaDeAresta() e passa por referencia a face, a linha e a coluna
*	  "=encontrarquina"		-chama a função CUB_EncontrarPosicaoDePecaDeQuina() e passa por referencia a face, a linha e a coluna
*						
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include	"CUBO.h"

/*Inicializa para testar o cubo*/
CUB_tppCUBO cubo;
int i;
int config[54];

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_CUB_CMD				"=criar"
#define     DESTROI_CUB_CMD				"=destruir"
#define		GIRAR_CUB_CMD				"=girar"
#define		CHECAR_CUB_CMD				"=checar"
#define		ENCONTRAR_ARESTA_CUB_CMD	"=encontrararesta"
#define		ENCONTRAR_QUINA_CUB_CMD		"=encontrarquina"
#define		EXIBIR_CUB_CMD				"=exibir"

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: TCUB Efetuar operações de teste específicas para cubo
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     cubo sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	CUB_tpCondRet CondRetObtido = CUB_CondRetOK;
	CUB_tpCondRet CondRetEsperada = CUB_CondRetFaltouMemoria;
	
	TST_tpCondRet Ret;

	/*variavais usasdas para o teste*/
	/* inicializa com menos -1*/
	/* Importante para os casos em que a variavel não é modificada*/

	int FaceObtida = -1;
	int FaceEsperada = -1;

	int CorObtida = -1;
	int CorObtida2 = -1;
	int CorObtida3 = -1;

	int CorEsperada = -1;
	
	int NumFace = -1;
	int NumGiro = -1;

	char Sentido = '?';

	int NumLinha = -1;
	int NumColuna = -1;

	int NumColunaEsperada = -1;
	int NumLinhaEsperada = -1;

	int  NumLidos = -1;


	for (i = 0; i < 54; i++)
		config[i] = i;

	/* Testar CUB Criar cubo */

	if (strcmp(ComandoTeste, CRIAR_CUB_CMD) == 0)
	{
		
		NumLidos = LER_LerParametros("i",
			&CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CUB_CriarCUBO(&cubo, config);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar cubo.");

	} /* Fim testar CUB Criar cubo */
	/*Testar destruir cubo*/
	else if (strcmp(ComandoTeste, DESTROI_CUB_CMD) == 0) {

		NumLidos = LER_LerParametros("i", &CondRetEsperada);

		if (NumLidos != 1) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_DestruirCUBO(cubo);
		cubo = NULL;

		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado ao destruir cubo");

	}/*Fim testar destruir cubo*/
	/*Testar girar cubo*/
	else if (strcmp(ComandoTeste, GIRAR_CUB_CMD) == 0) {
		
		NumLidos = LER_LerParametros("iici", &NumFace, &NumGiro, &Sentido, &CondRetEsperada);

		if (NumLidos != 4) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_GirarFace(cubo, NumFace, NumGiro, Sentido);

		return TST_CompararInt(CondRetEsperada, CondRetObtido, "retorno errado ao girar o cubo");

	}/*Fim testar girar cubo*/

	/*Testar checar cubo*/
	else if (strcmp(ComandoTeste, CHECAR_CUB_CMD) == 0) {
		
		NumLidos = LER_LerParametros("iiiii", &NumLinha, &NumColuna, &NumFace, &CorEsperada, &CondRetEsperada);

		if (NumLidos != 5) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_ChecarCorDaFace(&CorObtida, cubo, NumLinha, NumColuna, NumFace);
		
		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido, "retorno errado ao checar cor do cubo");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		return TST_CompararInt(CorEsperada, CorObtida, "retorno errado ao checar cor do cubo");

	}/*Fim testar checar cubo*/

	/*Testar encontrar aresta*/
	else if (strcmp(ComandoTeste, ENCONTRAR_ARESTA_CUB_CMD) == 0) {

		NumLidos = LER_LerParametros("iiiiii", &CorObtida, &CorObtida2, &FaceEsperada, &NumLinhaEsperada, &NumColunaEsperada, &CondRetEsperada);

		if (NumLidos != 6) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_EncontrarPosicaoDePecaDeAresta(&FaceObtida, &NumLinha, &NumColuna, cubo, CorObtida, CorObtida2);
		
		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido, "retorno errado ao obter posicao da aresta");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		Ret = TST_CompararInt(FaceEsperada, FaceObtida, "retorno errado ao obter numero da face");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		Ret = TST_CompararInt(NumLinhaEsperada, NumLinha, "retorno errado ao obter numero da linha");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		return TST_CompararInt(NumColunaEsperada, NumColuna, "retorno errado ao obter numero da coluna");

	}/*Fim testar encontrar aresta*/
	
	/*Testar encontrar quina*/
	else if (strcmp(ComandoTeste, ENCONTRAR_QUINA_CUB_CMD) == 0) {

		NumLidos = LER_LerParametros("iiiiiii", &CorObtida, &CorObtida2, &CorObtida3, &FaceEsperada, &NumLinhaEsperada, &NumColunaEsperada, &CondRetEsperada);

		if (NumLidos != 7) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_EncontrarPosicaoDePecaDeQuina(&FaceObtida, &NumLinha, &NumColuna, cubo, CorObtida, CorObtida2, CorObtida3);
		

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido, "retorno errado ao obter posicao da quina");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		Ret = TST_CompararInt(FaceEsperada, FaceObtida, "retorno errado ao obter posicao da aresta");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		Ret = TST_CompararInt(NumLinhaEsperada, NumLinha, "retorno errado ao obter numero da linha");

		if (Ret != TST_CondRetOK) {
			return Ret;
		}

		return TST_CompararInt(NumColunaEsperada, NumColuna, "retorno errado ao obter numero da coluna");

	}/*Fim testar encontrar quina*/

	/*Testar exibir cubo*/
	else if (strcmp(ComandoTeste, EXIBIR_CUB_CMD) == 0) {

		NumLidos = LER_LerParametros("i", &CondRetEsperada);

		if (NumLidos != 1) {
			return TST_CondRetParm;
		}

		CondRetObtido = CUB_ExibirCUBO(cubo);

		return TST_CompararInt(CondRetEsperada, CondRetObtido, "retorno errado ao exibir");

	}/*Fim testar exibir cubo*/
	

	return TST_CondRetNaoConhec;

} /* Fim função: TCUB Efetuar operações de teste específicas para cubo */

  /********** Fim do módulo de implementação: Módulo de teste específico **********/

