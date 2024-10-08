import java.util.Arrays;
import java.util.Scanner;

public class SortNames {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of names: ");
        int n = input.nextInt();
        input.nextLine(); // Consume newline

        String[] names = new String[n];
        System.out.println("Enter the names:");
        for (int i = 0; i < n; i++) {
            names[i] = input.nextLine();
        }

        // Sort the names in ascending order
        Arrays.sort(names);

        System.out.println("Names in ascending order:");
        for (String name : names) {
            System.out.println(name);
        }
    }
}
