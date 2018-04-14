#if ! defined( CUBO_ )
#define CUBO_
/******************************************************************************
*
*  $MCD Módulo de definição: CUB  Cubo mágico
*
*  Arquivo gerado:              CUBO.h
*  Letras identificadoras:      CUB
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: dlas	Daniel Luca Alves da Silva
			sgmpm	Sergio Gustavo Mendonça Pyrrho Moreira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	  10	  sgmpm  29/mar/2018 revisão final
*	  9		  sgmpm	 28/mar/2018 formatação e revisão
*	  8		  dlas	 28/mar/2018 implementação função busca quina
*	  7		  dlas	 26/mar/2018 implementação função busca aresta
*	  6		  dlas	 25/mar/2018 implementação da função giro
*	  5		  dlas	 19/mar/2018 Mudança do arquivo interface
*	  4		  sgmpm  18/mar/2018 Revisao
*	  3		  sgmpm	 16/mar/2018 Otimização
*	  2		  dlas	 12/mar/2018 Implementação das funções
*     1       dlas   07/mar/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*		Implementa Cubos mágicos.
*
*		O módulo implementa a representação de cubos mágicos de posição fixa
*			que são manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face terá sempre o mesmo valor.
*			O cubo deve ser inicializado com um vetor de inteiros, na ordem
*			definida na função de exibição.
*
******************************************************************************/

#if defined( CUBO_OWN )
#define CUBO_EXT
#else
#define CUBO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um Cubo */

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
*  $TC Tipo de dados: CUB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do Cubo
*
**************************************************************************/

typedef enum {

	CUB_CondRetOK,
	/* Concluiu corretamente */

	CUB_CondRetCuboInvalido,
	/* O endereço recebido aponta para NULL */

	CUB_CondRetCorInvalida,
	/* As cores não estão inseridas no  */

	CUB_CondRetFaceInvalida,
	/* O valor de face inserido não identifica nenhuma face
	representável */

	CUB_CondRetCoordenadasInvalidas,
	/* As coordenadas inseridas nao estao sobre a face
	do cubo */

	CUB_CondRetFaltouMemoria
	/* Faltou memória ao tentar criar um Cubo */

} CUB_tpCondRet;


/**************************************************************************
*
*  $FC Função: CUB  &Criar Cubo
*
*  $ED Descrição da função
*		Cria uma instância de Cubo mágico.
*		Recebe o endereço de uma variável do tipo ponteiro para Cubo.
*		A função é responsável por alocar a memória onde a estrutura
*		do CUBO será guardada e escrever esta no parâmetro recebido.
*
*  $EP Parâmetros
*					pCubo	-	Endereço no qual a função guardará a
*								localização do CUBO na memória. Essa
*								localização identifica um único cubo
*								e deve ser usada para manipulá-lo.
*
*		ConfiguracaoInicial -	Vetor de inteiros que descrevem a
*								configuração inicial que o cubo deve
*								ter, na ordem em que esses seriam
*								exibidos conforme descrito pela função
*								de exibição.
*
*  $FV Valor retornado
*		CUB_CondRetOK			 - Criou um cubo com sucesso.
*		CUB_CondRetFaltouMemoria - Erro ao criar o cubo por falta de
*								   memória.
*
**************************************************************************/

CUB_tpCondRet CUB_CriarCUBO(CUB_tppCUBO* pCubo, int* ConfiguracaoInicial);

/**************************************************************************
*
*  $FC Função: CUB  &Exibir Cubo
*
*  $ED Descrição da função
*		Exibe na tela a configuração atual do Cubo mágico. Essa exibição
*		segue a ideia de planificar a estrutura do Cubo Mágico tal que: A
*		face superior é impressa no topo, acima da face frontal, com seus
*		quadrados mais próximos da face traseira impressos no topo. As
*		faces esquerda, frontal, direita e traseira impressas nessa ordem
*		lado a lado com os quadrados mais altos impressos no topo. A face
*		inferior exibida por último, abaixo da face frontal com seus
*		quadrados mais próximos à face frontal exibidos no topo.
*
*  $EP Parâmetros
*		pCubo	-	Endereço onde está armazenado o Cubo mágico.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*
**************************************************************************/

CUB_tpCondRet CUB_ExibirCUBO(CUB_tppCUBO pCubo);


/**************************************************************************
*
*  $FC Função: CUB  &Destruir Cubo
*
*  $ED Descrição da função
*		Destrói o Cubo fornecido.
*		OBS. não existe previsão para possíveis falhas de execução.
*  $EP Parâmetros
*		pCubo	-	Identificador do cubo mágico.
*
*  $FV Valor retornado
*     CUB_CondRetOK    - destruiu sem problemas
*
**************************************************************************/

CUB_tpCondRet CUB_DestruirCUBO(CUB_tppCUBO pCubo);


