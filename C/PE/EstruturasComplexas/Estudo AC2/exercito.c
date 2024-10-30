#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs

typedef struct carreira{
	int   reg;
	int   qmilitar;
	char  org[20];
	char  patente[20];
	float salario;
}carreira;

typedef struct militar{
	char CPF[13];
	char nome[20];
	int  numreg;
}militar;

//prototipos

void aloca_carreira(carreira **c, int qc);
void aloca_militar(militar **m, int qm);

void cadastro_carreira(carreira *c, int qc);
void cadastro_militar(militar *m, carreira *pc, int qc);

void mostra_carreira(carreira *c, int qc);
void mostra_militar(militar *m, int qm);

int  busca_patente(carreira *c, int qc, char *p_org, char *p_pat);
int  busca_CPF(militar *m, int qm, char *aux_CPF);

void troca_patente(militar *m, int qm, carreira *c, int qc);

void maiuscula(char *p);

int main(){
	
	carreira *pc = NULL;
	militar  *pm = NULL;
	
	int qc = 5, qm = 0, op;
	
	aloca_carreira(&pc, qc);
	cadastro_carreira(pc, qc);
	
	do{
		system("cls");
		printf("\n[1]Cadastro Militar\n[2]Troca Patente\n[3]Mostra Patente\n[4]Mostra Militar\n[5]Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);
		
		switch(op){
			case 1: aloca_militar(&pm, qm+1);
					cadastro_militar(pm + qm, pc, qc); // ponteiro de militar deslocado, e as informacoes para buscar carreira
					qm++;
					break;
			
			case 2: troca_patente(pm, qm, pc, qc);
					break;
			
			case 3: mostra_carreira(pc, qc);
					break;
			
			case 4: mostra_militar(pm, qm);
					break;
		}//switch
		
	}while(op < 5);
	
	return 0;
}//main

void aloca_carreira(carreira **c, int qc){
	if((*c = (carreira*)realloc(*c, qc * sizeof(carreira))) == NULL)
		exit(1);	
}//aloca_carreira

void aloca_militar(militar **m, int qm){
	if((*m = (militar*)realloc(*m, qm * sizeof(militar))) == NULL)
		exit(1);
}///aloca_militar

void cadastro_carreira(carreira *c, int qc){
	int i;
	
	for(i = 0; i < qc; i++, c++){
		
		c->reg = i+1;
		
		c->qmilitar = 0;
		
		printf("\nOrganizacao (Exercito\tAeronautica\tMarinha):\nOpcao: ");
		gets(c->org);
		fflush(stdin);
		maiuscula(c->org);
		
		printf("\nPatente: ");
		gets(c->patente);
		fflush(stdin);
		maiuscula(c->patente);
		
		printf("Salario: R$");
		scanf("%f", &c->salario);
		fflush(stdin);
		
	}//for
}//cadastro_carreira

void cadastro_militar(militar *m, carreira *pc, int qc){
	
	char aux_org[20], aux_pat[20];
	
	printf("\nCPF: ");
	gets(m->CPF);
	fflush(stdin);
	
	printf("\nNome: ");
	gets(m->nome);
	fflush(stdin);
	
	printf("\nOrganizacao: ");
	gets(aux_org);
	fflush(stdin);
	maiuscula(aux_org);
	
	printf("\nPatente: ");
	gets(aux_pat);
	fflush(stdin);
	maiuscula(aux_pat);
	
	m->numreg = busca_patente(pc, qc, aux_org, aux_pat);
	
	if(m->numreg == -1)
		printf("\nOps, organizacao e patente nao encontrados...\n\n\n");
	else
		printf("\nMilitar cadastrado com sucesso.\nRegistro: %i\tSalario: R$%.2f\n\n\n", m->numreg, (pc+(m->numreg) - 1)->salario);
	
	system("pause");
	
	
}//cadastro_militar

int  busca_patente(carreira *c, int qc, char *p_org, char *p_pat){
	
	int i;
	
	for(i = 0; i < qc; i++, c++)
		if((strcmp(c->org, p_org) == 0) && (strcmp(c->patente, p_pat) == 0)){
			c->qmilitar++;
			return c->reg;
		}//if
	return -1; //ahhh cara, nao achei :(
	
}//busca_patente

int  busca_CPF(militar *m, int qm, char *aux_CPF){
	
	int i;
	
	for(i = 0; i < qm; i++, m++){
		if(strcmp(m->CPF, aux_CPF) == 0)
			return i;	//posicao do militar na estrutura MTO FODA LEK VAMO DANSA
	}
	return -1;	//ta errado slk
	
}//busca_CPF

void troca_patente(militar *m, int qm, carreira *c, int qc){
	
	int pos;
	char aux_CPF[13], aux_org[20], aux_pat[20];
	
	printf("\nCPF: ");
	gets(aux_CPF);
	fflush(stdin);
	
	pos = busca_CPF(m, qm, aux_CPF);
	
	if(pos == -1)
		printf("\nCPF nao encontrado\n\n\n");
	else{
		printf("\nNOVA Organizacao: ");
		gets(aux_org);
		fflush(stdin);
		maiuscula(aux_org);
		
		printf("\nNOVA Patente: ");
		gets(aux_pat);
		fflush(stdin);
		maiuscula(aux_pat);
		
		//atualizacao da lista mais gay de todo o planeta rosa 2.0
		
		(c+((m+pos)->numreg) - 1)->qmilitar--;	//baixamemoria
		(m+pos)->numreg = busca_patente(c, qc, aux_org, aux_pat);
		
		if((m+pos)->numreg == -1)
			printf("\nOps, organizacao e patente nao encontrados...\n\n\n");
		else
			printf("\nAtualizacao efetuada.\nPatente: %i\tSalario: R$%.2f\n\n\n", (m+pos)->numreg, (c+((m+pos)->numreg)-1)->salario);
	}
	
	system("pause");
	
}//troca_patente

void maiuscula(char *p){
	int tam = strlen(p), i;
	for(i = 0; i < tam; i++, p++)
		if(*p >='a' && *p <= 'z')
			*p-=32;
}//maiuscula

void mostra_carreira(carreira *c, int qc){
	int i;
	for(i = 0; i < qc; i++, c++)
		printf("\nRegistro: %i\nQtde militares: %i\nOrganizacao: %s\nPatente: %s\nSalario: R$%.2f\n\n", c->reg, c->qmilitar, c->org, c->patente, c->salario);
	system("pause");
}//mostra_carreira

void mostra_militar(militar *m, int qm){
	int i;
	for(i = 0; i < qm; i++, m++)
		printf("\nCPF: %s\nNome: %s\nNum do Registro: %i\n\n", m->CPF, m->nome, m->numreg);
	system("pause");
}//mostra_militar
