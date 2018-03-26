const Cube = require('./helpers/Cube.js');

const cube = process.argv[2] || Cube.newCube();

console.log(`Programa iniciado com o cubo ${cube}`);