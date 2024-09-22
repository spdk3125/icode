import java.util.Scanner;

public class PrimeNumberPrinter {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a Number: ");
		int n = scanner.nextInt();
		scanner.close();

		System.out.print("prime number up to " + n + " : ");
		for (int i = 2; i <= n; i++) {
			if (isPrime(i)) {
				System.out.print(i +" ");
			}
		}
	}

	private static boolean isPrime(int num) {
		if (num <= 1) {
			return false;
		}
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (num %i == 0) {
				return false;
			}
		}
		return true;

	}

}

		
