// Acrescente no exercício anterior a apresentação da faixa etária da
// pessoa, a partir da sua idade atual.
// Faixas:
// 12 a 17 anos: Adolescente
// 18 a 25 anos: Jovem
// 26 a 65 anos: Adulto


#include <stdio.h>

int main()
{
    int idade, gen;
    float altura, peso;
    float pesoideal;

    printf("Qual a sua idade?\n");
    scanf("%i", &idade);
    if (idade < 12 || idade > 65)
    {
        printf("Voce nao se enquadra neste indice.\n");
    }
    else
    {
        if (idade >= 12 && idade <= 17)
        {
            printf("Voce e um Adolescente\n");
        }

        else if (idade >= 18 && idade <= 25)
        {
            printf("Voce e Jovem\n");
        }

        else
        {
            printf("Voce e um Adulto\n");
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