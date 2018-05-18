/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico CUBO02
*
*  Arquivo gerado:              
*  Letras identificadoras:      
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:  CJ - Ana Carolina Junger
*			 TS - Tiago Simões	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*  $HA Histórico de evolução:
*     Versão  Autor      Data     Observações
*     1.0     MMA,BHL    3/05     atualização e casos de teste
*
*  $ED Descrição do módulo
*		Este módulo contém as funções específicas para o teste do
*     módulo 2 camada.
*    
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo:
*
*		"=resolveCuboNull"				 -Chama a funcao resolve 2 camada passando como
*										parametro um cubo nulo.
*
*		"=resolve2esquerdaInverso"		-Analoga a resolve2casoEsquerda mas com cubo para cima
*
*		"=resolve2direitaInverso"		-Analoga a resolve2casoDireita mas com cubo para cima
*
*		"=resolve2resolvidaInverso"		-Analoga a resolve2resolvida mas com cubo para cima
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
#define MAX 600

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

#define BRANCO 0
#define VERDE 1
#define VERMELHO 2
#define AZUL 3
#define LARANJA 4
#define AMARELO 5


/* Tabela dos nomes dos comandos de teste especÍficos */

#define     RESOLVE_CUBO_NULL_CMD			 "=resolveCuboNull" 
#define		RESOLVE_2_ESQUERDA_INVERSO_CMD	 "=resolve2esquerdaInverso" //cubo 0
#define		RESOLVE_2_DIREITA_INVERSO_CMD	 "=resolve2direitaInverso" // cubo 1
#define     RESOLVE_2_RESOLVIDA_INVERSO_CMD	 "=resolve2resolvidaInverso" //cubo 2