/**************************************************************************
*
*  $FC Função: CUB  &Girar face.
*
*  $ED Descrição da função
*		Gira a face uma quantidade qualquer de vezes passada como
*		parâmetro. A função deve receber também o sentido do giro,
*		podendo ser horário ou anti-horário.
*
*  $EP Parâmetros
*			 pCubo	-	Identificador do cubo mágico.
*		faceGirada	-	Identificador da Face que se pretende girar.
*		  numGiros	-	quantidade de giros que devem ser realizadas.
*		   sentido	-	'A' ou 'a' para anti-horário, 'h' ou demais
*						caracteres para sentido horário.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetFaceInvalida	-	A face recebida como parâmetro não
*								identifica nenhuma face representável.
*
**************************************************************************/

CUB_tpCondRet CUB_GirarFace(CUB_tppCUBO pCubo, CUB_tpFaceDeCUBO faceGirada,
	int numGiros, char sentido);


/**************************************************************************
*
*  $FC Função: CUB  &Checar cor da Face
*
*  $ED Descrição da função
*		A função recebe um endereço onde deve escrever a cor de um quadrado
*		descrito pelos demais parâmetros. A forma de indexação desse
*		quadrado é a partir de um número de linha e coluna de uma face, ou
*		seja, um número entre 0 e 2. O mapeamento é tal qual o definido na
*		função de exibição.
*
*  $EP Parâmetros
*				  pCor	-	Ponteiro onde é armazenada a cor encontrada.
*				 pCubo	-	Identificador do cubo mágico.
*				 linha	-	Coordenada da linha que se pretende checar.
*				coluna	-	Coordenada da coluna que se pretende checar.
*	  faceInspecionada	-	Identificador da Face que se pretende checar.
*
*  $FV Valor retornado
*	CUB_CondRetOK					- Executou normalmente.
*	CUB_CondRetCuboInvalido			- Recebeu um ponteiro NULL.
*	CUB_CondRetCoordenadasInvalidas - As coordenadas não são válidas.
*	CUB_CondRetFaceInvalida			- A face recebida como parâmetro não
*									  identifica nenhuma face representável.
*
**************************************************************************/

CUB_tpCondRet CUB_ChecarCorDaFace(int* pCor, CUB_tppCUBO pCubo, int linha,
	int coluna, CUB_tpFaceDeCUBO faceInspecionada);

/**************************************************************************
*
*  $FC Função: CUB  &Encontrar Posição de Peça de Aresta
*
*  $ED Descrição da função
*		A função procura dentro do cubo qual peça de aresta, ou seja, que tem
*		apenas duas faces visíveis, tem a configuração de cores fornecida e
*		retorna a face, linha e coluna que identificam o quadrado dessa peça
*		pintado com a cor1. Caso não encontre a peça, a função retorna a
*		condição de retorno de Cor Inválida.
*
*  $EP Parâmetros
*		 pFace	-	Ponteiro onde é armazenada a face do quadrado pintado
*					pela cor1.
*		pLinha	-	Ponteiro onde deve ser colocada a linha do quadrado
*					pintado pela cor1.
*	   pColuna	-	Ponteiro onde deve ser colocada a coluna do quadrado
*					pintado pela cor1.
*		 pCubo	-	Identificador do cubo mágico.
*		  cor1	-	Cor que a peça desejada possui.
*		  cor2	-	A outra cor que a peça desejada possui.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetCorInvalida	-	Não há peça no cubo com a configuração
*								de cores fornecida.
*
**************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeAresta(CUB_tpFaceDeCUBO* pFace,
	int*pLinha, int* pColuna, CUB_tppCUBO pCubo, int cor1, int cor2);

/**************************************************************************
*
*  $FC Função: CUB  &Encontrar Posição de Peça de Quina
*
*  $ED Descrição da função
*		A função procura dentro do cubo qual peça de quina (que três
*		faces visíveis) contém as cores fornecidas e retorna a
*		orientação, linha e coluna da face dessa quina pintada pela
*		cor1. Caso não encontre a peça, a função retorna a condição de
*		retorno de Cor Inválida.
*
*  $EP Parâmetros
*		 pFace	-	Ponteiro onde é armazenada a face do quadrado pintado
*					pela cor1.
*		pLinha	-	Ponteiro onde deve ser colocada a linha do quadrado
*					pintado pela cor1.
*	   pColuna	-	Ponteiro onde deve ser colocada a coluna do quadrado
*					pintado pela cor1.
*		 pCubo	-	Identificador do cubo mágico.
*		  cor1	-	Cor que a peça desejada possui.
*		  cor2	-	Outra cor que a peça desejada possui.
*		  cor3	-	Outra cor que a peça desejada possui.
*
*  $FV Valor retornado
*	CUB_CondRetOK			-	Executou normalmente.
*	CUB_CondRetCuboInvalido	-	Recebeu um ponteiro NULL.
*	CUB_CondRetCorInvalida	-	Não há peça no cubo com a configuração
*								de cores fornecida.
*
**************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeQuina(CUB_tpFaceDeCUBO* pFace,
	int*pLinha, int* pColuna, CUB_tppCUBO pCubo,
	int cor1, int cor2, int cor3);

#undef Cubo_EXT

/********** Fim do módulo de definição: CUB  Cubo duplamente encadeada **********/

#else
#endif
