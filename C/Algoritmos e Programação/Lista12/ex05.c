// Faça um programa que leia 10 elementos de um vetor e um valor de
// código. A seguir chame uma função para escrever o vetor da seguinte
// maneira: se o código for 1, mostrar o vetor na ordem direta que foi lido, se
// o código for 2, mostrar o vetor na ordem inversa a da leitura. 

#include<stdio.h>

void escrever_vetor(int vetor[], int valor) {
    if (valor == 1) {
        for(int i = 0; i < 10; i++) {
            printf("%5i", vetor[i]);
        }
    }
    else if(valor == 2) {
        for (int i = 9; i >= 0; i--) {
            printf("%5i", vetor[i]);
        }
    }
}

int main()
{
    int array[10];
    int value;

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento [%i]: ", i + 1);
        scanf("%i", &array[i]);
    }

    do
    {
        printf("\nDigite um valor para realizar o processo especificado:\n");
        printf("[1] Mostrar o vetor na ordem direta\n[2] Mostrar o vetor na ordem inversa\nEscolha: ");
        scanf("%i", &value);
    } while (value != 1 && value !=2);
    
    escrever_vetor(array, value);

    return 0;
}
