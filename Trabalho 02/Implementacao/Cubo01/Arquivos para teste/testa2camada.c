/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              
*  Letras identificadoras:      
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:  MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Hörner Lopes  
*
*  $HA Histórico de evolução:
*     Versão  Autor      Data     Observações
*	  2.0     MMA,BHL    1/05     atualização e mais casos de teste
*     1.0     MMA        30/04    protótipo das funções de teste
*
*  $ED Descrição do módulo
*		Este módulo contém as funções específicas para o teste do
*     módulo 2 camada.
*    
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo:
*
*		"=resolve2"                - Chama a funcao resolve 2 camada passando como
*									parametro um cubo com a 1 camada resolvida e para baixo.
*
*		"=resolve2resolvida"       - Chama a funcao resolve 2 camada passando como
*									parametro um cubo com a 1 e 2 camada resolvida e para baixo.
*
*		"=resolveCuboNull"         - Chama a funcao resolve 2 camada passando como
*									parametro um cubo nulo.
*
*		"=resolveCasoPreso"        - Chama a funcao resolve 2 camada passando como
*									parametro um cubo com caso de peca presa com a 1 camada 
*									resolvida e para baixo.
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "tst_espc.h"

#include    "generico.h"
#include    "lerparam.h"

#include    "2camada.h"
#include    "CUBO.h"

#define ALG 55

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

#define VERDE 1
#define VERMELHO 2
#define AMARELO 3
#define AZUL 4
#define BRANCO 5
#define LARANJA 6


/* Tabela dos nomes dos comandos de teste específicos */

#define     RESOLVE_2_CASO_ESQ_CMD			 "=resolve2casoEsquerda"
#define     RESOLVE_2_CASO_DIR_CMD			 "=resolve2casoDireita"
#define     RESOLVE_2_RESOLVIDA_CMD			 "=resolve2resolvida"
#define		RESOLVE_2_PECA_PRESA_CMD		 "=resolve2pecaPresa"
#define     RESOLVE_CUBO_NULL_CMD			 "=resolveCuboNull"
#define     RESOLVE_CASO_PRESO_CMD			 "=resolveCasoPreso"

// (config) ~> inteiro
//	config = vetor de 54 inteiros
//	inteiro =
//		0 -> sucesso


