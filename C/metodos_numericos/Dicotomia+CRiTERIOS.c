#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alocaMulti(float **p, int tam);
void recebeMulti(float *p, int i);
float calculaK(float a, float b, float erro);
float funcaoX(float ponto);
void imprimirCabecalhoTabel();
void imprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB);

int grau;
float *multi = NULL;

int main()
{
    int i, iteracao;
    float A, B, erro, M, fA, fB, fM;
    char fAfM, fMfB;

    printf("Informe o grau da funcao (2 a 6): ");
    scanf("%i", &grau);
    alocaMulti(&multi, grau + 1); // Alocar memória para todos os coeficientes de uma vez
    for (i = grau; i >= 0; i--)
    {
        recebeMulti(multi + i, i);
    }
    
    printf("A funcao recebida foi: ");
    for (i = grau; i >= 0; i--)
    {
        if (i == 0)
        printf("%.2f = 0", *(multi + i));
        else
        printf("%.2f*x^%d + ", *(multi + i), i);
    }
    printf("\n\n");
    printf("Valor de A: ");
    scanf("%f", &A);
    printf("Valor de B: ");
    scanf("%f", &B);
    printf("Valor do erro: ");
    scanf("%f", &erro);

    fA = funcaoX(A);
    fB = funcaoX(B);

    if (fA * fB > 0) {
        printf("Nao existe raiz no intervalo fornecido.\n");
        free(multi);
        return 1;
    }

    calculaK(A, B, erro);
    imprimirCabecalhoTabel();

    iteracao = 1;
    while (1)
    {
        M = (A + B) / 2;
        fA = funcaoX(A);
        fB = funcaoX(B);
        fM = funcaoX(M);

        if (fA * fM < 0)
            fAfM = '-';
        else
            fAfM = '+';
        if (fB * fM < 0)
            fMfB = '-';
        else
            fMfB = '+';
        
        imprimirTabela(iteracao, A, B, M, fA, fB, fM, fAfM, fMfB);

        if (fabs(B - A) < erro || fabs(fM) < erro || fM == 0) {
            printf("Criterio de parada atingido.\n");
            break;
        }

        if (fA * fM < 0)
            B = M;
        else
            A = M;

        iteracao++;
    }

    free(multi);

    return 0;
}

void alocaMulti(float **p, int tam)
{
    if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
}

void recebeMulti(float *p, int i)
{
    printf("Informe o fator multiplicador de x^%i(%c): ", i, 65 + (grau - i));
    scanf("%f", p);
    while (getchar() != '\n');
}

float calculaK(float a, float b, float erro)
{
    float fValorK;

    fValorK = (log10(b - a) - log10(erro)) / (log10(2));
    return ceil(fValorK);
}

float funcaoX(float ponto)
{
    int i;
    float resultado;
    resultado = 0;
    for (i = 0; i <= grau; i++)
    {
        resultado = resultado + *(multi + i) * pow(ponto, i);
    }
    return resultado;
}

void imprimirCabecalhoTabel()
{
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");
}

void imprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB)
{
    printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
}
