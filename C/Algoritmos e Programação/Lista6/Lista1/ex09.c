#include <stdio.h>
#include <math.h>

int main() {
    float num, raiz, oit;

    printf("Insira um número: ");
    scanf("%f", &num);
    

    raiz = sqrt(num);
    oit = pow(num, 8);
    
    printf("A raiz quadrada de %.2f e: %.2f\n", num, raiz);
    printf("A oitava potencia de %.2f e: %.2f\n", num, oit);
    return 0;
}
