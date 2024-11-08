//Receber 10 n�meros e informar se cada um deles � negativo, positivo ou nulo.

#include <stdio.h>

main()
{
	int i;
	int num;
	
	for (i = 0; i < 10; i++)
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


// estrutura básica ded for

// int i;    //lembrar de inicializar o i
// for (i = 0; i < "quantidade"; i++)
// {
// 		codigo
// }