int populaCubo(int *config, int numCubo) {

	// 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

	// Cubos: 0) Normal corrige esquerda | 1) Normal corrige direita | 2) Já resolvido | 3) Peça presa | 4) Cubo inverso
	if (numCubo == 0)	// Cubo normal -> só corrige pra esquerda
	{              
		// Up Face 0
		config[0] = AMARELO;
		config[1] = LARANJA;
		config[2] = AZUL;

		config[3] = VERMELHO;
		config[4] = AMARELO; 
		config[5] = VERMELHO;

		config[6] = VERDE;
		config[7] = AZUL;
		config[8] = AMARELO; 

		// Left Face 4
		config[9] = VERDE;
		config[10] = AMARELO;
		config[11] = LARANJA;

		config[21] = LARANJA;
		config[22] = VERMELHO;	
		config[23] = AZUL;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = AMARELO;
		config[13] = VERMELHO;
		config[14] = AZUL;

		config[24] = AMARELO;
		config[25] = VERDE;  
		config[26] = AMARELO;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERDE;
		config[17] = AMARELO;

		config[27] = LARANJA;
		config[28] = LARANJA; 
		config[29] = AMARELO;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = LARANJA;
		config[19] = AZUL;
		config[20] = VERMELHO;

		config[30] = VERDE;
		config[31] = AZUL;  
		config[32] = VERDE;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;
	}
	//-----------------------------------------------------------
	else if (numCubo == 1)	// Cubo normal -> Só corrige pra direita
	{		

			// Up Face 0
		config[0] = VERMELHO;
		config[1] = AMARELO;
		config[2] = AMARELO;

		config[3] = AMARELO;
		config[4] = AMARELO;
		config[5] = LARANJA;

		config[6] = AMARELO;
		config[7] = VERDE;
		config[8] = LARANJA;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = AMARELO;

		config[21] = AMARELO;
		config[22] = VERDE;
		config[23] = AZUL;

		config[33] = VERDE;
		config[34] = VERDE;
		config[35] = VERDE;

		// Front Face 1
		config[12] = AZUL;
		config[13] = LARANJA;
		config[14] = VERDE;

		config[24] = VERMELHO;
		config[25] = VERMELHO;
		config[26] = VERDE;

		config[36] = VERMELHO;
		config[37] = VERMELHO;
		config[38] = VERMELHO;

		// Right Face 2
		config[15] = AMARELO;
		config[16] = AZUL;
		config[17] = AZUL;

		config[27] = AMARELO;
		config[28] = AZUL;
		config[29] = VERMELHO;

		config[39] = AZUL;
		config[40] = AZUL;
		config[41] = AZUL;

		// Back Face 3
		config[18] = VERDE;
		config[19] = VERMELHO;
		config[20] = VERMELHO;

		config[30] = AMARELO;
		config[31] = VERDE;
		config[32] = AZUL;

		config[42] = VERDE;
		config[43] = VERDE;
		config[44] = VERDE;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;

	
	}
	//-----------------------------------------------------------
	else if (numCubo == 2)	// Cubo ja resolvido
	{                 

		// Up Face 0
		config[0] = AZUL;
		config[1] = AMARELO;
		config[2] = VERDE;

		config[3] = VERDE;
		config[4] = AMARELO; 
		config[5] = AZUL;

		config[6] = VERDE;
		config[7] = AMARELO;
		config[8] = AMARELO; 

		// Left Face 4
		config[9] = LARANJA;
		config[10] = AMARELO;
		config[11] = AMARELO;

		config[21] = VERMELHO;
		config[22] = VERMELHO;	
		config[23] = VERMELHO;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = VERMELHO;
		config[13] = VERMELHO;
		config[14] = VERMELHO;

		config[24] = VERDE;
		config[25] = VERDE;  
		config[26] = VERDE;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = AMARELO;
		config[16] = AMARELO;
		config[17] = LARANJA;

		config[27] = LARANJA;
		config[28] = LARANJA; 
		config[29] = LARANJA;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = AMARELO;
		config[19] = LARANJA;
		config[20] = AMARELO;

		config[30] = AZUL;
		config[31] = AZUL;  
		config[32] = AZUL;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;


	}
	//-----------------------------------------------------------
	else if (numCubo == 3)	//Peça presa
	{		

		// Up Face 0
		config[0] = VERDE;
		config[1] = AMARELO;
		config[2] = LARANJA;

		config[3] = LARANJA;
		config[4] = AMARELO;
		config[5] = VERDE;

		config[6] = LARANJA;
		config[7] = AZUL;
		config[8] = AZUL;

		// Left Face 4
		config[9] = VERMELHO;
		config[10] = VERDE;
		config[11] = AMARELO;

		config[21] = LARANJA;
		config[22] = VERMELHO;
		config[23] = AMARELO;

		config[33] = VERMELHO;
		config[34] = VERMELHO;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = VERDE;
		config[13] = LARANJA;
		config[14] = VERMELHO;

		config[24] = AZUL;
		config[25] = VERDE;
		config[26] = AZUL;

		config[36] = VERDE;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = AMARELO;
		config[16] = VERMELHO;
		config[17] = AZUL;

		config[27] = VERMELHO;
		config[28] = LARANJA;
		config[29] = VERDE;

		config[39] = LARANJA;
		config[40] = LARANJA;
		config[41] = LARANJA;

		// Back Face 3
		config[18] = AMARELO;
		config[19] = VERMELHO;
		config[20] = AMARELO;

		config[30] = AMARELO;
		config[31] = AZUL;
		config[32] = AMARELO;

		config[42] = AZUL;
		config[43] = AZUL;
		config[44] = AZUL;

		// Down Face 5
		config[45] = BRANCO;
		config[46] = BRANCO;
		config[47] = BRANCO;

		config[48] = BRANCO;
		config[49] = BRANCO;
		config[50] = BRANCO;

		config[51] = BRANCO;
		config[52] = BRANCO;
		config[53] = BRANCO;

	
	}
	//-----------------------------------------------------------
	else if (numCubo == 4)	//Cubo inverso
	{		

		// Up Face 0
		config[0] = BRANCO;
		config[1] = BRANCO;
		config[2] = BRANCO;

		config[3] = BRANCO;
		config[4] = BRANCO;
		config[5] = BRANCO;

		config[6] = BRANCO;
		config[7] = BRANCO;
		config[8] = BRANCO;

		// Left Face 4
		config[9] = LARANJA;
		config[10] = LARANJA;
		config[11] = LARANJA;

		config[21] = AZUL;
		config[22] = LARANJA;
		config[23] = VERMELHO;

		config[33] = AMARELO;
		config[34] = AZUL;
		config[35] = VERMELHO;

		// Front Face 1
		config[12] = VERDE;
		config[13] = VERDE;
		config[14] = VERDE;

		config[24] = AZUL;
		config[25] = VERDE;
		config[26] = VERDE;

		config[36] = AZUL;
		config[37] = VERDE;
		config[38] = VERDE;

		// Right Face 2
		config[15] = VERMELHO;
		config[16] = VERMELHO;
		config[17] = VERMELHO;

		config[27] = VERMELHO;
		config[28] = VERMELHO;
		config[29] = VERMELHO;

		config[39] = VERMELHO;
		config[40] = LARANJA;
		config[41] = AMARELO;

		// Back Face 3
		config[18] = AZUL;
		config[19] = AZUL;
		config[20] = AZUL;

		config[30] = AMARELO;
		config[31] = AZUL;
		config[32] = AMARELO;

		config[42] = AZUL;
		config[43] = VERDE;
		config[44] = VERDE;

		// Down Face 5
		config[45] = AMARELO;
		config[46] = LARANJA;
		config[47] = AMARELO;

		config[48] = LARANJA;
		config[49] = AMARELO;
		config[50] = AMARELO;

		config[51] = LARANJA;
		config[52] = AMARELO;
		config[53] = LARANJA;
	}

	return 0;


}


