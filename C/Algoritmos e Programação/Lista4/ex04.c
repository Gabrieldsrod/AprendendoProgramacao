//Receber 2 n�meros inteiros e exibir todos os n�meros inteiros existentes entre eles.

#include <stdio.h>

int main ()
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
		for (i = num1 + 1 ; i < num2; i++)
		{
			printf("%i\n", i);
		}
	}
	
	else
	{
		for (i = num2 + 1; i < num1; i++)
		{
			printf("%i\n", i);
		}
	}

	return 0;
}

