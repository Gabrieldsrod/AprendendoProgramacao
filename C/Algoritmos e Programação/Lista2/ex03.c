/*Receber numerador e denominador. Calcular e mostrar o resultado da
divis�o, desde que poss�vel (denominador diferente de zero). Se n�o for
poss�vel dividir, apenas escreva �n�o existe divis�o por zero�*/

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
