package application;

import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int x, y;
		
		x = sc.nextInt();
		y = sc.nextInt();
		
		int[][] mat = new int[x][y];
		
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				mat[i][j] = sc.nextInt();
			}
		}
		
		int num = sc.nextInt();
		
		for (int i = 0; i < mat.length; i++) {  //movimentação vertical
			for (int j = 0; j < mat[i].length; j++) {  // movimentação horizontal
				if (mat[i][j] == num) {
					System.out.println("Position: " + i + "," + j +":");
					
					if(j > 0)
						System.out.println("Left: "+ mat[i][j-1]);
					if(i > 0)
						System.out.println("Up: " + mat[i-1][j]);
					if (j < mat[i].length-1) // comprimento horizontal
						System.out.println("Right: " + mat[i][j+1]);
					if (i < mat.length-1) // comprimento vertical
						System.out.println("Down: " + mat[i+1][j]);
						
				}
			}
		}
		
		sc.close();
	}

}
