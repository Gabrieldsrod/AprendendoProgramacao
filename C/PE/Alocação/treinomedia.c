#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void mediaMaior(int *p, int tam, int **pm, int *qm);
int mediaMenor(int *p, int tam, int **pm);

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

    mediaMaior(ptr, cont, &pmaior, &qmaior);
    printf("\n\nNumeros maiores que a media:\n");
    imprime(pmaior, qmaior);

    qmenor = mediaMenor(ptr, cont, &pmenor);
    printf("\n\nNumeros menores que a media:\n");
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

void mediaMaior(int *p, int tam, int **pm, int *qm) {
    int i;
    float m = 0;

    for(i = 0; i < tam; i++) {
        m += (float) *(p + i);
    }

    m /= tam;
    printf("Media = %.2f", m);

    for (i = 0; i < tam; i++) {
        if (*(p + i) > m) {
            aloca(pm, (*qm) + 1);
            *(*pm + *qm) = *(p + i);
            (*qm)++;
        }
    }
}

int mediaMenor(int *p, int tam, int **pm) {
    int i;
    float m = 0;
    int qm = 0;

    for(i = 0; i < tam; i++) {
        m += (float) *(p + i);
    }

    m /= tam;

    for (i = 0; i < tam; i++) {
        if (*(p + i) < m) {
            aloca(pm, qm + 1);
            *(*pm + qm) = *(p + i);
            (qm)++;
        }
    }

    return qm;

}