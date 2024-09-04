#include<stdio.h>

int main()
{
	int num1, num2, div, rest;
	printf("Digite o numero a ser dividido: ");
	scanf("%i", &num1);
	printf("Digite o divisor: ");
	scanf("%i", &num2);
	div = num1/num2;
	rest = num1%num2;
	printf("\nA divisao entre %i e %i resulta em %i com resto %i.\n", num1, num2, div, rest);

}
