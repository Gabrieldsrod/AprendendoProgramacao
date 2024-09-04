// Receber dois números e mostrar o maior deles.
#include <stdio.h>

int main(){
    int num1, num2;

    printf("Digite um numero: ");
    scanf("%i", &num1);
    printf("Digite outro numero: ");
    scanf("%i", &num2);

    if (num1 > num2){
        printf("O primeiro numero e maior.");
    }
    else{
        printf("O segundo numero e maior.");
    }
}