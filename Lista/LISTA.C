/***************************************************************************
*  $MCI M�dulo de implementa��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	  6       bmt     24/08/18  Função de Deturpação
*     5       bmt   Junho, 2018 Transformação para uma lista verificável
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define LISTA_OWN
#include "LISTA.h"
#undef LISTA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: LIS Elemento da lista
*
*
***********************************************************************/

   typedef struct tagElemLista {

         void * pValor ;
               /* Ponteiro para o valor contido no elemento */

         struct tagElemLista * pAnt ;
               /* Ponteiro para o elemento predecessor */

         struct tagElemLista * pProx ;
               /* Ponteiro para o elemento sucessor */

	#ifdef _DEBUG

		/* Precisamos dessas duas informações para
		realizar testes de integridades completos
		com o propósito do módulo */

		LIS_tppLista ptCabeca;
		char tipo;

	#endif
   } tpElemLista ;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabe�a de lista
*
*
***********************************************************************/

   typedef struct LIS_tagLista {

         tpElemLista * pOrigemLista ;
               /* Ponteiro para a origem da lista */

         tpElemLista * pFimLista ;
               /* Ponteiro para o final da lista */

         tpElemLista * pElemCorr ;
               /* Ponteiro para o elemento corrente da lista */

         int numElem ;
               /* N�mero de elementos da lista */

         void ( * ExcluirValor ) ( void * pValor ) ;
               /* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */
      
      #ifdef _DEBUG
            char tipo;
      #endif

   } LIS_tpLista ;


/*****  Dados encapsulados no módulo  *****/

#ifdef _DEBUG

  static char EspacoLixo[ 256 ] =
          "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" ;
  /* Espaço de dados lixo usado ao testar */
 #endif

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void LiberarElemento( LIS_tppLista   pLista ,
                                tpElemLista  * pElem   ) ;

   static tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                       void *       pValor  ) ;

   static void LimparCabeca( LIS_tppLista pLista ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: LIS  &Criar lista
*  ****/

   LIS_tppLista LIS_CriarLista(
             void   ( * ExcluirValor ) ( void * pDado ) )
   {

      LIS_tpLista * pLista = NULL ;

      pLista = ( LIS_tpLista * ) malloc( sizeof( LIS_tpLista )) ;
      if ( pLista == NULL )
      {
         return NULL ;
      } /* if */

      LimparCabeca( pLista ) ;

      #ifdef _DEBUG
            pLista->tipo = LIS_TipoEspacoCabeca;
            CED_DefinirTipoEspaco(pLista, LIS_TipoEspacoCabeca);
      #elif
            
      #endif

      pLista->ExcluirValor = ExcluirValor ;

      return pLista ;

   } /* Fim fun��o: LIS  &Criar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Destruir lista
*  ****/

   void LIS_DestruirLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      LIS_EsvaziarLista( pLista ) ;

      free( pLista ) ;

   } /* Fim fun��o: LIS  &Destruir lista */

/***************************************************************************
*
*  Fun��o: LIS  &Esvaziar lista
*  ****/

   void LIS_EsvaziarLista( LIS_tppLista pLista )
   {

      tpElemLista * pElem ;
      tpElemLista * pProx ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      pElem = pLista->pOrigemLista ;
      while ( pElem != NULL )
      {
         pProx = pElem->pProx ;
         LiberarElemento( pLista , pElem ) ;
         pElem = pProx ;
      } /* while */

      LimparCabeca( pLista ) ;

   } /* Fim fun��o: LIS  &Esvaziar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento antes
*  ****/

   LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                           void * pValor        )
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Criar elemento a inerir antes */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LIS_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento antes do elemento corrente */

         if ( pLista->pElemCorr == NULL )
         {
            pLista->pOrigemLista = pElem ;
            pLista->pFimLista = pElem ;
         } else
         {
            if ( pLista->pElemCorr->pAnt != NULL )
            {
               pElem->pAnt  = pLista->pElemCorr->pAnt ;
               pLista->pElemCorr->pAnt->pProx = pElem ;
            } else
            {
               pLista->pOrigemLista = pElem ;
            } /* if */

            pElem->pProx = pLista->pElemCorr ;
            pLista->pElemCorr->pAnt = pElem ;
         } /* if */

         pLista->pElemCorr = pElem ;

         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Inserir elemento antes */

