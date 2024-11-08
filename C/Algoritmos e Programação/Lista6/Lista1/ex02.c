#include<stdio.h>

main()
{
	int num1, num2, media;
	printf("Digite um numero: ");
	scanf("%i", &num1);
	printf("\nDigite outro numero: ");
	scanf("%i", &num2);
	media = (num1 + num2)/2;
	printf("A media desses numeros resulta em %i\n", media);
	
}
