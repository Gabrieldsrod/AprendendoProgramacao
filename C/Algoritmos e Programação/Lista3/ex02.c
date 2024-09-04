// Receber um intervalo (dois valores) e em seguida um número. Informar se
// o número está dentro, fora ou nas extremidades do intervalo.

#include <stdio.h>

int main()
{
	int int1, int2, num;
	
	printf("Digite um intervalo de numeros:\n");
	scanf("%i %i", &int1, &int2);
	
	printf("Digite um numero: ");
	scanf("%i", &num);
	
	if (int1 < num && num < int2)
	{
		printf("O numero esta no intervalo");
	}
	else if ((num == int1) || (num == int2))
	{
		printf("O numero esta na extremidade do intervalo");
	}
	else
	{
		printf("O numero esta fora do intervalo");
	}
}