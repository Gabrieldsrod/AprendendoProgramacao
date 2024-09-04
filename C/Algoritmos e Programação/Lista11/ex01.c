// Solicite ao usuário que digite uma senha composta por 6 caracteres e na
// sequência pergunte novamente a senha. Confira se as duas sequências
// de caracteres são iguais e em caso afirmativo, exiba uma mensagem
// dizendo que a senha é valida. Caso os três primeiros caracteres sejam
// iguais, informe que houve algum erro na digitação, caso contrário, a
// senha será inválida.

// #include<stdio.h>

// int main() {
//     char senha[7];
//     char tentativa[7];
//     int i;
//     int aux = 0, acerto = 0;

//     printf("Digite uma senha: ");
//     scanf("%6s", senha); 

//     printf("Confirme a senha: ");
//     scanf("%6s", tentativa); 

//     for (i = 0; i < 7; i++) {
//         if(tentativa[i] == senha[i]){
//             acerto++;
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         if(tentativa[i] == senha[i]){
//             aux++;
//         }
//     }

//     if(acerto == 7) {
//         printf("A senha eh valida");
//     }
//     if(aux == 3 && acerto != 7) {
//         printf("Houve um erro de digitacao");
//     }
//     if (aux != 3 && acerto != 7) {
//         printf("A senha nao e valida");
//     }
// }

#include <stdio.h>
#include <string.h>

int main() {
    char senha1[7];
    char senha2[7];

    printf("Digite uma senha de 6 caracteres: ");
    scanf("%6s", senha1);

    printf("Digite a senha novamente: ");
    scanf("%6s", senha2);

    if (strcmp(senha1, senha2) == 0) {
        printf("Senha valida.\n");
    } else {
        if (strncmp(senha1, senha2, 3) == 0) {
            printf("Houve algum erro na digitacao.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }
}
