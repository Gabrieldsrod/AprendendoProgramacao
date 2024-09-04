/*Implemente um programa que calcule aumento de salário no ano
corrente. Se o salário for de até R$ 1000.00 deve ser calculado o novo
salário com aumento de 5%, para um salário maior que R$ 1000.00 o
aumento é de 7%.*/
#include<stdio.h>

int main(){
    float salat, salnv;
    printf("Qual o seu salario atual?\nR$");
    scanf("%f", &salat);

    if (salat <= 1000)
    {
        salnv = salat * 1.05;
        printf("Seu novo salario sera: R$%.2f", salnv);
    }
    else
    {
        salnv = salat * 1.07;
        printf("Seu novo salario sera: R$%.2f", salnv);
    }
}