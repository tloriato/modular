#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
#include <stdlib.h>
#include <stdio.h>

void testChecarCorDaFace(CUB_tppCUBO cubo)
{
	char perg = 'y';
	int i, j, face, cor;
	CUB_ExibirCUBO(cubo);
	while (perg == 'y')
	{
		printf("Digite Face: ");
		scanf(" %d", &face);
		printf("Digite linha: ");
		scanf(" %d", &i);
		printf("Digite coluna: ");
		scanf(" %d", &j);

		i = CUB_ChecarCorDaFace(&cor, cubo, i, j, face);
		printf("ret: %d -- Cor: %d\n", i, cor);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}
}

void testEncontrarPecaDeAresta(CUB_tppCUBO cubo)
{
	int i, j, face, cor1, cor2, ret;
	char perg = 'y';
	while (perg == 'y')
	{
		printf("Digite Cor1: ");
		scanf(" %d", &cor1);
		printf("Digite Cor2: ");
		scanf(" %d", &cor2);

		ret = CUB_EncontrarPosicaoDePecaDeAresta(&face, &i, &j, cubo, cor1, cor2);
		printf("ret: %d -- Face: %d, linha: %d, coluna:%d\n",ret, face, i, j);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}
	
}

void testEncontrarPecaDeQuina(CUB_tppCUBO cubo)
{
	int i, j, face, cor1, cor2, cor3, ret;
	char perg = 'y';
	while (perg == 'y')
	{
		printf("Digite Cor1: ");
		scanf(" %d", &cor1);
		printf("Digite Cor2: ");
		scanf(" %d", &cor2);
		printf("Digite Cor3: ");
		scanf(" %d", &cor3);

		ret = CUB_EncontrarPosicaoDePecaDeQuina(&face, &i, &j, cubo, cor1, cor2, cor3);
		printf("ret: %d -- Face: %d, linha: %d, coluna:%d\n", ret, face, i, j);
		printf("continuar? (y/n) ");
		scanf(" %c", &perg);
	}

}

void main() {

	int i;
	int config[54];
	for ( i = 0; i < 54; i++)
		config[i] = i;
	CUB_tppCUBO cubo;
	CUB_CriarCUBO(&cubo, config);
	printf("Resp: %d\n",CUB_GirarFace(cubo, CUB_faceSuperior, 5,'a'));
	CUB_ExibirCUBO(cubo);
	printf("\n");

	//testChecarCorDaFace(cubo);
	//testEncontrarPecaDeAresta(cubo);
	testEncontrarPecaDeQuina(cubo);

	system("pause");
}