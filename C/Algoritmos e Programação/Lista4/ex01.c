//Receber 10 n�meros e mostrar o dobro de cada um deles.

#include <stdio.h>

main ()
{
	int num, i;
	
	for (i = 1; i <= 10; i++)
	{
		printf("Digite um numero: ");
		scanf("%i", &num);
		printf("O dobro deste numero e %i\n", num * 2);
	}
}
