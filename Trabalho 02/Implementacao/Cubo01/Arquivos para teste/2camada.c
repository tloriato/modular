
/******************************************************************************
*
*  $MCD M�dulo de defini��o: 2L		Segunda Camada
*
*  Arquivo gerado:              secondLayer.h
*  Letras identificadoras:      2L
*
*  Projeto: INF 1301 Cubo m�gico
*  Gestor:  LES/DI/PUC-Rio
*  Autores: 
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es

*
*  $ED Descri��o do m�dulo
*		Implementa 2 Camada do Cubo m�gico.
*
*		
*
******************************************************************************/


#include "2camada.h"
#include "CUBO.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55

#define CIMA 0
#define ESQUERDA 4
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define BAIXO 5

#define VERDE 1
#define VERMELHO 2
#define AMARELO 3
#define AZUL 4
#define BRANCO 5
#define LARANJA 6


// (cubo, algoritmo) ~> inteiro
//	cubo = estrutura CUB_tppCUBO populada
//	algoritmo = string de no m�ximo ALG elementos com comandos no estilo:
//		"U R U' R' U' F' U U F F"
//	inteiro =
//		0 -> sucesso
//		-1 -> entradas invalidas (TODO)

// (cubo) -> Bool  //falta cond ret caso == 1 
	C2C_tpCondRet resolvidoAcima(CUB_tppCUBO cubo) {
		int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);

		CUB_ChecarCorDaFace(&aux1, cubo, 0, 0, CIMA);
		CUB_ChecarCorDaFace(&aux2, cubo, 0, 1, CIMA);
		CUB_ChecarCorDaFace(&aux3, cubo, 0, 2, CIMA);

		CUB_ChecarCorDaFace(&aux4, cubo, 1, 0, CIMA);
		CUB_ChecarCorDaFace(&aux5, cubo, 1, 2, CIMA);

		CUB_ChecarCorDaFace(&aux6, cubo, 2, 0, CIMA);
		CUB_ChecarCorDaFace(&aux7, cubo, 2, 1, CIMA);
		CUB_ChecarCorDaFace(&aux8, cubo, 2, 2, CIMA);

		if (corCima == aux1 == aux2 == aux3 == aux4 == aux5 == aux6 == aux7 == aux8) {
			return 1; // criar cond ret
		}
		else {
			return C2C_CondRetOK; //0
		}
	}

	// (cubo) -> Int Restante
	// Restante: Número de peças fora de posição:
	//	- 0
	//	- 1
	// 	- 2
	C2C_tpCondRet  resolveFrente(CUB_tppCUBO cubo) {

		int restantes = 2;

		int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

		int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
		int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

		CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
		CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

		cor1Aresta1 = corFrente;
		cor1Aresta2 = corFrente;

		cor2Aresta1 = corDireita;
		cor2Aresta2 = corEsquerda;

		printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
			corFrente, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

		if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita Resolvida
			restantes--;
			return C2C_CondRetOK; 
		}
		else {
			// Tenta resolver a Aresta da Direita

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima

				if (faceAresta1 == FRENTE && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
					// pois o cubo está de cabeça pra baixo
					// Later
				}
				else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar de orientação do lado direito invertido
					// Later
				}
			}
			else {
				// Face resolvida está para baixo

				if (faceAresta1 == FRENTE && linhaAresta1 == 0 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita
					executaAlgoritmo(cubo, "U R U' R' U' F' U F");
					restantes--;
					return C2C_CondRetOK; 
				}
				else if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U R U' R' U' F' U F"); // 2x pra Direita
					restantes--;
					return C2C_CondRetOK; 
				}
				else if (faceAresta1 == CIMA && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// É um caso onde a peça está com orientação errada na posição de cima. Nós vamos mover ela para a posição certa na orientação errada, 
					// depois iremos trazer ela de volta para a posição cima com a orientação certa, e ai movermos de novo para o lugar e orientação certos.
					// Algoritmo Direita -> Algoritmo de Troca de Orientação do Lado direito, ou seja: Direita -> Direita -> U U -> Direita
					// ps: uma solução mais elegante seria apenas realizar a primeira mudança, deixando a segunda para o próximo loop ou função :)
					executaAlgoritmo(cubo, "U R U' R' U' F' U F");
					executaAlgoritmo(cubo, "U R U' R' U' F' U F");
					executaAlgoritmo(cubo, "U U");
					executaAlgoritmo(cubo, "U R U' R' U' F' U F");
					restantes--;
					return C2C_CondRetOK; 

				}
			}
		}

		if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda Resolvida
			restantes--;
			return C2C_CondRetOK; 
		}
		else {
			// Tenta resolver a Aresta da Esquerda

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima
				if (faceAresta2 == FRENTE && linhaAresta2 == 2 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
					// pois o cubo está de cabeça para baixo
					// Later
				}
				else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar de orientação do lado esquerdo invertido
					// Later
				}

			}
			else {
				// Face resolvida está para baixo
				if (faceAresta2 == FRENTE && linhaAresta2 == 0 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda
					executaAlgoritmo(cubo, "U' L' U L U F U' F'");
					restantes--;
					return C2C_CondRetOK; 
				}
				else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK; 
				}
				else if (faceAresta2 == CIMA && linhaAresta2 == 2 && colunaAresta2 == 1) {
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' L' U L U F U' F'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK; 
				}
			}
		}

		printf("num restantes = %d \n", restantes);
		return C2C_CondRetNenhumMovPossivel;
	}

	// (cubo) -> Int Restante
	// Restante: Número de peças fora de posição:
	//	- 0
	//	- 1
	// 	- 2
	C2C_tpCondRet resolveEsquerda(CUB_tppCUBO cubo) {

		int restantes = 2;

		int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

		int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
		int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

		CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
		CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

		cor1Aresta1 = corEsquerda;
		cor1Aresta2 = corEsquerda;

		cor2Aresta1 = corFrente;
		cor2Aresta2 = corTraseira;

		printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
			corEsquerda, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

		if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Direita

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima

				if (faceAresta1 == ESQUERDA && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
					// pois o cubo está de cabeça pra baixo
					// Later
				}
				else if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar de orientação do lado direito invertido
					// Later
				}
			}
			else {
				// Face resolvida está para baixo

				if (faceAresta1 == ESQUERDA && linhaAresta1 == 0 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita
					executaAlgoritmo(cubo, "U F U' F' U' L' U L");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta1 == FRENTE && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta1 == CIMA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
					executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U F U' F' U' L' U L"); // 1x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}
			}
		}

		if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Esquerda

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima
				if (faceAresta2 == ESQUERDA && linhaAresta2 == 2 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
					// pois o cubo está de cabeça para baixo
					// Later
				}
				else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar de orientação do lado esquerdo invertido
					// Later
				}

			}
			else {
				// Face resolvida está para baixo
				if (faceAresta2 == ESQUERDA && linhaAresta2 == 0 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda
					executaAlgoritmo(cubo, "U' B' U B U L U' L'");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta2 == CIMA && linhaAresta2 == 1 && colunaAresta2 == 0) {
					executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
																// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' B' U B U L U' L'"); // 1x pra Esquerda
					restantes--;
					return C2C_CondRetOK;
				}
			}
		}

		printf("num restantes = %d \n", restantes);
		return C2C_CondRetNenhumMovPossivel;
	}

	// (cubo) -> Int Restante
	// Restante: Número de peças fora de posição:
	//	- 0
	//	- 1
	// 	- 2
	C2C_tpCondRet resolveDireita(CUB_tppCUBO cubo) {

		int restantes = 2;

		int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

		int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
		int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

		CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
		CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

		cor1Aresta1 = corDireita;
		cor1Aresta2 = corDireita;

		cor2Aresta1 = corTraseira;
		cor2Aresta2 = corFrente;

		printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
			corDireita, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);

		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

		if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Direita

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima

				if (faceAresta1 == DIREITA && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
					// pois o cubo está de cabeça pra baixo
					// Later
				}
				else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar de orientação do lado direito invertido
					// Later
				}
			}
			else {
				// Face resolvida está para baixo

				if (faceAresta1 == DIREITA && linhaAresta1 == 0 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita
					executaAlgoritmo(cubo, "U B U' B' U' R' U R");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 2x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta1 == CIMA && linhaAresta1 == 1 && colunaAresta1 == 2) {
					executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
																// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U B U' B' U' R' U R"); // 2x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}
			}
		}

		if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Esquerda

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima
				if (faceAresta2 == DIREITA && linhaAresta2 == 2 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
					// pois o cubo está de cabeça para baixo
					// Later
				}
				else if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar de orientação do lado esquerdo invertido
					// Later
				}

			}
			else {
				// Face resolvida está para baixo
				if (faceAresta2 == DIREITA && linhaAresta2 == 0 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda
					executaAlgoritmo(cubo, "U' F' U F U R U' R'");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta2 == FRENTE && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta2 == CIMA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
																// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' F' U F U R U' R'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK;
				}
			}
		}

		printf("num restantes = %d\n", restantes);
		return C2C_CondRetNenhumMovPossivel;
	}

	// (cubo) -> Int Restante
	// Restante: Número de peças fora de posição:
	//	- 0
	//	- 1
	// 	- 2
	C2C_tpCondRet  resolveTraseira(CUB_tppCUBO cubo) {

		int restantes = 2;

		int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

		int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
		int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

		CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
		CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

		cor1Aresta1 = corTraseira;
		cor1Aresta2 = corTraseira;

		cor2Aresta1 = corEsquerda;
		cor2Aresta2 = corDireita;

		printf("Cor da Face: %d \n Primeira Aresta: %d (cor ref.) %d (seg. cor) \n Segunda Aresta:  %d (cor ref.) %d (seg. cor)\n",
			corTraseira, cor1Aresta1, cor2Aresta1, cor1Aresta2, cor2Aresta2);


		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

		if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Direita

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima

				if (faceAresta1 == TRASEIRA && linhaAresta1 == 2 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita Invertido, "Baixo -> Direita" 
					// pois o cubo está de cabeça pra baixo
					// Later
				}
				else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar de orientação do lado direito invertido
					// Later
				}
			}
			else {
				// Face resolvida está para baixo

				if (faceAresta1 == TRASEIRA && linhaAresta1 == 0 && colunaAresta1 == 1) {
					// Algoritmo Cima -> Direita
					executaAlgoritmo(cubo, "U L U' L' U' B' U B");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
					// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 2x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta1 == CIMA && linhaAresta1 == 0 && colunaAresta1 == 1) {
					executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
																// Algoritmo de trocar a orientação do lado direito
					executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 1x pra Direita
					executaAlgoritmo(cubo, "U U"); // Gira a peça
					executaAlgoritmo(cubo, "U L U' L' U' B' U B"); // 2x pra Direita
					restantes--;
					return C2C_CondRetOK;
				}
			}
		}

		if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda Resolvida
			restantes--;
			return C2C_CondRetOK;
		}
		else {
			// Tenta resolver a Aresta da Esquerda

			if (resolvidoAcima(cubo)) {
				// Face resolvida está para cima
				if (faceAresta2 == TRASEIRA && linhaAresta2 == 2 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda invertido, "Baixo -> Esquerda",
					// pois o cubo está de cabeça para baixo
					// Later
				}
				else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar de orientação do lado esquerdo invertido
					// Later
				}

			}
			else {
				// Face resolvida está para baixo
				if (faceAresta2 == TRASEIRA && linhaAresta2 == 0 && colunaAresta2 == 1) {
					// Algoritmo Cima -> Esquerda
					executaAlgoritmo(cubo, "U' R' U R U B U' B'");
					restantes--;
					return C2C_CondRetOK;
				}
				else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
					// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK;
				}

				else if (faceAresta2 == CIMA && linhaAresta2 == 0 && colunaAresta2 == 1) {
					executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
																// Algoritmo de trocar a orientação do lado esquerdo
					executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 1x pra Esquerda
					executaAlgoritmo(cubo, "U U"); // (?) Gira a peça
					executaAlgoritmo(cubo, "U' R' U R U B U' B'"); // 2x pra Esquerda
					restantes--;
					return C2C_CondRetOK;

				}
			}
		}

		printf("num restantes = %d\n", restantes);
		return C2C_CondRetNenhumMovPossivel;
	}

	int aux(int a, int b, int c, int d) {
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			return 0;
		}

		return 1;
	}

	int forcaCuboFrente(CUB_tppCUBO cubo) {
		
		int alterado = 0;

		int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

		int faceAresta1, linhaAresta1, colunaAresta1, cor1Aresta1, cor2Aresta1;
		int faceAresta2, linhaAresta2, colunaAresta2, cor1Aresta2, cor2Aresta2;

		CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE);
		CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA);
		CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA);
		CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA);
		CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA);
		CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO);

		/* Cuidando da Face da Frente! */
		cor1Aresta1 = corFrente;
		cor1Aresta2 = corFrente;

		cor2Aresta1 = corDireita;
		cor2Aresta2 = corEsquerda;

		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta1, &linhaAresta1, &colunaAresta1, cubo, cor1Aresta1, cor2Aresta1);
		CUB_EncontrarPosicaoDePecaDeAresta(&faceAresta2, &linhaAresta2, &colunaAresta2, cubo, cor1Aresta2, cor2Aresta2);

		if (faceAresta1 == DIREITA && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita está na Direita da Face Direita
			// Algoritmo Cima <> Direita [da Direita]
			executaAlgoritmo(cubo, "U B U' B' U' R' U R");

			return 1;
		}

		else if (faceAresta1 == ESQUERDA && linhaAresta1 == 1 && colunaAresta1 == 0) {
			// Aresta da Direita está na Esquerda da Face Esquerda
			// Algoritmo Cima <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "U' B' U B U L U' L'");

			return 1;
		}

		else if (faceAresta1 == ESQUERDA &&  linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita está na Direita da Face Esquerda
			// Algorima Cima <> Direita [da Esquerda]
			executaAlgoritmo(cubo, "U F U' F' U' L' U L");
			return 1;
		}

		else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 0) {
			// Aresta da Direita está na Esquerda da Face Traseira
			// Algoritmo Cima <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "U' R' U R U B U' B'");
			
			return 1;
		}

		else if (faceAresta1 == TRASEIRA && linhaAresta1 == 1 && colunaAresta1 == 2) {
			// Aresta da Direita está na Direita da Face Traseira
			// Algoritmo Cima <> Direita [da Traseira]
			executaAlgoritmo(cubo, "U L U' L' U' B' U B");

			return 1;
		}

		else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda está na Esquerda da Face Direita
			// Algoritmo Cima <> Esquerda [da Direita]
			executaAlgoritmo(cubo, "U' F' U F U R U' R'");
			
			return 1;
		}

		else if (faceAresta2 == DIREITA && linhaAresta2 == 1 && colunaAresta2 == 2) {
			// Aresta da Esquerda está na Direita da Face Direita
			// Algoritmo Cima <> Direita [da Direita]
			executaAlgoritmo(cubo, "U B U' B' U' R' U R");

			return 1;
		}

		else if (faceAresta2 == ESQUERDA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda está na Esquerda da Face Esquerda
			// Algoritmo Cima <> Esquerda [da Esquerda]
			executaAlgoritmo(cubo, "U' B' U B U L U' L'");

			return 1;	
		}

		else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 0) {
			// Aresta da Esquerda está na Esquerda da Face Traseira
			// Algoritmo Cima <> Esquerda [da Traseira]
			executaAlgoritmo(cubo, "U' R' U R U B U' B'");
			return 1;
		}

		else if (faceAresta2 == TRASEIRA && linhaAresta2 == 1 && colunaAresta2 == 2) {
			// Aresta da Esquerda está na Direita da Face Traseira
			// Algoritmo Cima <> Direita [da Traseira]
			executaAlgoritmo(cubo, "U L U' L' U' B' U B");
			return 1;
		}



		return 0;
	}


