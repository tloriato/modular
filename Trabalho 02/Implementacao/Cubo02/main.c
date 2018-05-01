#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "CUBO.h"
#include <stdio.h>
#include <stdlib.h>
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

// (config) ~> inteiro
//	config = vetor de 54 inteiros
//	inteiro =
//		0 -> sucesso
int populaCubo(int *config) {

  // 1: Verde | 2: Vermelho | 3: Amarelo | 4: Azul | 5: Branco | 6: Laranja

  // Up Face 0

  config[0][0][0] = LARANJA;
  config[0][0][1] = LARANJA;
  config[0][0][2] = LARANJA;

  config[0][1][0] = LARANJA;
  config[0][1][1] = LARANJA;
  config[0][1][2] = LARANJA;

  config[0][2][0] = LARANJA;
  config[0][2][1] = LARANJA;
  config[0][2][2] = LARANJA;
  // Left Face 4
  config[4][0][0] = AMARELO;
  config[4][0][1] = AMARELO;
  config[4][0][2] = AMARELO;

  config[4][1][0] = AMARELO;
  config[4][1][1] = AMARELO;
  config[4][1][2] = AMARELO;

  config[4][2][0] = AMARELO;
  config[4][2][1] = AMARELO;
  config[4][2][2] = AMARELO;

  // Front Face 1
  config[1][0][0] = AMARELO;
  config[1][0][1] = AMARELO;
  config[1][0][2] = AMARELO;

  config[1][1][0] = AMARELO;
  config[1][1][1] = AMARELO;
  config[1][1][2] = AMARELO;

  config[1][2][0] = AMARELO;
  config[1][2][1] = AMARELO;
  config[1][2][2] = AMARELO;

  // Right Face 2
  config[2][0][0] = AMARELO;
  config[2][0][1] = AMARELO;
  config[2][0][2] = AMARELO;

  config[2][1][0] = AMARELO;
  config[2][1][1] = AMARELO;
  config[2][1][2] = AMARELO;

  config[2][2][0] = AMARELO;
  config[2][2][1] = AMARELO;
  config[2][2][2] = AMARELO;

  // Back Face 3
  config[3][0][0] = AMARELO;
  config[3][0][1] = AMARELO;
  config[3][0][2] = AMARELO;

  config[3][1][0] = AMARELO;
  config[3][1][1] = AMARELO;
  config[3][1][2] = AMARELO;

  config[3][2][0] = AMARELO;
  config[3][2][1] = AMARELO;
  config[3][2][2] = AMARELO;

  // Down Face 5
  config[5][0][0] = BRANCO;
  config[5][0][1] = BRANCO;
  config[5][0][2] = BRANCO;

  config[5][1][0] = BRANCO;
  config[5][1][1] = BRANCO;
  config[5][1][2] = BRANCO;

  config[5][2][0] = BRANCO;
  config[5][2][1] = BRANCO;
  config[5][2][2] = BRANCO;

  return 0;
}

// (cubo, algoritmo) ~> inteiro
//	cubo = estrutura CUB_tppCUBO populada
//	algoritmo = string de no máximo ALG elementos com comandos no estilo:
//		"U R U' R' U' F' U U F F"
//	inteiro =
//		0 -> sucesso
//		-1 -> entradas invalidas (TODO)
int executaAlgoritmo(CUB_tpCubo *cubo, char *algoritmo) {

  int i = 0;
  int ret;

  char comandos[ALG];
  memset(comandos, '\0', sizeof(comandos));
  strcpy(comandos, algoritmo);

  while (comandos[i]) {

    if (comandos[i] == 'U') {
      if (comandos[i + 1] == '\'') {
        CUB_giraTrasDireita(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else {
        CUB_giraTopoEsquerda(cubo, 1);
        // executa sentido horario
        i += 2;
      }
    }

    else if (comandos[i] == 'B') {
      if (comandos[i + 1] == '\'') {
        CUB_giraTopoDireita(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else {
        CUB_giraTrasEsquerda(cubo, 1);
        // executa sentido horario
        i += 2;
      }
    }

    else if (comandos[i] == 'D') {
      if (comandos[i + 1] == '\'') {
        CUB_giraBaixoDireita(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else {
        CUB_giraBaixoEsquerda(cubo, 1);
        // executa sentido horario
        i += 2;
      }
    } else if (comandos[i] == 'F') {
      if (comandos[i + 1] == '\'') {
        CUB_giraFrenteDireita(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else
        CUB_giraFrenteEsquerda(cubo, 1);
      // executa sentido horario
      i += 2;
    } else if (comandos[i] == 'R') {
      if (comandos[i + 1] == '\'') {
        CUB_giraDireitaFrente(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else {
        CUB_giraDireitaTras(cubo, 1);
        // executa sentido horario
        i += 2;
      }
    } else if (comandos[i] == 'L') {
      if (comandos[i + 1] == '\'') {
        CUB_giraEsquerdaTras(cubo, 1);
        // excuta sentido antihorario
        i += 3;
      } else {
        CUB_giraEsquerdaFrente(cubo, 1);
        // executa sentido horario
        i += 2;
      }
    }
  }

  return 0;
}
