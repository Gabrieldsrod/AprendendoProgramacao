//Receber três números e mostrar qual é o maior deles.
#include <stdio.h>

int main()
{
    int num1, num2, num3;

    printf("Digite 3 numeros:\n");
    scanf("%i %i %i", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
    {
        printf("O maior numero e: %i\n", num1);
    }

    else if (num2 >= num1 && num2 >= num3)
    {
        printf("O maior numero e: %i\n", num2);
    }
    
    else
    {
        printf("O maior numero e: %i", num3);
    }

}