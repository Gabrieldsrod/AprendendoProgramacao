// Luiza Mantovani - 248122
// Isabella Valim de Carvalho - 247499
// Gabriel da Silva Rodrigues - 248103
// Joao Vitor Rodrigues Martinelle Vieira - 248194 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int recebeDados();
void aloca(float **p, int tam);
void calcula(float *x, float *fx, int pontos);
void recebeValores(float *x, float *fx, int tam);

int main()
{
    char continua = 's';
    int pontos;
    float *valoresX = NULL;  // Armazena os valores de X
    float *valoresFX = NULL; // Armazena os valores de f(x)
    do
    {
        pontos = recebeDados(); // a variável pontos recebe o valor da função recebeDados que recebe o grau da função e retorna a quantidade de pontos para fazer a interpolação
        aloca(&valoresX, pontos); // aloca o espaço necessário para obter os valores de X
        aloca(&valoresFX, pontos); // aloca o espaço necessário para obter os valores de F(x)
        recebeValores(valoresX, valoresFX, pontos); // chamada da função recebeValores
        calcula(valoresX, valoresFX, pontos); // chamada da função calcula
        printf("\nDeseja fazer outra interpolacao de Lagrange [S]im / [N]ao?\n");
        scanf(" %c", &continua);
        fflush(stdin);
    } while (continua == 's' || continua == 'S'); // mantém o loop enquanto o usuário responder s ou S para a pergunta "Deseja fazer outra interpolacao de Lagrange [S]im / [N]ao?"
}

void recebeValores(float *x, float *fx, int tam)
{   // essa função tem como parâmetros dois ponteiros float e uma variável int
    int i; // ela recebe os valores de x e f(x)
    for (i = 0; i < tam; i++)
    { // loop que passa por todos os pontos
        printf("\nDigite o valor de x%i e de f(x%i) (exemplo: 1 2.5): ", i, i);
        // esclarece como o usuário deve enviar os valores
        scanf("%f %f", (x + i), (fx + i)); // recebe os valores digitados pelo usuário
        fflush(stdin); // limpa buffer
    }
}

void calcula(float *x, float *fx, int pontos)
{ // função com 2 ponteiros float e uma variável int como parâmetro
    float px, xp, li;
    int i, j;
    char continuaX = 's';
    do
    {   // mantém um loop enquanto o usuário digitar 'S' ou 's' para a pergunta
        px = 0;
        printf("\nDigite o valor de x para calcular f(x): "); // informa ao usuário que o valor de x para calcular f(x) deve ser passado
        scanf("%f", &xp); // recebe o valor de x para calcular f(x)
        fflush(stdin);        // limpa buffer
        for (i = 0; i < pontos; i++)
        {           // loop para calcular o polinômio
            li = 1; // inicializa li com o valor 1
            for (j = 0; j < pontos; j++)
            {
                if (j != i)
                {   // se j diferente de i, ele calcula o li
                    li *= (xp - *(x + j)) / (*(x + i) - *(x + j)); // expressão que representa a fórmula do li
                }
            }
            printf("\nO valor de l%i = %f", i, li); // imprime o valor de cada li
            px += li * (*(fx + i)); // incrementa o polinômio a cada li calculado
        }
        printf("\nO valor interpolado de f(%.2f) = %.4f\n", xp, px);
        // informa o resultado da interpolação ao usuário
        printf("\nDeseja calcular outro valor de x? [S]im / [N]ao: ");
        scanf(" %c", &continuaX); // recebe a resposta da pergunta anterior, se a resposta for s ou S toda parte de cálculo é repetida
        fflush(stdin);
    } while (continuaX == 's' || continuaX == 'S');
}

int recebeDados()
{ // recebe o grau da função e retorna a quantidade de pontos
    int grau, pontos;
    printf("Digite o grau da funcao que deseja obter: ");
    scanf("%i", &grau); // recebe o grau digitado pelo usuário
    pontos = grau + 1;  // Obtendo o número de pontos a partir do grau indicado
    return pontos;      // retorna a quantidade de pontos
}

void aloca(float **p, int tam)
{ // aloca um ponteiro float
    if ((*p = ((float *)realloc(*p, tam * sizeof(float)))) == NULL)
    {
        exit(1);
    }
}