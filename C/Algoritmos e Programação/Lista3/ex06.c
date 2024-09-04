// Implementar uma calculadora onde o usuário digita dois números e uma
// opção, que deve ser 1 para adição, 2 para subtração, 3 para multiplicação
// e 4 para divisão. Mostrar na tela caso seja informada uma opção inválida.

#include <stdio.h>

int main()
{
    float num1, num2;
    int op;
    float soma, sub, mult, div;

    printf("Digite o numero da operacao desejada:\n1 - ADICAO\n2 - SUBTRACAO\n3 - MULTIPLICACAO\n4 - DIVISAO\n");
    scanf("%i", &op);

    printf("Digite 2 numero para realizar a operacao:\n");
    scanf("%f %f", &num1, &num2);

    switch (op)
    {
    case 1:     //Adição
        soma = num1 + num2;
        printf("A adicao desses numeros resulta em: %.2f.", soma);
        break;
    
    case 2:     //Subtração
        sub = num1 - num2;
        printf("A subtracao desses numeros resulta em: %.2f.", sub);
        break;
    
    case 3:     //Multiplicação
        mult = num1 * num2;
        printf("A multiplicacao desses numeros resulta em: %.2f.", mult);
        break;
    
    case 4:     //Divisão
        div = num1 / num2;
        printf("A divisao desses numeros resulta em: %.2f.", div);
        break;
    }
}