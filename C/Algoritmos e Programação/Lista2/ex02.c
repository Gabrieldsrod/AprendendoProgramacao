#include<stdio.h>

int main(){
	int num;
	
	printf("Digite um numero: ");
	scanf("%i", &num);
	
	if(num <= 9 && num >= 0)
	{
		printf("O numero esta no intervalo entre 0 e 9!");
	}
	else
	{
		printf("O numero n esta no intervalo entre 0 e 9!");
	}
}
