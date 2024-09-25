#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void imprimePar(int *p, int tam);  //Eu inventei essa função
void imprimeImpar(int *p, int tam);
void somaPar(int *p, int tam, int **pp, int *qp);
void somaImpar(int *p, int tam, int **pi, int *qi);


int main() {
    int *ptr = NULL, *ppar = NULL, *pimpar = NULL;
    int cont = 0, qpar = 0, qimpar = 0;
    char op;

    system("cls");

    do{
        aloca(&ptr, cont + 1);
        recebe(ptr + cont);
        cont++;

        printf("Deseja continuar?\nSim ou nao? Digite S ou N : ");
        scanf("%c", &op);
        fflush(stdin);

        printf("\n");
    }while (op != 'n' && op != 'N');

    printf("\n\nNumeros digitados:\n");
    imprime(ptr, cont);

    somaPar(ptr, cont, &ppar, &qpar);
    somaImpar(ptr, cont, &pimpar, &qimpar);

    printf("\n");
    system("pause");
    return 0;
}

void aloca(int **p, int tam) {
    if ((*p = (int *) realloc(*p, tam*sizeof(int))) == NULL)
    {
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
    for (i = 0; i < tam; i++) {
        printf("%i\n", *(p + i));
    }
}

//Eu inventei essa função
void imprimePar(int *p, int tam){
    int i, soma;

    for (i = 0; i <= (tam / 2); i++) {
        if (i == (tam / 2)) {
            if (tam % 2 == 0 && *(p + (tam / 2)) % 2 == 0) {
                break;
            }
        } 
        else {
            soma = *(p + i) + *(p + tam - i - 1);
            if (soma % 2 == 0) {
                printf("%d + %d = %d\n", *(p + i), *(p + tam - i - 1), soma);
            }
        }
    }
}

void imprimeImpar(int *p, int tam)
{
    int i, soma;
    for (i = 0; i <= (tam / 2); i++) {
        if (i == (tam / 2)) {
            if (tam % 2 == 0 && *(p + (tam / 2)) % 2 == 1) {
                break;
            }
        } 
        else {
            soma = *(p + i) + *(p + tam - i - 1);
            if (soma % 2 == 1) {
                printf("%d + %d = %d\n", *(p + i), *(p + tam - i - 1), soma);
            }
        }
    }
}

void somaPar(int *p, int tam, int **pp, int *qp)
{
    int i;
    int soma;
    
    for(i = 0; i <= (tam / 2); i++) {
        
        soma = *(p + i) + *(p + tam - i -1);

        if(i == (tam / 2)) {
            if(tam % 2 == 1) {
                soma = *(p + (tam/2));
            }
            else {
                break;
            }
        }
        
        if (soma % 2 == 0) {
            aloca (pp, *qp + 1);
            *(*pp + *qp) = soma;   
            (*qp)++;
        }
    }

    //Eu inveitei essa função
    printf("\nSomas pares:\n");
    imprimePar(p, tam);

    printf("\nPares armazenados:\n");
    imprime(*pp, *qp);
}

void somaImpar(int *p, int tam, int **pi, int *qi) {
    int i;
    int soma;
    
    for(i = 0; i <= (tam / 2); i++) {
        
        soma = *(p + i) + *(p + tam - i -1);

        if(i == (tam / 2)) {
            if(tam % 2 == 1) {
                soma = *(p + (tam/2));
            }
            else {
                break;
            }
        }
        
        if (soma % 2 == 1) {
            aloca (pi, *qi + 1);
            *(*pi + *qi) = soma;   
            (*qi)++;
        }
    }

    //Eu inveitei essa função
    printf("\n\nSomas impares:\n");
    imprimeImpar(p, tam);

    printf("\nImpares armazenados:\n");
    imprime(*pi, *qi); 
}