#include <stdio.h>

int main()
{
	int num;
	printf("Digite um numero: ");
	scanf("%i", &num);
	
	if(num > 0)
	{
		printf("Este numero e positivo");	
	}
	else
	{
		printf("Este numero e negativo");
	}
}
