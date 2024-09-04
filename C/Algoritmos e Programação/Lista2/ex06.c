/* Receber dois números e os apresente em ordem crescente. Utilize
 apenas a estrutura de decisão if, ou seja, sem o opcional else.*/
 #include <stdio.h>

int main(){
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    if (num1 < num2) {
        printf("Os numeros em ordem crescente são: %d, %d\n", num1, num2);
    }
    if (num1 > num2) {
        printf("Os numeros em ordem crescente são: %d, %d\n", num2, num1);
    }

}
