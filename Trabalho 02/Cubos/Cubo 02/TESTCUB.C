/***************************************************************************
*  $MCI Módulo de implementação: TCUB Teste de Cubo
*
*  Arquivo gerado:              TESTCUB.c
*  Letras identificadoras:      TCUB
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\INF1301\TRAB1-1\FONTES
*
*  Projeto: INF 1301
*  Gestor:  Flávio B. Vilac
*  Autores: FM,MA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     3       FM,MA   17/abr/2018 término de desenvolvimento
*     2       FM,MA   10/abr/2018 ajustes teste/script
*     1       FM,MA   03/abr/2018 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_ESPC.h"

#include    "GENERICO.h"
#include    "LERPARM.h"

#include    "CUBO.h"

CUB_tpCubo *cubo;

static const char CRIAR_CUBO_CMD          [ ] = "=criarcubo"		;
static const char LIBERAR_CUBO_CMD        [ ] = "=liberarcubo"		;
static const char PREENCHE_CUBO_CMD	      [ ] = "=preenchecubo"		;
static const char GIR_FRE_ESQ_CMD         [ ] = "=girfrenteesq"		;
static const char GIR_FRE_DIR_CMD         [ ] = "=girfrentedir"		;
static const char GIR_DIR_TRA_CMD         [ ] = "=girdireitatra"	;
static const char GIR_DIR_FRE_CMD         [ ] = "=girdireitafre"	;
static const char GIR_ESQ_TRA_CMD         [ ] = "=giresquerdatra"   ;
static const char GIR_ESQ_FRE_CMD         [ ] = "=giresquerdafre"   ;
static const char GIR_BAI_ESQ_CMD         [ ] = "=girbaixoesq"		;
static const char GIR_BAI_DIR_CMD         [ ] = "=girbaixodir"		;
static const char GIR_TOP_ESQ_CMD         [ ] = "=girtopoesq"		;
static const char GIR_TOP_DIR_CMD         [ ] = "=girtopodir"		;
static const char GIR_TRA_ESQ_CMD         [ ] = "=girtrasesq"		;
static const char GIR_TRA_DIR_CMD         [ ] = "=girtrasdir"		;
static const char BUSCA_PECA_CMD          [ ] = "=buscapeca"		;
static const char PREENCHER_HLPR_CMD      [ ] = "=prhelper"         ;

/***********************************************************************
*
*  $FC Função: TCUB &Testar Cubo
*
*  $ED Descrição da função
*     Podem ser criadas apenas 1 cubo.
*
*     Comandos disponíveis:
*
*     =criarcubo									CondRetEsp
*	  =liberarcubo									CondRetEsp
*	  =preenchecubo			  x y z cor
*	  =girfrenteesq				 n 					CondRetEsp
*	  =girfrentedir				 n  				CondRetEsp
*	  =girdireitatra			 n  				CondRetEsp
*	  =girdireitafre			 n  				CondRetEsp
*	  =giresquerdatra			 n  				CondRetEsp
*	  =giresquerdafre			 n  				CondRetEsp
*	  =girbaixoesq				 n  				CondRetEsp
*	  =girbaixodir				 n  				CondRetEsp
*	  =girtopoesq				 n  				CondRetEsp
*	  =girtopodir				 n  				CondRetEsp
*	  =girtrasesq				 n  				CondRetEsp
*	  =girtrasdir				 n					CondRetEsp
*	  =buscapeca				 numCores			CondRetEsp
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{
	int faces , linhas , colunas ,cor;
	int numLidos;
	int cores[3];
    int numCores ;
	int n;
	CUB_tpCondRet CondRet1, CondRet2;
	cores[0]=1;
	cores[1]=2;
	cores[2]=3;
	/* Testar CriarCubo */

	if ( strcmp( ComandoTeste , CRIAR_CUBO_CMD ) == 0 )
	{
        CondRet1 = CUB_criaCubo(cubo);
  		numLidos = LER_LerParametros("i",&CondRet2);
		if (numLidos!= 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRet1 = CUB_criaCubo(cubo);

		return TST_CompararInt(CondRet2, CondRet1, "Retorno errado criando o cubo");

        } /* fim ativa: Testar CriarCubo */

        /* Testar LiberaCubo */

	else if ( strcmp( ComandoTeste , LIBERAR_CUBO_CMD ) == 0 )
	{
		numLidos = LER_LerParametros("i", &CondRet2);
		if (numLidos != 1) {
			return TST_CondRetParm;
		}
		CondRet1 = CUB_liberaCubo(cubo);
		return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao destruir cubo");
	} /* fim ativa: Testar LiberaCubo */

        /* TestarPreencherCubo */

	else if ( strcmp( ComandoTeste , PREENCHE_CUBO_CMD ) == 0 )
	{
            numLidos = LER_LerParametros("iiiii", &faces , &linhas , &colunas , &cor , &CondRet2);
            CondRet1 = CUB_preencheCubo(&cubo, faces , linhas,  colunas , cor);
            if(numLidos!=5)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar PreencheCubo */

	/* Testar Gira Frente Esquerda */

	else if ( strcmp( ComandoTeste , GIR_FRE_ESQ_CMD ) == 0 )
	{
			numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraFrenteEsquerda(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Frente Esquerda */

	/* Testar Gira Frente Direita */

	else if ( strcmp( ComandoTeste , GIR_FRE_DIR_CMD ) == 0 )
	{
			numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraFrenteDireita(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");

	} /* fim ativa: Testar Gira Frente Direita */

	/* Testar Gira Direita Tras */

	else if ( strcmp( ComandoTeste , GIR_DIR_TRA_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraDireitaTras(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");

	} /* fim ativa: Testar Gira DIreita Tras */

	/* Testar Gira Direita Frente */

	else if ( strcmp( ComandoTeste , GIR_DIR_FRE_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraDireitaFrente(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Direita Frente */

	/* Testar Gira Esquerda Tras */

	else if ( strcmp( ComandoTeste , GIR_ESQ_TRA_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraEsquerdaTras(&cubo,n);
            if(numLidos!=2 )
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Esquerda Tras */

	/* Testar Gira Esquerda Frente */

	else if ( strcmp( ComandoTeste , GIR_ESQ_FRE_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraEsquerdaFrente(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Esquerda Frente */

	/* Testar Gira Baixo Esquerda */

	else if ( strcmp( ComandoTeste , GIR_BAI_ESQ_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraBaixoEsquerda(&cubo,n);
            if(numLidos!=2 )
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Baixo Esquerda */

	/* Testar Gira Baixo Direita */

	else if ( strcmp( ComandoTeste , GIR_BAI_DIR_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraBaixoDireita(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Gira Baixo Direita */

	/* Testar Gira Topo Esquerda */

	else if ( strcmp( ComandoTeste , GIR_TOP_ESQ_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraTopoEsquerda(&cubo,n);
            if(numLidos!=2 )
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Topo Esquerda */

	/* Testar Gira Topo Direita */

	else if ( strcmp( ComandoTeste , GIR_TOP_DIR_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraTopoDireita(&cubo,n);
            if(numLidos!=2 )
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Topo Direita */

	/* Testar Gira Tras Esquerda */

	else if ( strcmp( ComandoTeste , GIR_TRA_ESQ_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n, &CondRet2);
			CondRet1 = CUB_giraTrasEsquerda(&cubo,n);
            if(numLidos!=2 )
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa: Testar Gira Tras Esquerda */

	/* Testar Gira Tras Direita */

	else if ( strcmp( ComandoTeste , GIR_TRA_DIR_CMD ) == 0 )
	{
            numLidos =  LER_LerParametros("ii", &n , &CondRet2);
			CondRet1 = CUB_giraTrasDireita(&cubo,n);
            if(numLidos!=2)
            {
                return TST_CondRetParm ;
            }
            return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao girar o cubo");
	} /* fim ativa:  Gira Tras Direita */

	/* Testar Busca Peca */

	else if ( strcmp( ComandoTeste , BUSCA_PECA_CMD ) == 0 )
	{
			numLidos = LER_LerParametros("ii", &numCores, &CondRet2);
			if(numCores == 2)
			{
				cores[0] = 1;
				cores[1] = 2;
			}
			else if(numCores == 3)
			{
				cores[0] = 1;
				cores[1] = 2;
				cores[2] = 3;
			}
			else
				return TST_CondRetParm;
			
			CondRet1 = CUB_buscaPeca(&cubo,cores,numCores);
            if(numLidos!=2)
            {
                return TST_CondRetParm;
            }
            else if(CondRet1 == CUB_CondRetPecaErrada)
            {
                return TST_CondRetErro;
            }
            else if(CondRet1 == CUB_CondRetOK)
            {
				return TST_CondRetOK;
            }
            else
                return TST_CompararInt(CondRet2, CondRet1, "Retorno errado ao buscar peca");;
	} /* fim ativa: Testar Busca Peca */

	return TST_CondRetNaoConhec ;

} /* Fim função: TCUB &Testar Cubo */

/****FUNCOES ENCAPSULADAS*******/

