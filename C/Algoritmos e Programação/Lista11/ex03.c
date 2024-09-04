// Receba um vetor de caracteres para guardar uma sequencia de 10 letras.
// Na sequencia exiba as 6 primeiras letras, sendo que apenas uma letra
// deve ser apresentada por linha. 

#include<stdio.h>

int main(){
    char  palavra[11];
    int i;

    printf("Digite uma palavra: ");
    printf("%10s", palavra);

    for (i = 0; i < 6; i++) {
        printf("%c \n", palavra[i]);
    }
}