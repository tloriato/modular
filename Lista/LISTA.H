#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*           bmt - Bernardo, Mariaela e Tiago
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
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/

#ifdef _DEBUG
    #include "GENERICO.h"
    #include "CESPDIN.h"
    #include "CONTA.h"
	#include "IdTiposEspaco.def"
#endif
 
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         LIS_CondRetOK ,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia ,
               /* A lista n�o cont�m elementos */

         LIS_CondRetFimLista ,
               /* Foi atingido o fim de lista */

         LIS_CondRetNaoAchou ,
               /* N�o encontrou o valor procurado */

         LIS_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } LIS_tpCondRet ;

/************************************************
 * 
 * $TC Tipo de dados: Lis Verificações de Retorno
 * 
 * $ED Descrição oo tipo
 *      Retorno das funções de verificação em ordem hierárquica
************************************************/

    typedef enum {

        /* A lista passada não existe */
        LIS_verifInexistente,

        /* Lista com origem nula mas elemento corrente */

        LIS_verifSemOrigemComCorrente,

        /* Lista com origem nula, corrente nulo, mas com 
        elemento final */

        LIS_verifSemOrigemComFinal,

        /* Lista com origem, corrente, final nulos mas numero 
        de elementos diferente de 0 */

        LIS_verifSemOrigemComElemento,

        /* Equivalentemente para lista sem elemento final */
        LIS_verifSemFimComOrigem,
        LIS_verifSemFimComCorrente,
        LIS_verifSemFimComElemento,

        /* Numero de Elementos da Lista invalido (negativo) */

        LIS_verifNumElementosNegativo,

        /* Ponteiro para origem incorreta pois existe anterior */

        LIS_verifOrigemIncorreta,

        /* Ponteiro para final incorreto pois existe próximo */

        LIS_verifFinalIncorreto,

        /* Lista ligada de maneira errada no sentido -> */

        LIS_verifOrigemNaoChegaAoFinal,

        /* Lista ligada de maneira errada no sentido <- */

        LIS_verifAntLinkErrado,

        /* Elemento corrente nao encontrado partindo do primeiro */

        LIS_verifCorrenteNaoLigado,

        /* Numero de Elementos inconsisente*/

        LIS_verifNumElemInconsisente,

        /* Elemento da Lista aponta para o valor nulo */

        LIS_verifElemNulo,

        /* Tipo da cabeça inconsistente */
        LIS_verifCabecaTipoInconsistente,

        /* Tipo do Elemen inconsistente */
        LIS_verifElemTpInconsistente,

        /* Memoria vazando */
        LIS_verifVazamentoMemoria,

		/* Deturpação recebida não existe*/
		LIS_CondRetDeturpacaoInexistente,

        /* Lista está estruturada corretamente */

        LIS_verifOK
        
    } LIS_verifCondRet;




	
/************************************************
 * 
 * $TC Tipo de dados: Lis Deturpação
 * 
 * $ED Descrição oo tipo
 *      Retorno das funções de verificação em ordem hierárquica
************************************************/


	/*					!!!!!!!!!!! OBS !!!!!!!!!!!
	No deturpador (abaixo), sempre que houver um tipo dizendo que
	realiza uma ação em um nó, sem especificar qual, implica-se que
	esta sendo aplicado no elemento corrente.*/

#ifdef _DEBUG

      typedef enum {

			/* Nulifica cabeca lista */
			LIS_NulificaCabeca,

            /* Ponteiro de origem com valor NULL*/
            LIS_DeturpaPontOrigem,

            /* Ponteiro final com valor NULL*/
            LIS_DeturpaPontFinal,

            /* Ponteiro anterior a origem diferente NULL*/
            LIS_DeturpaPontAnteriorOrigem,

            /* Ponteiro proximo ao final diferente NULL*/
            LIS_DeturpaPontProxFimLista,

			/* Ponteiro do elemento corrente com NULL */
			LIS_DeturpaPontCorr,
		
            /* Elemento corrente da lista com valor NULL */
            LIS_DeturpaValorNULL,

			/* Ponteiro para o proximo elemento da lista com NULL*/
			LIS_DeturpaPontProxNULL,

			/* Ponteiro para o elemento anterior da lista com NULL*/
			LIS_DeturpaPontAntNULL,

            /* !!! Faz ponteiro para o prox apontar para lixo */
            LIS_DeturpaProxLixo,

            /* !!! Faz ponteiro para o ant apontar para lixo */
            LIS_DeturpaAntLixo,   

            /* Num de elementos menor 0*/
            LIS_DeturpaNumElementosNeg,

			/* Num de elementos declarado na cabeça != tamanho real da lista*/
			LIS_DeturpaNumElementos,

            /* !!! Altera tipo estrutura*/
            LIS_DeturpaAlteraTipoEstrutura,

			/*Tipo do elemento como NULL*/
			LIS_DeturpaTipoElem,

            /* !!! Elimina o elemento corrente da lista*/
            LIS_DeturpaEliminaCorrente,

            /* !!! Desencadeia nó sem liberálo com free */
            LIS_DeturpaDesencadeiaSemFree,

			/*Altera o tipo indicado na cabeça da lista para NULL*/
			LIS_DeturpaTipoCabeca,

			/* !!! Não deturpa a lista*/
            LIS_naoDeturpa
  
      }LIS_tpModosDeDeturpacao;
