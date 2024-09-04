// 7. Escreva uma função que recebe as 3 notas de um aluno por parâmetro e
// uma letra. Se a letra for A, a função calcula a média aritmética das notas
// do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2). A média
// calculada deve ser retornada a função main( ). Crie uma função capaz de
// substituir todos os números negativos de um vetor por seu módulo. 

#include<stdio.h>
#include <ctype.h>


void media_aritmetica(float nota1, float nota2, float nota3) {
    float media;

    media = (nota1 + nota2 + nota3) / 3;
    printf("Media aritmetica: %.2f\n", media);
}

void media_ponderada(float nota1, float nota2, float nota3) {
    float media;

    media = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2)) / 10;
    printf("Media ponderada: %.2f\n", media);
}

int main() {
    float n1, n2, n3;
    char escolha;

    printf("Nota 1: ");
    scanf("%f", &n1);

    printf("Nota 2: ");
    scanf("%f", &n2);

    printf("Nota 3: ");
    scanf("%f", &n3);

    printf("\nDigite a letra de uma das opcoes abaixo:\n");
    printf("[A]Media aritmetica\n[P]Media ponderada\nEscolha:");
    scanf(" %c", &escolha);

    escolha = toupper(escolha);
    
    if(escolha == 'A') {
        media_aritmetica(n1, n2, n3);
    }
    else if(escolha == 'P') {
        media_ponderada(n1, n2, n3);
    }

    return 0;
}