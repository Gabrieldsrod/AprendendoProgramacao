#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void imprimeImpar(int *p, int tam);
void imprimePar(int *p, int tam);
void subtraiImpar(int *p, int tam, int **pi, int *qi);
void subtraiPar(int *p, int tam, int **pp, int *qp);

int main() {
    int *ptr = NULL, *pimpar = NULL, *ppar = NULL;
    int cont = 0, qimpar = 0, qpar = 0;
    char op;

    system("cls");

    do {
        aloca(&ptr, cont+1);
        recebe(ptr+cont);
        cont++;

        printf("Deseja continuar? Sim ou nao?\nDigite S ou N: ");
        scanf("%c", &op);
        fflush(stdin);

        printf("\n");
    } while(op != 'n' && op != 'N');

    system("cls");

    printf("\n\nNumeros digitados:\n");
    imprime(ptr, cont);

    subtraiImpar(ptr, cont, &pimpar, &qimpar);
    subtraiPar(ptr, cont, &ppar, &qpar);

    system("pause");
    return 0;
}

void aloca(int **p, int tam) {
    if((*p = (int *) realloc(*p, tam*sizeof(int))) == NULL) {
        exit(1);
    }
}

void recebe(int *p) {
    printf("Digite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void imprime(int *p, int tam) {
    int i;

    for(i = 0; i < tam; i++){
        printf("%i\n", *(p+i));
    }
}

void imprimeImpar(int *p, int tam) {
    int i, sub;

    for(i = 0; i <= (tam/2); i++){
        if(i == (tam/2)) {
            if(tam % 2 == 0 && *(p + (tam/2)) % 2 == 1) {
                break;
            }
        }
        else {
            sub = *(p + i) - *(p + tam - 1 - i);
            if(abs(sub) % 2 == 1){
                printf("%i - %i = %i\n", *(p+i), *(p+tam-1-i), sub);
            }
        }
    }
}

void imprimePar(int *p, int tam) {
    int i, sub;

    for(i = 0; i <= (tam/2); i++){
        if(i == (tam/2)) {
            if(tam % 2 == 0 && *(p + (tam/2)) % 2 == 0) {
                break;
            }
        }
        else {
            sub = *(p + i) - *(p + tam - 1 - i);
            if(abs(sub) % 2 == 0) {
                printf("%i - %i = %i", *(p + i), *(p + tam - 1 - i), sub);
            }
        }
    }
}

void subtraiImpar(int *p, int tam, int **pi, int *qi) {
    int i, sub;

    for(i = 0; i <= (tam/2);i++) {
        
        sub = *(p + i) - *(p + tam - 1 - i);

        if(i == (tam/2)) {
            if (tam % 2 == 1){
                sub = *(p + (tam/2));
            } 
            else {
                break;
            }
        }

        if(abs(sub) % 2 == 1){
            aloca(pi, *qi+1);
            *(*pi+*qi) = sub;
            (*qi)++;
        }
    }

    printf("\n\nSubtracao de impares:\n");
    imprimeImpar(p, tam);

    printf("\nImpares armazenados:\n");
    imprime(*pi, *qi);
}

void subtraiPar(int *p, int tam, int **pp, int *qp) {
    int i, sub;

    for(i = 0; i <= (tam/2); i++) {
        sub = *(p + i) - *(p + tam - 1 - i);

        if(i == (tam/2)) {
            if(tam % 2 == 1) {
                sub = *(p + (tam/2));
            }
            else{
                break;
            }
        }

        if (abs(sub) % 2 == 0) {
            aloca(pp, *qp + 1);
            *(*pp + *qp) = sub;
            (*qp)++;
        }
    }

    printf("\nSubtracao de pares:\n");
    imprimePar(p, tam);

    printf("\n\nPares armazenados:\n");
    imprime(*pp, *qp);
}