//Para 30 alunos da turma de Algoritmos e Programa��o, receber a m�dia
//de teoria e a m�dia de laborat�rio, calcular a m�dia final (final = teoria *
//0.6 + laborat�rio * 0.4) e informar se cada um foi bem (final >= 7), razo�vel
//(5 <= final < 7) ou mal (final < 5).

#include <stdio.h>
#include <conio.h>

main()
{
	int i;
	float mt, ml, mf;
	
	for (i = 1; i <= 30; i++)
	{
		printf("Aluno %i\n", i);
		
		printf("Qual a media de teoria?\n");
		scanf("%f", &mt);
		printf("Qual a media de laboratorio?\n");
		scanf("%f", &ml);
		
		mf = (mt * 0.6) + (ml * 0.4);
		printf("A media final e %.2f\n", mf);
		
		if (mf >= 7)
		{
			printf("Voce foi bem\n");
			getch();
		}
		else if (5 <= mf && mf < 7)
		{
			printf("Voce foi razoavel\n");
			getch();
		}
		else
		{
			printf("Voce foi mal\n");
			getch();
		}
		printf("---------------\n");
	}
}