int populaCubo(int numCubo, CUB_tpCubo *cubo) {

	 if (numCubo == 0){   //  Cubo inverso corrige pra esquerda
	
		// Up Face 0
		CUB_preencheCubo(cubo, 0, 0, 0, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 1, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 1, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 2, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 2, BRANCO); 
		
		// Left Face 4

		CUB_preencheCubo(cubo, 4, 0, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 2, LARANJA);

		CUB_preencheCubo(cubo, 4, 1, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 2, LARANJA); 

		CUB_preencheCubo(cubo, 4, 2, 0, AMARELO);
		CUB_preencheCubo(cubo, 4, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 4, 2, 2, AMARELO); 

		// Front Face 1

		CUB_preencheCubo(cubo, 1, 0, 0, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 2, VERDE);

		CUB_preencheCubo(cubo, 1, 1, 0, VERDE); 
		CUB_preencheCubo(cubo, 1, 1, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 1, 2, AMARELO); 

		CUB_preencheCubo(cubo, 1, 2, 0, VERDE);
		CUB_preencheCubo(cubo, 1, 2, 1, VERMELHO);
		CUB_preencheCubo(cubo, 1, 2, 2, AZUL); 

		// Right Face 2

		CUB_preencheCubo(cubo, 2, 0, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 2, VERMELHO);

		CUB_preencheCubo(cubo, 2, 1, 0, LARANJA); 
		CUB_preencheCubo(cubo, 2, 1, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 1, 2, VERMELHO); 

		CUB_preencheCubo(cubo, 2, 2, 0, AMARELO);
		CUB_preencheCubo(cubo, 2, 2, 1, VERDE);
		CUB_preencheCubo(cubo, 2, 2, 2, AMARELO); 

		// Back Face 3

		CUB_preencheCubo(cubo, 3, 0, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 2, AZUL);

		CUB_preencheCubo(cubo, 3, 1, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 2, AZUL); 

		CUB_preencheCubo(cubo, 3, 2, 0, LARANJA);
		CUB_preencheCubo(cubo, 3, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 3, 2, 2, LARANJA); 

		// Down Face 5

		CUB_preencheCubo(cubo, 5, 0, 0, VERDE); 
		CUB_preencheCubo(cubo, 5, 0, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 5, 0, 2, AZUL);

		CUB_preencheCubo(cubo, 5, 1, 0, AMARELO); 
		CUB_preencheCubo(cubo, 5, 1, 1, AMARELO); 
		CUB_preencheCubo(cubo, 5, 1, 2, AZUL); 

		CUB_preencheCubo(cubo, 5, 2, 0, VERMELHO);
		CUB_preencheCubo(cubo, 5, 2, 1, VERDE);
		CUB_preencheCubo(cubo, 5, 2, 2, VERMELHO); 
	}
	
	
	else if (numCubo == 1){   //  Cubo inverso corrige pra direita
		
		// Up Face 0
		CUB_preencheCubo(cubo, 0, 0, 0, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 1, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 1, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 2, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 2, BRANCO); 

		// Left Face 4

		CUB_preencheCubo(cubo, 4, 0, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 2, LARANJA);

		CUB_preencheCubo(cubo, 4, 1, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 2, LARANJA); 

		CUB_preencheCubo(cubo, 4, 2, 0, AZUL);
		CUB_preencheCubo(cubo, 4, 2, 1, AZUL);
		CUB_preencheCubo(cubo, 4, 2, 2, AMARELO); 

		// Front Face 1

		CUB_preencheCubo(cubo, 1, 0, 0, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 2, VERDE);

		CUB_preencheCubo(cubo, 1, 1, 0, AMARELO); 
		CUB_preencheCubo(cubo, 1, 1, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 1, 2, VERDE); 

		CUB_preencheCubo(cubo, 1, 2, 0, VERDE);
		CUB_preencheCubo(cubo, 1, 2, 1, VERDE);
		CUB_preencheCubo(cubo, 1, 2, 2, AMARELO); 

		// Right Face 2

		CUB_preencheCubo(cubo, 2, 0, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 2, VERMELHO);

		CUB_preencheCubo(cubo, 2, 1, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 1, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 1, 2, VERMELHO); 

		CUB_preencheCubo(cubo, 2, 2, 0, VERMELHO);
		CUB_preencheCubo(cubo, 2, 2, 1, VERDE);
		CUB_preencheCubo(cubo, 2, 2, 2, LARANJA); 


		// Back Face 3

		CUB_preencheCubo(cubo, 3, 0, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 2, AZUL);

		CUB_preencheCubo(cubo, 3, 1, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 2, AZUL); 

		CUB_preencheCubo(cubo, 3, 2, 0, VERDE);
		CUB_preencheCubo(cubo, 3, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 3, 2, 2, AMARELO); 

		// Down Face 5

		CUB_preencheCubo(cubo, 5, 0, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 5, 0, 1, LARANJA); 
		CUB_preencheCubo(cubo, 5, 0, 2, AZUL);

		CUB_preencheCubo(cubo, 5, 1, 0, AMARELO); 
		CUB_preencheCubo(cubo, 5, 1, 1, AMARELO); 
		CUB_preencheCubo(cubo, 5, 1, 2, AMARELO); 

		CUB_preencheCubo(cubo, 5, 2, 0, LARANJA);
		CUB_preencheCubo(cubo, 5, 2, 1, VERMELHO);
		CUB_preencheCubo(cubo, 5, 2, 2, AMARELO); 

	}
	else if (numCubo == 2){          //  Cubo inverso 2 camada feita

		// Up Face 0

		CUB_preencheCubo(cubo, 0, 0, 0, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 1, BRANCO);
		CUB_preencheCubo(cubo, 0, 0, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 1, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 1, 2, BRANCO);

		CUB_preencheCubo(cubo, 0, 2, 0, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 1, BRANCO); 
		CUB_preencheCubo(cubo, 0, 2, 2, BRANCO); 

		// Left Face 4

		CUB_preencheCubo(cubo, 4, 0, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 0, 2, LARANJA);

		CUB_preencheCubo(cubo, 4, 1, 0, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 1, LARANJA); 
		CUB_preencheCubo(cubo, 4, 1, 2, LARANJA); 

		CUB_preencheCubo(cubo, 4, 2, 0, LARANJA);
		CUB_preencheCubo(cubo, 4, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 4, 2, 2, AMARELO); 

		// Front Face 1

		CUB_preencheCubo(cubo, 1, 0, 0, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 0, 2, VERDE);

		CUB_preencheCubo(cubo, 1, 1, 0, VERDE); 
		CUB_preencheCubo(cubo, 1, 1, 1, VERDE); 
		CUB_preencheCubo(cubo, 1, 1, 2, VERDE); 

		CUB_preencheCubo(cubo, 1, 2, 0, VERMELHO);
		CUB_preencheCubo(cubo, 1, 2, 1, VERMELHO);
		CUB_preencheCubo(cubo, 1, 2, 2, VERMELHO); 

		// Right Face 2

		CUB_preencheCubo(cubo, 2, 0, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 0, 2, VERMELHO);

		CUB_preencheCubo(cubo, 2, 1, 0, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 1, 1, VERMELHO); 
		CUB_preencheCubo(cubo, 2, 1, 2, VERMELHO); 

		CUB_preencheCubo(cubo, 2, 2, 0, AMARELO);
		CUB_preencheCubo(cubo, 2, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 2, 2, 2, LARANJA); 


		// Back Face 3

		CUB_preencheCubo(cubo, 3, 0, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 0, 2, AZUL);

		CUB_preencheCubo(cubo, 3, 1, 0, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 1, AZUL); 
		CUB_preencheCubo(cubo, 3, 1, 2, AZUL); 

		CUB_preencheCubo(cubo, 3, 2, 0, AMARELO);
		CUB_preencheCubo(cubo, 3, 2, 1, LARANJA);
		CUB_preencheCubo(cubo, 3, 2, 2, AMARELO); 

		// Down Face 5

		CUB_preencheCubo(cubo, 5, 0, 0, VERDE); 
		CUB_preencheCubo(cubo, 5, 0, 1, AMARELO); 
		CUB_preencheCubo(cubo, 5, 0, 2, VERDE);

		CUB_preencheCubo(cubo, 5, 1, 0, AZUL); 
		CUB_preencheCubo(cubo, 5, 1, 1, AMARELO); 
		CUB_preencheCubo(cubo, 5, 1, 2, VERDE); 

		CUB_preencheCubo(cubo, 5, 2, 0, VERDE);
		CUB_preencheCubo(cubo, 5, 2, 1, AMARELO);
		CUB_preencheCubo(cubo, 5, 2, 2, AZUL); 

	}


	return 0;

}

