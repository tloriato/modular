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

#include "CUBO.h"

#include <stdio.h>
#include <stdlib.h>

#define NUMERODEFACES 6
#define UNIDADESPOREIXO 3

typedef struct
{
	int lados[NUMERODEFACES];
} CUB_tpPecadeCubo; //Definindo a estrutura que compoe o cubo;

typedef struct
{
	CUB_tpPecadeCubo estrutura[27]; //Definindo a estrutura do cubo com suas faces detalhadas;
} CUB_tagCUBO;

/***** Protótipos das funções encapsuladas pelos modulo*****/

static void funcaoDebugger(CUB_tagCUBO* cubo); //Documentado dentro da função;

static void matriz3DParaLinhaEColuna(int *linha, int *coluna, CUB_tpFaceDeCUBO face, int x, int y, int z); //Documentado dentro da função;

static void preencherCuboVazio(CUB_tagCUBO* recipiente, int* configuracaoInicial); //Documentado dentro da função;

static void preencherPosicao(CUB_tagCUBO* recipiente, int x, int y, int z, CUB_tpFaceDeCUBO face, int valor); //Documentado dentro da função;

static void imprimirElemento(CUB_tagCUBO* cubo, int x, int y, int z, CUB_tpFaceDeCUBO face); //Documentado dentro da função;

static CUB_tpPecadeCubo giroDePecaUnitarioEixoX(CUB_tpPecadeCubo peca); //Documentado dentro da função
static CUB_tpPecadeCubo giroDePecaUnitarioEixoY(CUB_tpPecadeCubo peca); //Documentado dentro da função
static CUB_tpPecadeCubo giroDePecaUnitarioEixoZ(CUB_tpPecadeCubo peca); //Documentado dentro da função

static int calcularGirosUnitarios(int numeroDeGiros, CUB_tpFaceDeCUBO face); //Documentado dentro da função

static int geraIndice(int x, int y, int z); //Documentado dentro da função

static int geraIndiceEmBuffer(int a, int b); //Documentado dentro da função

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
 *
 *  Funcão: CUB Criar cubo
 *  
 ***************************************************************************/

CUB_tpCondRet CUB_CriarCUBO(CUB_tppCUBO* pCubo, int* ConfiguracaoInicial) //Função para criação do cubo
{
	CUB_tagCUBO* candidato; //Variavel auxiliar para criação da estrutura do cubo
	candidato = (CUB_tagCUBO*)malloc(sizeof(CUB_tagCUBO));
	if (candidato == NULL)
		return CUB_CondRetFaltouMemoria; //Retorna em caso de falta de espaço na memória
	preencherCuboVazio(candidato, ConfiguracaoInicial);
	*pCubo = candidato;
	return CUB_CondRetOK; //Retorna em caso de inserção bem sucedida da estrutura do cubo na memória 
}

/***************************************************************************
*
*  Funcão: CUB destroi cubo
*
***************************************************************************/

CUB_tpCondRet CUB_DestruirCUBO(CUB_tppCUBO pCubo) //Função para destruir a estrutura do cubo
{
	free(pCubo);
	return CUB_CondRetOK; //Retorna positivamenta a destruição do cubo
}

