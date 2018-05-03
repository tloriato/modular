#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALG 55
#define MAX 600

#define CIMA 0
#define FRENTE 1
#define DIREITA 2
#define TRASEIRA 3
#define ESQUERDA 4
#define BAIXO 5

#define BRANCO 0
#define VERDE 1
#define LARANJA 2
#define AZUL 3
#define VERMELHO 4
#define AMARELO 5

// Ou seja, cores das faces são fixas

/* STRING GLOBAL QUE GUARDA OS COMANDOS */

char comandos[MAX] = "";

// (cubo) -> 1 | 0
int resolvidoAcima(CUB_tpCubo* cubo) {
//CUB_tpCondRet CUB_buscaPeca(CUB_tpPeca *Peca, CUB_tpCubo *cubo, int cores[], int numCores);
	/*CUB_tpPeca *peca1, *peca2, *peca3, *peca4, *peca5, *peca6, *peca7, *peca8, *peca9;
	int cores[3], numCores;

	cores[0]=VERDE; cores[1]=BRANCO
	CUB_buscaPeca(peca1, cubo, cores, numCores);*/ //aresta frente/cima

	return 0;
	/*
	int corCima, aux1, aux2, aux3, aux4, aux5, aux6, aux7, aux8;

	if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(11); }

	if (CUB_ChecarCorDaFace(&aux1, cubo, 0, 0, CIMA) != 0) { exit(11); }
	if (CUB_ChecarCorDaFace(&aux2, cubo, 0, 1, CIMA) != 0) { exit(12); }
	if (CUB_ChecarCorDaFace(&aux3, cubo, 0, 2, CIMA) != 0) { exit(13); }

	if (CUB_ChecarCorDaFace(&aux4, cubo, 1, 0, CIMA) != 0) { exit(14); }
	if (CUB_ChecarCorDaFace(&aux5, cubo, 1, 2, CIMA) != 0) { exit(15); }

	if (CUB_ChecarCorDaFace(&aux6, cubo, 2, 0, CIMA) != 0) { exit(16); }
	if (CUB_ChecarCorDaFace(&aux7, cubo, 2, 1, CIMA) != 0) { exit(17); }
	if (CUB_ChecarCorDaFace(&aux8, cubo, 2, 2, CIMA) != 0) { exit(18); }

	if (corCima == aux1 == aux2 == aux3 == aux4 == aux5 == aux6 == aux7 == aux8) {
		return 1;
	}
	else {
		return 0;
	}
	*/
}

