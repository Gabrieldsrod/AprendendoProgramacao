import java.util.Scanner;

public class condicional {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
//		int num1, num2, soma;
//		
//		num1 = sc.nextInt();
//		num2 = sc.nextInt();
//		System.out.println();
//		
//		System.out.println(num1);
//		System.out.println(num2);
//		System.out.println();
//
//		soma = num1 + num2;
//		
//		System.out.println(soma);
//		
//		if (soma < 10)
//		{
//			System.out.println("A soma é menor que 10");
//		}
//		else
//		{
//			System.out.println("A soma é maior que 10");
//		}
		
		int horas;
		
		System.out.print("Que horas são? Apenas a hora em formato de 24h: ");
		horas = sc.nextInt();
		
		if(horas < 12 && horas >= 6) {
			System.out.println("Bom dia!!!");
		}
		else if (horas >= 12 && horas < 18) {
			System.out.println("Boa tarde!!!");
		}
		else {
			System.out.println("Boa noite!!!");
		}
		
		
		sc.close();
	}

}
