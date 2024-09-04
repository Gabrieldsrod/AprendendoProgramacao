#include <stdio.h>

int main() {
    int tamanho = 5;
    int linha, coluna;

    for (linha = 1; linha <= tamanho; linha++) {
        for (coluna = 1; coluna <= linha; coluna++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}