#include<stdio.h>

int main(){
	float p1, p2, m, dif;
	
	printf("Nota da primeira prova: \n");
	scanf("%f", &p1);
	printf("Nota da segunda prova: \n");
	scanf("%f", &p2);
	
	m = (p1 + p2) / 2;
	if (m >= 5){
		printf("Aprovado!!!");
	}
	else{
		dif = 5 - m;
		printf("Reprovado!!!\n");
		printf("Faltaram %f pontos para atingir 5", dif);
	}
}
