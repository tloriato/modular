#if ! defined( CUBO_ )
#define CUBO_
/******************************************************************************
*
*  $MCD M�dulo de defini��o: CUB  Cubo m�gico
*
*  Arquivo gerado:              CUBO.h
*  Letras identificadoras:      CUB
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: dlas	Daniel Luca Alves da Silva
			sgmpm	Sergio Gustavo Mendon�a Pyrrho Moreira
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	  10	  sgmpm  29/mar/2018 revis�o final
*	  9		  sgmpm	 28/mar/2018 formata��o e revis�o
*	  8		  dlas	 28/mar/2018 implementa��o fun��o busca quina
*	  7		  dlas	 26/mar/2018 implementa��o fun��o busca aresta
*	  6		  dlas	 25/mar/2018 implementa��o da fun��o giro
*	  5		  dlas	 19/mar/2018 Mudan�a do arquivo interface
*	  4		  sgmpm  18/mar/2018 Revisao
*	  3		  sgmpm	 16/mar/2018 Otimiza��o
*	  2		  dlas	 12/mar/2018 Implementa��o das fun��es
*     1       dlas   07/mar/2018 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*		Implementa Cubos m�gicos.
*
*		O m�dulo implementa a representa��o de cubos m�gicos de posi��o fixa
*			que s�o manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face ter� sempre o mesmo valor.
*			O cubo deve ser inicializado com um vetor de inteiros, na ordem
*			definida na fun��o de exibi��o.
*
******************************************************************************/

#if defined( CUBO_OWN )
#define CUBO_EXT
#else
#define CUBO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um Cubo */

typedef struct CUB_tagCUBO * CUB_tppCUBO;

/* Tipo faces de Cubo */
typedef enum {
	CUB_faceSuperior = 0,

	CUB_faceFrontal = 1,

	CUB_faceDireita = 2,

	CUB_faceTraseira = 3,

	CUB_faceEsquerda = 4,

	CUB_faceInferior = 5,

} CUB_tpFaceDeCUBO;


/**************************************************************************
*
*  $TC Tipo de dados: CUB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do Cubo
*
**************************************************************************/

typedef enum {

	CUB_CondRetOK,
	/* Concluiu corretamente */

	CUB_CondRetCuboInvalido,
	/* O endere�o recebido aponta para NULL */

	CUB_CondRetCorInvalida,
	/* As cores n�o est�o inseridas no  */

	CUB_CondRetFaceInvalida,
	/* O valor de face inserido n�o identifica nenhuma face
	represent�vel */

	CUB_CondRetCoordenadasInvalidas,
	/* As coordenadas inseridas nao estao sobre a face
	do cubo */

	CUB_CondRetFaltouMemoria
	/* Faltou mem�ria ao tentar criar um Cubo */

} CUB_tpCondRet;


/**************************************************************************
*
*  $FC Fun��o: CUB  &Criar Cubo
*
*  $ED Descri��o da fun��o
*		Cria uma inst�ncia de Cubo m�gico.
*		Recebe o endere�o de uma vari�vel do tipo ponteiro para Cubo.
*		A fun��o � respons�vel por alocar a mem�ria onde a estrutura
*		do CUBO ser� guardada e escrever esta no par�metro recebido.
*
*  $EP Par�metros
*					pCubo	-	Endere�o no qual a fun��o guardar� a
*								localiza��o do CUBO na mem�ria. Essa
*								localiza��o identifica um �nico cubo
*								e deve ser usada para manipul�-lo.
*
*		ConfiguracaoInicial -	Vetor de inteiros que descrevem a
*								configura��o inicial que o cubo deve
*								ter, na ordem em que esses seriam
*								exibidos conforme descrito pela fun��o
*								de exibi��o.
*
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   mem�ria.
*
**************************************************************************/

CUB_tpCondRet CUB_CriarCUBO(CUB_tppCUBO* pCubo, int* ConfiguracaoInicial);

/**************************************************************************
*
*  $FC Fun��o: CUB  &Exibir Cubo
*
*  $ED Descri��o da fun��o
*		Exibe na tela a configura��o atual do Cubo m�gico. Essa exibi��o
*		segue a ideia de planificar a estrutura do Cubo M�gico tal que: A
*		face superior � impressa no topo, acima da face frontal, com seus
*		quadrados mais pr�ximos da face traseira impressos no topo. As
*		faces esquerda, frontal, direita e traseira impressas nessa ordem
*		lado a lado com os quadrados mais altos impressos no topo. A face
*		inferior exibida por �ltimo, abaixo da face frontal com seus
*		quadrados mais pr�ximos � face frontal exibidos no topo.
*
*  $EP Par�metros
*		pCubo	-	Endere�o onde est� armazenado o Cubo m�gico.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*
**************************************************************************/

CUB_tpCondRet CUB_ExibirCUBO(CUB_tppCUBO pCubo);


/**************************************************************************
*
*  $FC Fun��o: CUB  &Destruir Cubo
*
*  $ED Descri��o da fun��o
*		Destr�i o Cubo fornecido.
*		OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*  $EP Par�metros
*		pCubo	-	Identificador do cubo m�gico.
*
*  $FV Valor retornado
*     CUB_CondRetOK    - destruiu sem problemas
*
**************************************************************************/

CUB_tpCondRet CUB_DestruirCUBO(CUB_tppCUBO pCubo);


