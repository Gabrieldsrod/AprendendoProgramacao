#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void processaNumeros(int *p, int tam, int **pp, int *qp, int **pi, int *qi);

int main() {
    int *ptr = NULL, *ppar = NULL, *pimpar = NULL;
    int cont = 0, qpar = 0, qimpar = 0;
    char op;

    system("cls");

    do {
        aloca(&ptr, cont + 1);
        recebe(ptr + cont);
        cont++;

        printf("Deseja continuar?\nSim ou nao? Digite S ou N : ");
        scanf(" %c", &op);  // Note the space before %c to consume any leftover whitespace
        fflush(stdin);

        printf("\n");
    } while (op != 'n' && op != 'N');

    printf("\n\nNumeros digitados:\n");
    imprime(ptr, cont);

    processaNumeros(ptr, cont, &ppar, &qpar, &pimpar, &qimpar);

    printf("\n");
    system("pause");
    return 0;
}

void aloca(int **p, int tam) {
    if ((*p = (int *) realloc(*p, tam * sizeof(int))) == NULL) {
        exit(1);
    }
}

void recebe(int *p) {
    printf("Digite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void imprime(int *p, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%i\n", *(p + i));
    }
}

void processaNumeros(int *p, int tam, int **pp, int *qp, int **pi, int *qi) {
    int i, soma;

    for (i = 0; i <= (tam / 2); i++) {
        if (i == (tam / 2)) {
            if (tam % 2 == 1) {
                soma = *(p + (tam / 2));
            } else {
                break;
            }
        } else {
            soma = *(p + i) + *(p + tam - i - 1);
        }

        if (soma % 2 == 0) {
            aloca(pp, *qp + 1);
            *(*pp + *qp) = soma;
            (*qp)++;
        } else {
            aloca(pi, *qi + 1);
            *(*pi + *qi) = soma;
            (*qi)++;
        }
    }

    printf("\nSomas pares:\n");
    for (i = 0; i < *qp; i++) {
        printf("%d\n", *(*pp + i));
    }

    printf("\nSomas impares:\n");
    for (i = 0; i < *qi; i++) {
        printf("%d\n", *(*pi + i));
    }
}