#endif

/***********************************************************************
*
*  $FC Fun��o: LIS  &Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   LIS_tppLista LIS_CriarLista(
             void   ( * ExcluirValor ) ( void * pDado ) ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Destruir lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void LIS_DestruirLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Esvaziar lista
*
*  $ED Descri��o da fun��o
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

   void LIS_EsvaziarLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir elemento antes
*
*  $ED Descri��o da fun��o
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista ,
                                           void * pValor        ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir elemento ap�s
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     Par�metros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*     Valor retornado
*        LIS_CondRetOK
*        LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista ,
                                          void * pValor        )
       ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Excluir elemento
*
*  $ED Descri��o da fun��o
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o valor contido no elemento corrente da lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista de onde se quer o valor
*
*  $FV Valor retornado
*     n�o NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

   void * LIS_ObterValor( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento inicial
*
*  $ED Descri��o da fun��o
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
***********************************************************************/

   void LIS_IrInicioLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento final
*
*  $ED Descri��o da fun��o
*     Torna corrente o elemento final da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
***********************************************************************/

   void LIS_IrFinalLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Avan�ar elemento
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente numElem elementos na lista
*     Se numElem for positivo avan�a em dire��o ao final
*     Se numElem for negativo avan�a em dire��o ao in�cio
*     numElem pode ser maior do que o n�mro de elementos existentes na
*               dire��o desejada
*     Se numElem for zero somente verifica se a lista est� vazia
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*     numElem - o n�mero de elementos a andar
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,
                                              int numElem ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Procurar elemento contendo valor
*
*  $ED Descri��o da fun��o
*     Procura o elemento que referencia o valor dado.
*     A fun��o compara ponteiro e n�o conte�do apontado.
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK  - se encontrou.
*                      O elemento corrente � o primeiro elemento do
*                      elemento corrente inclusive para o fim da lista
*                      e que cont�m o ponteiro procurado
*
*     LIS_CondRetNaoEncontrou - se o ponteiro n�o foi encontrado
*                      O elemento corrente continua o mesmo
*     LIS_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,
                                    void * pValor        ) ;


#ifdef _DEBUG
/*********************************************************************
 * 
 * $FC Função: LIS &Verificar a Lista
 * 
 * $ED Descrição:
 *      Verifica a integridade da lista
 * 
 * $EP Parâmetros
 *      ptLista     -   Ponteiro p/ cabeçca da Lista
 * 
 * $FV Valor retornado
 *      LIS_verifCondRet: retorna o erro encontrado na lista
 *******************************************************************/

    int LIS_VerificarLista (LIS_tppLista ptLista);

#endif


#ifdef _DEBUG
/*********************************************************************
 * 
 * $FC Função: LIS &Deturpar a Lista
 * 
 * $ED Descrição:
 *      Provoca falhas intencionais na lista
 * 
 * $EP Parâmetros
 *      ptLista     -   Ponteiro p/ cabeça da Lista
 *		modoDeturpar - Ação escolhida para deturpar lista
 * 
 * $FV Valor retornado
 *      LIS_CondRetAcaoDeturpInexistente
 *		LIS_CondRetOK
 *		LIS_verifInexistente
 *******************************************************************/

    LIS_tpCondRet LIS_DeturpaLista(LIS_tppLista ptLista,  LIS_tpModosDeDeturpacao modoDeturpar);

#endif


#undef LISTA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
