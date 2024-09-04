// Preencher automaticamente um vetor com todos os números pares entre 1
// e 100 e depois exibir os números para o usuário.

#include <stdio.h>


int main() {
    int pares[50];
    int i, numero = 2;

    for (i = 0; i < 50; i++) {
        pares[i] = numero;
        numero += 2;
    }

    printf("Números pares entre 1 e 100:\n");
    for (i = 0; i < 50; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");

    return 0;
}
