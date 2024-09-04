#include <stdio.h>

int main() {
    int habitantes = 4;
    float salario, soma_salarios = 0, maior_salario = 0;
    int numero_filhos, soma_filhos = 0, count_salario_ate_500 = 0;

    // Solicitar e receber os dados de salário e número de filhos para cada habitante
    for (int i = 1; i <= habitantes; i++) {
        printf("Habitante %d:\n", i);

        // Receber o salário
        printf("Salário: R$ ");
        scanf("%f", &salario);
        soma_salarios += salario;

        // Verificar se o salário é o maior até agora
        if (salario > maior_salario) {
            maior_salario = salario;
        }

        // Contar o percentual de pessoas com salário até R$ 500,00
        if (salario <= 500.00) {
            count_salario_ate_500++;
        }

        // Receber o número de filhos
        printf("Número de filhos: ");
        scanf("%d", &numero_filhos);
        soma_filhos += numero_filhos;
    }

    // Calcular a média do salário da população
    float media_salario = soma_salarios / habitantes;

    // Calcular a média do número de filhos
    float media_filhos = (float)soma_filhos / habitantes;

    // Calcular o percentual de pessoas com salário até R$ 500,00
    float percentual_salario_ate_500 = (float)count_salario_ate_500 / habitantes * 100;

    // Exibir os resultados
    printf("\nResultados:\n");
    printf("Média do salário da população: R$ %.2f\n", media_salario);
    printf("Média do número de filhos: %.2f\n", media_filhos);
    printf("Maior salário: R$ %.2f\n", maior_salario);
    printf("Percentual de pessoas com salário até R$ 500,00: %.2f%%\n", percentual_salario_ate_500);

    return 0;
}
