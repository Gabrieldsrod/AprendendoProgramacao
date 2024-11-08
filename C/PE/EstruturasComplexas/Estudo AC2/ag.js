var numeros = [3, 5, 2]; // Ou [3, 5, 2] conforme a descrição do problema

var resul1 = numeros.map(function(num) {
  return num * 2;
});

var resul2 = numeros.reduce(function(x, v) {
  return x + v;
});

console.log(resul1); // Saída: [2, 8, 18] ou [6, 10, 4]
console.log(resul2); // Saída: 14 ou 9

// Declarar resul3 antes do forEach
var resul3 = [];

resul1.forEach(element => {
  resul3.push(element * resul2);
});

console.log(resul3); // Saída: [28, 112, 252] ou [84, 90, 36]