/***********************************************************************
*
*  $FC Função: TCUB Efetuar operações de teste específicas para 2 camada
*
*  $ED Descrição da função
*		Efetua os diversos comandos de teste específicos para o módulo
*		2 camada sendo testado, cada um representando uma configuração 
*		inicial relevante do cubo.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
		/*variaveis usadas para o teste*/
		CUB_tppCUBO cubo = NULL;	
		C2C_tpCondRet CondRetEsperada , CondRetObtido;
        int numLidos;
		int config[54],numCubo;
		
		/* Testar resolver 2 camada com camada resolvida para baixo, tendo vários casos que usam o algoritmo de "jogar pra esquerda"*/

		if ( strcmp( ComandoTeste , RESOLVE_2_CASO_ESQ_CMD) == 0 )
        {
			populaCubo(config, 0);
			CUB_CriarCUBO(&cubo, config);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_DestruirCUBO(cubo);
			

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada com 1 camada para baixo */

		/* Testar resolver 2 camada com camada resolvida para baixo, tendo vários casos que usam o algoritmo de "jogar pra direita" */

		if ( strcmp( ComandoTeste , RESOLVE_2_CASO_ESQ_CMD) == 0 )
        {
			populaCubo(config, 1);
			CUB_CriarCUBO(&cubo, config);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_DestruirCUBO(cubo);
			

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada com 1 camada para baixo */

		  /* Testar resolver 2 camada de um cubo ja resolvido*/

		 if ( strcmp( ComandoTeste , RESOLVE_2_RESOLVIDA_CMD) == 0 )
         {
			populaCubo(config, 2);
			CUB_CriarCUBO(&cubo, config);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_DestruirCUBO(cubo);
			

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         }  /* fim ativa: Testar resolver 2 camada de um cubo ja resolvido*/

		  /* Testar resolver 2 camada cubo com peca presa*/

		 if ( strcmp( ComandoTeste , RESOLVE_CASO_PRESO_CMD) == 0 )
         {
			populaCubo(config, 3);
			CUB_CriarCUBO(&cubo, config);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_DestruirCUBO(cubo);
			

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         }  /* fim ativa: Testar resolver 2 camada cubo com peca presa*/

		/* Testar resolver 2 camada com camada resolvida para cima */
		if ( strcmp( ComandoTeste , RESOLVE_2_CASO_ESQ_CMD) == 0 )
        {
			populaCubo(config, 4);
			CUB_CriarCUBO(&cubo, config);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_DestruirCUBO(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada com camada resolvida para cima */

		 /* Testar resolver 2 camada com cubo NULL*/

         if ( strcmp( ComandoTeste, RESOLVE_CUBO_NULL_CMD) == 0 )
         {
			cubo = NULL;
			 	
            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver Caso Cubo NULL.");

         } /* fim ativa: Testar resolver 2 camada com cubo NULL */      

      return TST_CondRetNaoConhec ;

   } /* Fim função: Efetuar operações de teste específicas para 2 camada */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

