
//import java.util.Locale;
import java.util.Scanner;

public class input {

	public static void main(String[] args) {
//		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);

		double x;

		System.out.println("Digite um numero: ");
		x = sc.nextDouble();

		System.out.printf("Você digitou: %.2f%n", x);

		sc.close();
	}

}

//Para ler um texto ATÉ A QUEBRA DE LINHA
//import java.util.Scanner;
//
//public class input {
//	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		String s1, s2, s3;
//		s1 = sc.nextLine();
//		s2 = sc.nextLine();
//		s3 = sc.nextLine();
//		System.out.println("DADOS DIGITADOS:");
//		System.out.println(s1);
//		System.out.println(s2);
//		System.out.println(s3);
//		sc.close();
//	}
//}