/***************************************************************************
*
*  Funcão: CUB girar face do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_GirarFace(CUB_tppCUBO pCubo, CUB_tpFaceDeCUBO faceGirada, int numGiros, char sentido) //Função para girar as faces do cubo
{

	CUB_tagCUBO* cubo = pCubo;
	CUB_tpPecadeCubo peca;
	CUB_tpPecadeCubo buffer[9];
	int x, y, z;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo inserido seja inválido e/ou inexistente

	numGiros = (sentido == 'a' || sentido == 'A') ? -abs(numGiros) : abs(numGiros);

	if (faceGirada > CUB_faceInferior || faceGirada < CUB_faceSuperior)
		return CUB_CondRetFaceInvalida; //Retorna caso a face especificada seja inválida e/ou inexistente

	if (faceGirada == CUB_faceFrontal || faceGirada == CUB_faceTraseira) //Caso o giro seja relacionado a face frontal ou face traseira
	{
		z = faceGirada == CUB_faceTraseira ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (x = -1; x <= 1; x++)
			{
				for (y = -1; y <= 1; y++)
				{
					peca = giroDePecaUnitarioEixoZ(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(x, y)] = peca; //Gira a peça especificada e atualiza o indice junto
				}
			}
			for (x = -1; x <= 1; x++)
				for (y = -1; y <= 1; y++)
					cubo->estrutura[geraIndice(y, -x, z)] = buffer[geraIndiceEmBuffer(x, y)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	if (faceGirada == CUB_faceSuperior || faceGirada == CUB_faceInferior) //Caso o giro seja relacionado a face superior ou face inferior
	{
		y = faceGirada == CUB_faceInferior ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (x = -1; x <= 1; x++)
			{
				for (z = -1; z <= 1; z++)
				{
					peca = giroDePecaUnitarioEixoY(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(x, z)] = peca; //Gira a peça especificada e atualiza o indice junto
				}
			}
			for (x = -1; x <= 1; x++)
				for (z = -1; z <= 1; z++)
					cubo->estrutura[geraIndice(-z, y, x)] = buffer[geraIndiceEmBuffer(x, z)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	if (faceGirada == CUB_faceDireita || faceGirada == CUB_faceEsquerda) //Caso o giro seja relacionado a face esquerda ou face direita
	{
		x = faceGirada == CUB_faceEsquerda ? -1 : 1;
		numGiros = calcularGirosUnitarios(numGiros, faceGirada);
		while (numGiros--)
		{
			for (y = -1; y <= 1; y++)
			{
				for (z = -1; z <= 1; z++)
				{
					peca = giroDePecaUnitarioEixoX(cubo->estrutura[geraIndice(x, y, z)]);
					buffer[geraIndiceEmBuffer(y, z)] = peca; //Gira a peça especificada e atualiza o indice junto
				}
			}
			for (y = -1; y <= 1; y++)
				for (z = -1; z <= 1; z++)
					cubo->estrutura[geraIndice(x, z, -y)] = buffer[geraIndiceEmBuffer(y, z)]; //Passa o indice gerado para estrutura do cubo
		}
	}

	return CUB_CondRetOK; //Retorna que o cubo foi girado com sucesso
}

/***************************************************************************
*
*  Funcão: CUB checar cor da face do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_ChecarCorDaFace(int * pCor, CUB_tppCUBO pCubo, int linha, int coluna, CUB_tpFaceDeCUBO faceInspecionada) //Função para checar a cor da face em questão
{
	CUB_tagCUBO* cubo = pCubo;
	int x, y, z;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inválido e/ou inexistente

	if (linha < 0 || linha >= UNIDADESPOREIXO)
		return CUB_CondRetCoordenadasInvalidas; //Retorna caso as coordenadas especificadas sejam inválidas
	if (coluna < 0 || coluna >= UNIDADESPOREIXO)
		return CUB_CondRetCoordenadasInvalidas; //Retorna caso as coordenadas especificadas sejam inválidas
	switch (faceInspecionada)
	{
	case(CUB_faceSuperior): //Caso seja a face superior
		x = coluna - 1;
		y = 1;
		z = linha - 1;
		break;
	case(CUB_faceFrontal): //Caso seja a face frontal
		x = coluna - 1;
		y = 1 - linha;
		z = 1;
		break;
	case(CUB_faceDireita): //Caso seja a face da direita
		x = 1;
		y = 1 - linha;
		z = 1 - coluna;
		break;
	case(CUB_faceTraseira): //Caso seja a face traseira
		x = 1 - coluna;
		y = 1 - linha;
		z = -1;
		break;
	case(CUB_faceEsquerda): //Caso seja a face da esquerda
		x = -1;
		y = 1 - linha;
		z = coluna - 1;
		break;
	case(CUB_faceInferior): //Caso seja a face inferior
		x = coluna - 1;
		y = -1;
		z = 1 - linha;
		break;
	default:
		return CUB_CondRetFaceInvalida; //Retorna em caso da face especificada ser inválida
	}
	*pCor = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada];
	return CUB_CondRetOK; //Retorna o sucesso da função
}

/***************************************************************************
*
*  Funcão: CUB Encontrar posição de aresta do cubo
*
***************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeAresta(CUB_tpFaceDeCUBO * pFace, int * pLinha, int * pColuna, CUB_tppCUBO pCubo, int cor1, int cor2) //Função que verifica a peça na aresta
{
	int x, y, z;
	CUB_tpFaceDeCUBO valorNaFace1, valorNaFace2, faceInspecionada1, faceInspecionada2;
	CUB_tagCUBO* cubo = pCubo;

	if (cubo == NULL)
		return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inválido e/ou inexistente

	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			for (z = -1; z <= 1; z++)
			{
				if (abs(x) + abs(y) + abs(z) == 2)
				{
					if (x < 0)
						faceInspecionada1 = CUB_faceEsquerda;
					else if (x > 0)
						faceInspecionada1 = CUB_faceDireita;
					else if (y < 0)
						faceInspecionada1 = CUB_faceInferior;
					else
						faceInspecionada1 = CUB_faceSuperior;

					if (z < 0)
						faceInspecionada2 = CUB_faceTraseira;
					else if (z > 0)
						faceInspecionada2 = CUB_faceFrontal;
					else if (y < 0)
						faceInspecionada2 = CUB_faceInferior;
					else
						faceInspecionada2 = CUB_faceSuperior;

					valorNaFace1 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada1];
					valorNaFace2 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada2];
					if (valorNaFace1 == cor1 && valorNaFace2 == cor2)
					{
						*pFace = faceInspecionada1;
						matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada1, x, y, z);
						return CUB_CondRetOK; //Retorna caso a peça foi encontrada com sucesso
					}
					else if (valorNaFace1 == cor2 && valorNaFace2 == cor1)
					{
						*pFace = faceInspecionada2;
						matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada2, x, y, z);
						return CUB_CondRetOK; //Retorna caso a peça foi encontrada com sucesso
					}
				}
			}
		}
	}
	return CUB_CondRetCorInvalida; //Retorna caso a cor especificada seja inválida
}

/***************************************************************************
*
*  Funcão: CUB encontrar posição da peça da quina
*
***************************************************************************/