/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento ap�s
*  ****/

   LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,void * pValor)
      
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Criar elemento a inerir ap�s */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LIS_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento ap�s o elemento */

         if ( pLista->pElemCorr == NULL )
         {
            pLista->pOrigemLista = pElem ;
            pLista->pFimLista = pElem ;
         } else
         {
            if ( pLista->pElemCorr->pProx != NULL )
            {
               pElem->pProx  = pLista->pElemCorr->pProx ;
               pLista->pElemCorr->pProx->pAnt = pElem ;
            } else
            {
               pLista->pFimLista = pElem ;
            } /* if */

            pElem->pAnt = pLista->pElemCorr ;
            pLista->pElemCorr->pProx = pElem ;

         } /* if */
                  
         pLista->pElemCorr = pElem ;
                  
         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Inserir elemento ap�s */

/***************************************************************************
*
*  Fun��o: LIS  &Excluir elemento
*  ****/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista )
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista  != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LIS_CondRetListaVazia ;
      } /* if */

      pElem = pLista->pElemCorr ;

      /* Desencadeia � esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } else {
            pLista->pElemCorr    = pElem->pProx ;
            pLista->pOrigemLista = pLista->pElemCorr ;
         } /* if */

      /* Desencadeia � direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
         } else
         {
            pLista->pFimLista = pElem->pAnt ;
         } /* if */

      LiberarElemento( pLista , pElem ) ;

      return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Excluir elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*  ****/

   void * LIS_ObterValor( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
        return NULL ;
      } /* if */

      return pLista->pElemCorr->pValor ;

   } /* Fim fun��o: LIS  &Obter refer�ncia para o valor contido no elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento inicial
*  ****/

   void IrInicioLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      pLista->pElemCorr = pLista->pOrigemLista ;

   } /* Fim fun��o: LIS  &Ir para o elemento inicial */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento final
*  ****/

   void IrFinalLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      pLista->pElemCorr = pLista->pFimLista ;

   } /* Fim fun��o: LIS  &Ir para o elemento final */

/***************************************************************************
*
*  Fun��o: LIS  &Avan�ar elemento
*  ****/

   LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                              int numElem )
   {

      int i ;

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Tratar lista vazia */

         if ( pLista->pElemCorr == NULL )
         {

            return LIS_CondRetListaVazia ;

         } /* fim ativa: Tratar lista vazia */

      /* Tratar avan�ar para frente */

         if ( numElem > 0 )
         {

            pElem = pLista->pElemCorr ;
            for( i = numElem ; i > 0 ; i-- )
            {
               if ( pElem == NULL )
               {
                  break ;
               } /* if */
               pElem    = pElem->pProx ;
            } /* for */

            if ( pElem != NULL )
            {
               pLista->pElemCorr = pElem ;
               return LIS_CondRetOK ;
            } /* if */

            pLista->pElemCorr = pLista->pFimLista ;
            return LIS_CondRetFimLista ;

         } /* fim ativa: Tratar avan�ar para frente */

      /* Tratar avan�ar para tr�s */

         else if ( numElem < 0 )
         {

            pElem = pLista->pElemCorr ;
            for( i = numElem ; i < 0 ; i++ )
            {
               if ( pElem == NULL )
               {
                  break ;
               } /* if */
               pElem    = pElem->pAnt ;
            } /* for */

            if ( pElem != NULL )
            {
               pLista->pElemCorr = pElem ;
               return LIS_CondRetOK ;
            } /* if */

            pLista->pElemCorr = pLista->pOrigemLista ;
            return LIS_CondRetFimLista ;

         } /* fim ativa: Tratar avan�ar para tr�s */

      /* Tratar n�o avan�ar */

         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Avan�ar elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Procurar elemento contendo valor
*  ****/

   LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                    void * pValor        )
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista  != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LIS_CondRetListaVazia ;
      } /* if */

      for ( pElem  = pLista->pElemCorr ;
            pElem != NULL ;
            pElem  = pElem->pProx )
      {
         if ( pElem->pValor == pValor )
         {
            pLista->pElemCorr = pElem ;
            return LIS_CondRetOK ;
         } /* if */
      } /* for */

      return LIS_CondRetNaoAchou ;

   } /* Fim fun��o: LIS  &Procurar elemento contendo valor */

