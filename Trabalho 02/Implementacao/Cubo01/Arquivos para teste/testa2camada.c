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

#define     RESOLVE_ARESTA_CMD  "=resolveAresta"


#define MAX_CUBOS 5


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
        int numLidos, endCubo, face, resolvidoCima;
        
	    C2C_tpCondRet CondRetEsperada , CondRetObtido;

        /* Testar resolve aresta face*/

         if ( strcmp( ComandoTeste , RESOLVE_ARESTA_CMD  ) == 0 )
         {

            numLidos = LER_LerParametros( "iiii" ,
                               &endCubo,&face, &resolvidoCima,&CondRetEsperada ) ;
            if ( numLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  resolveArestaDeFace(cubo, face,resolvidoCima);  //como passar o cubo?

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao resolver aresta na face.");

         } /* fim ativa: Testar resolve aresta face */

      

      return TST_CondRetNaoConhec ;

   } /* Fim função: Efetuar operações de teste específicas para 2 camada */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