CUB_tpCondRet CUB_EncontrarPosicaoDePecaDeQuina(CUB_tpFaceDeCUBO * pFace, int * pLinha, int * pColuna, CUB_tppCUBO pCubo, int cor1, int cor2, int cor3) //Função para busca de peça de quina de cubo
{
	int x, y, z, valorNaFace1, valorNaFace2, valorNaFace3;
	CUB_tpFaceDeCUBO faceInspecionada1, faceInspecionada2, faceInspecionada3;
	CUB_tagCUBO* cubo = pCubo;
	faceInspecionada1 = CUB_faceEsquerda;

	if (cubo == NULL)
		return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inválido


	for (x = -1; x <= 1; x = x + 2)
	{
		faceInspecionada2 = CUB_faceInferior;
		for (y = -1; y <= 1; y = y + 2)
		{
			faceInspecionada3 = CUB_faceTraseira;
			for (z = -1; z <= 1; z = z + 2)
			{
				valorNaFace1 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada1];
				valorNaFace2 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada2];
				valorNaFace3 = cubo->estrutura[geraIndice(x, y, z)].lados[faceInspecionada3];


				if (valorNaFace1 == cor1 && conjuntosSaoEquivalentes(valorNaFace2, valorNaFace3, cor2, cor3))
				{
					*pFace = faceInspecionada1;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada1, x, y, z);
					return CUB_CondRetOK; //Retorna caso a peça de quina seja encontrada com sucesso
				}
				else if (valorNaFace2 == cor1 && conjuntosSaoEquivalentes(valorNaFace1, valorNaFace3, cor2, cor3))
				{
					*pFace = faceInspecionada2;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada2, x, y, z);
					return CUB_CondRetOK; //Retorna caso a peça de quina seja encontrada com sucesso
				}
				else if (valorNaFace3 == cor1 && conjuntosSaoEquivalentes(valorNaFace1, valorNaFace2, cor2, cor3))
				{
					*pFace = faceInspecionada3;
					matriz3DParaLinhaEColuna(pLinha, pColuna, faceInspecionada3, x, y, z);
					return CUB_CondRetOK; //Retorna caso a peça de quina seja encontrada com sucesso
				}

				faceInspecionada3 = CUB_faceFrontal;
			}
			faceInspecionada2 = CUB_faceSuperior;
		}
		faceInspecionada1 = CUB_faceDireita;
	}
	return CUB_CondRetCorInvalida; //Retorna caso a cor requisitada seja inválida
}

