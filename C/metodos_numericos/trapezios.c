// Programa executa o método da regra dos trapézios
// Luiza Mantovani - 248122
// Isabella Valim de Carvalho - 247499
// Gabriel da Silva Rodrigues - 248103
// João Vitor Rodrigues Martinelle Vieira - 248194
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
void aloca(float **p, int tam);
int recebeGrau();
float recebeValores(float *func, float *intervalo, float *div, int grau);
float calculaPolinomio(float *func, int grau, float valor);
void calculaIntegral(float *func, float *intervalo, float *div, int grau, float altura);
main()
{
    setlocale(LC_ALL, "Portuguese");
    char continua;
    float *func = NULL;
    float *intervalo = NULL;
    int grauFunc;
    float h, x, div;
    do
    { // manter o algoritmo em loop at o usu rio digitar algo diferente de 'S'
        ou 's' grauFunc = recebeGrau();
        aloca(&func, grauFunc + 1);
        aloca(&intervalo, 2);
        h = recebeValores(func, intervalo, &div, grauFunc);
        calculaIntegral(func, intervalo, &div, grauFunc, h);
        printf("\nDeseja utilizar a Regra dos Trapézios em outra função? F<[S]im/[N]ão>");
        scanf(" %c", &continua);
        fflush(stdin);
        system("cls");
    } while (continua == 's' || continua == 'S');
    free(func);
    free(intervalo);
}
int recebeGrau()
{ // recebe o grau do polinomio e retorna esse valor
    int grau;
    printf("\nQual o grau da função que deseja descobrir a integral? ");
    scanf("%i", &grau);
    fflush(stdin);
    return grau;
}
void aloca(float **p, int tam)
{ // aloca memório para os ponteiros
    if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
        exit(1);
}
float recebeValores(float *func, float *intervalo, float *div, int grau)
{
    // recebeos valores da função, do intervalo e do número de divisões, retornando a
    altura int i;
    float altura;
    for (i = 0; i <= grau; i++)
    {
        printf("\nDigite o valor do multiplicador de quando x está elevado a %i: ",
               i);
        scanf("%f", func + i);
        fflush(stdin);
    }
printf("\nO intervalo em que deseja calcular a integral vai de quanto
aquanto? (Exemplo: 1 3, isso significa que o intervalo vai de 1 a 3): ");
scanf("%f %f", (intervalo+0), (intervalo+1));
fflush(stdin);
printf("\nQual o número de divisões desejado? ");
scanf("%f", div);
altura = (*(intervalo+1)-*(intervalo+0))/(*div);
return altura;
}
void calculaIntegral(float *func, float *intervalo, float *div, int grau, float altura)
{ // calcula a integral por meio da regra dos Trapézios
    float soma = 0;
    int n = (int)(*div);
    int i;
    float x;
    for (i = 0; i <= n; i++)
    {
        x = intervalo[0] + i * altura;
        if (i == 0 || i == n)
            soma += calculaPolinomio(func, grau, x); // f(x0) + f(xn)
        else
            soma += 2 * calculaPolinomio(func, grau, x); // 2*f(x1...xn-1)
    }
    float integral = (altura / 2) * soma;
    printf("\nO valor aproximado da integral pelo método dos trapézios : %.4f\n",
           integral);
}
float calculaPolinomio(float *func, int grau, float valor)
{ // calcula o valor do
    polinomio para um determinado valor int i;
    float resultado = 0;
    for (i = 0; i <= grau; i++)
    {
        resultado += *(func + i) * pow(valor, i);
    }
    return resultado;
}