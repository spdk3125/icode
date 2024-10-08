package distanceconverter;
import java.util.Scanner;
public class DistanceConverter {
    public void convert() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Distance Converter");
        System.out.println("1: Meters to Kilometers");
        System.out.println("2: Kilometers to Meters");
        System.out.println("3: Miles to Kilometers");
        System.out.println("4: Kilometers to Miles");
        System.out.print("Choose an option: ");
        int choice = sc.nextInt();
        double distance, result;
        switch (choice) {
            case 1:
                System.out.print("Enter distance in Meters: ");
                distance = sc.nextDouble();
                result = distance / 1000;
                System.out.println("Kilometers: " + result);
                break;
            case 2:
                System.out.print("Enter distance in Kilometers: ");
                distance = sc.nextDouble();
                result = distance * 1000;
                System.out.println("Meters: " + result);
                break;
            case 3:
                System.out.print("Enter distance in Miles: ");
                distance = sc.nextDouble();
                result = distance * 1.60934;
                System.out.println("Kilometers: " + result);
                break;
            case 4:
                System.out.print("Enter distance in Kilometers: ");
                distance = sc.nextDouble();
                result = distance / 1.60934;
                System.out.println("Miles: " + result);
                break;
            default:
                System.out.println("Invalid choice.");
        }
    }
}
