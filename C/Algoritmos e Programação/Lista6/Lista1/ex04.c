#include<stdio.h>

main()
{
	int nasc,idade, dias;
	printf("Qual ano vc nasceu?\n");
	scanf("%i", &nasc);
	idade = 2024-nasc;
	dias = idade*365;
	printf("Vc tem aprox. %i dias de vida.", dias);
	   
}