/*****************************************************************
 * 
 * Função: LIS &Verificar Lista
 * 
 * ***************************************************************/

      LIS_verifCondRet LIS_VerificarLista(LIS_tppLista ptLista) {

            // Se o ponteiro passado for nulo, a lista, evidentemente, não existe
            if (ptLista == NULL) {
                  CNT_CONTAR("LIS_verifInexistente");
                  return LIS_verifInexistente;
            }


            // Se o ponteiro para a origem da lista é nulo,
            // todos os demais também devem ser, pois não deverá existir elementos
            // na lista.
            if (ptLista->pOrigemLista == NULL) {
                  if (ptLista->pElemCorr != NULL) 
                  {
                        CNT_CONTAR("LIS_verifSemOrigemComCorrente");
                        return LIS_verifSemOrigemComCorrente;
                  }

                  if (ptLista->pFimLista != NULL){
                        CNT_CONTAR("LIS_verifSemOrigemComFinal");
                        return LIS_verifSemOrigemComFinal;
                  } 
                  if (ptLista->numElem != 0){
                        CNT_CONTAR("LIS_verifSemOrigemComElemento");
                        return LIS_verifSemOrigemComElemento;
                  }
                        
            }

            // Equivalentemente, para ponteiro final da lista nulo
            if (ptLista->pFimLista == NULL) {
                  if (ptLista->pOrigemLista != NULL) {
                        CNT_CONTAR("LIS_verifSemFimComOrigem");
                        return LIS_verifSemFimComOrigem;
                  }
                        

                  if (ptLista->pElemCorr != NULL) {
                        CNT_CONTAR("LIS_verifSemFimComCorrente");
                        return LIS_verifSemFimComCorrente;
                  }
                        
                  
                  if (ptLista->numElem != 0) {
                        CNT_CONTAR("LIS_verifSemFimComElemento");
                        return LIS_verifSemFimComElemento;
                  }
                        
            }

            // numElem não pode ser menor que 0     ok-> tem deturpador
            if (ptLista->numElem < 0){
                  CNT_CONTAR("LIS_verifNumElementosNegativo");
                  return LIS_verifNumElementosNegativo;
            }
                  
            
            // Tomar cuidado para não acessar à dentro de 
            // ponteiros nulos!
            if (ptLista->pOrigemLista != NULL)
                  if (ptLista->pOrigemLista->pAnt != NULL){
                        CNT_CONTAR("LIS_verifOrigemIncorreta");
                        return LIS_verifOrigemIncorreta;
                  }
                        

            if (ptLista->pFimLista != NULL)
                  if (ptLista->pFimLista->pProx != NULL){
                        CNT_CONTAR("LIS_verifFinalIncorreto");
                        return LIS_verifFinalIncorreto;
                  }
                        

            // Verifica se conseguimos partir da origem e chegar 
            // no final, enquanto conta os passos e depois
            // checa com o número de elementos declarados
            // Verifica se o elemento anterior está sempre linkado corretamente 
            // e que nenhum elemento aponta para um valor nulo

            if (ptLista->pOrigemLista != NULL) {
                  int contador = 1;
                  int numElem = ptLista->numElem;

                  tpElemLista * temp = ptLista->pOrigemLista;
                  tpElemLista * ant = NULL;
                  tpElemLista * corr = ptLista->pElemCorr;

                  int corrente = 0;

                  while (temp->pProx != NULL || temp->pValor != ptLista->pFimLista->pValor) {
                        
                        if (temp->pAnt != ant) {
                              CNT_CONTAR("LIS_verifAntLinkErrado");
                              return LIS_verifAntLinkErrado;
                        }
                        
                        if (temp->pValor == NULL) {
                              CNT_CONTAR("LIS_verifElemNulo");
                              return LIS_verifElemNulo;
                        }

                        if (corr = temp) {
                              corrente = 1;
                        }
                        
                        contador++;
                        ant = temp;
                        temp = temp->pProx;
                  }

                  if (temp->pValor != ptLista->pFimLista->pValor){
                        CNT_CONTAR("LIS_verifOrigemNaoChegaAoFinal");
                        return LIS_verifOrigemNaoChegaAoFinal;
                  }
                        
                  
                  if (contador != numElem){
                        CNT_CONTAR("LIS_verifNumElemInconsisente");
                        return LIS_verifNumElemInconsisente;
                  }
                        
                  
                  if (corrente = 0 && ptLista->pElemCorr != NULL){
                        CNT_CONTAR("LIS_verifCorrenteNaoLigado");
                        return LIS_verifCorrenteNaoLigado;   
                  }
                        
            }

            void * ptVoid = (void *) ptLista;
            // Marcar os espaços dinâmicos inativos
            CED_MarcarTodosEspacosInativos();
            // Marca o tipo da lista e aponta o espaço como ativo
            int tipoCabeca = CED_ObterTipoEspaco(ptVoid);
            CED_MarcarEspacoAtivo(ptVoid);

            if (tipoCabeca != LIS_TipoEspacoCabeca) {
                  CNT_CONTAR("LIS_verifCabecaTipoInconsistente");
                  return LIS_verifCabecaTipoInconsistente;
            }

            tpElemLista * temp = ptLista->pOrigemLista;
            int tipoEsp;

            while (tpElemLista != NULL) {

                  if (CED_ObterTipoEspaco(temp) != temp->tipo) {
                        CNT_CONTAR("LIS_verifElemTpInconsistente");
                        return LIS_verifElemTpInconsistente;
                  }

                  if (CED_ObterTipoEspaco(temp->ptCabeca) != ptLista->tipo) {
                        CNT_CONTAR("LIS_verifCabecaTipoInconsistente");
                        return LIS_verifCabecaTipoInconsistente;
                  }
                  
                  // Checa o controle da memória dinâmica
                  // marca os visitados como ativo
                  ptVoid = (void *) temp;
                  CED_MarcarEspacoAtivo(ptVoid);

                  ptVoid = (void *) temp->pValor;
                  tipoEsp = CED_ObterTipoEspaco(ptVoid);
                  CED_MarcarEspacoAtivo(ptVoid);

                  temp = temp->pProx;
            }

            /* Controla Vazamento da Memória da Lista */
            int espacos = CED_ObterNumeroEspacosAlocados();

            CED_InicializarIteradorEspacos();

            for (int i = 0; i < espacos; i++) {
                  ptVoid = CED_ObterPonteiroEspacoCorrente();
                  int statusAtivo = CED_EhEspacoAtivo(ptVoid);
                  tipoEsp = CED_ObterTipoEspaco(ptVoid);

                  if (tipoEsp == tipoCabeca) {
                        if (statusAtivo == 0) {
                              CED_TerminarIteradorEspacos();
                              CNT_CONTAR("LIS_verifVazamentoMemoria");
                              return LIS_verifVazamentoMemoria;
                        }
                  }

                  CED_AvancarProximoEspaco();
            }

            CED_TerminarIteradorEspacos();

            NT_CONTAR("LIS_verifOK");
            return LIS_verifOK;
            
      }



