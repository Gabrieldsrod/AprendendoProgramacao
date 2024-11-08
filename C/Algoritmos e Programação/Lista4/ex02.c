//Receber um n�mero e mostrar sua tabuada do 1 ao 10.

#include <stdio.h>

main ()
{
	int num, tab, i;
	
	printf("-----Tabuada-----\n");
	printf("Digite um numero:");
	scanf("%i", &num);
	
	for (i = 0; i < 10; i++)
	{
		tab = num * (i + 1);
		printf("%i x %i = %i\n", num, i + 1, tab);
	}
}
