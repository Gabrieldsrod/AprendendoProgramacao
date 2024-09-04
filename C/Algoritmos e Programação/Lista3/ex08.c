// Faça um programa para calcular o peso ideal de uma pessoa. Ao iniciar o
// programa, peça a idade da pessoa, pois o índice não é preciso para
// crianças e pessoas idosas. Assim, não calcule para pessoas maiores que
// 65 anos e menores que 12 anos
// Através do sexo (1 para masculino, 2 para feminino) e da altura, calcular o
// peso ideal de uma pessoa. Receber também o peso atual dela e indicar
// se a mesma está no peso ideal, acima ou abaixo, conforme o cálculo:
// -> Fórmula do peso ideal do homem: (72.7 * altura) – 62
// -> Fórmula do peso ideal da mulher: (62.1 * altura) – 48.7

#include <stdio.h>

int main()
{
    int idade, gen;
    float altura, peso;
    float pesoideal;

    printf("Qual a sua idade?\n");
    scanf("%i", &idade);
    if (idade <= 12 || idade >= 65)
    {
        printf("Voce nao se enquadra neste indice.\n");
    }
    else
    {
        if (idade > 12 && idade <= 17)
        {
            printf("Vo")
        }
        printf("Qual a sua altura?\n");
        scanf("%f", &altura);

        printf("Qual o seu peso?\n");
        scanf("%f", &peso);

        printf("Qual o seu genero?\n1 - Masculino\n2 - Feminino\n");
        scanf("%i", &gen);

        switch (gen)
        {
            case 1:
                pesoideal = (72.7 * altura) - 62;
                printf("Seu peso ideal e: %.2f\n", pesoideal);

                if (peso < pesoideal)
                {
                    printf("Voce esta abaixo do peso ideal!\n");
                }

                if (peso > pesoideal)
                {
                    printf("Voce esta acima do peso ideal!\n");
                }
                
                if (peso == pesoideal)
                {
                    printf("Voce esta no peso ideal");
                }

                break;

            case 2:
                pesoideal = (62.1 * altura) - 48.7;
                printf("Seu peso ideal e: %.2f\n", pesoideal);

                if (peso < pesoideal)
                {
                    printf("Voce esta abaixo do peso ideal!\n");
                }

                if (peso > pesoideal)
                {
                    printf("Voce esta acima do peso ideal!\n");
                }
                
                if (peso == pesoideal)
                {
                    printf("Voce esta no peso ideal");
                }
                
                break;    
        }
    }
}