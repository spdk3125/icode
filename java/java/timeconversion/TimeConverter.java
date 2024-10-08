package timeconverter;
import java.util.Scanner;
public class TimeConverter {
    public void convert() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Time Converter");
        System.out.println("1: Hours to Minutes");
        System.out.println("2: Minutes to Hours");
        System.out.println("3: Seconds to Minutes");
        System.out.println("4: Minutes to Seconds");
        System.out.print("Choose an option: ");
        int choice = sc.nextInt();
        double time, result;
        switch (choice) {
            case 1:
                System.out.print("Enter time in Hours: ");
                time = sc.nextDouble();
                result = time * 60;
                System.out.println("Minutes: " + result);
                break;
            case 2:
                System.out.print("Enter time in Minutes: ");
                time = sc.nextDouble();
                result = time / 60;
                System.out.println("Hours: " + result);
                break;
            case 3:
                System.out.print("Enter time in Seconds: ");
                time = sc.nextDouble();
                result = time / 60;
                System.out.println("Minutes: " + result);
                break;
            case 4:
                System.out.print("Enter time in Minutes: ");
                time = sc.nextDouble();
                result = time * 60;
                System.out.println("Seconds: " + result);
                break;
            default:
                System.out.println("Invalid choice.");
        }
    }
}
