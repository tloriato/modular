## Trabalho de Modular 2018.1

---

#### Terminologia:

##### Nota:

Todas as rotações são feitas com o cubo fixo, mantendo a perspectiva de estar olhando para a face frontal. Ao mudar a face frontal, as novas instruções já estarão de acordo.

"Face [cor X]" se refere à face do cubo que possui como peça central um painél de cor X. 

##### X vs X':

X representa uma rotação de 90° no sentido horário.
X' representa uma rotação de 90° no sentido anti-horário.

##### Movimentos:

U & U' : Gira a face de cima.
E & E' : Gira a linha horizontal do meio.
D & D' : Gira a face de baixo.
R & R' : Gira a face direita.
L & L' : Gira a face esquerda.
F & F' : Gira a face frontal.
B & B' : Gira a face traseira.
M & M' : Gira a linha vertical do meio.
S & S' : Gira a face do meio, a que possui 3 peças de cada uma das faces: cima, direita, de baixo e esquerda.

##### Peças:

Peças de Canto: Existem 8 peças de canto no Cube. Elas possuem 3 painés de cores que podem estar em quaisquer ordens.

Peças de Borda: Existem 12 peças de borda. Elas possuem 2 painés de cores que podem estar em quaisquer ordens.

---

#### Algoritmo:

##### Objetivo:

- Ter a face superior completa.
- Ter a primeira linha de todas as faces completa.

##### Descrição:

1. Comece botando a face branca para cima.
1. Identifique a cor da peça central da face frontal, e chame a cor de X.
1. Busque pela Peça de Canto da cor X/Branca, chame a peça de Y.
1. Mova Y para a face de baixo do cubo. *Se não for possível fazê-lo sem modificar o sinal de + que está se formando na face de cima, pule para o passo N*
1. Rotacione a face de baixo de forma que um painel de Y esteja na face frontal.
1. *Analise: Se o painél da face de baixo de Y for Branco, siga para o passo 7, caso contrário pule para o passo 8.*
1. Gire a face frontal 180°. *Pule para o passo 9*.
1. Assuma como face frontal o lado do cubo que teria a sua parte da cruz modificada.

**WIP**


