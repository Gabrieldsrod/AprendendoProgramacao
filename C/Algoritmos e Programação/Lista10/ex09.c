// No exercício anterior, além de receber as respostas de cada aluno, leia
// sua matrícula (número inteiro). Calcule e mostre:
// a) para cada aluno, mostre a sua matrícula, suas respostas, e sua nota.
// b) o percentual de aprovação, assumindo média 5.0
#include <stdio.h>

#define ALUNOS 3
#define QUESTOES 10

int main() {
    char gabarito[QUESTOES];
    char respostas[ALUNOS][QUESTOES];
    int matriculas[ALUNOS];
    int resultados[ALUNOS] = {0};
    float notas[ALUNOS] = {0};
    float media = 5.0;

    printf("Digite o gabarito das respostas (a, b, c ou d):\n");
    for (int i = 0; i < QUESTOES; i++) {
        printf("Questao %d: ", i + 1);
        scanf(" %c", &gabarito[i]); 
    }

    printf("\nDigite as matriculas e respostas dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("\nMatricula do aluno %d: ", i + 1);
        scanf("%d", &matriculas[i]);

        printf("Respostas do aluno %d\n", i + 1);
        for (int j = 0; j < QUESTOES; j++) {
            printf("Resposta da questao %d: ", j + 1);
            scanf(" %c", &respostas[i][j]);
        }
    }

    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < QUESTOES; j++) {
            if (respostas[i][j] == gabarito[j]) {
                resultados[i]++;
            }
        }
        notas[i] = (float)resultados[i];
    }

    printf("\nResultados dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matricula: %d\n", matriculas[i]);
        printf("Respostas: ");
        for (int j = 0; j < QUESTOES; j++) {
            printf("%c ", respostas[i][j]);
        }
        printf("\nNota: %.2f\n", notas[i]);
    }

    int aprovados = 0;
    for (int i = 0; i < ALUNOS; i++) {
        if (notas[i] >= media) {
            aprovados++;
        }
    }
    float percentual_aprovacao = (float)aprovados / ALUNOS * 100;

    printf("\nPercentual de aprovacao: %.2f%%\n", percentual_aprovacao);

    return 0;
}