C2C_tpCondRet resolve2camada (CUB_tppCUBO cubo){

	//ULTIMA VERSAO QUE ESTÁ NO GIT 29/04 18:49

	int i, fd;
	int config[54];

	int r = 1, a = 0, b = 0, c = 0, d = 0;
	int oldA = 2, oldB = 2, oldC = 2, oldD = 2;

	char * algoritmoDireita = "U R U' R' U' F' U F";
	char * algoritmoEsquerda = "U' L' U L U F U' F'";
	char * algoritmoOrientacao = "U R U' R' U' F' U F U U U R U' R' U' F' U F";

	populaCubo(config);

	CUB_CriarCUBO(&cubo, config);

	CUB_ExibirCUBO(cubo);
	i = 0;
	while (r) {
		printf("Frente: \n");
		if (i % 2 == 0)
			a = resolveFrente(cubo);
		else
			oldA = resolveFrente(cubo);
		printf("Restantes: %d \n", a);
		//CUB_ExibirCUBO(cubo);

		printf("Direita: \n");
		if (i % 2 == 0)
			b = resolveDireita(cubo);
		else
			oldB = resolveDireita(cubo);
		printf("Restantes: %d \n", b);
		//CUB_ExibirCUBO(cubo);

		printf("Traseira: \n");
		if (i % 2 == 0)
			c = resolveTraseira(cubo);
		else
			oldC = resolveTraseira(cubo);
		printf("Restantes: %d \n", c);
		//CUB_ExibirCUBO(cubo);

		printf("Esquerda: \n");
		if (i % 2 == 0)
			d = resolveEsquerda(cubo);
		else
			oldD = resolveEsquerda(cubo);
		printf("Restantes: %d \n", d);
		//CUB_ExibirCUBO(cubo);

		//printf("Restantes: F  %d D %d T %d E %d \n", a, b, c, d);

		if (oldA == a && oldB == b && oldC == c && oldD == d) {
			executaAlgoritmo(cubo, "U");
			printf("Execute U \n");
		}

		i++;

		if (i % 2 == 0)
			r = aux(a, b, c, d);
		else
			r = aux(a, b, c, d);
	}

	CUB_ExibirCUBO(cubo);
	printf("Loops: %d\n", i);


	return C2C_CondRetOK;
		
}


