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

##### Cubo:
````
             +------------+
             | U1  U2  U3 |
             |            |
 Cima   >    | U4  U5  U6 |
             |            |
             | U7  U8  U9 |   Direita     Traseira
+------------+------------+------------+------------+
| L1  L2  L3 | F1  F2  F3 | R1  R2  R3 | B1  B2  B3 |
|            |            |            |            |
| L4  L5  L6 | F4  F5  F6 | R4  R5  R6 | B4  B5  B6 |
|            |            |            |            |
| L7  L8  L9 | F7  F8  F9 | R7  R8  R9 | B7  B8  B9 |
+------------+------------+------------+------------+
 Esquerda    | D1  D2  D3 |
             |            |
             | D4  D5  D6 |  < Baixo
             |            |
             | D7  D8  D9 |
             +------------+
````

##### Peças:

1. Peças de Canto: Existem 8 peças de canto no Cube. Elas possuem 3 painés de cores que podem estar em quaisquer ordens. São elas: 
    1. U1/B3/L1 
    1. U3/B1/R3 
    1. L7/B9/D7 
    1. L9/F7/D1 
    1. F1/L3/U7 
    1. F3/U9/R1  
    1. F9/R7/D3
    1. R9/D9/B7


1. Peças de Borda: Existem 12 peças de borda. Elas possuem 2 painés de cores que podem estar em quaisquer ordens.
    1. U2/B2
    1. U4/L2
    1. U6/R2
    1. U8/F2
    1. F4/L6
    1. F6/R4
    1. F8/D2
    1. B4/R6
    1. B6/L4
    1. B8/D8
    1. D6/R8
    1. D4/L8

---

#### Algoritmo:

##### Objetivo:

- Ter a face superior completa.
- Ter a primeira linha de todas as faces completa.

1. Rotacione a face de baixo de forma que um painel de Y na face onde está posicionada a peça central de cor X.
1. *Analise: Se o painél da face de baixo de Y for Branco, siga para o passo 8, caso contrário pule para o passo 9.*
1. Gire a face com a cor central X 180°. *Pule para o passo 10*.
1. Execute a sequência: D' F' R F. *Siga para o passo 8*.
1. ~~Mova sua perspectiva de forma que sua atual face direita, vire sua nova face frontal.~~ Chame a cor central da próxima face, no sentido horário de X. Exemplo: se você acabou de executar as intruções na face frontal, a próxima face seria a face direita. *Siga para o passo 4*.

##### Descrição:

1. Comece botando a face branca para cima.
1. Verifique se a cruz está formada, ou seja, se U2 U4 U6 e U8 são brancos. *Caso positivo, pule para o passo 16*.
1. Identifique a cor da peça central da face frontal, e chame a cor de X.
1. Busque pela Peça de Canto da cor X/Branca, chame a peça de Y.
1. Mova Y para a face de baixo do cubo. ***Se não for possível fazê-lo sem modificar o sinal de + que está se formando na face de cima, ou seja, se a peça residir na mesma coluna de uma face já montada, pule para o passo 11***
1. Rotacione a face de baixo de forma que um painel de Y na face onde está posicionada a peça central de cor X.
1. *Analise: Se o painél da face de baixo de Y for Branco, siga para o passo 8, caso contrário pule para o passo 9.*
1. Gire a face com a cor central X 180°. *Pule para o passo 10*.
1. Execute a sequência: D' F' R F. *Siga para o passo 8*.
1. ~~Mova sua perspectiva de forma que sua atual face direita, vire sua nova face frontal.~~ Chame a cor central da próxima face, no sentido horário de X. Exemplo: se você acabou de executar as intruções na face frontal, a próxima face seria a face direita. *Siga para o passo 4*.
10. *Se sua peça for F4/L6, siga para o passo 12. Se sua peça for F6/R4, siga para o passo 13. Se sua peça for B6/L4, siga para o passo 14. Se sua peça for B4/R6, siga para o passo 15.*
11. Execute: L D' L'. *Siga para o passo 6*.
12. Execute: R' D R. *Siga para o passo 6*.
13. Execute: L' D' L. *Siga para o passo 6*.
14. Execute: R' D R. *Siga para o passo 6*.
15. Certificar-se que U2 U4 U6 e U8 são brancos, *caso negativo ERRO*.
16. Buscar a peça da cor X, branca e cor W (cor seguinte a frontal). Caso verde seja a frontal, W será vermelho, caso X seja vermelho, W será azul, caso X seja azul, W será laranja, caso laranja seja X, verde será W.
17. Caso a peça esteja na face inferior: 
    1. Caso	L7/B9/D7: Execute D D. Siga para o passo 20
    2. Caso L9/F7/D1: Execute D’. Siga para o passo 20
    3. Caso F9/R7/D3 : Siga para o passo 20
    4. Caso R9/D9/B7: Execute D . Siga para o passo 20
18. Caso a peça esteja na face superior: 
    1. Caso U1/B3/L1: Execute L’ D’ L . Retorne para o passo 18.i
    2. Caso U3/B1/R3: Execute R D R’. Siga para o passo 20
    3. Caso F1/L3/U7: Execute L  D’ L’ . Siga para o passo 20
    4. Caso U9/F3/R1. Siga para o passo 20
20.  Repita R’ D R D’ até a peça atingir as posições U9 (branca), F3 (cor X) e R1 (cor W)


