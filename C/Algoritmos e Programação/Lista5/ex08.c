// Desenvolver um programa que recebe a quantidade de alunos que estão
// cursando o 3º semestre. Para cada aluno receber a quantidade de
// disciplinas que cursou no 2º semestre e também a nota final relativa a
// cada disciplina. Calcular e mostrar a média de cada aluno para verificar o
// aproveitamento do último semestre cursado.

#include <stdio.h>

int main() {
    int alunos, i, disciplinas, j;
    float nota, media;
    float somanotas = 0;

    printf("Digite a quantidade de alunos cursando o 3o semestre: ");
    scanf("%d", &alunos);

    for (i = 1; i <= alunos; i++) {
        printf("\nAluno %d:\n", i);

        printf("Digite a quantidade de disciplinas cursadas no 2o semestre: ");
        scanf("%d", &disciplinas);

        for (j = 1; j <= disciplinas; j++) {
            printf("Digite a nota final da disciplina %d: ", j);
            scanf("%f", &nota);

            somanotas += nota;
        }

        media = somanotas / disciplinas;

        printf("Media do aluno %d: %.2f\n", i, media);
        
        if (media >= 6.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

}