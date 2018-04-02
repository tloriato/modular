#if !defined(ARVORE_)
#define ARVORE_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo árvore
*
*  Arquivo gerado:              ARVORE.H
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar árvores binárias.
*     A árvore possui uma cabeça que contém uma referência para a raíz da
*     árvore e outra para um nó corrente da árvore.
*     A cada momento o módulo admite no máximo uma única árvore.
*     Ao iniciar a execução do programa não existe árvore.
*     A árvore poderá estar vazia. Neste caso a raiz e o nó corrente
*     serão nulos, embora a cabeça esteja definida.
*     O nó corrente será nulo se e somente se a árvore estiver vazia.
*
***************************************************************************/

#if defined(ARVORE_OWN)
#define ARVORE_EXT
#else
#define ARVORE_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: ARV Condicoes de retorno
*
*
***********************************************************************/

typedef enum {

    ARV_CondRetOK = 0,
    /* Executou correto */

    ARV_CondRetNaoCriouRaiz = 1,
    /* Não criou nó raiz */

    ARV_CondRetErroEstrutura = 2,
    /* Estrutura da árvore está errada */

    ARV_CondRetNaoEhFolha = 3,
    /* Não é folha relativa à direção de inserção desejada */

    ARV_CondRetArvoreNaoExiste = 4,
    /* Árvore não existe */

    ARV_CondRetArvoreVazia = 5,
    /* Árvore está vazia */

    ARV_CondRetNohEhRaiz = 6,
    /* Nó corrente é raiz */

    ARV_CondRetNaoPossuiFilho = 7,
    /* Nó corrente não possui filho na direção desejada */

    ARV_CondRetFaltouMemoria = 8
    /* Faltou memória ao alocar dados */

} ARV_tpCondRet;

/***********************************************************************
*
*  $FC Função: ARV Criar árvore
*
*  $ED Descrição da função
*     Cria uma nova árvore vazia no ponteiro determinado.
*     Caso já exista uma árvore no endereço para qual o ponteiro aponta,
*     esta será destruída.
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

ARV_tpCondRet ARV_CriarArvore(void **PontParam);

/***********************************************************************
*
*  $FC Função: ARV Destruir árvore
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da árvore no ponteiro passado.
*     Faz nada caso o ponteiro aponte para NULL (não aponta p/ uma árvore).
*
***********************************************************************/

void ARV_DestruirArvore(void **PontParam);

/***********************************************************************
*
*  $FC Função: ARV Adicionar filho à esquerda
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*     $P ValorParm - valor a ser inserido no novo nó.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso não seja folha para a esquerda
*
***********************************************************************/

ARV_tpCondRet ARV_InserirEsquerda(void *PontParam, char ValorParm);

/***********************************************************************
*
*  $FC Função: ARV Adicionar filho à direita
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*     $P ValorParm - valor a ser inserido no novo nó
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso não seja folha para a direita
*
***********************************************************************/

ARV_tpCondRet ARV_InserirDireita(void *PontParam, char ValorParm);

/***********************************************************************
*
*  $FC Função: ARV Ir para nó pai
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNoEhRaiz
*
***********************************************************************/

ARV_tpCondRet ARV_IrPai(void *PontParam);

/***********************************************************************
*
*  $FC Função: ARV Ir para nó à esquerda
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - nó corrente não possui filho à esquerda
*
***********************************************************************/

ARV_tpCondRet ARV_IrNoEsquerda(void *PontParam);

/***********************************************************************
*
*  $FC Função: ARV Ir para nó à direita
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - nó corrente não possui filho à direita
*
***********************************************************************/

ARV_tpCondRet ARV_IrNoDireita(void *PontParam);

/***********************************************************************
*
*  $FC Função: ARV Obter valor corrente
*
*  $EP Parâmetros
*     $P PontParam - ponteiro para árvore
*     $P ValorParm - é o parâmetro que receberá o valor contido no nó.
*                    Este parâmetro é passado por referência.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*
***********************************************************************/

ARV_tpCondRet ARV_ObterValorCorr(void *PontParam, char *ValorParm);

#undef ARVORE_EXT

/********** Fim do módulo de definição: Módulo árvore **********/

#else
#endif
