import java.util.Scanner;

public class MatrixMultiplication {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter Number of rows for Matrix A: ");
		int m = scanner.nextInt();
		System.out.print("Enter Number of columns for Matrix A: ");
		int n = scanner.nextInt();
		int[][] matrixA = new int[m][n];

		System.out.println("Enter elements of matrix A");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrixA[i][j] = scanner.nextInt();
			}
		}

		System.out.print("Enter Number of rows for Matrix B: ");
		int p = scanner.nextInt();
		int[][] matrixB = new int[n][p];

		System.out.println("Enter elements of matrix B");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				matrixB[i][j] = scanner.nextInt();
			}
		}
		scanner.close();

		int[][] matrixC = new int[m][p];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) { 
				for (int k = 0; k < n; k++) {
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				      }
			}
		}
		
		System.out.println("Resultant matrix C (A * B)");
		for (int i = 0; i < m; i++) { 
			for (int j = 0; j < p; j++) {
				System.out.print(matrixC[i][j] + " ");
			}
			System.out.println();
		}	


		
	}
}