/*****************************************************************
 * 
 * Função: LIS &Deturpar Lista
 * 
 * ***************************************************************/

#ifdef _DEBUG

 LIS_tpCondRet LIS_DeturpaLista(LIS_tppLista ptLista,  LIS_tpModosDeDeturpacao modoDeturpar) {

       if (ptLista == NULL)
            return LIS_verifInexistente;
      
      switch(modoDeturpar){
           
            case naoDeturpa:
                  break;

             //elimina o elemento corrente da lista
             case DeturpaEliminaCorrente :
                  free(pLista->pElemCorr) ;
                  pLista->pElemCorr = NULL ;
                  pLista->NumeroDeElementos-- ;
                  break ;

            //atribui null ao ponteiro para prox no
            case DeturpaProxNull:
                  ptLista->pElemCorr->pProx = NULL;
                  break;
            
            //atribui null ao ponteiro para no anterior
            case DeturpaAntNull:
                  ptLista->pElemCorr->pAnt = NULL;

            //atribui lixo ao ponteiro de prox no
            case DeturpaProxLixo:
                  ptLista->pElemCorr->pProx = (tpElemLista *)(EspacoLixo);
                  break;

            //atribui lixo ao ponteiro de no anterior
            case DeturpaAntLixo:
                  ptLista->pElemCorr->pAnt = (tpElemLista *)(EspacoLixo);
                  break;
            
            //atribui null ao conteudo do no  
            case DeturpaConteudoNull:
                  ptLista->pValor == NULL;
                  break;
   
            //altera tipo de estrutura apontada no no 
            case DeturpaAlteraTipoEstrutura :
                  pLista->tipo++;
                  break ;
            
            //desencadeia nó sem liberálo com free 
            case DeturpaDesencadeiaSemFree:
                  if (pLista->pElemCorr->pAnt != NULL)
                        pLista->pElemCorr->pAnt->pProx = pLista->pElemCorr->pProx ;
                  else
                        pLista->pOrigemLista = pLista->pElemCorr->pProx;

                  if (pLista->pElemCorr->pProx != NULL)
                        pLista->pElemCorr->pProx->pAnt = pLista->pElemCorr->pAnt ;
                  else
                        pLista->pFimLista = pLista->pElemCorr->pAnt;

                  pLista->numElem --;
                  pLista->pElemCorr = NULL;
                  break ;

            //atribui null ao ponteiro corrente
            case DeturpaCorrNULL: 
                  ptLista->pElemCorr == NULL;
                  break;

             //atribui null ao ponteiro de origem
            case DeturpaOrigem:
                  ptLista->pOrigemLista == NULL;
                  break;
            
            //// outros casos //

            case DeturpaFinal:
                  ptLista->pFimLista == NULL;
                  break;

            case DeturpaNumElementos:
                  ptLista->numElem = -1;
                  break;
            
            case DeturpaAnteriorOrigem: 
                  ptLista->pOrigemLista->pAnt == 10;
                  break;
            
            case DeturpaProxFimLista: 
                  ptLista->pFimLista->pProx == 10;
                  break;

            case DeturpaValorOrigemNULL:
                  ptLista->pOrigemLista->pValor== NULL;
                  break;

            case LIS_DeturpaNULLCabeca:
                  pLista->pElemCorr->pCabeca = NULL;
                  break;

            case DeturpaPtCabecaLixo:
                  pLista->pElemCorr->pCabeca = (tpElemLista *)(EspacoLixo);
                  break;

            case DeturpaFinalLixo:
                  ptLista->pFimLista = (tpElemLista *)(EspacoLixo);
                  break;

            case DeturpaCorrLixo:
                  ptLista->pElemCorr = (tpElemLista *)(EspacoLixo);
                  break;

            default :
         return LIS_CondRetDeturpacaoInexistente;
      } 
     return LIS_CondRetOK;
 }
