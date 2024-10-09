#include<stdio.h>
#include<stdlib.h>

typedef struct agenda{
	int reg;
	char nome[80];
	float nota;
}agenda;

agenda cadastro();
void mostra(agenda ag[], int cont);
int main(){
	agenda ag[10];
	char op;
	int cont=0;
	
	do{
		system("cls");
		printf("\nRegistro de agenda\n");
		if(cont<10){
			ag[cont]=cadastro();
			cont++;
		}
		else{		
		printf("\nCadatro lotado.");
		}
		
		printf("\nDeseja continuar <S/N>?:");
		scanf("%c", &op);
		fflush(stdin);
	}while(op!='n'&&op!='N');
	
	mostra(ag,cont);
	return 0;
}

agenda cadastro(){
	agenda aux;
	static int n=24000;
	
	aux.reg=n++;
	printf("\nNome:");
	gets(aux.nome);
	fflush(stdin);
	printf("\nNota:");
	scanf("%f", &aux.nota);
	fflush(stdin);
	
	return aux;
}
void mostra(agenda ag[], int cont){
	int i;
	for(i = 0; i < cont; i++){
		printf("\nAluno %i\nCadastro: %i\nNome: %s\nNota: %.2f\n", 
			i+1, ag[i].reg, ag[i].nome, ag[i].nota);
	}
}