int pecaDeCimaTrocada(int face, int faceAresta, int linhaAresta, int colunaAresta, int resolvidoPraCima) {

	if (face == DIREITA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 2 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 1 && colunaAresta == 2 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == TRASEIRA) {
		if (faceAresta == CIMA && linhaAresta == 0 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 2 && colunaAresta == 1 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == ESQUERDA) {
		if (faceAresta == CIMA && linhaAresta == 1 && colunaAresta == 0 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 1 && colunaAresta == 0 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	else if (face == FRENTE) {
		if (faceAresta == CIMA && linhaAresta == 2 && colunaAresta == 1 && resolvidoPraCima == 0) {
			return 1;
		}
		else if (faceAresta == BAIXO && linhaAresta == 0 && colunaAresta == 1 && resolvidoPraCima == 1) {
			return 1;
		}
	}

	return 0;
}

int resolveArestaDeFace(CUB_tpCubo* cubo, int face, int resolvidoPraCima) {

	int restantes = 2;

	int corFrente, corCima, corDireita, corEsquerda, corTraseira, corBaixo;

	CUB_tpPeca * pecaFrente;
	CUB_tpPeca * pecaCima;
	CUB_tpPeca * pecaDireita;
	CUB_tpPeca * pecaEsquerda;
	CUB_tpPeca * pecaTraseira;
	CUB_tpPeca * pecaBaixo;

	int cor[3];
	int i = 0;

	CUB_tpPeca * pecaAux = CUB_criaPeca();

	int faceDireitaRelativa = 0, faceEsquerdaRelativa = 0;

	int faceArestaD, linhaArestaD, colunaArestaD, cor1ArestaD, cor2ArestaD;
	int faceArestaE, linhaArestaE, colunaArestaE, cor1ArestaE, cor2ArestaE;

	char * algoDireita;
	char * algoEsquerda;
	char * algoIntermediario;
	
	if (cubo == NULL)
		return -1;

	//if (CUB_ChecarCorDaFace(&corFrente, cubo, 1, 1, FRENTE) != 0) { exit(1); }
	//if (CUB_ChecarCorDaFace(&corCima, cubo, 1, 1, CIMA) != 0) { exit(2); }
	//if (CUB_ChecarCorDaFace(&corDireita, cubo, 1, 1, DIREITA) != 0) { exit(3); }
	//if (CUB_ChecarCorDaFace(&corEsquerda, cubo, 1, 1, ESQUERDA) != 0) { exit(4); }
	//if (CUB_ChecarCorDaFace(&corTraseira, cubo, 1, 1, TRASEIRA) != 0) { exit(5); }
	//if (CUB_ChecarCorDaFace(&corBaixo, cubo, 1, 1, BAIXO) != 0) { exit(6); }

	switch (face) {
	case(FRENTE): {
		cor1ArestaD = FRENTE;	
		cor1ArestaE = FRENTE;

		cor2ArestaD = DIREITA;
		cor2ArestaE = ESQUERDA;

		if (resolvidoPraCima) {
			algoDireita = "D R' D' R D' F D F'";
			algoEsquerda = "D' L D L' D F' D' F";
			algoIntermediario = "D' D'";
		}
		else {
			algoDireita = "U R U' R' U' F' U F";
			algoEsquerda = "U' L' U L U F U' F'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(DIREITA): {
		cor1ArestaD = DIREITA;
		cor1ArestaE = DIREITA;

		cor2ArestaD = TRASEIRA;
		cor2ArestaE = FRENTE;

		if (resolvidoPraCima) {
			algoDireita = "D F' D' F D' L D L'";
			algoEsquerda = "D' B D B' D L' D' L";
			algoIntermediario = "D' D'";;

		}
		else {
			algoDireita = "U B U' B' U' R' U R";
			algoEsquerda = "U' F' U F U R U' R'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(ESQUERDA): {
		cor1ArestaD = ESQUERDA;
		cor1ArestaE = ESQUERDA;

		cor2ArestaD = FRENTE;
		cor2ArestaE = TRASEIRA;

		if (resolvidoPraCima) {
			algoDireita = "D B' D' B D' R D R'";
			algoEsquerda = "D' F D F' D R' D' R";
			algoIntermediario = "D' D'";

		}
		else {
			algoDireita = "U F U' F' U' L' U L";
			algoEsquerda = "U' B' U B U L U' L'";
			algoIntermediario = "U U";
		}

		break;
	}
	case(TRASEIRA): {
		cor1ArestaD = TRASEIRA;
		cor1ArestaE = TRASEIRA;

		cor2ArestaD = ESQUERDA;
		cor2ArestaE = DIREITA;

		if (resolvidoPraCima) {
			algoDireita = "D L' D' L D' B D B'";
			algoEsquerda = "D' R D R' D B' D' B";
			algoIntermediario = "D' D'";

		}
		else {
			algoDireita = "U L U' L' U' B' U B";
			algoEsquerda = "U' R' U R U B U' B'";
			algoIntermediario = "U U";
		}

		break;
	}
	default: {
		return -1;
	}
	}
	cor[0] = cor1ArestaD; cor[1] = cor2ArestaD;
	CUB_buscaPeca(pecaDireita, cubo, cor, 2);

	cor[0] = cor1ArestaE; cor[1] = cor2ArestaE;
	CUB_buscaPeca(pecaEsquerda, cubo, cor, 2);
	//if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaD, &linhaArestaD, &colunaArestaD, cubo, cor1ArestaD, cor2ArestaD) != 0) { exit(8); }
	//if (CUB_EncontrarPosicaoDePecaDeAresta(&faceArestaE, &linhaArestaE, &colunaArestaE, cubo, cor1ArestaE, cor2ArestaE) != 0) { exit(9); }

	(face + 1) == 5 ? faceDireitaRelativa = 1 : (faceDireitaRelativa = (face + 1));
	(face - 1) == 0 ? faceDireitaRelativa = 4 : (faceDireitaRelativa = (face - 1));
	
	

	if (faceArestaD == face && linhaArestaD == 1 && colunaArestaD == 2) {
		// Aresta da Direita de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {
			// Cubo está resolvido para cima
			if (faceArestaD == face && linhaArestaD == 2 && colunaArestaD == 1) {
				// Algoritmo "Baixo" -> Direita
				restantes--;
			}

			else if (faceArestaD == faceDireitaRelativa && linhaArestaD == 1 && colunaArestaD == 0) {
				// Algoritmo de trocar a orientação da aresta do lado direito
				restantes--;
			}

			else if (
				
				(face, faceArestaD, linhaArestaD, colunaArestaD, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Direita + Trocar orientação do lado direito
				restantes--;
			}
		}
		else {

			if (faceArestaD == face && linhaArestaD == 0 && colunaArestaD == 1) {
				// Algoritmo Cima -> Direita
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

			else if (faceArestaD == faceDireitaRelativa && linhaArestaD == 1 && colunaArestaD == 0) {
				// Algoritmo de trocar a orientação do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaD, linhaArestaD, colunaArestaD, resolvidoPraCima)) {
				// Algoritmo Cima -> Direita + Trocar orientação do lado direito
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoDireita);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoDireita);
				restantes--;
			}

		}

	}

	if (faceArestaE == face && linhaArestaE == 1 && colunaArestaE == 0) {
		// Aresta da Esquerda de [face] está resolvida
		restantes--;
	}

	else {

		if (resolvidoPraCima) {

			if (faceArestaE == face && linhaArestaE == 2 && colunaArestaE == 1) {
				// Algoritmo "Baixo" -> Esquerda
				restantes--;
			}

			else if (faceArestaE == faceEsquerdaRelativa && linhaArestaE == 1 && colunaArestaE == 2) {
				// Algoritmo de trocar a orientação da aresta do lado esquerdo
				restantes--;
			}

			else if (pecaDeCimaTrocada(face, faceArestaE, linhaArestaE, colunaArestaE, resolvidoPraCima)) {
				// Algoritmo "Baixo" - > Esquerda + Trocar orientação do lado esquerda
				restantes--;
			}

		}

		else {

			if (faceArestaE == face && linhaArestaE == 0 && colunaArestaE == 1) {
				// Algoritmo Cima -> Esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;

			}

			else if (faceArestaE == faceEsquerdaRelativa && linhaArestaE == 1 && colunaArestaE == 2) {
				// Algoritmo de trocar a orientação do lado esquerdo
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;

			}

			else if (pecaDeCimaTrocada(face, faceArestaE, linhaArestaE, colunaArestaE, resolvidoPraCima)) {
				// Algoritmo Cima -> Esquerda + Trocar orientação do lado esquerda
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoEsquerda);
				executaAlgoritmo(cubo, algoIntermediario);
				executaAlgoritmo(cubo, algoEsquerda);
				restantes--;
			}

		}

	}

	*/
	return restantes;
}

// (cubo, algoritmo) ~> inteiro
//	cubo = estrutura CUB_tppCUBO populada
//	algoritmo = string de no máximo ALG elementos com comandos no estilo:
//		"U R U' R' U' F' U U F F"
//	inteiro =
//		0 -> sucesso
//		-1 -> entradas invalidas (TODO)
int executaAlgoritmo(CUB_tpCubo* cubo, char* algoritmo)
{

	int i = 0;

	char comandos[ALG];
	memset(comandos, '\0', sizeof(comandos));
	strcpy(comandos, algoritmo);

	while (comandos[i]) {

		if (comandos[i] == 'U') {
			if (comandos[i + 1] == '\'') {
				CUB_giraTrasDireita(cubo, 1);
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
				CUB_giraTopoDireita(cubo, 1);
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
				CUB_giraBaixoDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else {
				CUB_giraBaixoEsquerda(cubo, 1);
				//executa sentido horario
				i += 2;
			}
		}
		else if (comandos[i] == 'F') {
			if (comandos[i + 1] == '\'') {
				CUB_giraFrenteDireita(cubo, 1);
				//excuta sentido antihorario
				i += 3;
			}
			else
				CUB_giraFrenteEsquerda(cubo, 1);
			//executa sentido horario
			i += 2;
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



	}

	return 0;
}

// Aux
int aux(int a, int b, int c, int d) {
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		return 0;
	}

	return 1;
}

// Rotina para Resolver o Cubo
int resolveCubo(CUB_tpCubo* cubo) {
	int r = 1, j = 1, i = 0;

	int primeiraFrente = 2, segundaFrente = 2;
	int primeiraDireita = 2, segundaDireita = 2;
	int primeiraTraseira = 2, segundaTraseira = 2;
	int primeiraEsquerda = 2, segundaEsquerda = 2;

	int resolvidoPraCima = resolvidoAcima(cubo);

	while (r) {


		if (i == 3) {
			// força o cubo
			i = 0;

			//forcaCuboFrente(cubo);
		}

		if (j == 0) {
			j++;

			primeiraFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			primeiraDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			primeiraTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			primeiraEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
			r = aux(primeiraFrente, primeiraDireita, primeiraTraseira, primeiraEsquerda);
		}
		else if (j == 1) {
			j++;

			segundaFrente = resolveArestaDeFace(cubo, FRENTE, resolvidoPraCima);
			segundaDireita = resolveArestaDeFace(cubo, DIREITA, resolvidoPraCima);
			segundaTraseira = resolveArestaDeFace(cubo, TRASEIRA, resolvidoPraCima);
			segundaEsquerda = resolveArestaDeFace(cubo, ESQUERDA, resolvidoPraCima);
			r = aux(segundaFrente, segundaDireita, segundaTraseira, segundaEsquerda);
		}
		else if (j == 2) {
			// Move o layer de cima/baixo do cubo
			j = 0;
			i++;

			if (resolvidoPraCima) {
				executaAlgoritmo(cubo, "D");
			}
			else {
				executaAlgoritmo(cubo, "U");
			}
		}
	}
}

int main() {
	CUB_tpCubo * cubo = NULL;
	int cor[1];
	int i = 0;
	CUB_tpPeca * pecaAux = CUB_criaPeca();

	if (CUB_criaCubo(&cubo) != 0) { exit(1); }

	// Preenche o Cubo
	if (1) {

		/* Face de Cima */

		if (CUB_preencheCubo(cubo, 0, 0, 0, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 0, 1, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 0, 2, BRANCO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 0, 1, 0, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 1, 1, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 1, 2, BRANCO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 0, 2, 0, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 2, 1, BRANCO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 0, 2, 2, BRANCO) != 0) { exit(2); }

		/* Face da Esquerda */

		if (CUB_preencheCubo(cubo, 4, 0, 0, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 0, 1, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 0, 2, LARANJA) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 4, 1, 0, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 1, 1, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 1, 2, LARANJA) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 4, 2, 0, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 2, 1, LARANJA) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 4, 2, 2, LARANJA) != 0) { exit(2); }

		/* Face da Frente */

		if (CUB_preencheCubo(cubo, 1, 0, 0, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 0, 1, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 0, 2, VERDE) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 1, 1, 0, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 1, 1, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 1, 2, VERDE) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 1, 2, 0, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 2, 1, VERDE) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 1, 2, 2, VERDE) != 0) { exit(2); }

		/* Face da Direita */

		if (CUB_preencheCubo(cubo, 2, 0, 0, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 0, 1, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 0, 2, VERMELHO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 2, 1, 0, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 1, 1, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 1, 2, VERMELHO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 2, 2, 0, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 2, 1, VERMELHO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 2, 2, 2, VERMELHO) != 0) { exit(2); }

		/* Face da Traseira */

		if (CUB_preencheCubo(cubo, 3, 0, 0, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 0, 1, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 0, 2, AZUL) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 3, 1, 0, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 1, 1, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 1, 2, AZUL) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 3, 2, 0, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 2, 1, AZUL) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 3, 2, 2, AZUL) != 0) { exit(2); }

		/* Face debaixo */

		if (CUB_preencheCubo(cubo, 5, 0, 0, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 0, 1, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 0, 2, AMARELO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 5, 1, 0, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 1, 1, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 1, 2, AMARELO) != 0) { exit(2); }

		if (CUB_preencheCubo(cubo, 5, 2, 0, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 2, 1, AMARELO) != 0) { exit(2); }
		if (CUB_preencheCubo(cubo, 5, 2, 2, AMARELO) != 0) { exit(2); }

	}

	

	for (i = 0; i < 6; i++) {
		cor[0] = i;
		CUB_buscaPeca(pecaAux, cubo, cor, 2);
		printf("quero ver algo");
		printf("%d", pecaAux->C);
	}

	resolveCubo(&cubo);

	return 0;

}