/***************************************************************************
*
*  Funcão: CUB exibir o cubo
*
***************************************************************************/

CUB_tpCondRet CUB_ExibirCUBO(CUB_tppCUBO pCubo) //Função que exibe o cubo em seu estado atual
{
	int x, y, z;
	CUB_tagCUBO* cubo = pCubo;

	if (pCubo == NULL) return CUB_CondRetCuboInvalido; //Retorna caso o cubo seja inválido

													   // Printando Face Superior
	for (z = -1; z <= 1; z++)
	{
		printf("\t\t\t");
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, 1, z, CUB_faceSuperior);
		printf("\n");
	}
	//Printando linha a linha as diferentes faces intermediarias
	for (y = 1; y >= -1; y--)
	{
		for (z = -1; z <= 1; z++)
			imprimirElemento(cubo, -1, y, z, CUB_faceEsquerda);
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, y, 1, CUB_faceFrontal);
		for (z = -1; z <= 1; z++)
			imprimirElemento(cubo, 1, y, -z, CUB_faceDireita);
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, -x, y, -1, CUB_faceTraseira);
		printf("\n");
	}
	//Printando a face Inferior
	for (z = -1; z <= 1; z++)
	{
		printf("\t\t\t");
		for (x = -1; x <= 1; x++)
			imprimirElemento(cubo, x, -1, -z, CUB_faceInferior);
		printf("\n");
	}

	return CUB_CondRetOK; //Retorna caso a exibição do cubo tenha sido realizada com êxito
}

/*****  Código das funções encapsuladas no módulo  *****/

/***************************************************************************
*
*  Funcão: CUB conjunto sao equivalentes
*
***************************************************************************/

int conjuntosSaoEquivalentes(int elementoA1, int elementoA2, int elementoB1, int elementoB2) //Função que determina se conjuntos são ou não equivalentes
{
	if ((elementoA1 == elementoB1 && elementoA2 == elementoB2)
		|| (elementoA1 == elementoB2 && elementoA2 == elementoB1))
		return 1; //Retorna caso os conjuntos sejam equivalentes
	return 0; //Retorna caso não haja conjuntos equivalentes
}

/***************************************************************************
*
*  Funcão: CUB calcular giros unitarios
*
***************************************************************************/

int calcularGirosUnitarios(int numeroDeGiros, CUB_tpFaceDeCUBO face) //Função de cálculo de giros unitários a serem realizados
{
	// Primeiramente são eliminadas as redundâncias dos giros de 360°
	int equivalente = numeroDeGiros % 4;
	// Em seguida é necessário adequar os giros em relação à face
	if (face == CUB_faceTraseira || face == CUB_faceEsquerda || face == CUB_faceInferior)
		equivalente = 4 - equivalente;
	return equivalente < 0 ? equivalente + 4 : equivalente; //Retorna o numero de giros unitários a serem realizados
}

