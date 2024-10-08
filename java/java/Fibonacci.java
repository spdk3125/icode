import java.util.Scanner;

public class Fibonacci {
    public static int fibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    public static int fibonacciIterative(int n) {
        if (n <= 1) {
            return n;
        }

        int fib = 1;
        int prev = 0;

        for (int i = 2; i <= n; i++) {
            int temp = fib;
            fib += prev;
            prev = temp;
        }

        return fib;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();

        if (n < 0) {
            System.out.println("Invalid input: n must be a non-negative integer.");
        } else {
            System.out.println("Fibonacci sequence using recursive approach:");
            for (int i = 0; i <= n; i++) {
                System.out.print(fibonacciRecursive(i) + " ");
            }
            System.out.println();

            System.out.println("Fibonacci sequence using non-recursive approach:");
            for (int i = 0; i <= n; i++) {
                System.out.print(fibonacciIterative(i) + " ");
            }
        }

        scanner.close();
    }
}
