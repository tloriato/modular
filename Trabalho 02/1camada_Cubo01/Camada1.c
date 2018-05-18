/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:              camada1.c
*  Letras identificadoras:      PCC

/******************************************************************************
*
*  $MCD Módulo de definição: Primeira camada cubo mágico
*
*  Arquivo gerado:				Camada1.c
*  Letras identificadoras:      PCC
*
*  Projeto: INF 1301 Cubo mágico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: bl    Bruno Leão
ms    Mariana Salgueiro
pf    Pilar Fernandez
gf    Gabriel Faria   
*
*  $HA Histórico de evolução:
*    Versão		Autor          Data			Observações
*	  7		  pf ms bl gf   03/maio/2018	finalização	
*     6       pf ms bl gf   02/maio/2018	ajustes e continuacao do desenvolvimento
*     5       pf ms bl gf   01/maio/2018	ajustes e continuacao do desenvolvimento
*	  4       pf ms bl gf   28/abr/2018		ajustes e continuação do desenvolvimento
*	  3       pf ms bl      27/abr/2018		ajustes e continuação do desenvolvimento
*	  2		  pf ms bl      26/abr/2018		ajustes e continuação do desenvolvimento
*     1       pf ms bl      25/abr/2018		início 
*
*
*
*  $ED Descrição do módulo
*		Implementa a primeira camada da resolução de um cubo mágico
*
*		O módulo implementa a representação de cubos mágicos de posição fixa
*			que são manipulados apenas tendo suas faces giradas. Ou seja, o
*			quadrado central de uma dada face terá sempre o mesmo valor.
*			O cubo deve ser inicializado com um vetor de inteiros, na ordem
*			definida na função de exibição.
*
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Camada1.h"


#define BRANCO 0
#define LARANJA 1
#define VERDE 2
#define VERMELHO 3
#define AMARELO 4
#define AZUL 5

CUB_tpCubo *cubo;

/***************************************************************************
*
*  Funcão: fazCamada1
*  
***************************************************************************/

//AE: Recebe uma lista de comandos a ser preenchida
//AS: Retorna um protótipo de cubo com a primeira camada resolvida

