#include <stdio.h>

int main()
{
    float nt1, nt2, np1 , np2, medp, medt, nf;

    printf("Nota da primeira prova pratica: ");
    scanf("%f", &np1);
    printf("Nota da segunda prova pratica: ");
    scanf("%f", &np2);
    
    printf("Nota da primeira prova teorica: ");
    scanf("%f", &nt1);
    printf("Nota da segunda prova teorica: ");
    scanf("%f", &nt2);

    medp = (np1 + np2) / 2;
    medt = (nt1 + nt2) / 2;
    
    nf = (medp * 0.4) + (medt * 0.6);

    printf("A nota final do aluno neste semestre e de %.2f", nf);
    return 0;
}