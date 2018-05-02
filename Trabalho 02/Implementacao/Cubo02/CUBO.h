/***************************************************************************
*
*  $Módulo de definição: Módulo  cubo
*
*  Arquivo gerado:              CUBO.H
*  Letras identificadoras:      CUB
*
*  Arquivo da base de software: D:\INF1301\TRAB1-1\FONTES
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  Flavio B. Vilac
*  Autores: AC, FM e MA
*  Autores: Bernardo L., Carol J., Mariela, Tiago S.
*
*  $HA Histórico de evolução:
*     Versão   Autor     Data        Observações
*       1.00  AC,FM,MA  01/03/2018   Início do desenvolvimento.
*		1.10  AC,FM,MA  19/03/2018   Termino do desenvolvimento.
*		1.20    BCMT    02/05/2018	 Alteração na função de Buscar Peça
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto de funções para criar e
*     movimentar um cubo mágico.
*     O cubo é gerado apartir de uma matiz cúbica.
*     A cada momento o módulo admite no máximo um único cubo.
*     Ao iniciar a execução do programa não existe cubo.
*     O cubo deverá estár devidamente preenchido. Caso contrário as funções
*	  não tem utilidae.
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um cubo */

typedef struct tpCubo CUB_tpCubo;

/***********************************************************************
*
*  $TC Tipo de dados: CUB Elemento da peça
*
*	$ED Descrição:
*		Referente a uma peça do cubo e tratada como se fosse um cubinho
*		 dentro do cubo maior. como o cubinho está inserido no cubo maior
*		 possui apenas 2 ou 3 faces preenchidas, referenbtta aos tipos
*		 de peças de um cubo mágico (borda e quina).
*
***********************************************************************/

typedef struct tpPeca
{
	int C;
	/* Será preenchida com a cor referente a face de cima da peça ou um valor nulo. */

	int E;
	/* Será preenchida com a cor referente a face da esquerda da peça ou um valor nulo. */

	int F;
	/* Será preenchida com a cor referente a face da frente da peça ou um valor nulo. */

	int D;
	/* Será preenchida com a cor referente a face da direita da peça ou um valor nulo. */

	int B;
	/* Será preenchida com a cor referente a face de baixo da peça ou um valor nulo. */

	int T;
	/* Será preenchida com a cor referente a face de trás da peça ou um valor nulo. */

	int coordPeca[3];
	/* Mostra a coordenada da prça em 3 coordenadas, largura sendo referente a posiçao 0 do vetor,
	*  altura referente a posiçao 1 do vetor e a profundidade é referente a terceira posiçao do vetor.
	* O domínio vai de 1 à 3, tendo como referencia a face da frente do cubo a quina inferior esquerda
	*  sendo 1|1|1. */

} CUB_tpPeca;

/***********************************************************************
*
*  $TC Tipo de dados: CUB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do cubo
*
***********************************************************************/

typedef enum {

	CUB_CondRetOK = 0,
	/* Executou corretamente */

	CUB_CondRetFaltouMemoria = 1,
	/* Faltou memoria ao alocar dados */

	CUB_CondRetPecaNaoExiste = 2,
	/* Peça buscada não é possível */

	CUB_CondRetPecaErrada = 3,
	/* Peça retornada errada */

	CUB_CondRetErro = 4,
	/* Qualquer condição de erro inesperada */

} CUB_tpCondRet;

/***********************************************************************
*
*  $FC Função: CUB Criar cubo
*
*  $ED Descrição da função
*     Cria um novo cubo vazio.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o cubo.
*     Este ponteiro será utilizado pelas funções que manipulem este cubo.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

CUB_tpCondRet CUB_criaCubo(CUB_tpCubo **cubo);

/***********************************************************************
*
*  $FC Função: CUB Libera cubo
*
*  $EP Parâmetros
*     $P cubo - parâmetro do cubo a ser destroido.
*
*  $ED Descrição da função
*     Destrói o corpo do cubo, anulando o cubo.
*     Faz nada caso o cubo não exista.0
*
*  $FV Valor retornado
*     CUB_CondRetOK  -  liberou sem problemas
*
***********************************************************************/