/***********************************************************************
*
*  $FC Função: TCUB Efetuar operações de teste específicas para 2 camada
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     2 camada sendo testado.
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
		CUB_tpCubo * cubo;
		C2C_tpCondRet CondRetEsperada , CondRetObtido;
        int numLidos;
		int numCubo;
		
		 /* Testar resolver 2 camada com cubo NULL*/

         if ( strcmp( ComandoTeste ,RESOLVE_CUBO_NULL_CMD) == 0 )
         {
			cubo = NULL; 	
            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(&cubo);  
			CUB_liberaCubo(&cubo);
			

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver Caso Cubo NULL.");

         } /* fim ativa: Testar resolver 2 camada com cubo NULL */


		/* Testar resolver 2 camada caso esquerda*/

         if ( strcmp( ComandoTeste , RESOLVE_2_ESQUERDA_INVERSO_CMD) == 0 )
         {
			CUB_criaCubo(&cubo); 	
			populaCubo(0,cubo);

            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;

            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(cubo);  
			CUB_liberaCubo(cubo);
			
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada caso esquerda*/

		 if ( strcmp( ComandoTeste , RESOLVE_2_DIREITA_INVERSO_CMD) == 0 )
         {
			
			CUB_CriarCUBO(&cubo);
			populaCubo(1, cubo);
			 	
            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(&cubo);  
			CUB_liberaCubo(&cubo);
		
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada caso direita*/

		 	/* Testar resolver 2 camada caso resolvida*/
		
			if ( strcmp( ComandoTeste , RESOLVE_2_RESOLVIDA_INVERSO_CMD	) == 0 )
         {
			
			CUB_CriarCUBO(&cubo);
			populaCubo(2, cubo);
			 	
            numLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( numLidos != 1 )
            { 
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolve2camada(&cubo);  
			CUB_liberaCubo(&cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver 2 Camada.");

         } /* fim ativa: Testar resolver 2 camada caso resolvida*/




   }