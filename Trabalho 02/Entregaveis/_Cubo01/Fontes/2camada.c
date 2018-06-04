/******************************************************************************
*
*  $MCD Módulo de definição: C2C		Segunda Camada
*
*  Arquivo gerado:              2camada.c
*  Letras identificadoras:      C2C
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  CJ - Ana Carolina Junger
*			 TS - Tiago Simões	
*			 MMA - Mariela Mendonca de Andrade
*			 BHL - 	Bernardo Horner Lopes  
*
*  $HA Histórico de evolução:
*	Versãoo		Autor		Data		Observações
*	3.0			TSMMABHL	02/06/18	Código refeito para melhor atender o módulo do cubo 1	
*	2.0			CJTSMMABHL	30/04/18	Código refatorado
*	0.1			CJTSMMABHL	20/04/18	Início do código
*  $ED Descriçãoo do módulo
*		Este módulo visa resolver a 2a camada do cubo mágico usando o método de 
*		iniciante (método das camadas) tendo o módulo do cubo 1 como base.
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
*  $FC Função: C2C Descobre cores e algoritmo
*
*  $ED Descrição da função
*		Descobre quais as cores da peça que será posta na posição da aresta 
*		à direita da face atual.
*		
*  $EParâmetros
*		$P	face = rescebe o número referente à face do cubo a ser trabalhada.
*       $P	coresPeca = um vetor vazio de 2 inteiros que será usado para armazenar
*			as cores da peça.
*		$P	algDir e algEsq = strings vazias que armazenarão o algoritmo de jogar a
*			peça para direita ou esquerda (respectivamente) referentes à face atual.
*       
*	$FV Valor retornado
*		0 - sucesso
*
*	$EAE Assertiva de Entrada esperadas
*		- face é um número de 0 a 5
*		- coresPeca tem pelo menos espaço para 2 inteiros
*
*	Assertivas de Saida
*		- coresPeca tem as duas cores da peça procurada
*		- algDir e algEsq têm os algoritmos corretos em relação à face atual
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
		//Por questão de conveniência, nesse caso, consideraremos a face traseira como 4 ao inves de 5
		case(4): {
		//Porem, no coresPeca não podemos fazer isso porque precisamos da cor igual à dos defines quando usarmos a buscaPeca
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
*  $FC Função: C2C  executaAlgoritmo
*
*  $ED Descrição da função
*    Executa algoritmo recebido pela string
*		
*  $EParâmetros
*		$P cubo = estrutura CUB_tppCUBO populada
*       $P algoritmo = string de no mÃ¡ximo ALG elementos com comandos no estilo: "U R U' R' U' F' U U F F"
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

	//Para uniformizar o string, primeiro concatenamos um espaço entre os dois strings.
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
		/*Pode ocorrer de o último elemento não ser anti-horário, fazendo com que o i incremente em 2 
		e fique em loop na pos 19, que é um espaço*/
		else if(comandos[i] == ' ')
			i++;
	}
	return 0;
}

