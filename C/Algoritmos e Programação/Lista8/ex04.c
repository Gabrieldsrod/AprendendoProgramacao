// Leia um vetor A de 6 elementos contendo o gabarito da Mega-Sena. O
// sorteio consiste na extração de 6 números diferentes, no universo de 01 a
// 60. A seguir, ler um vetor B de 10 elementos contendo uma aposta.
// Escrever quantos pontos fez o apostador, e se ele fez a sena (6 acertos),
// a quina (5 acertos) ou a quadra (4 acertos).

#include <stdio.h>

int main() {
    int gabarito[6], aposta[10];
    int i, j, acertos = 0;

    printf("Digite os 6 numeros do gabarito da Mega-Sena:\n");
    for (i = 0; i < 6; i++) 
    {
        do {
            printf("Numero %d: ", i + 1);
            scanf("%d", &gabarito[i]);
            if (gabarito[i] < 1 || gabarito[i] > 60) 
            {
                printf("Numero invalido. Digite um numero entre 1 e 60.\n");
            }
        } while (gabarito[i] < 1 || gabarito[i] > 60);
    }

    printf("\nDigite os 10 numeros da aposta:\n");
    for (i = 0; i < 10; i++) 
    {
        do {
            printf("Numero %d: ", i + 1);
            scanf("%d", &aposta[i]);
            if (aposta[i] < 1 || aposta[i] > 60) 
            {
                printf("Numero invalido. Digite um numero entre 1 e 60.\n");
            }
        } while (aposta[i] < 1 || aposta[i] > 60);
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 10; j++) {
            if (gabarito[i] == aposta[j]) 
            {
                acertos++;
                break;
            }
        }
    }

    if (acertos == 6) {
        printf("\nVoce fez a sena (6 acertos)!\n");
    } else if (acertos == 5) {
        printf("\nVoce fez a quina (5 acertos)!\n");
    } else if (acertos == 4) {
        printf("\nVoce fez a quadra (4 acertos)!\n");
    } else {
        printf("\nVoce fez %d acertos.\n", acertos);
    }

    return 0;
}
