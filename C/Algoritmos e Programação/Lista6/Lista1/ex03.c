#include<stdio.h>

main()
{
	float metros, cent;
	printf("Digite um valor em metros: ");
	scanf("%f", &metros);
	cent = metros*100;
	printf("\n%f metros equivalem a %f centimetros\n", metros,cent);
	
}