int populaCubo(int *config) {

	// 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

	//Up Face
	config[0] = AZUL;
	config[1] = VERDE;
	config[2] = AZUL;

	config[3] = VERDE;
	config[4] = AMARELO; 
	config[5] = AZUL;

	config[6] = VERDE;
	config[7] = AMARELO;
	config[8] = VERDE;

	// Left Face 4
	config[9] = LARANJA;
	config[10] = AMARELO;
	config[11] = LARANJA;

	config[21] = AZUL;
	config[22] = VERMELHO;	
	config[23] = AMARELO;

	config[33] = VERMELHO;
	config[34] = VERMELHO;
	config[35] = VERMELHO;

	// Front Face 1
	config[12] = AMARELO;
	config[13] = VERMELHO;
	config[14] = AMARELO;

	config[24] = LARANJA;
	config[25] = VERDE;  
	config[26] = VERDE;

	config[36] = VERDE;
	config[37] = VERDE;
	config[38] = VERDE;

	// Right Face 2
	config[15] = VERMELHO;
	config[16] = VERMELHO;
	config[17] = VERMELHO;

	config[27] = LARANJA;
	config[28] = LARANJA; 
	config[29] = LARANJA;

	config[39] = LARANJA;
	config[40] = LARANJA;
	config[41] = LARANJA;

	// Back Face 3
	config[18] = AMARELO;
	config[19] = VERMELHO;
	config[20] = AMARELO;

	config[30] = AZUL;
	config[31] = AZUL;  
	config[32] = AMARELO;

	config[42] = AZUL;
	config[43] = AZUL;
	config[44] = AZUL;

	// Down Face 5
	config[45] = BRANCO;
	config[46] = BRANCO;
	config[47] = BRANCO;

	config[48] = BRANCO;
	config[49] = BRANCO;
	config[50] = BRANCO;

	config[51] = BRANCO;
	config[52] = BRANCO;
	config[53] = BRANCO;

	return 0;
}

int executaAlgoritmo(cubo, algoritmo) {

		int i = 0;
		int jump = 2;

		char comandos[ALG];
		memset(comandos, '\0', sizeof(comandos));
		strcpy(comandos, algoritmo);

		while (comandos[i]) {

			char rot;
			int face;

			if (comandos[i + 1] == '\'') {
				rot = 'a';
				jump = 3;
			}
			else {
				rot = 'h';
				jump = 2;
			}

			switch (comandos[i]) {
			case 'U':
				face = 0;
				break;
			case 'L':
				face = 4;
				break;
			case 'F':
				face = 1;
				break;
			case 'R':
				face = 2;
				break;
			case 'B':
				face = 3;
				break;
			case 'D':
				face = 5;
				break;
			default:
				face = -1;
				break;
			}

			if (face < 0)
				return -1;

			CUB_GirarFace(cubo, face, 1, rot);

			i += jump;
		}

		printf("\nExecute %s\n", algoritmo);

	return 0;
}