/**************************
*  $FC Função: C2C  resolveDireitaFace
*
*  $ED Descrição da função
*		Põe a peça de aresta (com as cores da face atual e da face à sua direita) correta 
*		na direita da face recebida 
*		
*  $EParâmetros
*		$P face = face do cubo a tratar
*		$P cubo = estrutura CUB_tppCUBO populada
*       
*  $FV Valor retornado
*       0 - sucesso
*	Assertiva de Entrada
*	- cubo != NULL
*	- face é um número entre 0 e 5
*
*	Assertivas de Saida
*	- A face está agora com sua peça de aresta da direita correta
*	
**************************/
int C2C_resolveDireitaFace(int face, CUB_tppCubo cubo, char *instrucoes)
{
	CUB_tppPeca p;
	int corNaFace, coresPeca[2], facePeca, estaNaPosCerta = 0, foiMovida = 0, numGiros;
	int usarAlgEsq = 0;
	char algDirAux[20], algEsqAux[20], algDir[20], algEsq[20];
	
	CUB_criaPeca(&p);
	//Primeiro, descobrimos a peça que queremos e qual algoritmo teremos que usar, dependendo da face atual:
	C2C_descobreCoresEalg(face, coresPeca, algDir, algEsq);

	//Segundo, descobrimos onde ela está:
	CUB_buscaPeca(p, cubo, coresPeca, 2);

	//Terceiro, descobrimos se ela está na 2a camada (a do meio). Se estiver: 
	if(p->coordPeca[1] == 2) //Está na camada do meio (2a camada)
	{
		if(p->coordPeca[2] == 1) // na face da frente
		{
			strcpy(algDirAux, "D' R' D' R D F D F'");
			strcpy(algEsqAux,  "D L D L' D' F' D' F");

			if(p->coordPeca[0] == 3)//e na direita da face (nesse caso, a direita do cubo)
			{
				//Se um desses dois estiver errado, a peça está na posição errada. Usamos o algoritmo para jogá-la para a 3a camada
				if(p->D != DIREITA || p->F != FRENTE)
				{
					C2C_executaAlgoritmo(cubo, algDirAux, instrucoes);
					foiMovida = 1;
				}
				//Se não, a peça está na posição certa
				else
					estaNaPosCerta = 1;
			}
			else //e na esquerda da face (nesse caso, a esquerda do cubo)
			{
				//Se um desses dois estiver errado, a peça está na posição errada. Usamos o algoritmo para jogá-la para a 3a camada
				if(p->E != ESQUERDA || p->F != FRENTE)
				{
					C2C_executaAlgoritmo(cubo, algEsqAux, instrucoes);
					foiMovida = 1;
				}
				//Se não, a peça está na posição certa
				else
					estaNaPosCerta = 1;
			}
		} 
		
		else if(p->coordPeca[2] == 3) // na face de trás
		{
			strcpy(algDirAux,  "D' L' D' L D B D B'");
			strcpy(algEsqAux,  "D R D R' D' B' D' B");

			if(p->coordPeca[0] == 1)//e na direita da face (nesse caso, a esquerda do cubo)
			{
				//Se um desses dois estiver errado, a peça está na posição errada. Usamos o algoritmo para jogá-la para a 3a camada
				if(p->E != ESQUERDA || p->T != TRASEIRA)
				{
					C2C_executaAlgoritmo(cubo, algDirAux, instrucoes);
					foiMovida = 1;
				}
				//Se não, a peça está na posição certa
				else
					estaNaPosCerta = 1;
			}
			else //e na esquerda da face (nesse caso, a direita do cubo)
			{
				//Se um desses dois estiver errado, a peça está na posição errada. Usamos o algoritmo para jogá-la para a 3a camada
				if(p->D != DIREITA || p->T != TRASEIRA)
				{
					C2C_executaAlgoritmo(cubo, algEsqAux, instrucoes);
					foiMovida = 1;
				}
				//Se não, a peça está na posição certa
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
	//Quarto, descobrimos em qual face a peça está na camada inferior (3a camada) e qual a cor da peça sobre essa face

	/*OBS: Não precisamos fazer um teste para saber se a peça está na terceira camada agora porque, se chegamos até aqui (não caiu no caso de já estar na posição correta), ela com certeza está.
	Sabemo disso porque, o cubo estando com a primeira camada resolvida, a peça só pode estar na 2a ou terceira camada. Como já tratamos os casos da 2a camada e descobrimos que a peça não
	está na posição correta (se fosse o caso, o programa já teria retornado), a peça só pode estar na 3a camada.*/
	
	//Se a peça foi movida, precisamos achá-la de novo:
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
		//Por conveniência, a face TRASEIRA será considerada como 4.
		corNaFace = p->T;
		facePeca = 4;
	}
	
	if(corNaFace == 5) corNaFace = 4;

	//Caso a cor na face não seja a mesma da face atual, teremos que fazer 3 alterações:
	if(corNaFace != face) 
	{
		//1) Usaremos a face à direita da atual para calcular a quantidade de giros
		if(face == 4) face = 1;
		else face++;

		//2) Como mudamos a face, temos que redefinir qual é o algoritmo a ser usado para ela
		C2C_descobreCoresEalg(face, coresPeca, algDir, algEsq);
		//3) Usaremos o algoritmo de jogar para esquerda ao invés de jogar para direita
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
		//Os próximos dois casos fazem essencialmente a mesma coisa, porém, por limitações do switch, tem que pôr os dois.
		case(2): {
			C2C_executaAlgoritmo(cubo, "D D", instrucoes);
			break;
		}
		case(-2): {
			C2C_executaAlgoritmo(cubo, "D' D'", instrucoes);
			break;
		}
		//Prox 2 casos ocorrem quando as faces envolvidas são a esquerda e a traseira (4-1 e 1-4)
		case(3):{
			C2C_executaAlgoritmo(cubo, "D", instrucoes);
			break;
		}
		case(-3):{
			C2C_executaAlgoritmo(cubo, "D'", instrucoes);
			break;
		}
		//Sem default porque só há mais o caso 0, em que o cubo não tem nenhuma face girada.
	}
	//Se for o caso, usaremos o algoritmo de jogar para a esquerda no lugar do da direita
	if(usarAlgEsq) C2C_executaAlgoritmo(cubo, algEsq, instrucoes);
	else C2C_executaAlgoritmo(cubo, algDir, instrucoes);

	CUB_liberaPeca(p);
	return 0;
}

/**************************
*  $FC Função: C2C  resolve 2ª camada
*
*  $ED Descrição da função
*		Resolve a segunda camada de um cubo mágico com a primeira camada resovida,
*		seguindo os passos de resolução do método de iniciantes (método das camadas)
*		
*  $EParâmetros
*		$P cubo = estrutura CUB_tppCUBO populada
*		$P instrucoes = string vazio que abrigará os comandos de giro obtidos na função
*       
*  $FV Valor retornado
*       C2C_CondRetCuboVazio - O cubo recebido está vazio
*		C2C_CondRetOK - A segunda camada foi resolvida com sucesso
*
*	Assertiva de Entrada
*	- cubo != NULL
*	- instrucoes está vazio
*
*	Assertivas de Saida
*	- O cubo está com a segunda camada resolvida
*	- O vetor de instruções está com o tamanho certo e com os comandos para resolver
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

	//Resolve aresta direita de trás:
	C2C_resolveDireitaFace(4, cubo, instrucoes);

	return C2C_CondRetOK;
}
