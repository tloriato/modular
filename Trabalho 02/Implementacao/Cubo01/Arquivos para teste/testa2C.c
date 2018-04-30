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
*  Autores:
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     
*
*  $ED Descrição do módulo
*    
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
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

/* Tabela dos nomes dos comandos de teste específicos */

#define     GIRA_FRENTE_CMD     "=giraFrente"
#define     GIRA_CIMA_CMD       "=giraCima"
#define     GIRA_DIREITA_CMD    "=giraDireita"
#define     GIRA_ESQUERDA_CMD   "=giraEsquerda"
#define     GIRA_TRASEIRA__CMD  "=giraTraseira"
#define     GIRA_BAIXO_CMD      "=giraBaixo"


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
        int numLidos;
        
	    C2C_tpCondRet CondRetEsperada , CondRetObtido;

        /* Testar 2C Girar Frente*/

         if ( strcmp( ComandoTeste , GIRA_FRENTE_CMD  ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndCubo, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveFrente(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar frente." );

         } /* fim ativa: Testar Gira Frente */

      /* Testar 2C Girar Cima */

         else if ( strcmp( ComandoTeste , GIRA_CIMA_CMD  ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndCubo, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveCima(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar cima." );

         } /* fim ativa: Testar Gira Cima */

         /* Testar 2C Girar Direita*/

        else if ( strcmp( ComandoTeste , GIRA_DIREITA_CMD  ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndCubo, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveDireita(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar direita" );

         } /* fim ativa: Testar Gira Direita*/

        /* Testar 2C Girar Esquerda*/

         else if ( strcmp( ComandoTeste , GIRA_ESQUERDA_CMD) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndPonteiro, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveEsquerda(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar esquerda" );

         } /* fim ativa: Testar Gira Esquerda*/

      /* Testar ARV Ir para nó à esquerda */

         /* Testar 2C Girar Traseira*/

         else if ( strcmp( ComandoTeste , GIRA_TRASEIRA_CMD) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndPonteiro, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveTraseira(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar traseira" );

         } /* fim ativa: Testar Gira Traseira/

      /* Testar 2C Girar Baixo*/

         else if ( strcmp( ComandoTeste , GIRA_BAIXO_CMD) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IndPonteiro, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = resolveBaixo(cubo);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao girar baixo" );

         } /* fim ativa: Testar Gira Baixo*/

      return TST_CondRetNaoConhec ;

   } /* Fim função: Efetuar operações de teste específicas para 2 camada */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

