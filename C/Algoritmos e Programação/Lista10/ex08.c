// Leia uma matriz 3 x 10 que se refere as respostas de 10 questões de
// múltipla escolha, referentes a 3 alunos. Leia também um vetor de 10
// posições contendo o gabarito de respostas que podem ser a, b, c ou d.
// Seu programa deverá comparar as respostas de cada aluno com o
// gabarito e emitir um vetor de resultados (cada questão vale um ponto),
// contendo a pontuação correspondente a cada aluno.

#include<stdio.h>

#define QUESTOES 10
#define ALUNOS 3

int main(){
    char gabarito[QUESTOES];
    char respostas[ALUNOS][QUESTOES];
    int resultados[ALUNOS] = {0};
    int i, j;

    printf("Digite o gabarito das questoes:\n(a) (b) (c) ou (d)\n");
    for (i = 0; i < QUESTOES; i++){
        printf("Questao %i: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    printf("\nDigite as respostas dos alunos:");
    for (i = 0; i < ALUNOS; i++){
        printf("\nAluno %i\n", i + 1);
        for (j = 0; j < QUESTOES; j++){
            printf("Resposta questao %i: ", j + 1);
            scanf(" %c", & respostas[i][j]);
        }
    }

    for (i = 0; i < ALUNOS; i++){
        for (j = 0; j < QUESTOES; j++){
            if (respostas[i][j] == gabarito[j]){
                resultados[i]++;
            }
        }
    }
    
    printf("\nResultados:\n");
    for (i = 0; i < ALUNOS; i++){
        printf("Aluno %i: %i pontos\n", i + 1, resultados[i]);
    }    
}