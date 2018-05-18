/***************************************************************************
*  $Módulo de implementação: Módulo Cubo
*
*  Arquivo gerado:              CUBO.C
*  Letras identificadoras:      CUB
*
*  Arquivo da base de software: D:\INF1301\TRAB1-1\FONTES
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  Flávio B. Vilac
*  Autores: FM e MA
*
*  $HA Histórico de evolução:
*     Versão   Autor     Data        Observações
*       1.00  FM,MA  01/03/2018   Início do desenvolvimento.
*		1.10  FM,MA  30/03/2018   Termino do desenvolvimento.
*		1.20  FM,MA  17/04/2018   Término de ajustes pós Teste.
*
***************************************************************************  ****/

#include   <malloc.h>
#include   <stdio.h>

#include   "CUBO.H"

/***********************************************************************
*
*  $TC Tipo de dados: CUB - Elemento do Cubo
*
************************************************************************/

struct tpCubo
{
	int faces[6][3][3];
	/* $ED Descrição
	*    Vetor de Matrizes 3x3 responsável pelo armazenamento das cores
	*	das faces do cubo. Uma matriz representa cada face do cubo
	*	e cada termo da matriz representa um "quadradinho" da face.
	*	É importante destacar que as coordenadas desse vetor no código
	*	são de grande relevância para o funcionamento do módulo, pois
	*    todas as funções se basearam nessa lógica para construir um
	*    referêncial.*/
};

/***** Protótipos das funções encapuladas no módulo *****/

static void preencheCores(CUB_tpPeca *peca, int cords[], int numCores);

static void pegaCoordenadas(CUB_tpCubo *cubo, int cores[], int cords[], int numCores);

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: CUB Preenche Cubo
*  ****/

CUB_tpCondRet CUB_preencheCubo(CUB_tpCubo *cubo, int x, int y, int z, int cor)
{
	cubo->faces[x][y][z] = cor;
	return CUB_CondRetOK;
}

/***********************************************************************
*
*  $FC Função: CUB Gira frente esquerda
*  ****/

