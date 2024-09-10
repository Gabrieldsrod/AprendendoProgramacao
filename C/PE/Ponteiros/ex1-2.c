// Idem ao exercício resolvido, porém a quantidade de nºs reais deverá ser estipulada pelo usuário.
// Lembrar que a matriz ao ser definida deve conter necessariamente o tamanho.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int qntd, *pos, i;
    char continuar;

    system("cls");

    do
    {
        printf("\nQuantos numeros deseja colocar no array?\n");
        scanf("%i", &qntd);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        int nums[qntd];
        system("cls");

        prin
        pos = nums;
        printf("Insira os valores da matriz:\n");
        for (i = 0; i < qntd; i++)
        {
            printf("%i elemento: ", i + 1);
            scanf("%i", pos + i);
        }

        printf("\nConteudos da matriz: \n");
        for (i = 0; i < qntd; i++)
        {
            printf("nums[%i]: %i\n", i, *(pos + i));
        }

        do
        {
            printf("\nDeseja continuar? (S/N): ");
            scanf(" %c", &continuar);
            fflush(stdin);
        } while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');

    } while (continuar == 's'|| continuar == 'S');
    
    system("pause");
    return 0;
}