// Faça um programa que receba o estoque atual de três produtos que estão
// armazenados em quatro armazéns e coloque esses dados em uma matriz
// de 4 linhas e 3 colunas, sendo que as colunas representam os produtos e
// as linhas, os armazéns. Após, calcule e mostre:
// a) a quantidade de itens armazenados no segundo armazém;
// b) a média de produtos do terceiro armazém;
// c) a quantidade total do primeiro produto.

#include <stdio.h>
int main(){
    int estoque[4][3];
    int i, j;
    int totalarmazem2 = 0;
    float mediaterceiroarmazem;
    int totalarmazem3 = 0;
    int totalproduto1 = 0;

    printf("Digite o estoque atual dos produtos em cada armazem:\n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("Armazem %i, produto %i: ", i + 1, j + 1);
            scanf("%i", &estoque[i][j]);
        }
    }
    
    for (j = 0; j < 3; j++){
        totalarmazem2 += estoque[1][j];
    }

    for (j = 0; j < 3; j++){
        totalarmazem3 += estoque[2][j];
    }
    mediaterceiroarmazem = (float)totalarmazem3 / 3;

    for (i = 0; i < 4; i++){
        totalproduto1 += estoque[i][0];
    }

    printf("\nMatriz do estoque:\n");
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("%5i", estoque[i][j]);
        }
        printf("\n");
    }

    printf("\na)Quantidade de itens armazenados no segundo armazem: %d\n", totalarmazem2);
    printf("b)Media de produtos do terceiro armazem: %.2f\n", mediaterceiroarmazem);
    printf("c)Quantidade total do primeiro produto: %d\n", totalproduto1);
}