/***************************************************************************
*
*  Funcão: CUB preecher cubo
*
***************************************************************************/

void preencherCuboVazio(CUB_tagCUBO* recipiente, int* configuracaoInicial) //Função de preenchimento do cubo vazio
{
	int x, y, z;
	int *chaveAtual = configuracaoInicial;
	for (z = -1; z <= 1; z++)
	{
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, 1, z, CUB_faceSuperior, *chaveAtual++);
		}
	}
	for (y = 1; y >= -1; y--)
	{
		for (z = -1; z <= 1; z++)
		{
			preencherPosicao(recipiente, -1, y, z, CUB_faceEsquerda, *chaveAtual++);
		}
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, y, 1, CUB_faceFrontal, *chaveAtual++);
		}
		for (z = -1; z <= 1; z++)
		{
			preencherPosicao(recipiente, 1, y, -z, CUB_faceDireita, *chaveAtual++);
		}
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, -x, y, -1, CUB_faceTraseira, *chaveAtual++);
		}
	}
	for (z = -1; z <= 1; z++)
	{
		for (x = -1; x <= 1; x++)
		{
			preencherPosicao(recipiente, x, -1, -z, CUB_faceInferior, *chaveAtual++);
		}
	}
} //Função apenas preenche o cubo com as cores em suas respectivas posições assim como declaradas em sua inserção

  /***************************************************************************
  *
  *  Funcão: CUB gerar o indice
  *
  ***************************************************************************/

int geraIndice(int x, int y, int z) //Função que gera o indice de localização de cada elemento do cubo
{
	// Somar 1 em cada coordenada equivale à uma transformação afim
	x = x + 1;
	y = y + 1;
	z = z + 1;
	return UNIDADESPOREIXO * (UNIDADESPOREIXO * z + y) + x; //Retorna o indice inicializado e preenchido
}

/***************************************************************************
*
*  Funcão: CUB gerar o indice para o buffer
*
***************************************************************************/

int geraIndiceEmBuffer(int a, int b) //Função que gera o índice em um 'buffer' voltado para acesso rápido
{
	a = a + 1;
	b = b + 1;
	return UNIDADESPOREIXO * b + a; //Retorna o indice inicializado no 'buffer'
}

/***************************************************************************
*
*  Funcão: CUB imprimir elemento
*
***************************************************************************/

void imprimirElemento(CUB_tagCUBO* cubo, int x, int y, int z, CUB_tpFaceDeCUBO face) //Função que imprime o elemento especificado do cubo
{
	CUB_tpPecadeCubo unidadeDeCubo = cubo->estrutura[geraIndice(x, y, z)];
	int valor = unidadeDeCubo.lados[face];
	printf("\t%d", valor < 0 ? -1 : valor);
} //Função não possui retorno, apenas realiza a impressão do elemento especificado

  /***************************************************************************
  *
  *  Funcão: CUB preencher a posição
  *
  ***************************************************************************/

