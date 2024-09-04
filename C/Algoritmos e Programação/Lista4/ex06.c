//Implementar um programa que exibe todos os números inteiros de 1 a
//1000 em ordem inversa (1000, 999, 998, ..., 3, 2, 1)

#include <stdio.h>

main()
{
	int i;
	
	for (i = 1000; i >= 1; i--)
	{
		printf("%i\n", i);
	}
}