#endif




















/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: LIS  -Liberar elemento da lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

   void LiberarElemento( LIS_tppLista   pLista ,
                         tpElemLista  * pElem   )
   {

      if ( ( pLista->ExcluirValor != NULL )
        && ( pElem->pValor != NULL        ))
      {
         pLista->ExcluirValor( pElem->pValor ) ;
      } /* if */

      free( pElem ) ;

      pLista->numElem-- ;

   } /* Fim fun��o: LIS  -Liberar elemento da lista */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Criar o elemento
*
***********************************************************************/

   tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                void *       pValor  )
   {

      tpElemLista * pElem ;

      pElem = ( tpElemLista * ) malloc( sizeof( tpElemLista )) ;
      if ( pElem == NULL )
      {
         return NULL ;
      } /* if */

      pElem->pValor = pValor ;
      pElem->pAnt   = NULL  ;
      pElem->pProx  = NULL  ;

      pLista->numElem ++ ;

      return pElem ;

   } /* Fim fun��o: LIS  -Criar o elemento */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Limpar a cabe�a da lista
*
***********************************************************************/

   void LimparCabeca( LIS_tppLista pLista )
   {

      pLista->pOrigemLista = NULL ;
      pLista->pFimLista = NULL ;
      pLista->pElemCorr = NULL ;
      pLista->numElem   = 0 ;

   } /* Fim fun��o: LIS  -Limpar a cabe�a da lista */

/********** Fim do m�dulo de implementa��o: LIS  Lista duplamente encadeada **********/

