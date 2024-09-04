//Receber 2 números inteiros e exibir todos os números inteiros existentes entre eles.

#include <stdio.h>

main ()
{
	int num1, num2, i;
	
	printf("Digite um numero: ");
	scanf("%i", &num1);
	printf("Digite outro numero: ");
	scanf("%i", &num2);
	
	printf("Os numeros inteiros existentes\n");
	printf("entre eles sao:\n");
	
	if (num1 < num2)
	{
		for (i = num1 + 1; i <= num2 - 1; i++)
		{
			printf("%i\n", i);
		}
	}
	
	else
	{
		for (i = num2 + 1; i <= num1 - 1; i++)
		{
			printf("%i\n", i);
		}
	}
}

