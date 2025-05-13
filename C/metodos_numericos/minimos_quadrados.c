/*
 * Nome: Gabriel da Silva Rodrigues, Isabella Valim de Carvalho, João Vitor Rodrigues Martinelle Vieira, Luiza Mantovani
 * RA: 248103
 * Programa: Ajuste de Curvas com Mínimos Quadrados e Eliminação de Gauss
 * Descrição: Calcula o polinômio que melhor se ajusta a um conjunto de dados utilizando
 *            o método dos mínimos quadrados e resolve o sistema linear por eliminação de Gauss.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void aloca(float **ponteiro, int tamanho);
void recebeValores(float *valoresX, float *valoresFx, int tamanho);
void calcula(float *valoresX, float *valoresFx, int numeroPontos, int grauPolinomio);
void eliminacaoGauss(float **matriz, float *resultado, int tamanho);
void imprimeSistema(float **matriz, int tamanho, const char *titulo);

int main(void)
{
    char continuar = 's';
    int numeroPontos, grauPolinomio;
    float *valoresX = NULL, *valoresFx = NULL;

    do
    {
        printf("Digite o grau do polinomio (1 ou 2): ");
        scanf("%d", &grauPolinomio);

        if (grauPolinomio != 1 && grauPolinomio != 2)
        {
            printf("Erro: apenas grau 1 ou 2 sao permitidos.\n");
            continue;
        }

        printf("Digite o numero de pontos (maior que %d): ", grauPolinomio);
        scanf("%d", &numeroPontos);

        if (numeroPontos <= grauPolinomio)
        {
            printf("Erro: o numero de pontos deve ser maior que o grau.\n");
        }

        aloca(&valoresX, numeroPontos);
        aloca(&valoresFx, numeroPontos);

        recebeValores(valoresX, valoresFx, numeroPontos);
        calcula(valoresX, valoresFx, numeroPontos, grauPolinomio);

        printf("\nDeseja fazer o processo novamente? [S]im / [N]ao? ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Libera a memória alocada
    free(valoresX);
    free(valoresFx);

    return 0;
} // main

// Função para alocar memória dinamicamente para um vetor
void aloca(float **ponteiro, int tamanho)
{
    if ((*ponteiro = (float *)realloc(*ponteiro, tamanho * sizeof(float))) == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        free(*ponteiro); // Libera memória em caso de erro
        exit(1);         // Encerra o programa
    }
} // aloca

// Função para receber os valores de X e f(X) do usuário
void recebeValores(float *valoresX, float *valoresFx, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor de x[%d]: ", i);
        scanf("%f", &valoresX[i]); // Lê o valor de X
        printf("Digite o valor de f(x[%d]): ", i);
        scanf("%f", &valoresFx[i]); // Lê o valor de f(X)
    }
} // recebeValores

// Função principal para calcular o polinômio ajustado
void calcula(float *valoresX, float *valoresFx, int numeroPontos, int grauPolinomio)
{
    int tamanho = grauPolinomio + 1; // Determina o tamanho do sistema linear

    // Aloca memória para a matriz do sistema e o vetor de coeficientes
    float **matriz = (float **)malloc(tamanho * sizeof(float *));
    for (int i = 0; i < tamanho; i++)
        matriz[i] = (float *)malloc((tamanho + 1) * sizeof(float));
    float *coeficientes = (float *)malloc(tamanho * sizeof(float));

    // Preenche a matriz do sistema com os somatórios necessários
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            matriz[i][j] = 0; // Inicializa o elemento da matriz
            for (int k = 0; k < numeroPontos; k++)
                matriz[i][j] += pow(valoresX[k], i) * pow(valoresX[k], j); // Soma dos produtos de potências de X
        }
        matriz[i][tamanho] = 0; // Inicializa o termo independente
        for (int k = 0; k < numeroPontos; k++)
            matriz[i][tamanho] += valoresFx[k] * pow(valoresX[k], i); // Soma dos produtos de f(X) e potências de X
    }

    // Imprime o sistema linear antes e depois da eliminação de Gauss
    imprimeSistema(matriz, tamanho, "Sistema Linear Original");
    eliminacaoGauss(matriz, coeficientes, tamanho);
    imprimeSistema(matriz, tamanho, "Sistema Escalonado por Gauss");

    // Exibe o polinômio ajustado
    printf("\nPolinomio ajustado:\nP(x) = ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%.4f", coeficientes[i]); // Exibe o coeficiente
        if (i > 0)
            printf("x^%d", i); // Exibe a potência de X
        if (i < tamanho - 1)
            printf(" + "); // Adiciona o sinal de soma entre os termos
    }
    printf("\n");

    // Libera a memória alocada para a matriz e os coeficientes
    for (int i = 0; i < tamanho; i++)
        free(matriz[i]);
    free(matriz);
    free(coeficientes);
} // calcula

// Função para realizar a eliminação de Gauss no sistema linear
void eliminacaoGauss(float **matriz, float *resultado, int tamanho)
{
    // Escalonamento da matriz
    for (int i = 0; i < tamanho; i++)
    {
        for (int k = i + 1; k < tamanho; k++)
        {
            float multiplicador = matriz[k][i] / matriz[i][i]; // Calcula o multiplicador
            for (int j = i; j <= tamanho; j++)
                matriz[k][j] -= multiplicador * matriz[i][j]; // Elimina o elemento abaixo do pivô
        }
    }

    // Substituição regressiva para encontrar os resultados
    for (int i = tamanho - 1; i >= 0; i--)
    {
        resultado[i] = matriz[i][tamanho]; // Inicializa com o termo independente
        
        for (int j = i + 1; j < tamanho; j++)
            resultado[i] -= matriz[i][j] * resultado[j]; // Subtrai os termos já calculados
        resultado[i] /= matriz[i][i];                    // Divide pelo pivô para obter o resultado final
    }
} // eliminacaoGauss

// Função para imprimir o sistema linear
void imprimeSistema(float **matriz, int tamanho, const char *titulo)
{
    printf("\n%s:\n", titulo); // Exibe o título do sistema
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
            printf("%10.4f ", matriz[i][j]);      // Exibe os coeficientes da equação
        printf("| %10.4f\n", matriz[i][tamanho]); // Exibe o termo independente
    }
} // imprimeSistema
