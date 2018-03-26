/*           +------------+
             | 00  01  02 |
             |            |
 Cima   >    | 03  04  05 |
             |            |
             | 06  07  08 |   Direita     Traseira
+------------+------------+------------+------------+
| 09  10  11 | 18  19  20 | 27  28  29 | 36  37  38 |
|            |            |            |            |
| 12  13  14 | 21  22  23 | 30  31  32 | 39  40  41 |
|            |            |            |            |
| 15  16  17 | 24  25  26 | 33  34  35 | 42  43  44 |
+------------+------------+------------+------------+
 Esquerda    | 45  46  47 |
             |            |
             | 48  49  50 |  < Baixo
             |            |
             | 51  52  53 |
             +------------+                                    
*/

module.exports = {

  newCube: function (cube = false) {
    if(cube){
      let prototype = importCube(cube);
      this.cp = prototype.cp;
      this.ep = prototype.ep;
      this.co = prototype.co;
    } else {
      this.cp = ['U', 'L', 'F', 'R', 'B', 'D']; // U L F R B D 
      this.ep = [
        ['U', 'B'], ['U', 'R'], ['U', 'F'], ['U', 'L'], // 01/37 | 05/28 | 07/19 | 03/10
        ['F', 'R'], ['F', 'D'], ['F', 'L'],             // 23/30 | 25/46 | 21/14
        ['B', 'L'], ['B', 'D'], ['B', 'R'],             // 41/12 | 43/52 | 39/32
        ['D', 'R'], ['D', 'L']                          // 50/34 | 48/16 
      ];
      this.co = [
        ['U','B','L'],['U','B','R'],['U','F','L'],['U','F','R'], // 00/38/09 | 02/36/29 | 06/18/11 | 08/20/27
        ['D','B','L'],['D','B','R'],['D','F','L'],['D','F','R']  // 51/44/15 | 53/42/35 | 45/24/17 | 47/26/33   
      ];
      this.scramble = function() {
        let moves = "";
        for(let i = 0; i < 35; i++){
          let random = Math.random();
          let z = random > 0.5 ? "'" : ""
          console.log(random);
          if (random < 0.16)
            moves = moves.concat(" U".concat(z));
          else if (random < 0.32)
            moves = moves.concat(" L".concat(z));
          else if (random < 0.48)
            moves = moves.concat(" F".concat(z));
          else if (random < 0.64)
            moves = moves.concat(" R".concat(z));
          else if (random < 0.80)
            moves = moves.concat(" B".concat(z));
          else if (random < 0.96)
            moves = moves.concat(" D".concat(z));
        }
        this.move(moves);
      }
    }
  },
}

function importCube(s){
  let prototype = {};
  prototype.cp = [s[4], s[13], s[22], s[31], s[40], s[49]];
  prototype.ep = [
    [s[1], s[37]], [s[5], s[28]], [s[7], s[19]], [s[3], s[10]],
    [s[23], s[30]], [s[25], s[46]], [s[21], s[14]],
    [s[41], s[12]], [s[43], s[52]], [s[39], s[32]],
    [s[50], s[34]], [s[48], s[16]], 
  ];
  prototype.co = [
    [s[0], s[38], s[9]],[s[2], s[36], s[29]],[s[6], s[18], s[11]],[s[8], s[20], s[27]],
    [s[51], s[44], s[15]],[s[53], s[42], s[35]],[s[45], s[24], s[17]],[s[47], s[26], s[33]]
  ];
  return prototype;
}