/***************************************************************************
*
*  $M�dulo de defini��o: M�dulo  cubo
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
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autor     Data        Observa��es
*       1.00  AC,FM,MA  01/03/2018   In�cio do desenvolvimento.
*		1.10  AC,FM,MA  19/03/2018   Termino do desenvolvimento.
*		1.20    BCMT    02/05/2018	 Altera��o na fun��o de Buscar Pe�a
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto de fun��es para criar e
*     movimentar um cubo m�gico.
*     O cubo � gerado apartir de uma matiz c�bica.
*     A cada momento o m�dulo admite no m�ximo um �nico cubo.
*     Ao iniciar a execu��o do programa n�o existe cubo.
*     O cubo dever� est�r devidamente preenchido. Caso contr�rio as fun��es
*	  n�o tem utilidae.
*
***************************************************************************/

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um cubo */

typedef struct tpCubo CUB_tpCubo;

/***********************************************************************
*
*  $TC Tipo de dados: CUB Elemento da pe�a
*
*	$ED Descri��o:
*		Referente a uma pe�a do cubo e tratada como se fosse um cubinho
*		 dentro do cubo maior. como o cubinho est� inserido no cubo maior
*		 possui apenas 2 ou 3 faces preenchidas, referenbtta aos tipos
*		 de pe�as de um cubo m�gico (borda e quina).
*
***********************************************************************/

typedef struct tpPeca
{
	int C;
	/* Ser� preenchida com a cor referente a face de cima da pe�a ou um valor nulo. */

	int E;
	/* Ser� preenchida com a cor referente a face da esquerda da pe�a ou um valor nulo. */

	int F;
	/* Ser� preenchida com a cor referente a face da frente da pe�a ou um valor nulo. */

	int D;
	/* Ser� preenchida com a cor referente a face da direita da pe�a ou um valor nulo. */

	int B;
	/* Ser� preenchida com a cor referente a face de baixo da pe�a ou um valor nulo. */

	int T;
	/* Ser� preenchida com a cor referente a face de tr�s da pe�a ou um valor nulo. */

	int coordPeca[3];
	/* Mostra a coordenada da pr�a em 3 coordenadas, largura sendo referente a posi�ao 0 do vetor,
	*  altura referente a posi�ao 1 do vetor e a profundidade � referente a terceira posi�ao do vetor.
	* O dom�nio vai de 1 � 3, tendo como referencia a face da frente do cubo a quina inferior esquerda
	*  sendo 1|1|1. */

} CUB_tpPeca;

/***********************************************************************
*
*  $TC Tipo de dados: CUB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do cubo
*
***********************************************************************/

typedef enum {

	CUB_CondRetOK = 0,
	/* Executou corretamente */

	CUB_CondRetFaltouMemoria = 1,
	/* Faltou memoria ao alocar dados */

	CUB_CondRetPecaNaoExiste = 2,
	/* Pe�a buscada n�o � poss�vel */

	CUB_CondRetPecaErrada = 3,
	/* Pe�a retornada errada */

	CUB_CondRetErro = 4,
	/* Qualquer condi��o de erro inesperada */

} CUB_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: CUB Criar cubo
*
*  $ED Descri��o da fun��o
*     Cria um novo cubo vazio.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o cubo.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem este cubo.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

CUB_tpCondRet CUB_criaCubo(CUB_tpCubo **cubo);

/***********************************************************************
*
*  $FC Fun��o: CUB Libera cubo
*
*  $EP Par�metros
*     $P cubo - par�metro do cubo a ser destroido.
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo do cubo, anulando o cubo.
*     Faz nada caso o cubo n�o exista.0
*
*  $FV Valor retornado
*     CUB_CondRetOK  -  liberou sem problemas
*
***********************************************************************/

CUB_tpCondRet CUB_liberaCubo(CUB_tpCubo *cubo);

/***********************************************************************
*
*  $FC Fun��o: CUB Criar pe�a
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a vazia.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a pe�a.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem esta pe�a.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

CUB_tpPeca *CUB_criaPeca(void);

/***********************************************************************
*
*  $FC Fun��o: CUB Libera pe�a
*
*  $EP Par�metros
*     $P peca - par�metro da pe�a a ser destroida.
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo da pe�a, anulando a pe�a.
*     Faz nada caso a pe�a n�o exista.
*
***********************************************************************/

void CUB_liberaPeca(CUB_tpPeca *peca);

/***********************************************************************
*
*  $FC Fun��o: CUB Preenche cubo
*
*  $EP Par�metros
*     $P cubo - par�metro do cubo a ser preenchido.
*
*  $ED Descri��o da fun��o
*     preeche o cubo.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo preenchido.
*
***********************************************************************/

CUB_tpCondRet CUB_preencheCubo(CUB_tpCubo *cubo, int x, int y, int z, int cor);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira frente esquerda
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da frente do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraFrenteEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira frente direita
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da frente do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraFrenteDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira direita tr�s
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da direita do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para tr�s.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraDireitaTras(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira direita frente
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da direita do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a frente.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraDireitaFrente(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira esquerda frente
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da esquerda do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a frente.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraEsquerdaFrente(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira esquerda tr�s
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face da esqueda do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para tr�s.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraEsquerdaTras(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira baixo esquerda
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face de baixo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraBaixoEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira baixo direita
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face de baixo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraBaixoDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira topo esquerda
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face do topo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTopoEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira tras direita
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face do tras do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTrasDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira tras esquerda
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face de tras do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a esquerda.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTrasEsquerda(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Gira topo direita
*
*  $ED Descri��o da fun��o
*     Fun��o que gira a face de topo do cubo recebido em 1/4 de volta
*	  ou 1/2 de volta para a direita.
*
*  $EP Par�metros
*     $P cubo - par�metro a ser alterado.
*	  $P n - valor que indica o n�meros de 1/4 de volta a ser rotacionado.
*
*  $FV Valor retornado
*     Retorna um ponteiro para cubo rotacionado.
*	  CUB_CondretOK  -  Giro aconteceu normalmente.
*
***********************************************************************/

CUB_tpCondRet CUB_giraTopoDireita(CUB_tpCubo *cubo, int n);

/***********************************************************************
*
*  $FC Fun��o: CUB Busca pe�a
*
*  $ED Descri��o da fun��o
*     Fun��o que busca determinada pe�a pelas suas cores e pela
*	  quantidade de cores na pe�a.
*
*  $EP Par�metros
*     $P cubo	  -  Par�metro a ser alterado.
*	  $P cores	  -  String que diz quais cores a pe�a a ser procura da possui.
*					 Pode ter duas ou tr�s diferentes cores relacionadas ao cubo.
*	  $P numCores -  Valor que indica o n�meros de cores da pe�a a ser procurada.
*					 Pode conter apenas 2 ou 3.
*
*  $FV Valor retornado
*     Retorna um ponteiro para com dos dados da pe�a desejada.
*	  CUB_CondretOK      -  Giro aconteceu normalmente.
*	  CUB_PecaNaoExiste  -  Pe�a procurada n�o � possivel de ter em um cubo.
*
***********************************************************************/

CUB_tpCondRet CUB_buscaPeca(CUB_tpCubo *cubo, int cores[], int numCores, CUB_tpPeca *peca);


/********** Fim do m�dulo de defini��o: CUB M�dulo Cubo **********/
