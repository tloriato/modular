/******************************************************************************
*
*  $MCD M�dulo de defini��o: C2C		Segunda Camada
*
*  Arquivo gerado:              2camada.c
*  Letras identificadoras:      C2C
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  CJ - Ana Carolina Junger
*			 TS - Tiago Sim�es	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*
*  $HA Hist�rico de evolu��o:
*	Vers�oo		Autor		Data		Observa��es
*	3.0			TSMMABHL	02/06/18	C�digo refeito para melhor atender o m�dulo do cubo 1	
*	2.0			CJTSMMABHL	30/04/18	C�digo refatorado
*	0.1			CJTSMMABHL	20/04/18	In�cio do c�digo
*  $ED Descri��oo do m�dulo
*		Este m�dulo visa resolver a 2a camada do cubo m�gico usando o m�todo de 
*		iniciante (m�todo das camadas) tendo o m�dulo do cubo 1 como base.
******************************************************************************/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "2camada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55

#define CIMA 0
#define ESQUERDA 1
#define FRENTE 2
#define DIREITA 3
#define BAIXO 4
#define TRASEIRA 5

#define BRANCO 0
#define LARANJA 1
#define VERDE 2
#define VERMELHO 3
#define AMARELO 4
#define AZUL 5

/**************************
*  $FC Fun��o: C2C Descobre cores e algoritmo
*
*  $ED Descri��o da fun��o
*		Descobre quais as cores da pe�a que ser� posta na posi��o da aresta 
*		� direita da face atual.
*		
*  $EPar�metros
*		$P	face = rescebe o n�mero referente � face do cubo a ser trabalhada.
*       $P	coresPeca = um vetor vazio de 2 inteiros que ser� usado para armazenar
*			as cores da pe�a.
*		$P	algDir e algEsq = strings vazias que armazenar�o o algoritmo de jogar a
*			pe�a para direita ou esquerda (respectivamente) referentes � face atual.
*       
*	$FV Valor retornado
*		0 - sucesso
*
*	$EAE Assertiva de Entrada esperadas
*		- face � um n�mero de 0 a 5
*		- coresPeca tem pelo menos espa�o para 2 inteiros
*
*	Assertivas de Saida
*		- coresPeca tem as duas cores da pe�a procurada
*		- algDir e algEsq t�m os algoritmos corretos em rela��o � face atual
**************************/
int C2C_descobreCoresEalg (int face, int *coresPeca, char *algDir, char *algEsq)
{
	switch (face) {
		case(ESQUERDA): {
			coresPeca[0] = ESQUERDA;
			coresPeca[1] = FRENTE;

			strcpy(algDir, "D' F' D' F D L D L'");
			strcpy(algEsq,  "D B D B' D' L' D' L");
			break;
		}
		case(FRENTE): {
			coresPeca[0] = FRENTE;
			coresPeca[1] = DIREITA;

			strcpy(algDir, "D' R' D' R D F D F'");
			strcpy(algEsq,  "D L D L' D' F' D' F");
			break;
		}
		case(DIREITA): {
			coresPeca[0] = DIREITA;
			coresPeca[1] = TRASEIRA;
				
			strcpy(algDir,  "D' B' D' B D R D R'");			
			strcpy(algEsq,  "D F D F' D' R' D' R");

			break;
		}
		//Por quest�o de conveni�ncia, nesse caso, consideraremos a face traseira como 4 ao inves de 5
		case(4): {
		//Porem, no coresPeca n�o podemos fazer isso porque precisamos da cor igual � dos defines quando usarmos a buscaPeca
			coresPeca[0] = TRASEIRA;
			coresPeca[1] = ESQUERDA;

			strcpy(algDir,  "D' L' D' L D B D B'");
			strcpy(algEsq,  "D R D R' D' B' D' B");
			break;
		}
		default: {
			return -1;
		}
	}
	return 0;
}