CUB_tpCondRet CUB_liberaCubo(CUB_tpCubo *cubo);

/***********************************************************************
*
*  $FC Função: CUB Criar peça
*
*  $ED Descrição da função
*     Cria uma peça vazia.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a peça.
*     Este ponteiro será utilizado pelas funções que manipulem esta peça.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

CUB_tpPeca *CUB_criaPeca(void);

/***********************************************************************
*
*  $FC Função: CUB Libera peça
*
*  $EP Parâmetros
*     $P peca - parâmetro da peça a ser destroida.
*
*  $ED Descrição da função
*     Destrói o corpo da peça, anulando a peça.
*     Faz nada caso a peça não exista.
*
***********************************************************************/

void CUB_liberaPeca(CUB_tpPeca *peca);

/***********************************************************************
*
*  $FC Função: CUB Preenche cubo
*
*  $EP Parâmetros
*     $P cubo - parâmetro do cubo a ser preenchido.
*
*  $ED Descrição da função
*     preeche o cubo.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo preenchido.
*
***********************************************************************/

CUB_tpCondRet CUB_preencheCubo(CUB_tpCubo *cubo, int x, int y, int z, int cor);

/***********************************************************************
*
*  $FC Função: CUB Gira frente esquerda
*
*  $ED Descrição da função
*     Função que gira a face da frente do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraFrenteEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira frente direita
*
*  $ED Descrição da função
*     Função que gira a face da frente do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraFrenteDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira direita trás
*
*  $ED Descrição da função
*     Função que gira a face da direita do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para trás.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraDireitaTras(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira direita frente
*
*  $ED Descrição da função
*     Função que gira a face da direita do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a frente.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraDireitaFrente(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira esquerda frente
*
*  $ED Descrição da função
*     Função que gira a face da esquerda do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a frente.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraEsquerdaFrente(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira esquerda trás
*
*  $ED Descrição da função
*     Função que gira a face da esqueda do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para trás.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraEsquerdaTras(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira baixo esquerda
*
*  $ED Descrição da função
*     Função que gira a face de baixo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraBaixoEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira baixo direita
*
*  $ED Descrição da função
*     Função que gira a face de baixo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraBaixoDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira topo esquerda
*
*  $ED Descrição da função
*     Função que gira a face do topo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTopoEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira tras direita
*
*  $ED Descrição da função
*     Função que gira a face do tras do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTrasDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira tras esquerda
*
*  $ED Descrição da função
*     Função que gira a face de tras do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTrasEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Gira topo direita
*
*  $ED Descrição da função
*     Função que gira a face de topo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Parâmetros
*     $P cubo - parâmetro a ser alterado.
*	  $P n - valor que indica o números de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTopoDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Função: CUB Busca peça
*
*  $ED Descrição da função
*     Função que busca determinada peça pelas suas cores e pela
*	  quantidade de cores na peça.
*
*  $EP Parâmetros
*     $P cubo	  -  Parâmetro a ser alterado.
*	  $P cores	  -  String que diz quais cores a peça a ser procura da possui.
*					 Pode ter duas ou três diferentes cores relacionadas ao cubo.
*	  $P numCores -  Valor que indica o números de cores da peça a ser procurada.
*					 Pode conter apenas 2 ou 3.
*
*  $FV Valor retornado
*     Retorna um ponteiro para com dos dados da peça desejada.
*	  CUB_CondretOK      -  Giro aconteceu normalmente.
*	  CUB_PecaNaoExiste  -  Peça procurada não é possivel de ter em um cubo.
*
***********************************************************************/

CUB_tpCondRet CUB_buscaPeca(CUB_tpCubo *cubo, int cores[], int numCores, CUB_tpPeca *peca);


/********** Fim do módulo de definição: CUB Módulo Cubo **********/
