import java.util.Scanner;

public class FibonacciIterative {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int n = input.nextInt();

        int num1 = 0, num2 = 1;
        

        for (int i = 0; i < n; i++) {
            int num3 = num1 + num2;
            System.out.print(" " + num1);
            num1 = num2;
            num2 = num3;
        }
    }
}
