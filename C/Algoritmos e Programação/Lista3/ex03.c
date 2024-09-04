// Calcular o IMC (Índice de Massa Corporal) de uma pessoa através da
// fórmula IMC = Peso (kg) / Altura2 (m). Informe a classificação do IMC na
// tela de acordo com as regras abaixo:
// < 18,5 						Abaixo do peso
// De 18,5 a menor que 25,0 	Saudável
// De 25,0 a menor que 30,0 	Sobrepeso
// De 30,0 a menor que 35,0 	Obesidade Grau I
// De 35,0 a menor que 40,0 	Obesidade Grau II (severa)
// De 40,0 em diante 			Obesidade Grau III (mórbida)


#include <stdio.h>
#include <math.h>

int main()
{
	float peso, altura, imc, alt;
	
	printf("Vamos calcular o seu IMC\n");
	
	printf("Qual o seu peso? (em kg)\n");
	scanf("%f", &peso);
	
	printf("Qual a sua altura? (em m)\n");
	scanf("%f", &altura);
	
	alt = pow(altura, 2);
	imc = peso / alt;
	
	printf("Seu imc  %f\n", imc);
	
	if (imc < 18.5)
	{
		printf("Voce esta abaixo do peso");
	}
	else if (imc >= 18.5 && imc < 25)
	{
		printf("Voce esta saudavel");
	}
	else if (imc >= 25 && imc < 30)
	{
		printf("Voce esta co sobrepeso");
	}
	else if (imc >= 30 && imc < 35)
	{
		printf("Voce esta com obesidade de grau I");
	}
	else if (imc >= 35 && imc < 40)
	{
		printf("Voce esta com obesidade de grau II");
	}
	else if (imc >= 40)
	{
		printf("Voce esta com obesidade de grau III");
	}
}