CUB_tpCondRet CUB_giraFrenteEsquerda(CUB_tpCubo *cubo, int n)
{

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = aux;

	aux = cubo->faces[0][2][1];
	cubo->faces[0][2][1] = cubo->faces[3][1][0];
	cubo->faces[3][1][0] = cubo->faces[4][0][1];
	cubo->faces[4][0][1] = cubo->faces[1][1][2];
	cubo->faces[1][1][2] = aux;

	aux = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = aux;

	aux = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = aux;

	aux = cubo->faces[2][0][1];
	cubo->faces[2][0][1] = cubo->faces[2][1][0];
	cubo->faces[2][1][0] = cubo->faces[2][1][2];
	cubo->faces[2][1][2] = cubo->faces[2][2][1];
	cubo->faces[2][2][1] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteEsquerda(cubo, n);
	}
	if (cubo->faces[0][2][0] == cubo->faces[3][0][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira frente direita
*  ****/

CUB_tpCondRet CUB_giraFrenteDireita(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = aux;

	aux = cubo->faces[0][2][1];
	cubo->faces[0][2][1] = cubo->faces[1][1][2];
	cubo->faces[1][1][2] = cubo->faces[4][0][1];
	cubo->faces[4][0][1] = cubo->faces[3][1][0];
	cubo->faces[3][1][0] = aux;

	aux = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = aux;

	aux = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = aux;

	aux = cubo->faces[2][0][1];
	cubo->faces[2][0][1] = cubo->faces[2][2][1];
	cubo->faces[2][2][1] = cubo->faces[2][1][2];
	cubo->faces[2][1][2] = cubo->faces[2][1][0];
	cubo->faces[2][1][0] = aux;


	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteDireita(cubo, n);
	}
	if (cubo->faces[0][2][0] == cubo->faces[1][2][2])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira direita trás
*  ****/

CUB_tpCondRet CUB_giraDireitaTras(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = aux;

	aux = cubo->faces[0][1][2];
	cubo->faces[0][1][2] = cubo->faces[2][1][2];
	cubo->faces[2][1][2] = cubo->faces[4][1][2];
	cubo->faces[4][1][2] = cubo->faces[5][1][2];
	cubo->faces[5][1][2] = aux;

	aux = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = aux;

	aux = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = aux;

	aux = cubo->faces[3][0][1];
	cubo->faces[3][0][1] = cubo->faces[3][2][1];
	cubo->faces[3][2][1] = cubo->faces[3][1][2];
	cubo->faces[3][1][2] = cubo->faces[3][1][0];
	cubo->faces[3][1][0] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraDireitaTras(cubo, n);
	}
	if (cubo->faces[0][2][2] == cubo->faces[2][2][2])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira direita frente
*  ****/

CUB_tpCondRet CUB_giraDireitaFrente(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = aux;

	aux = cubo->faces[0][1][2];
	cubo->faces[0][1][2] = cubo->faces[5][1][2];
	cubo->faces[5][1][2] = cubo->faces[4][1][2];
	cubo->faces[4][1][2] = cubo->faces[2][1][2];
	cubo->faces[2][1][2] = aux;

	aux = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = aux;

	aux = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = aux;

	aux = cubo->faces[3][0][1];
	cubo->faces[3][0][1] = cubo->faces[3][1][0];
	cubo->faces[3][1][0] = cubo->faces[3][1][2];
	cubo->faces[3][1][2] = cubo->faces[3][2][1];
	cubo->faces[3][2][1] = aux;
	if (n == 2)
	{
		n = n - 1;
		CUB_giraDireitaFrente(cubo, n);
	}
	if (cubo->faces[0][2][2] == cubo->faces[5][2][2])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira tras direita
*  ****/

CUB_tpCondRet CUB_giraTrasDireita(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = aux;

	aux = cubo->faces[0][0][1];
	cubo->faces[0][0][1] = cubo->faces[1][1][0];
	cubo->faces[1][1][0] = cubo->faces[4][2][1];
	cubo->faces[4][2][1] = cubo->faces[3][1][2];
	cubo->faces[3][1][2] = aux;

	aux = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = aux;

	aux = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = aux;

	aux = cubo->faces[5][0][1];
	cubo->faces[5][0][1] = cubo->faces[5][1][2];
	cubo->faces[5][1][2] = cubo->faces[5][2][1];
	cubo->faces[5][2][1] = cubo->faces[5][1][0];
	cubo->faces[5][1][0] = aux;


	if (n == 2)
	{
		n = n - 1;
		CUB_giraTrasDireita(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[1][2][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira tras esquerda
*  ****/

CUB_tpCondRet CUB_giraTrasEsquerda(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = aux;

	aux = cubo->faces[0][0][1];
	cubo->faces[0][0][1] = cubo->faces[3][1][2];
	cubo->faces[3][1][2] = cubo->faces[4][2][1];
	cubo->faces[4][2][1] = cubo->faces[1][1][0];
	cubo->faces[1][1][0] = aux;

	aux = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = aux;

	aux = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = aux;

	aux = cubo->faces[5][0][1];
	cubo->faces[5][0][1] = cubo->faces[5][1][0];
	cubo->faces[5][1][0] = cubo->faces[5][2][1];
	cubo->faces[5][2][1] = cubo->faces[5][1][2];
	cubo->faces[5][1][2] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraTrasEsquerda(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[3][0][2])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}
/***********************************************************************
*
*  $FC Função: CUB Gira esquerda frente
*  ****/

CUB_tpCondRet CUB_giraEsquerdaFrente(CUB_tpCubo *cubo, int n)
{
	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = aux;

	aux = cubo->faces[0][1][0];
	cubo->faces[0][1][0] = cubo->faces[5][1][0];
	cubo->faces[5][1][0] = cubo->faces[4][1][0];
	cubo->faces[4][1][0] = cubo->faces[2][1][0];
	cubo->faces[2][1][0] = aux;

	aux = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = aux;

	aux = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = aux;

	aux = cubo->faces[1][0][1];
	cubo->faces[1][0][1] = cubo->faces[1][1][0];
	cubo->faces[1][1][0] = cubo->faces[1][1][2];
	cubo->faces[1][1][2] = cubo->faces[1][2][1];
	cubo->faces[1][2][1] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteEsquerda(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[5][0][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira esquerda trás
*  ****/


CUB_tpCondRet CUB_giraEsquerdaTras(CUB_tpCubo *cubo, int n)
{
	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = aux;

	aux = cubo->faces[0][1][0];
	cubo->faces[0][1][0] = cubo->faces[2][1][0];
	cubo->faces[2][1][0] = cubo->faces[4][1][0];
	cubo->faces[4][1][0] = cubo->faces[5][1][0];
	cubo->faces[5][1][0] = aux;

	aux = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = aux;


	aux = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = aux;

	aux = cubo->faces[1][0][1];
	cubo->faces[1][0][1] = cubo->faces[1][1][2];
	cubo->faces[1][1][2] = cubo->faces[1][2][1];
	cubo->faces[1][2][1] = cubo->faces[1][1][0];
	cubo->faces[1][1][0] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteEsquerda(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[2][0][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira baixo esquerda
*  ****/

CUB_tpCondRet CUB_giraBaixoEsquerda(CUB_tpCubo *cubo, int n)
{
	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = aux;

	aux = cubo->faces[2][2][1];
	cubo->faces[2][2][1] = cubo->faces[3][2][1];
	cubo->faces[3][2][1] = cubo->faces[5][0][1];
	cubo->faces[5][0][1] = cubo->faces[1][2][1];
	cubo->faces[1][2][1] = aux;

	aux = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = aux;


	aux = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = aux;

	aux = cubo->faces[4][0][1];
	cubo->faces[4][0][1] = cubo->faces[4][1][2];
	cubo->faces[4][1][2] = cubo->faces[4][2][1];
	cubo->faces[4][2][1] = cubo->faces[4][1][0];
	cubo->faces[4][1][0] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteEsquerda(cubo, n);
	}
	if (cubo->faces[2][2][0] == cubo->faces[3][2][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira baixo direita
*  ****/

CUB_tpCondRet CUB_giraBaixoDireita(CUB_tpCubo *cubo, int n)
{
	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[2][2][0];
	cubo->faces[2][2][0] = cubo->faces[1][2][0];
	cubo->faces[1][2][0] = cubo->faces[5][0][2];
	cubo->faces[5][0][2] = cubo->faces[3][2][0];
	cubo->faces[3][2][0] = aux;

	aux = cubo->faces[2][2][1];
	cubo->faces[2][2][1] = cubo->faces[1][2][1];
	cubo->faces[1][2][1] = cubo->faces[5][0][1];
	cubo->faces[5][0][1] = cubo->faces[3][2][1];
	cubo->faces[3][2][1] = aux;

	aux = cubo->faces[2][2][2];
	cubo->faces[2][2][2] = cubo->faces[1][2][2];
	cubo->faces[1][2][2] = cubo->faces[5][0][0];
	cubo->faces[5][0][0] = cubo->faces[3][2][2];
	cubo->faces[3][2][2] = aux;

	aux = cubo->faces[4][0][0];
	cubo->faces[4][0][0] = cubo->faces[4][2][0];
	cubo->faces[4][2][0] = cubo->faces[4][2][2];
	cubo->faces[4][2][2] = cubo->faces[4][0][2];
	cubo->faces[4][0][2] = aux;

	aux = cubo->faces[4][0][1];
	cubo->faces[4][0][1] = cubo->faces[4][1][0];
	cubo->faces[4][1][0] = cubo->faces[4][2][1];
	cubo->faces[4][2][1] = cubo->faces[4][1][2];
	cubo->faces[4][1][2] = aux;

	if (n == 2)
	{
		n = n - 1;
		CUB_giraFrenteEsquerda(cubo, n);
	}
	if (cubo->faces[2][2][0] == cubo->faces[1][2][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira topo esquerda
*  ****/

CUB_tpCondRet CUB_giraTopoDireita(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = aux;

	aux = cubo->faces[0][0][1];
	cubo->faces[0][0][1] = cubo->faces[0][1][0];
	cubo->faces[0][1][0] = cubo->faces[0][2][1];
	cubo->faces[0][2][1] = cubo->faces[0][1][2];
	cubo->faces[0][1][2] = aux;

	aux = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = aux;

	aux = cubo->faces[1][0][1];
	cubo->faces[1][0][1] = cubo->faces[5][2][1];
	cubo->faces[5][2][1] = cubo->faces[3][0][1];
	cubo->faces[3][0][1] = cubo->faces[2][0][1];
	cubo->faces[2][0][1] = aux;

	aux = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = aux;

	if (n == 2) {
		n = n - 1;
		CUB_giraTopoDireita(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[0][2][0])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Gira topo direita
*  ****/

CUB_tpCondRet CUB_giraTopoEsquerda(CUB_tpCubo *cubo, int n) {

	int aux;
	if (cubo == NULL)
		return CUB_CondRetFaltouMemoria;

	aux = cubo->faces[0][0][0];
	cubo->faces[0][0][0] = cubo->faces[0][0][2];
	cubo->faces[0][0][2] = cubo->faces[0][2][2];
	cubo->faces[0][2][2] = cubo->faces[0][2][0];
	cubo->faces[0][2][0] = aux;

	aux = cubo->faces[0][0][1];
	cubo->faces[0][0][1] = cubo->faces[0][1][2];
	cubo->faces[0][1][2] = cubo->faces[0][2][1];
	cubo->faces[0][2][1] = cubo->faces[0][1][0];
	cubo->faces[0][1][0] = aux;

	aux = cubo->faces[1][0][0];
	cubo->faces[1][0][0] = cubo->faces[2][0][0];
	cubo->faces[2][0][0] = cubo->faces[3][0][0];
	cubo->faces[3][0][0] = cubo->faces[5][2][2];
	cubo->faces[5][2][2] = aux;

	aux = cubo->faces[1][0][1];
	cubo->faces[1][0][1] = cubo->faces[2][0][1];
	cubo->faces[2][0][1] = cubo->faces[3][0][1];
	cubo->faces[3][0][1] = cubo->faces[5][2][1];
	cubo->faces[5][2][1] = aux;

	aux = cubo->faces[1][0][2];
	cubo->faces[1][0][2] = cubo->faces[2][0][2];
	cubo->faces[2][0][2] = cubo->faces[3][0][2];
	cubo->faces[3][0][2] = cubo->faces[5][2][0];
	cubo->faces[5][2][0] = aux;

	if (n == 2) {
		n = n - 1;
		CUB_giraTopoEsquerda(cubo, n);
	}
	if (cubo->faces[0][0][0] == cubo->faces[0][0][2])
		return CUB_CondRetOK;

	else
		return CUB_CondRetErro;
}

/***********************************************************************
*
*  $FC Função: CUB Criar cubo
*  ****/

CUB_tpCondRet CUB_criaCubo(CUB_tpCubo **cubo)
{
	*cubo = (CUB_tpCubo *)malloc(sizeof(CUB_tpCubo));
	if (cubo == NULL)
	{
		return CUB_CondRetFaltouMemoria;
	} /* if *  ****/
	return CUB_CondRetOK;
}

/***********************************************************************
*
*  $FC Função: CUB Criar Peça
*  ****/

CUB_tpPeca *CUB_criaPeca(void)
{
	CUB_tpPeca *peca;
	peca = (CUB_tpPeca*)malloc(sizeof(CUB_tpPeca));

	if (peca == NULL)
	{
		return;
	}
	peca->C = 9;
	peca->E = 9;
	peca->F = 9;
	peca->D = 9;
	peca->B = 9;
	peca->T = 9;

	return peca;
}

/***********************************************************************
*
*  $FC Função: CUB Libera cubo
*  ****/

CUB_tpCondRet CUB_liberaCubo(CUB_tpCubo *cubo)
{
	if (cubo == NULL)
	{
		return CUB_CondRetOK;
	}
	free(cubo);
	return CUB_CondRetOK;
}

/***********************************************************************
*
*  $FC Função: CUB Libera Peca
*  ****/

void CUB_liberaPeca(CUB_tpPeca *peca)
{
	if (peca == NULL)
	{
		return;
	}
	free(peca);
}

/***********************************************************************
*
*  $FC Função: CUB Busca Peca
*  ****/

CUB_tpCondRet CUB_buscaPeca(CUB_tpCubo *cubo, int cores[], int numCores, CUB_tpPeca *Peca) {
	int i, j = 2, k = 3;
	int cords[12];
	if (cubo == NULL)
	{
		printf("Erro! Cubo inválido.");
		return CUB_CondRetPecaNaoExiste;
	}
	if (numCores == 2)
	{
		if (cores[0] == cores[1])
		{
			printf("Erro! Peça inexistente!.");
			return CUB_CondRetPecaNaoExiste;
		}
	}
	if (numCores == 3)
	{
		if (cores[0] == cores[1] || cores[1] == cores[2] || cores[0] == cores[2])
		{
			printf("Erro! Peca inexistente!.");
			return CUB_CondRetPecaNaoExiste;
		}
	}
	pegaCoordenadas(cubo, cores, cords, numCores);
	preencheCores(Peca, cords, numCores);
	if (numCores == 2)
	{
		j = 2;
		k = 3;
		for (i = 1; i < 6; i = i + 4)
		{
			if (cords[i] == 0 && cords[j] == 1 && cords[k] == 0)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 2;
			}
			else if (cords[i] == 0 && cords[j] == 0 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 2;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 0 && cords[j] == 2 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 2;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 0 && cords[j] == 1 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 2;
			}
			else if (cords[i] == 1 && cords[j] == 1 && cords[k] == 0)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 2;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 1 && cords[j] == 2 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 2;
			}
			else if (cords[i] == 1 && cords[j] == 1 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 2;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 2 && cords[j] == 2 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 2;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 2 && cords[j] == 1 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 2;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 3 && cords[j] == 2 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 2;
			}
			else if (cords[i] == 3 && cords[j] == 1 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 2;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 4 && cords[j] == 2 && cords[k] == 1)
			{
				Peca->coordPeca[0] = 2;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 3;
			}
			j = j + 4;
			k = k + 4;
		}
	}
	if (numCores == 3)
	{
		for (i = 1; i < 10; i = i + 4)
		{
			if (cords[i] == 0 && cords[j] == 0 && cords[k] == 0)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 0 && cords[j] == 2 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 0 && cords[j] == 0 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;

				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 0 && cords[j] == 2 && cords[k] == 0)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 3;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 1 && cords[j] == 2 && cords[k] == 0)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 3;
			}
			else if (cords[i] == 1 && cords[j] == 2 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 1;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 2 && cords[j] == 2 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 1;
			}
			else if (cords[i] == 3 && cords[j] == 2 && cords[k] == 2)
			{
				Peca->coordPeca[0] = 3;
				Peca->coordPeca[1] = 1;
				Peca->coordPeca[2] = 3;
			}
			j = j + 4;
			k = k + 4;
		}
	}
	return CUB_CondRetOK;
}

/*****  Código das funções encapsuladas no módulo  *****  ****/
/***********************************************************************
*
*  $FC Função: CUB Preenche Cores
*  ****/

void preencheCores(CUB_tpPeca *peca, int cords[], int numCores) {
	int x = 1, y = 0, aux = 0;
	peca->C = 9;
	peca->E = 9;
	peca->F = 9;
	peca->D = 9;
	peca->B = 9;
	peca->T = 9;

	if (numCores == 2)
	{
		for (x = 1; x < 6; x = x + 4)
		{
			if (cords[x] == 0)
			{
				peca->C = cords[y];
				aux++;
			}

			if (cords[x] == 1)
			{
				peca->E = cords[y];
				aux++;
			}
			if (cords[x] == 2)
			{
				peca->F = cords[y];
				aux++;
			}
			if (cords[x] == 3)
			{
				peca->D = cords[y];
				aux++;
			}
			if (cords[x] == 4)
			{
				peca->B = cords[y];
				aux++;
			}
			if (cords[x] == 5)
			{
				peca->T = cords[y];
				aux++;
			}
			if (aux == 2)
			{
				return;
			}
			y = y + 4;
		}
	}
	if (numCores == 3)
	{
		for (x = 1; x < 10; x = x + 4)
		{
			if (cords[x] == 0)
			{
				peca->C = cords[y];
				aux++;
			}

			if (cords[x] == 1)
			{
				peca->E = cords[y];
				aux++;
			}
			if (cords[x] == 2)
			{
				peca->F = cords[y];
				aux++;
			}
			if (cords[x] == 3)
			{
				peca->D = cords[y];
				aux++;
			}
			if (cords[x] == 4)
			{
				peca->B = cords[y];
				aux++;
			}
			if (cords[x] == 5)
			{
				peca->T = cords[y];
				aux++;
			}
			if (aux == 3)
			{
				return;
			}
			y = y + 4;
		}
	}
}

/***********************************************************************
*
*  $FC Função: CUB Pega Coordenadas
*  ****  ****/

void pegaCoordenadas(CUB_tpCubo *cubo, int cores[], int cords[], int numCores)
{
	int i, j, k, aux, aux2;
	for (aux = 0; aux < numCores - 1; aux++)
	{
		for (aux2 = 0; aux2 < numCores; aux2++)
		{
			if ((cores[aux] == 1 && cores[aux2] == 5) || (cores[aux] == 2 && cores[aux2] == 4) || (cores[aux] == 3 && cores[aux2] == 6))
			{
				printf("Erro! Peca inexistente!");
				return;
			}
		}
	}
	if (numCores == 2)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (cubo->faces[0][0][1] == cores[i] && cubo->faces[5][2][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 0;
					cords[2] = 0;
					cords[3] = 1;
					cords[4] = cores[j];
					cords[5] = 5;
					cords[6] = 2;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[0][1][0] == cores[i] && cubo->faces[1][0][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 0;
					cords[2] = 1;
					cords[3] = 0;
					cords[4] = cores[j];
					cords[5] = 1;
					cords[6] = 0;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[0][2][1] == cores[i] && cubo->faces[2][0][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 0;
					cords[2] = 2;
					cords[3] = 1;
					cords[4] = cores[j];
					cords[5] = 2;
					cords[6] = 0;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[0][1][2] == cores[i] && cubo->faces[3][0][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 0;
					cords[2] = 1;
					cords[3] = 2;
					cords[4] = cores[j];
					cords[5] = 3;
					cords[6] = 0;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[2][1][0] == cores[i] && cubo->faces[1][1][2] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 2;
					cords[2] = 1;
					cords[3] = 0;
					cords[4] = cores[j];
					cords[5] = 1;
					cords[6] = 1;
					cords[7] = 2;
					return;
				}
				else if (cubo->faces[2][1][2] == cores[i] && cubo->faces[3][0][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 2;
					cords[2] = 1;
					cords[3] = 2;
					cords[4] = cores[j];
					cords[5] = 3;
					cords[6] = 0;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[1][1][0] == cores[i] && cubo->faces[5][1][0] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 1;
					cords[2] = 1;
					cords[3] = 0;
					cords[4] = cores[j];
					cords[5] = 5;
					cords[6] = 1;
					cords[7] = 0;
					return;
				}
				else if (cubo->faces[3][1][2] == cores[i] && cubo->faces[5][1][2] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 3;
					cords[2] = 1;
					cords[3] = 2;
					cords[4] = cores[j];
					cords[5] = 5;
					cords[6] = 1;
					cords[7] = 2;
					return;
				}
				else if (cubo->faces[4][0][1] == cores[i] && cubo->faces[2][2][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 4;
					cords[2] = 0;
					cords[3] = 1;
					cords[4] = cores[j];
					cords[5] = 2;
					cords[6] = 2;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[4][1][0] == cores[i] && cubo->faces[1][2][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 4;
					cords[2] = 1;
					cords[3] = 0;
					cords[4] = cores[j];
					cords[5] = 1;
					cords[6] = 2;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[4][1][2] == cores[i] && cubo->faces[3][2][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 4;
					cords[2] = 1;
					cords[3] = 2;
					cords[4] = cores[j];
					cords[5] = 3;
					cords[6] = 2;
					cords[7] = 1;
					return;
				}
				else if (cubo->faces[4][2][1] == cores[i] && cubo->faces[5][0][1] == cores[j])
				{
					cords[0] = cores[i];
					cords[1] = 4;
					cords[2] = 2;
					cords[3] = 1;
					cords[4] = cores[j];
					cords[5] = 5;
					cords[6] = 0;
					cords[7] = 1;
					return;
				}
			}
		}
	}
	else if (numCores == 3)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					if (i == j || j == k || i == k)
					{
						continue;
					}
					if (cubo->faces[0][0][0] == cores[i] && cubo->faces[5][2][0] == cores[j] && cubo->faces[1][0][0] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 0;
						cords[2] = 0;
						cords[3] = 0;
						cords[4] = cores[j];
						cords[5] = 5;
						cords[6] = 2;
						cords[7] = 0;
						cords[8] = cores[k];
						cords[9] = 1;
						cords[10] = 0;
						cords[11] = 0;
						return;
					}
					else if (cubo->faces[0][0][2] == cores[i] && cubo->faces[5][0][0] == cores[j] && cubo->faces[3][0][2] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 0;
						cords[2] = 0;
						cords[3] = 2;
						cords[4] = cores[j];
						cords[5] = 5;
						cords[6] = 0;
						cords[7] = 0;
						cords[8] = cores[k];
						cords[9] = 3;
						cords[10] = 0;
						cords[11] = 2;
						return;
					}
					else if (cubo->faces[0][2][0] == cores[i] && cubo->faces[2][0][0] == cores[j] && cubo->faces[1][0][2] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 0;
						cords[2] = 2;
						cords[3] = 0;
						cords[4] = cores[j];
						cords[5] = 2;
						cords[6] = 0;
						cords[7] = 0;
						cords[8] = cores[k];
						cords[9] = 1;
						cords[10] = 0;
						cords[11] = 2;
						return;
					}
					else if (cubo->faces[0][2][2] == cores[i] && cubo->faces[2][0][2] == cores[j] && cubo->faces[3][0][0] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 0;
						cords[2] = 2;
						cords[3] = 2;
						cords[4] = cores[j];
						cords[5] = 2;
						cords[6] = 0;
						cords[7] = 2;
						cords[8] = cores[k];
						cords[9] = 3;
						cords[10] = 0;
						cords[11] = 0;
						return;
					}
					else if (cubo->faces[4][0][0] == cores[i] && cubo->faces[2][2][0] == cores[j] && cubo->faces[1][2][2] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 4;
						cords[2] = 0;
						cords[3] = 0;
						cords[4] = cores[j];
						cords[5] = 2;
						cords[6] = 2;
						cords[7] = 0;
						cords[8] = cores[k];
						cords[9] = 1;
						cords[10] = 2;
						cords[11] = 2;
						return;
					}
					else if (cubo->faces[4][0][2] == cores[i] && cubo->faces[2][2][2] == cores[j] && cubo->faces[3][2][0] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 4;
						cords[2] = 0;
						cords[3] = 2;
						cords[4] = cores[j];
						cords[5] = 2;
						cords[6] = 2;
						cords[7] = 2;
						cords[8] = cores[k];
						cords[9] = 3;
						cords[10] = 2;
						cords[11] = 0;
						return;
					}
					else if (cubo->faces[4][2][0] == cores[i] && cubo->faces[5][0][0] == cores[j] && cubo->faces[1][2][0] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 4;
						cords[2] = 2;
						cords[3] = 0;
						cords[4] = cores[j];
						cords[5] = 5;
						cords[6] = 0;
						cords[7] = 0;
						cords[8] = cores[k];
						cords[9] = 1;
						cords[10] = 2;
						cords[11] = 0;
						return;
					}
					else if (cubo->faces[4][2][2] == cores[i] && cubo->faces[5][0][2] == cores[j] && cubo->faces[3][2][2] == cores[k])
					{
						cords[0] = cores[i];
						cords[1] = 4;
						cords[2] = 2;
						cords[3] = 2;
						cords[4] = cores[j];
						cords[5] = 5;
						cords[6] = 0;
						cords[7] = 2;
						cords[8] = cores[k];
						cords[9] = 3;
						cords[10] = 2;
						cords[11] = 2;
						return;
					}
				}
			}
		}
	}
	else
		return;
}

CUB_tpCondRet CUB_ChecarCorDaFace(int * pCor, CUB_tpCubo * pCubo, int face, int linha, int coluna) //Função para checar a cor da face em questão
{
	CUB_tpCubo *cubo;
	cubo = pCubo;

	if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2 && face >= 0 && face <= 5) {
		*pCor = cubo->faces[face][linha][coluna];
		return CUB_CondRetOK; //Retorna o sucesso da função
	}

	return CUB_CondRetPecaNaoExiste;
}