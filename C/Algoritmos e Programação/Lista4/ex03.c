//Receber 10 números e informar se cada um deles é negativo, positivo ou nulo.

#include <stdio.h>

main()
{
	int i;
	int num;
	
	for (i = 1; i <= 10; i++)
	{
		printf("Digite um numero: ");
		scanf("%i", &num);
		
		if (num < 0)
		{
			printf("O numero %i e negativo\n", num);
		}
		
		else if (num > 0)
		{
			printf("O numero %i e positivo\n", num);
		}
		
		else
		{
			printf("O numero e nulo\n");
		}
	}
}

