// Calcular a média de um aluno em um semestre com duas provas,
// onde M = (P1 + P2) / 2. Se a média for maior ou igual a 5 escreva “aprovado”,
// senão calcule e mostre quanto faltou para atingir 5. 

#include<stdio.h>

void calcular_media(float P1, float P2) {

    float M = (P1 + P2) / 2;

    if (M >= 5) {
        printf("APROVADO!!!");
    }
    else {
        printf("REPROVADO!!!\n");

        float dif = 5 - M;
        printf("Faltou %.2f para atingir a media\n", dif);
    }
}

int main() {
    float n1, n2;

    printf("Digite a nota da Prova 1: ");
    scanf("%f", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &n2);

    calcular_media(n1, n2);
}