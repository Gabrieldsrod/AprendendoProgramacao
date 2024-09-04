// A prefeitura de Sorocaba está em eleições. Apresentaram-se 3
// candidatos: JOSÉ com o nº 1, MARIA com o nº 2 e JOÃO com o nº 3.
// Cada eleitor deve indicar a sua opção, que pode ser o nº de um candidato
// (1,2,3), voto branco (nº 4) ou voto nulo (nº 5). Preparar um programa que
// receba e processe os dados de um número não determinado de cédulas
// até que seja digitado 0 para o voto, escrevendo os seguintes dados:
// a) o número de votos de cada uma das 5 opções;
// b) o nome do candidato vencedor;
// c) o percentual de eleitores que elegeram o candidato vencedor.

#include<stdio.h>
#include <string.h>

#define JOSE 1
#define MARIA 2
#define JOAO 3
#define BRANCO 4
#define NULO 5
#define ENCERRAR 0

int main()
{
    int voto, eleitores = 0,joao = 0, maria = 0, jose = 0, branco = 0, nulo = 0;
    char* vencedor;
    float perc_vencedor = 0;

    do
    {
        printf("\nVote em uma das opçoes abaixo:\n");
        printf("[1]JOSE\n[2]MARIA\n[3]JOAO\n[4]VOTO BRANCO\n[5]VOTO NULO\n[0]ENCERRAR\n");
        scanf("%i", &voto);

        switch (voto)
        {
        case JOSE:
            jose++;
            eleitores++;
            break;

        case MARIA:
            maria++;
            eleitores++;
            break;
        
        case JOAO:
            joao++;
            eleitores++;
            break;
        
        case BRANCO:
            branco++;
            eleitores++;
            break;

        case NULO:
            nulo++;
            eleitores++;
            break;

        case ENCERRAR:
            break;

        default:
            printf("Voto invalido...\n");
            break;
        }
    } while (voto != ENCERRAR);

    printf("\nTotal de votos:\n");
    printf("Jose: %i\n", jose);
    printf("Maria: %i\n", maria);
    printf("Joao: %i\n", joao);
    printf("Branco: %i\n", branco);
    printf("Nulo: %i\n", nulo);
    
    if (jose > maria && jose > joao)
    {
        vencedor = "Jose";
        perc_vencedor = ((float)jose / eleitores) * 100;
    }
    
    else if (maria > jose && maria > joao)
    {
        vencedor = "Maria";
        perc_vencedor = ((float)maria / eleitores) * 100;
    }
    
    else if (joao > maria && joao > jose)
    {
        vencedor = "Joao";
        perc_vencedor = ((float)joao / eleitores) * 100;
    }
    else
    {
        vencedor = "Ninguem";
    }
    
    printf("\nCandidato vencedor: %s\n", vencedor);
    if (strcmp(vencedor, "Ninguem") != 0) 
    {
        printf("Percentual de eleitores que elegeram o candidato vencedor: %.2f%%\n", perc_vencedor);
    }
}