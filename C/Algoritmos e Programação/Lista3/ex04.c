//Receber três números e dizer se existe algum número repetido entre eles.
//Em caso afirmativo, mostre qual o número esta repetido.

#include <stdio.h>

int main() 
{
    int num1, num2, num3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    if (num1 == num2 || num1 == num3) 
	{
        printf("O numero repetido e: %d\n", num1);
    } 

	else if (num2 == num3) 
	{
        printf("O numero repetido e: %d\n", num2);
    } 

	else 
	{
        printf("Nao ha numeros repetidos.\n");
    }

}