CUB_tpCondRet fazCamada1(char Comandos[]){
	CUB_tpPeca *Peca1 = CUB_criaPeca();
	CUB_tpPeca *Peca2 = CUB_criaPeca();
	CUB_tpPeca *Peca3 = CUB_criaPeca();
	CUB_tpPeca *Peca4 = CUB_criaPeca();
	CUB_tpPeca *Peca5 = CUB_criaPeca();
	CUB_tpPeca *Peca6 = CUB_criaPeca();
	CUB_tpPeca *Peca7 = CUB_criaPeca();
	CUB_tpPeca *Peca8 = CUB_criaPeca();

	int cores_cruz[2];
	int cores_quina[3];
	int j=0;
	CUB_criaCubo(&cubo);

	CUB_preencheCubo(&cubo, 0, 0, 0, 2);
	CUB_preencheCubo(&cubo, 0, 0, 1, 3);
	CUB_preencheCubo(&cubo, 0, 0, 2, 5);
	CUB_preencheCubo(&cubo, 0, 1, 0, 5);
	CUB_preencheCubo(&cubo, 0, 1, 1, 0);
	CUB_preencheCubo(&cubo, 0, 1, 2, 2);
	CUB_preencheCubo(&cubo, 0, 2, 0, 5);
	CUB_preencheCubo(&cubo, 0, 2, 1, 4);
	CUB_preencheCubo(&cubo, 0, 2, 2, 5);

	CUB_preencheCubo(&cubo, 1, 0, 0, 0);
	CUB_preencheCubo(&cubo, 1, 0, 1, 3);
	CUB_preencheCubo(&cubo, 1, 0, 2, 3);
	CUB_preencheCubo(&cubo, 1, 1, 0, 1);
	CUB_preencheCubo(&cubo, 1, 1, 1, 1);
	CUB_preencheCubo(&cubo, 1, 1, 2, 2);
	CUB_preencheCubo(&cubo, 1, 2, 0, 1);
	CUB_preencheCubo(&cubo, 1, 2, 1, 5);
	CUB_preencheCubo(&cubo, 1, 2, 2, 5);

	CUB_preencheCubo(&cubo, 2, 0, 0, 4);
	CUB_preencheCubo(&cubo, 2, 0, 1, 1);
	CUB_preencheCubo(&cubo, 2, 0, 2, 4);
	CUB_preencheCubo(&cubo, 2, 1, 0, 0);
	CUB_preencheCubo(&cubo, 2, 1, 1, 2);
	CUB_preencheCubo(&cubo, 2, 1, 2, 3);
	CUB_preencheCubo(&cubo, 2, 2, 0, 0);
	CUB_preencheCubo(&cubo, 2, 2, 1, 3);
	CUB_preencheCubo(&cubo, 2, 2, 2, 3);

	CUB_preencheCubo(&cubo, 3, 0, 0, 1);
	CUB_preencheCubo(&cubo, 3, 0, 1, 1);
	CUB_preencheCubo(&cubo, 3, 0, 2, 0);
	CUB_preencheCubo(&cubo, 3, 1, 0, 0);
	CUB_preencheCubo(&cubo, 3, 1, 1, 3);
	CUB_preencheCubo(&cubo, 3, 1, 2, 5);
	CUB_preencheCubo(&cubo, 3, 2, 0, 4);
	CUB_preencheCubo(&cubo, 3, 2, 1, 4);
	CUB_preencheCubo(&cubo, 3, 2, 2, 2);	

	CUB_preencheCubo(&cubo, 4, 0, 0, 1);
	CUB_preencheCubo(&cubo, 4, 0, 1, 4);
	CUB_preencheCubo(&cubo, 4, 0, 2, 2);
	CUB_preencheCubo(&cubo, 4, 1, 0, 4);
	CUB_preencheCubo(&cubo, 4, 1, 1, 4);
	CUB_preencheCubo(&cubo, 4, 1, 2, 2);
	CUB_preencheCubo(&cubo, 4, 2, 0, 0);
	CUB_preencheCubo(&cubo, 4, 2, 1, 0);
	CUB_preencheCubo(&cubo, 4, 2, 2, 1);	

	CUB_preencheCubo(&cubo, 5, 0, 0, 2);
	CUB_preencheCubo(&cubo, 5, 0, 1, 5);
	CUB_preencheCubo(&cubo, 5, 0, 2, 4);
	CUB_preencheCubo(&cubo, 5, 1, 0, 0);
	CUB_preencheCubo(&cubo, 5, 1, 1, 5);
	CUB_preencheCubo(&cubo, 5, 1, 2, 1);
	CUB_preencheCubo(&cubo, 5, 2, 0, 3);
	CUB_preencheCubo(&cubo, 5, 2, 1, 2);
	CUB_preencheCubo(&cubo, 5, 2, 2, 3);

	imprimeCubo(&cubo);

	cores_cruz[0] = 0;
	cores_cruz[1] = 2;
	CUB_buscaPeca(Peca1,&cubo,cores_cruz,2); //branca e verde

	cores_cruz[0] = 0;
	cores_cruz[1] = 3;
	CUB_buscaPeca(Peca2,&cubo,cores_cruz,2); //branca e vermelha

	cores_cruz[0] = 0;
	cores_cruz[1] = 5;
	CUB_buscaPeca(Peca3,&cubo,cores_cruz,2); //branca e azul

	cores_cruz[0] = 0;
	cores_cruz[1] = 1;
	CUB_buscaPeca(Peca4,&cubo,cores_cruz,2); //branca e laranja 


	while(!(j==4 || ((Peca1->C == 0 && Peca1->F == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 1) && 
		((Peca2->C == 0 && Peca2->D == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 2) && 
		((Peca3->C == 0 && Peca3->T == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 3 && Peca3->coordPeca[2] == 3) && 
		((Peca4->C == 0 && Peca4->E == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 3 && Peca4->coordPeca[2] == 2)))
	{
		if(j == 0){ // peça branca e verde

			if((Peca1->C == 0 && Peca1->T == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->T == 0 && Peca1->C == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorD, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->C == 0 && Peca1->E == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 2){
				CUB_giraEsquerdaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->E == 0 && Peca1->C == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 2){
				CUB_giraEsquerdaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_giraBaixoEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if((Peca1->C == 0 && Peca1->D == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 2){
				CUB_giraDireitaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->D == 0 && Peca1->C == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 2){
				CUB_giraDireitaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaA, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->F == 0 && Peca1->C == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 3 && Peca1->coordPeca[2] == 1){
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if((Peca1->E == 0 && Peca1->F == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 1){
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if ((Peca1->F == 0 && Peca1->E == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 1){
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");

			}
			else if((Peca1->D == 0 && Peca1->F == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 1){
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->F == 0 && Peca1->D == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 1){
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->B == 0 && Peca1->F == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 1)
			{
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->F == 0 && Peca1->B == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 1){
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
			}
			else if((Peca1->T == 0 && Peca1->D == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 3){
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			} 
			else if((Peca1->D == 0 && Peca1->T == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 3){
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->T == 0 && Peca1->E == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 3){
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x face FrontalH, ");

			}
			else if((Peca1->E == 0 && Peca1->T == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 2 && Peca1->coordPeca[2] == 3){
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->B == 0 && Peca1->T == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 3){
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->T == 0 && Peca1->B == 2) && Peca1->coordPeca[0] == 2 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 3){
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->B == 0 && Peca1->E == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 2){
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");

			}
			else if((Peca1->E == 0 && Peca1->B == 2) && Peca1->coordPeca[0] == 1 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 2){
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");

			}
			else if((Peca1->B == 0 && Peca1->D == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 2){
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraFrenteDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face FrontalH, ");
			}
			else if((Peca1->D == 0 && Peca1->B == 2) && Peca1->coordPeca[0] == 3 && Peca1->coordPeca[1] == 1 && Peca1->coordPeca[2] == 2){	
				CUB_giraFrenteEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face FrontalA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraFrenteEsquerda(&cubo, 1);	
				strcat(Comandos, "Girar Face FrontalA, ");	
			}		
		}

		if(j == 1){ //peça branca e vermelha
			cores_cruz[0] = 0;
			cores_cruz[1] = 3;
			CUB_buscaPeca(Peca2,&cubo,cores_cruz,2);


			if((Peca2->C == 0 && Peca2->T == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");

			}
			else if((Peca2->T == 0 && Peca2->C == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 3){	
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->C == 0 && Peca2->E == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 2){	
				CUB_giraEsquerdaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");

			}
			else if((Peca2->E == 0 && Peca2->C == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 2){	
				CUB_giraEsquerdaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");

			}
			else if((Peca2->C == 0 && Peca2->D == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 2){
				; //nothing
			}
			else if((Peca2->D == 0 && Peca2->C == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 3 && Peca2->coordPeca[2] == 2){	
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->E == 0 && Peca2->F == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 1){	
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if ((Peca2->F == 0 && Peca2->E == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 1){	
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->D == 0 && Peca2->F == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 1){	
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->F == 0 && Peca2->D == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 1){	
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->B == 0 && Peca2->F == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 1){	
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->F == 0 && Peca2->B == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 1){	
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 1);	
				strcat(Comandos, "Girar Face TraseiraH, ");		
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->T == 0 && Peca2->D == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 3){	
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->D == 0 && Peca2->T == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 3){				
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");	
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->T == 0 && Peca2->E == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 3){	
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->E == 0 && Peca2->T == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 2 && Peca2->coordPeca[2] == 3){	
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasEsquerda(&cubo, 1);	
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->B == 0 && Peca2->T == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 3){	
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->T == 0 && Peca2->B == 3) && Peca2->coordPeca[0] == 2 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 3){	
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");	
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->B == 0 && Peca2->E == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 2){
				CUB_giraBaixoEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_giraDireitaTras(&cubo, 2);			
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->E == 0 && Peca2->B == 3) && Peca2->coordPeca[0] == 1 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 2){
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}
			else if((Peca2->B == 0 && Peca2->D == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 2){
				CUB_giraDireitaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face DireitaH, ");
			}
			else if((Peca2->D == 0 && Peca2->B == 3) && Peca2->coordPeca[0] == 3 && Peca2->coordPeca[1] == 1 && Peca2->coordPeca[2] == 2){
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
			}

		}

		if(j == 2){ // peça branca e azul
			cores_cruz[0] = 0;
			cores_cruz[1] = 5;
			CUB_buscaPeca(Peca3,&cubo,cores_cruz,2);

			if((Peca3->C == 0 && Peca3->T == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 3 && Peca3->coordPeca[2] == 3)
				; //nothing
			else if((Peca3->T == 0 && Peca3->C == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 3 && Peca3->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}
			else if((Peca3->C == 0 && Peca3->E == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 3 && Peca3->coordPeca[2] == 2){	
				CUB_giraEsquerdaTras(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->E == 0 && Peca3->C == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 3 && Peca3->coordPeca[2] == 2){
				CUB_giraEsquerdaFrente(&cubo, 2);
				strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}
			else if((Peca3->E == 0 && Peca3->F == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 1){	
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}
			else if((Peca3->F == 0 && Peca3->E == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 1){
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->D == 0 && Peca3->F == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 1){

				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");

			}
			else if((Peca3->F == 0 && Peca3->D == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 1){
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->B == 0 && Peca3->F == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 1){
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorH, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->F == 0 && Peca3->B == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 1){
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}

			else if((Peca3->T == 0 && Peca3->D == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 3){
				CUB_giraDireitaTras(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraDireitaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face DireitaA, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->D == 0 && Peca3->T == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
			}
			else if((Peca3->T == 0 && Peca3->E == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}
			else if((Peca3->E == 0 && Peca3->T == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 2 && Peca3->coordPeca[2] == 3){
				CUB_giraEsquerdaTras(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaA, ");
				CUB_giraBaixoEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorH, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");

			}
			else if((Peca3->B == 0 && Peca3->T == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 3){
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->T == 0 && Peca3->B == 5) && Peca3->coordPeca[0] == 2 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 3){	
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");
			}
			else if((Peca3->B == 0 && Peca3->E == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 2){
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");

			}
			else if((Peca3->E == 0 && Peca3->B == 5) && Peca3->coordPeca[0] == 1 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 2){
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
				CUB_giraTrasDireita(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraH, ");

			}
			else if((Peca3->B == 0 && Peca3->D == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 2){	
				CUB_giraBaixoDireita(&cubo, 1);
				strcat(Comandos, "Girar Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 2);
				strcat(Comandos, "Girar 2x Face TraseiraA, ");
			}
			else if((Peca3->D == 0 && Peca3->B == 5) && Peca3->coordPeca[0] == 3 && Peca3->coordPeca[1] == 1 && Peca3->coordPeca[2] == 2){
				CUB_giraBaixoDireita(&cubo, 2);
				strcat(Comandos, "Girar 2x Face InferiorA, ");
				CUB_giraTrasEsquerda(&cubo, 1);
				strcat(Comandos, "Girar Face TraseiraA, ");
				CUB_giraEsquerdaFrente(&cubo, 1);
				strcat(Comandos, "Girar Face EsquerdaH, ");
			}
		}
			if(j == 3){ //peça branca e laranja
				cores_cruz[0] = 0;
				cores_cruz[1] = 1;
				CUB_buscaPeca(Peca4,&cubo,cores_cruz,2);

				if((Peca4->C == 0 && Peca4->E == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 3 && Peca4->coordPeca[2] == 2)
					; //nothing
				else if((Peca4->E == 0 && Peca4->C == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 3 && Peca4->coordPeca[2] == 2){
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraEsquerdaTras(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalH, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->E == 0 && Peca4->F == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 1){
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraEsquerdaTras(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalH, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->F == 0 && Peca4->E == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 1){
					CUB_giraEsquerdaTras(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaA, ");
				}
				else if((Peca4->D == 0 && Peca4->F == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 1){
					CUB_giraDireitaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaA, ");
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorH, ");
					CUB_giraDireitaTras(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaH, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalH, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->F == 0 && Peca4->D == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 1){
					CUB_giraDireitaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaA, ");
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorH, ");
					CUB_giraDireitaTras(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaH, ");
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorH, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->B == 0 && Peca4->F == 1) && Peca4->coordPeca[0] == 2 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 1){
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorH, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->F == 0 && Peca4->B == 1) && Peca4->coordPeca[0] == 2 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 1){
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalH, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->T == 0 && Peca4->D == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 3){
					CUB_giraDireitaTras(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaH, ");
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraDireitaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaA, ");
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->D == 0 && Peca4->T == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 3){

					CUB_giraDireitaTras(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaH, ");
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorH, ");
					CUB_giraDireitaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face DireitaA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");

				}
				else if((Peca4->T == 0 && Peca4->E == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 3)
				{
					CUB_giraEsquerdaFrente(&cubo, 1);	
					strcat(Comandos, "Girar Face EsquerdaH, ");
				}
				else if((Peca4->E == 0 && Peca4->T == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 2 && Peca4->coordPeca[2] == 3){
					CUB_giraEsquerdaTras(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaA, ");
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->B == 0 && Peca4->T == 1) && Peca4->coordPeca[0] == 2 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 3){
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->T == 0 && Peca4->B == 1) && Peca4->coordPeca[0] == 2 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 3){
					CUB_giraBaixoDireita(&cubo, 2);
					strcat(Comandos, "Girar 2x Face InferiorA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->B == 0 && Peca4->E == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 2)
				{
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->E == 0 && Peca4->B == 1) && Peca4->coordPeca[0] == 1 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 2){
					CUB_giraBaixoDireita(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->B == 0 && Peca4->D == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 2){
					CUB_giraBaixoDireita(&cubo, 2);
					strcat(Comandos, "Girar 2x Face InferiorA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
				else if((Peca4->D == 0 && Peca4->B == 1) && Peca4->coordPeca[0] == 3 && Peca4->coordPeca[1] == 1 && Peca4->coordPeca[2] == 2){
					CUB_giraBaixoEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face InferiorA, ");
					CUB_giraFrenteDireita(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 1);
					strcat(Comandos, "Girar Face EsquerdaH, ");
					CUB_giraFrenteEsquerda(&cubo, 1);
					strcat(Comandos, "Girar Face FrontalA, ");
					CUB_giraEsquerdaFrente(&cubo, 2);
					strcat(Comandos, "Girar 2x Face EsquerdaH, ");
				}
			}

			j++;

		}

		cores_quina[0] = 0;
		cores_quina[1] = 2;
		cores_quina[2] = 3;
		CUB_buscaPeca(Peca5,&cubo,cores_quina,3); //peça branca, verde e vermelha


		if(((Peca5->T == 0 && Peca5->E == 2 && Peca5->B == 3) || (Peca5->T == 0 && Peca5->E == 3 && Peca5->B == 2) || (Peca5->B == 0 && Peca5->E == 2 && Peca5->T == 3) || (Peca5->B == 0 && Peca5->E == 3 && Peca5->T == 2) || (Peca5->E == 0 && Peca5->B == 2 && Peca5->T == 3) || (Peca5->E == 0 && Peca5->B == 3 && Peca5->T == 2)) && (Peca5->coordPeca[0] == 1 && Peca5->coordPeca[1] == 1 && Peca5->coordPeca[2] == 3)){
			CUB_giraBaixoDireita(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorA, ");
		}
		else if(((Peca5->F == 0 && Peca5->E == 2 && Peca5->B == 3) || (Peca5->F == 0 && Peca5->E == 3 && Peca5->B == 2) || (Peca5->B == 0 && Peca5->E == 2 && Peca5->F == 3) || (Peca5->B == 0 && Peca5->E == 3 && Peca5->F == 2) || (Peca5->E == 0 && Peca5->B == 2 && Peca5->F == 3) || (Peca5->E == 0 && Peca5->B == 3 && Peca5->F == 2)) && (Peca5->coordPeca[0] == 1 && Peca5->coordPeca[1] == 1 && Peca5->coordPeca[2] == 1)){
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
		}


		else if(((Peca5->T == 0 && Peca5->D == 2 && Peca5->B == 3) || (Peca5->T == 0 && Peca5->D == 3 && Peca5->B == 2) || (Peca5->B == 0 && Peca5->D == 2 && Peca5->T == 3) || (Peca5->B == 0 && Peca5->D == 3 && Peca5->T == 2) || (Peca5->D == 0 && Peca5->B == 2 && Peca5->T == 3) || (Peca5->D == 0 && Peca5->B == 3 && Peca5->T == 2)) && (Peca5->coordPeca[0] == 3 && Peca5->coordPeca[1] == 1 && Peca5->coordPeca[2] == 3))	{
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");

		}
		else if(((Peca5->T == 0 && Peca5->E == 2 && Peca5->C == 3) || (Peca5->T == 0 && Peca5->E == 3 && Peca5->C == 2) || (Peca5->C == 0 && Peca5->E == 2 && Peca5->T == 3) || (Peca5->C == 0 && Peca5->E == 3 && Peca5->T == 2) || (Peca5->E == 0 && Peca5->C == 2 && Peca5->T == 3) || (Peca5->E == 0 && Peca5->C == 3 && Peca5->T == 2)) && (Peca5->coordPeca[0] == 1 && Peca5->coordPeca[1] == 3 && Peca5->coordPeca[2] == 3)){

			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoEsquerda(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorA, ");

		}
		else if(((Peca5->T == 0 && Peca5->D == 2 && Peca5->C == 3) || (Peca5->T == 0 && Peca5->D == 3 && Peca5->C == 2) || (Peca5->C == 0 && Peca5->D == 2 && Peca5->T == 3) || (Peca5->B == 0 && Peca5->D == 3 && Peca5->T == 2) || (Peca5->D == 0 && Peca5->C == 2 && Peca5->T == 3) || (Peca5->D == 0 && Peca5->C == 3 && Peca5->T == 2)) && (Peca5->coordPeca[0] == 3 && Peca5->coordPeca[1] == 3 && Peca5->coordPeca[2] == 3)){
			CUB_giraDireitaTras(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaH, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
			CUB_giraDireitaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
		}
		else if(((Peca5->F == 0 && Peca5->E == 2 && Peca5->C == 3) || (Peca5->F == 0 && Peca5->E == 3 && Peca5->C == 2) || (Peca5->C == 0 && Peca5->E == 2 && Peca5->F == 3) || (Peca5->C == 0 && Peca5->E == 3 && Peca5->F == 2) || (Peca5->E == 0 && Peca5->C == 2 && Peca5->F == 3) || (Peca5->E == 0 && Peca5->C == 3 && Peca5->F == 2)) && (Peca5->coordPeca[0] == 1 && Peca5->coordPeca[1] == 3 && Peca5->coordPeca[2] == 1)){
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
		}

		CUB_buscaPeca(Peca5,&cubo,cores_quina,3);

		while(!((Peca5->C == 0 && Peca5->F == 2 && Peca5->D == 3) && (Peca5->coordPeca[0] == 3 && Peca5->coordPeca[1] == 3 && Peca5->coordPeca[2] == 1))){		
			CUB_giraDireitaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
			CUB_giraDireitaTras(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaH, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");

			CUB_buscaPeca(Peca5,&cubo,cores_quina,3);
		}

		cores_quina[0] = 0;
		cores_quina[1] = 3;
		cores_quina[2] = 5;
		CUB_buscaPeca(Peca6,&cubo,cores_quina,3); //peça branca, vermelha e azul


		if(((Peca6->E == 0 && Peca6->T == 3 && Peca6->B == 5) || (Peca6->E == 0 && Peca6->T == 5 && Peca6->B == 3) || (Peca6->B == 0 && Peca6->T == 3 && Peca6->E == 5) || (Peca6->B == 0 && Peca6->T == 5 && Peca6->E == 3) || (Peca6->T == 0 && Peca6->E == 3 && Peca6->B == 5) || (Peca6->T == 0 && Peca6->E == 5 && Peca6->B == 3)) && (Peca6->coordPeca[0] == 1 && Peca6->coordPeca[1] == 1 && Peca6->coordPeca[2] == 3)) {
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
		}
		else if(((Peca6->B == 0 && Peca6->F == 3 && Peca6->E == 5) || (Peca6->B == 0 && Peca6->F == 5 && Peca6->E == 3) || (Peca6->F == 0 && Peca6->B == 3 && Peca6->E == 5) || (Peca6->F == 0 && Peca6->B == 5 && Peca6->E == 3) || (Peca6->E == 0 && Peca6->F == 3 && Peca6->B == 5) || (Peca6->E == 0 && Peca6->F == 5 && Peca6->B == 3)) && (Peca6->coordPeca[0] == 1 && Peca6->coordPeca[1] == 1 && Peca6->coordPeca[2] == 1)) {
			CUB_giraBaixoDireita(&cubo, 2);	
			strcat(Comandos, "Girar 2x Face InferiorH, ");
		}
		else if(((Peca6->B == 0 && Peca6->D == 3 && Peca6->F == 5) || (Peca6->B == 0 && Peca6->D == 5 && Peca6->F == 3) || (Peca6->F == 0 && Peca6->B == 3 && Peca6->D == 5) || (Peca6->F == 0 && Peca6->B == 5 && Peca6->D == 3) || (Peca6->D == 0 && Peca6->F == 3 && Peca6->B == 5) || (Peca6->D == 0 && Peca6->F == 5 && Peca6->B == 3)) && (Peca6->coordPeca[0] == 3 && Peca6->coordPeca[1] == 1 && Peca6->coordPeca[2] == 1)) {
			CUB_giraBaixoDireita(&cubo, 1);	
			strcat(Comandos, "Girar Face InferiorH, ");
		}
		else if(((Peca6->C == 0 && Peca6->T == 3 && Peca6->E == 5) || (Peca6->C == 0 && Peca6->T == 5 && Peca6->E == 3) || (Peca6->T == 0 && Peca6->C == 3 && Peca6->E == 5) || (Peca6->T == 0 && Peca6->C == 5 && Peca6->E == 3) || (Peca6->E == 0 && Peca6->T == 3 && Peca6->C == 5) || (Peca6->E == 0 && Peca6->T == 5 && Peca6->C == 3)) && (Peca6->coordPeca[0] == 1 && Peca6->coordPeca[1] == 3 && Peca6->coordPeca[2] == 3)){ 
			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
		}
		else if(((Peca6->C == 0 && Peca6->F == 3 && Peca6->E == 5) || (Peca6->C == 0 && Peca6->F == 5 && Peca6->E == 3) || (Peca6->F == 0 && Peca6->C == 3 && Peca6->E == 5) || (Peca6->F == 0 && Peca6->C == 5 && Peca6->E == 3) || (Peca6->E == 0 && Peca6->F == 3 && Peca6->C == 5) || (Peca6->E == 0 && Peca6->F == 5 && Peca6->C == 3)) && (Peca6->coordPeca[0] == 1 && Peca6->coordPeca[1] == 3 && Peca6->coordPeca[2] == 1)){ 
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoDireita(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorH, ");
			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
		}

		CUB_buscaPeca(Peca6,&cubo,cores_quina,3);

		while(!((Peca6->C == 0 && Peca6->D == 3 && Peca6->T == 5) && (Peca6->coordPeca[0] == 3 && Peca6->coordPeca[1] == 3 && Peca6->coordPeca[2] == 3))){
			CUB_giraDireitaTras(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaH, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
			CUB_giraDireitaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face DireitaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");

			CUB_buscaPeca(Peca6,&cubo,cores_quina,3);
		}

		cores_quina[0] = 0;
		cores_quina[1] = 1;
		cores_quina[2] = 5;
		CUB_buscaPeca(Peca7,&cubo,cores_quina,3); // peça branca, laranja e azul


		if(((Peca7->F == 0 && Peca7->B == 1 && Peca7->E == 5) || (Peca7->F == 0 && Peca7->B == 5 && Peca7->E == 1) || (Peca7->B == 0 && Peca7->F == 1 && Peca7->E == 5) || (Peca7->B == 0 && Peca7->F == 5 && Peca7->E == 1) || (Peca7->E == 0 && Peca7->B == 1 && Peca7->F == 5) || (Peca7->E == 0 && Peca7->B == 5 && Peca7->F == 1)) && (Peca7->coordPeca[0] == 1 && Peca7->coordPeca[1] == 1 && Peca7->coordPeca[2] == 1))	{
			CUB_giraBaixoEsquerda(&cubo, 1);	
			strcat(Comandos, "Girar Face InferiorA, ");
		}
		else if(((Peca7->F == 0 && Peca7->B == 1 && Peca7->D == 5) || (Peca7->F == 0 && Peca7->B == 5 && Peca7->D == 1) || (Peca7->B == 0 && Peca7->F == 1 && Peca7->D == 5) || (Peca7->B == 0 && Peca7->F == 5 && Peca7->D == 1) || (Peca7->D == 0 && Peca7->B == 1 && Peca7->F == 5) || (Peca7->D == 0 && Peca7->B == 5 && Peca7->F == 1)) && (Peca7->coordPeca[0] == 3 && Peca7->coordPeca[1] == 1 && Peca7->coordPeca[2] == 1)){
			CUB_giraBaixoEsquerda(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorA, ");
		}

		else if(((Peca7->T == 0 && Peca7->B == 1 && Peca7->D == 5) || (Peca7->T == 0 && Peca7->B == 5 && Peca7->D == 1) || (Peca7->B == 0 && Peca7->T == 1 && Peca7->D == 5) || (Peca7->B == 0 && Peca7->T == 5 && Peca7->D == 1) || (Peca7->D == 0 && Peca7->B == 1 && Peca7->T == 5) || (Peca7->D == 0 && Peca7->B == 5 && Peca7->T == 1)) && (Peca7->coordPeca[0] == 3 && Peca7->coordPeca[1] == 1 && Peca7->coordPeca[2] == 3))	{
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
		}
		else if(((Peca7->F == 0 && Peca7->C == 1 && Peca7->E == 5) || (Peca7->F == 0 && Peca7->C == 5 && Peca7->E == 1) || (Peca7->C == 0 && Peca7->F == 1 && Peca7->E == 5) || (Peca7->C == 0 && Peca7->F == 5 && Peca7->E == 1) || (Peca7->E == 0 && Peca7->C == 1 && Peca7->F == 5) || (Peca7->E == 0 && Peca7->C == 5 && Peca7->F == 1)) && (Peca7->coordPeca[0] == 1 && Peca7->coordPeca[1] == 3 && Peca7->coordPeca[2] == 1)){	
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoDireita(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorH, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
			CUB_giraBaixoDireita(&cubo, 1);		
			strcat(Comandos, "Girar Face InferiorH, ");
		}

		CUB_buscaPeca(Peca7,&cubo,cores_quina,3);

		while(!((Peca7->C == 0 && Peca7->E == 1 && Peca7->T == 5) && (Peca7->coordPeca[0] == 1 && Peca7->coordPeca[1] == 3 && Peca7->coordPeca[2] == 3))){
			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
			CUB_buscaPeca(Peca7,&cubo,cores_quina,3);
		}	

		cores_quina[0] = 0;
		cores_quina[1] = 2;
		cores_quina[2] = 1;
		CUB_buscaPeca(Peca8,&cubo,cores_quina,3); //peça branca, laranja e verde

		if(((Peca8->B == 0 && Peca8->T == 2 && Peca8->E == 1) || (Peca8->B == 0 && Peca8->T == 1 && Peca8->E == 2) || (Peca8->T == 0 && Peca8->B == 2 && Peca8->E == 1) || (Peca8->T == 0 && Peca8->B == 1 && Peca8->E == 2) || (Peca8->E == 0 && Peca8->B == 2 && Peca8->T == 1) || (Peca8->E == 0 && Peca8->B == 1 && Peca8->T == 2)) && (Peca8->coordPeca[0] == 1 && Peca8->coordPeca[1] == 1 && Peca8->coordPeca[2] == 3)){
			CUB_giraBaixoDireita(&cubo, 1);	
			strcat(Comandos, "Girar Face InferiorH, ");
		}
		else if(((Peca8->B == 0 && Peca8->F == 2 && Peca8->D == 1) || (Peca8->B == 0 && Peca8->F == 1 && Peca8->D == 2) || (Peca8->F == 0 && Peca8->B == 2 && Peca8->D == 1) || (Peca8->F == 0 && Peca8->B == 1 && Peca8->D == 2) || (Peca8->D == 0 && Peca8->B == 2 && Peca8->F == 1) || (Peca8->D == 0 && Peca8->B == 1 && Peca8->F == 2)) && (Peca8->coordPeca[0] == 3 && Peca8->coordPeca[1] == 1 && Peca8->coordPeca[2] == 1)){
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");
		}
		else if(((Peca8->B == 0 && Peca8->T == 2 && Peca8->D == 1) || (Peca8->B == 0 && Peca8->T == 1 && Peca8->D == 2) || (Peca8->T == 0 && Peca8->B == 2 && Peca8->D == 1) || (Peca8->T == 0 && Peca8->B == 1 && Peca8->D == 2) || (Peca8->D == 0 && Peca8->B == 2 && Peca8->T == 1) || (Peca8->D == 0 && Peca8->B == 1 && Peca8->T == 2)) && (Peca8->coordPeca[0] == 3 && Peca8->coordPeca[1] == 1 && Peca8->coordPeca[2] == 3)){
			CUB_giraBaixoDireita(&cubo, 2);
			strcat(Comandos, "Girar 2x Face InferiorH, ");
		}

		CUB_buscaPeca(Peca8,&cubo,cores_quina,3);

		while(!((Peca8->C == 0 && Peca8->F == 2 && Peca8->E == 1) && (Peca8->coordPeca[0] == 1 && Peca8->coordPeca[1] == 3 && Peca8->coordPeca[2] == 1))){
			CUB_giraEsquerdaFrente(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaH, ");
			CUB_giraBaixoDireita(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorH, ");
			CUB_giraEsquerdaTras(&cubo, 1);
			strcat(Comandos, "Girar Face EsquerdaA, ");
			CUB_giraBaixoEsquerda(&cubo, 1);
			strcat(Comandos, "Girar Face InferiorA, ");

			CUB_buscaPeca(Peca8,&cubo,cores_quina,3);
		}

		imprimeCubo(&cubo);
		return CUB_CondRetOK;
	}