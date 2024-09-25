#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void media(int *p, int tam, int **pm, int *qm, int **pM, int *qM);


int main() {
    system("cls");

    int *ptr = NULL;
    int *pmaior = NULL, *pmenor = NULL;
    int cont = 0;
    int qmenor = 0, qmaior = 0;
    char op;

    do
    {
        aloca(&ptr, cont+1);
        recebe(ptr+cont);

        cont++;

        printf("\n\nDeseja continuar? <S/N>:");
        scanf("%c", &op);
        fflush(stdin);
        printf("\n");

    } while (op != 'n' && op != 'N');

    system("cls");

    printf("\nNumeros digitados:\n");
    imprime(ptr, cont);

    media(ptr, cont, &pmaior, &qmaior, &pmenor, &qmenor);

    printf("\nNumeros maiores que a media:\n");
    imprime(pmaior, qmaior);
    printf("\nNumeros menores que a media:\n");
    imprime(pmenor, qmenor);

    system("pause");
    return 0;
}

void aloca(int **p, int tam) {
    if((*p = (int *) realloc(*p, tam*sizeof(int))) == NULL) {
        exit(1);
    }
}

void recebe(int *p) {
    printf("\nDigite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void imprime(int *p, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("%i\n", *(p+i));
    }
}

void media(int *p, int tam, int **pm, int *qm, int **pM, int *qM) {
    int i;
    float m = 0;

    for(i = 0; i < tam; i++) {
        m += (float) *(p + i);
    }

    m /= tam;
    printf("Media = %.2f\n\n", m);

    for (i = 0; i < tam; i++) {
        if (*(p + i) > m) {
            aloca(pm, (*qm) + 1);
            *(*pm + *qm) = *(p + i);
            (*qm)++;
        }
        else
        {
            aloca(pM, (*qM) + 1);
            *(*pM + *qM) = *(p + i);
            (*qM)++;
        }
    }
}