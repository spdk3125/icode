import currencyconverter.CurrencyConverter;
import distanceconverter.DistanceConverter;
import timeconverter.TimeConverter;

import java.util.Scanner;

public class Converter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1: Currency Converter");
            System.out.println("2: Distance Converter");
            System.out.println("3: Time Converter");
            System.out.println("4: Exit");
            System.out.print("Choose an option: ");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    CurrencyConverter currencyConverter = new CurrencyConverter();
                    currencyConverter.convert();
                    break;
                case 2:
                    DistanceConverter distanceConverter = new DistanceConverter();
                    distanceConverter.convert();
                    break;
                case 3:
                    TimeConverter timeConverter = new TimeConverter();
                    timeConverter.convert();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