/**************************************************************************
*
*  $FC Fun��o: CUB  &Girar face.
*
*  $ED Descri��o da fun��o
*		Gira a face uma quantidade qualquer de vezes passada como
*		par�metro. A fun��o deve receber tamb�m o sentido do giro,
*		podendo ser hor�rio ou anti-hor�rio.
*
*  $EP Par�metros
*			 pCubo	-	Identificador do cubo m�gico.
*		faceGirada	-	Identificador da Face que se pretende girar.
*		  numGiros	-	quantidade de giros que devem ser realizadas.
*		   sentido	-	'A' ou 'a' para anti-hor�rio, 'h' ou demais
*						caracteres para sentido hor�rio.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetFaceInvalida	-	A face recebida como par�metro n�o
*								identifica nenhuma face represent�vel.
*
**************************************************************************/

CUB_tpCondRet CUB_GirarFace(CUB_tppCUBO pCubo, CUB_tpFaceDeCUBO faceGirada,
	int numGiros, char sentido);


/**************************************************************************
*
*  $FC Fun��o: CUB  &Checar cor da Face
*
*  $ED Descri��o da fun��o
*		A fun��o recebe um endere�o onde deve escrever a cor de um quadrado
*		descrito pelos demais par�metros. A forma de indexa��o desse
*		quadrado � a partir de um n�mero de linha e coluna de uma face, ou
*		seja, um n�mero entre 0 e 2. O mapeamento � tal qual o definido na
*		fun��o de exibi��o.
*
*  $EP Par�metros
*				  pCor	-	Ponteiro onde � armazenada a cor encontrada.
*				 pCubo	-	Identificador do cubo m�gico.
*				 linha	-	Coordenada da linha que se pretende checar.
*				coluna	-	Coordenada da coluna que se pretende checar.
*	  faceInspecionada	-	Identificador da Face que se pretende checar.
*
*  $FV Valor retornado
*	CUB_CondRetOK					- Executou normalmente.
*	CUB_CondRetCuboInvalido			- Recebeu um ponteiro NULL.
*	CUB_CondRetCoordenadasInvalidas - As coordenadas n�o s�o v�lidas.
*	CUB_CondRetFaceInvalida			- A face recebida como par�metro n�o
*									  identifica nenhuma face represent�vel.
*
**************************************************************************/

CUB_tpCondRet CUB_ChecarCorDaFace(int* pCor, CUB_tppCUBO pCubo, int linha,
	int coluna, CUB_tpFaceDeCUBO faceInspecionada);

/**************************************************************************
*
*  $FC Fun��o: CUB  &Encontrar Posi��o de Pe�a de Aresta
*
*  $ED Descri��o da fun��o
*		A fun��o procura dentro do cubo qual pe�a de aresta, ou seja, que tem
*		apenas duas faces vis�veis, tem a configura��o de cores fornecida e
*		retorna a face, linha e coluna que identificam o quadrado dessa pe�a
*		pintado com a cor1. Caso n�o encontre a pe�a, a fun��o retorna a
*		condi��o de retorno de Cor Inv�lida.
*
*  $EP Par�metros
*		 pFace	-	Ponteiro onde � armazenada a face do quadrado pintado
*					pela cor1.
*		pLinha	-	Ponteiro onde deve ser colocada a linha do quadrado
*					pintado pela cor1.
*	   pColuna	-	Ponteiro onde deve ser colocada a coluna do quadrado
*					pintado pela cor1.
*		 pCubo	-	Identificador do cubo m�gico.
*		  cor1	-	Cor que a pe�a desejada possui.
*		  cor2	-	A outra cor que a pe�a desejada possui.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetCorInvalida	-	N�o h� pe�a no cubo com a configura��o
*								de cores fornecida.
*
**************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeAresta(CUB_tpFaceDeCUBO* pFace,
	int*pLinha, int* pColuna, CUB_tppCUBO pCubo, int cor1, int cor2);

/**************************************************************************
*
*  $FC Fun��o: CUB  &Encontrar Posi��o de Pe�a de Quina
*
*  $ED Descri��o da fun��o
*		A fun��o procura dentro do cubo qual pe�a de quina (que tr�s
*		faces vis�veis) cont�m as cores fornecidas e retorna a
*		orienta��o, linha e coluna da face dessa quina pintada pela
*		cor1. Caso n�o encontre a pe�a, a fun��o retorna a condi��o de
*		retorno de Cor Inv�lida.
*
*  $EP Par�metros
*		 pFace	-	Ponteiro onde � armazenada a face do quadrado pintado
*					pela cor1.
*		pLinha	-	Ponteiro onde deve ser colocada a linha do quadrado
*					pintado pela cor1.
*	   pColuna	-	Ponteiro onde deve ser colocada a coluna do quadrado
*					pintado pela cor1.
*		 pCubo	-	Identificador do cubo m�gico.
*		  cor1	-	Cor que a pe�a desejada possui.
*		  cor2	-	Outra cor que a pe�a desejada possui.
*		  cor3	-	Outra cor que a pe�a desejada possui.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetCorInvalida	-	N�o h� pe�a no cubo com a configura��o
*								de cores fornecida.
*
**************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeQuina(CUB_tpFaceDeCUBO* pFace,
	int*pLinha, int* pColuna, CUB_tppCUBO pCubo,
	int cor1, int cor2, int cor3);

#undef Cubo_EXT

/********** Fim do m�dulo de defini��o: CUB  Cubo duplamente encadeada **********/

#else
#endif