/**************************
*  $FC Fun��o: C2C  executaAlgoritmo
*
*  $ED Descri��o da fun��o
*    Executa algoritmo recebido pela string
*		
*  $EPar�metros
*		$P cubo = estrutura CUB_tppCUBO populada
*       $P algoritmo = string de no máximo ALG elementos com comandos no estilo: "U R U' R' U' F' U U F F"
*  $FV Valor retornado
*       0 - sucesso
*	Assertiva de Entrada
*		- cubo != NULL
*		- algoritmo != ""
*
*	Assertivas de Saida
*		- Executou algoritmo passado
**************************/
int C2C_executaAlgoritmo(CUB_tppCubo cubo, char *algoritmo, char *instrucoes)
{
	int i = 0;
	char comandos[ALG];

	//Para uniformizar o string, primeiro concatenamos um espa�o entre os dois strings.
	strcat(instrucoes, " ");
	strcat(instrucoes, algoritmo);

	memset(comandos, '\0', sizeof(comandos));
	strcpy(comandos, algoritmo);

	while (comandos[i]) {
		if (comandos[i] == 'U') {
			if (comandos[i + 1] == '\'') {
				CUB_giraTopoDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraTopoEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}

		else if (comandos[i] == 'B') {
			if (comandos[i + 1] == '\'') {
				CUB_giraTrasDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraTrasEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}

		else if (comandos[i] == 'D') {
			if (comandos[i + 1] == '\'') {
				CUB_giraBaixoEsquerda(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraBaixoDireita(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		else if (comandos[i] == 'F') {
			if (comandos[i + 1] == '\'') {
				CUB_giraFrenteEsquerda(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else{
				CUB_giraFrenteDireita(cubo, 1);
			//executa sentido horario
			i += 2;
			}
		}
		else if (comandos[i] == 'R') {
			if (comandos[i + 1] == '\'') {
				CUB_giraDireitaFrente(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraDireitaTras(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		else if (comandos[i] == 'L') {
			if (comandos[i + 1] == '\'') {
				CUB_giraEsquerdaTras(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraEsquerdaFrente(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		/*Pode ocorrer de o �ltimo elemento n�o ser anti-hor�rio, fazendo com que o i incremente em 2 
		e fique em loop na pos 19, que � um espa�o*/
		else if(comandos[i] == ' ')
			i++;
	}
	return 0;
}

/**************************
*  $FC Fun��o: C2C  resolveDireitaFace
*
*  $ED Descri��o da fun��o
*		P�e a pe�a de aresta (com as cores da face atual e da face � sua direita) correta 
*		na direita da face recebida 
*		
*  $EPar�metros
*		$P face = face do cubo a tratar
*		$P cubo = estrutura CUB_tppCUBO populada
*       
*  $FV Valor retornado
*       0 - sucesso
*	Assertiva de Entrada
*	- cubo != NULL
*	- face � um n�mero entre 0 e 5
*
*	Assertivas de Saida
*	- A face est� agora com sua pe�a de aresta da direita correta
*	
**************************/
int C2C_resolveDireitaFace(int face, CUB_tppCubo cubo, char *instrucoes)
{
	CUB_tppPeca p;
	int corNaFace, coresPeca[2], facePeca, estaNaPosCerta = 0, foiMovida = 0, numGiros;
	int usarAlgEsq = 0;
	char algDirAux[20], algEsqAux[20], algDir[20], algEsq[20];
	
	CUB_criaPeca(&p);
	//Primeiro, descobrimos a pe�a que queremos e qual algoritmo teremos que usar, dependendo da face atual:
	C2C_descobreCoresEalg(face, coresPeca, algDir, algEsq);

	//Segundo, descobrimos onde ela est�:
	CUB_buscaPeca(p, cubo, coresPeca, 2);

	//Terceiro, descobrimos se ela est� na 2a camada (a do meio). Se estiver: 
	if(p->coordPeca[1] == 2) //Est� na camada do meio (2a camada)
	{
		if(p->coordPeca[2] == 1) // na face da frente
		{
			strcpy(algDirAux, "D' R' D' R D F D F'");
			strcpy(algEsqAux,  "D L D L' D' F' D' F");

			if(p->coordPeca[0] == 3)//e na direita da face (nesse caso, a direita do cubo)
			{
				//Se um desses dois estiver errado, a pe�a est� na posi��o errada. Usamos o algoritmo para jog�-la para a 3a camada
				if(p->D != DIREITA || p->F != FRENTE)
				{
					C2C_executaAlgoritmo(cubo, algDirAux, instrucoes);
					foiMovida = 1;
				}
				//Se n�o, a pe�a est� na posi��o certa
				else
					estaNaPosCerta = 1;
			}
			else //e na esquerda da face (nesse caso, a esquerda do cubo)
			{
				//Se um desses dois estiver errado, a pe�a est� na posi��o errada. Usamos o algoritmo para jog�-la para a 3a camada
				if(p->E != ESQUERDA || p->F != FRENTE)
				{
					C2C_executaAlgoritmo(cubo, algEsqAux, instrucoes);
					foiMovida = 1;
				}
				//Se n�o, a pe�a est� na posi��o certa
				else
					estaNaPosCerta = 1;
			}
		} 
		
		else if(p->coordPeca[2] == 3) // na face de tr�s
		{
			strcpy(algDirAux,  "D' L' D' L D B D B'");
			strcpy(algEsqAux,  "D R D R' D' B' D' B");

			if(p->coordPeca[0] == 1)//e na direita da face (nesse caso, a esquerda do cubo)
			{
				//Se um desses dois estiver errado, a pe�a est� na posi��o errada. Usamos o algoritmo para jog�-la para a 3a camada
				if(p->E != ESQUERDA || p->T != TRASEIRA)
				{
					C2C_executaAlgoritmo(cubo, algDirAux, instrucoes);
					foiMovida = 1;
				}
				//Se n�o, a pe�a est� na posi��o certa
				else
					estaNaPosCerta = 1;
			}
			else //e na esquerda da face (nesse caso, a direita do cubo)
			{
				//Se um desses dois estiver errado, a pe�a est� na posi��o errada. Usamos o algoritmo para jog�-la para a 3a camada
				if(p->D != DIREITA || p->T != TRASEIRA)
				{
					C2C_executaAlgoritmo(cubo, algEsqAux, instrucoes);
					foiMovida = 1;
				}
				//Se n�o, a pe�a est� na posi��o certa
				else
					estaNaPosCerta = 1;
			}
		}
	}
	
	if(estaNaPosCerta)
	{
		CUB_liberaPeca(p);
		return 0;
	}
	//Quarto, descobrimos em qual face a pe�a est� na camada inferior (3a camada) e qual a cor da pe�a sobre essa face

	/*OBS: N�o precisamos fazer um teste para saber se a pe�a est� na terceira camada agora porque, se chegamos at� aqui (n�o caiu no caso de j� estar na posi��o correta), ela com certeza est�.
	Sabemo disso porque, o cubo estando com a primeira camada resolvida, a pe�a s� pode estar na 2a ou terceira camada. Como j� tratamos os casos da 2a camada e descobrimos que a pe�a n�o
	est� na posi��o correta (se fosse o caso, o programa j� teria retornado), a pe�a s� pode estar na 3a camada.*/
	
	//Se a pe�a foi movida, precisamos ach�-la de novo:
	if(foiMovida)
	{
		CUB_liberaPeca(p);
		CUB_criaPeca(&p);
		CUB_buscaPeca(p, cubo, coresPeca, 2);
	}

	if(p->coordPeca[0] == 1 && p->coordPeca[2] == 2) //Na face esquerda
	{
		corNaFace = p->E;
		facePeca = ESQUERDA;
	}
	else if(p->coordPeca[0] == 2 && p->coordPeca[2] == 1) //Na face frontal
	{
		corNaFace = p->F;
		facePeca = FRENTE;
	}
	else if(p->coordPeca[0] == 3 && p->coordPeca[2] == 2) //Na face direita
	{
		corNaFace = p->D;
		facePeca = DIREITA;
	}
	else if(p->coordPeca[0] == 2 && p->coordPeca[2] == 3) //Na face traseira
	{
		//Por conveni�ncia, a face TRASEIRA ser� considerada como 4.
		corNaFace = p->T;
		facePeca = 4;
	}
	
	if(corNaFace == 5) corNaFace = 4;

	//Caso a cor na face n�o seja a mesma da face atual, teremos que fazer 3 altera��es:
	if(corNaFace != face) 
	{
		//1) Usaremos a face � direita da atual para calcular a quantidade de giros
		if(face == 4) face = 1;
		else face++;

		//2) Como mudamos a face, temos que redefinir qual � o algoritmo a ser usado para ela
		C2C_descobreCoresEalg(face, coresPeca, algDir, algEsq);
		//3) Usaremos o algoritmo de jogar para esquerda ao inv�s de jogar para direita
		usarAlgEsq = 1;
	}
	numGiros = facePeca - face;
	switch(numGiros)
	{
		case(1): {
			C2C_executaAlgoritmo(cubo, "D'", instrucoes);
			break;
		}
		case(-1): {
			C2C_executaAlgoritmo(cubo, "D", instrucoes);
			break;
		}
		//Os pr�ximos dois casos fazem essencialmente a mesma coisa, por�m, por limita��es do switch, tem que p�r os dois.
		case(2): {
			C2C_executaAlgoritmo(cubo, "D D", instrucoes);
			break;
		}
		case(-2): {
			C2C_executaAlgoritmo(cubo, "D' D'", instrucoes);
			break;
		}
		//Prox 2 casos ocorrem quando as faces envolvidas s�o a esquerda e a traseira (4-1 e 1-4)
		case(3):{
			C2C_executaAlgoritmo(cubo, "D", instrucoes);
			break;
		}
		case(-3):{
			C2C_executaAlgoritmo(cubo, "D'", instrucoes);
			break;
		}
		//Sem default porque s� h� mais o caso 0, em que o cubo n�o tem nenhuma face girada.
	}
	//Se for o caso, usaremos o algoritmo de jogar para a esquerda no lugar do da direita
	if(usarAlgEsq) C2C_executaAlgoritmo(cubo, algEsq, instrucoes);
	else C2C_executaAlgoritmo(cubo, algDir, instrucoes);

	CUB_liberaPeca(p);
	return 0;
}

/**************************
*  $FC Fun��o: C2C  resolve 2� camada
*
*  $ED Descri��o da fun��o
*		Resolve a segunda camada de um cubo m�gico com a primeira camada resovida,
*		seguindo os passos de resolu��o do m�todo de iniciantes (m�todo das camadas)
*		
*  $EPar�metros
*		$P cubo = estrutura CUB_tppCUBO populada
*		$P instrucoes = string vazio que abrigar� os comandos de giro obtidos na fun��o
*       
*  $FV Valor retornado
*       C2C_CondRetCuboVazio - O cubo recebido est� vazio
*		C2C_CondRetOK - A segunda camada foi resolvida com sucesso
*
*	Assertiva de Entrada
*	- cubo != NULL
*	- instrucoes est� vazio
*
*	Assertivas de Saida
*	- O cubo est� com a segunda camada resolvida
*	- O vetor de instru��es est� com o tamanho certo e com os comandos para resolver
*	a segunda camada para o cubo dado
*	
**************************/
C2C_tpCondRet resolve2camada (CUB_tppCubo cubo, char *instrucoes){

	if (cubo == NULL){
		return C2C_CondRetCuboVazio;
	}

	//Resolve aresta direita da esquerda:
	C2C_resolveDireitaFace(1, cubo, instrucoes);

	//Resolve aresta direita da frente:
	C2C_resolveDireitaFace(2, cubo, instrucoes);

	//Resolve aresta direita da direita:
	C2C_resolveDireitaFace(3, cubo, instrucoes);

	//Resolve aresta direita de tr�s:
	C2C_resolveDireitaFace(4, cubo, instrucoes);

	return C2C_CondRetOK;
}
