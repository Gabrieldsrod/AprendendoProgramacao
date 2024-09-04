/*Receber numerador e denominador. Calcular e mostrar o resultado da
divisão, desde que possível (denominador diferente de zero). Se não for
possível dividir, apenas escreva “não existe divisão por zero”*/

#include<stdio.h>

int main() {
	int num, den;
	float res;
	
	printf("Digite o numerador: ");
	scanf("%i", &num);
	printf("Digite o denominador: ");
	scanf("%i", &den);
		
	if(den != 0){
		res = num / den;
		printf("O resultado da divisao e: %.2f", res);
	}
	else{
		printf("Nao existe divisao por 0!!!");
	}
}
