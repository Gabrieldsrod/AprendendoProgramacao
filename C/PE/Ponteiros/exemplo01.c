#include <stdio.h>

void leitura(float *t, int tam);                    // leitura das temperaturas             
void maior_temperatura(float *t, int tam);          // retorna a maior temperatura  
float media_temperatura(float *t, int tam);         // retorna a media das temperaturas
int inf_media(float *t, int tam, float media, int *pos);        // retorna a quantidade de dias com temperatura inferior a media
void imprime(int *pos, int qtde, float *t);                   // imprime os dias com temperatura inferior a media

int main() 
{
    float temp[31], media;
    int dias, pos_inf[31], qtde;

    printf("\nTemperaturas Diarias\n");
    printf("\nDigite a quantidade de dias: ");
    scanf("%i", &dias);
    fflush(stdin);
    
    leitura(temp, dias);

    maior_temperatura(temp, dias);
    media = media_temperatura(temp, dias);
    qtde = inf_media(temp, dias, media, pos_inf);
    imprime(pos_inf, qtde, temp);

}

void leitura(float *t, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("Temperatura- %i dia: ", i + 1);
        scanf("%f", t + i); // ou for (i = 0; i < tam; i++, t++) ou t+i
    }

}

void maior_temperatura(float *t, int tam)
{
    int i;
    float maior = *t;
    int dia_maior = 1;
    for (i = 0; i < tam; i++)
    {
        if (*(t + i) > maior)
        {
            maior = *(t + i);
            dia_maior = i + 1;
        }
    }
    printf("\nMaior temperatura: %.2f\nMaior_dia: %i\n", maior, dia_maior);
}

float media_temperatura(float *t, int tam)
{
    int i;
    float media = 0;
    for (i = 0; i < tam; i++)
    {
        media += *(t + i);
    }

    return (media / tam);
}      

int inf_media(float *t, int tam, float media, int *pos)
{
    int i, j = 0;

    for (i = 0; i < tam; i++)
    {
        if (*(t + i) < media)
        {
            *(pos + j) = i;
            j++;
        }
    }

    return j;
}

void imprime(int *pos, int qtde, float *t)
{
    int i;
    printf("\nTemperatura inferior a media:\n");
    for(i = 0; i < qtde; i++)
    {
        printf("Temperatura %.2f - Dia: %i\n", *(t+*(pos+i)), *(pos+i)+1);
    }
}