void preencherPosicao(CUB_tagCUBO* recipiente, int x, int y, int z, CUB_tpFaceDeCUBO face, int valor) //Função que preenche uma posição no cubo
{
	int indice = geraIndice(x, y, z);
	recipiente->estrutura[indice].lados[face] = valor;
} //Não há retorno, apenas preenche elementos dentro da matriz do cubo

  /***************************************************************************
  *
  *  Funcão: CUB giro de peça unitario no eixo X
  *
  ***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoX(CUB_tpPecadeCubo peca) //Função de giro no eixo 'X'
{
	int aux;
	aux = peca.lados[CUB_faceSuperior];
	peca.lados[CUB_faceSuperior] = peca.lados[CUB_faceFrontal];
	peca.lados[CUB_faceFrontal] = peca.lados[CUB_faceInferior];
	peca.lados[CUB_faceInferior] = peca.lados[CUB_faceTraseira];
	peca.lados[CUB_faceTraseira] = aux;
	return peca; //Retorna a nova posição da peça no eixo 'X'
}

/***************************************************************************
*
*  Funcão: CUB giro de peça unitario no eixo Y
*
***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoY(CUB_tpPecadeCubo peca) //Função de giro no eixo 'Y'
{
	int aux;
	aux = peca.lados[CUB_faceTraseira];
	peca.lados[CUB_faceTraseira] = peca.lados[CUB_faceEsquerda];
	peca.lados[CUB_faceEsquerda] = peca.lados[CUB_faceFrontal];
	peca.lados[CUB_faceFrontal] = peca.lados[CUB_faceDireita];
	peca.lados[CUB_faceDireita] = aux;
	return peca; //Retorna a nova posição da peça no eixo 'Y'
}

/***************************************************************************
*
*  Funcão: CUB giro de peça unitario no eixo Z
*
***************************************************************************/

CUB_tpPecadeCubo giroDePecaUnitarioEixoZ(CUB_tpPecadeCubo peca) //Função de giro no eixo 'Z'
{
	int aux;
	aux = peca.lados[CUB_faceSuperior];
	peca.lados[CUB_faceSuperior] = peca.lados[CUB_faceEsquerda];
	peca.lados[CUB_faceEsquerda] = peca.lados[CUB_faceInferior];
	peca.lados[CUB_faceInferior] = peca.lados[CUB_faceDireita];
	peca.lados[CUB_faceDireita] = aux;
	return peca; //Retorna a nova posição da peça no eixo 'Z'
}

/***************************************************************************
*
*  Funcão: CUB matriz 3d para linha e coluna
*
***************************************************************************/

void matriz3DParaLinhaEColuna(int *linha, int *coluna, CUB_tpFaceDeCUBO face, int x, int y, int z) //Função de criação da matriz 3D para estrutura do cubo
{
	switch (face)
	{
	case(CUB_faceSuperior):
		*linha = z + 1;
		*coluna = x + 1;
		break;

	case(CUB_faceFrontal):
		*linha = 1 - y;
		*coluna = x + 1;
		break;

	case(CUB_faceDireita):
		*linha = 1 - y;
		*coluna = 1 - z;
		break;

	case(CUB_faceTraseira):
		*linha = 1 - y;
		*coluna = 1 - x;
		break;

	case(CUB_faceEsquerda):
		*linha = 1 - y;
		*coluna = z + 1;
		break;

	case(CUB_faceInferior):
		*linha = 1 - z;
		*coluna = x + 1;

		break;
	}
} // Realiza a criação da matriz tridimensional apenas

  /***************************************************************************
  *
  *  Funcão: CUB debugger
  *
  ***************************************************************************/

void funcaoDebugger(CUB_tagCUBO* cubo) //Função de exibição teste para o cubo
{
	int i, f;
	char* strings[] = { "CUB_faceSuperior",		"CUB_faceFrontal",		"CUB_faceDireita",
		"CUB_faceTraseira",		"CUB_faceEsquerda",		"CUB_faceInferior" };
	//string contendo todas as faces do cubo em seu atual estado;
	for (f = 0; f < 27; f++)
	{
		for (i = CUB_faceSuperior; i <= CUB_faceInferior; i++)
		{
			printf("Peca numero %d, ", f);
			printf(strings[i]);
			printf(": %d\n", cubo->estrutura[f].lados[i] < 0 ? -1 : cubo->estrutura[f].lados[i]);
		} //Função que imprime cada um dos lados do cubo, ou seja, exibe todas as faces menores com suas configurações atuais;
	}
	printf("\n\n");
} //Apenas uma função de teste para visualização das peças em suas respectivas posições no cubo
