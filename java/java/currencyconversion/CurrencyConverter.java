package currencyconverter;
import java.util.Scanner;
public class CurrencyConverter {
    public void convert() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Currency Converter");
        System.out.println("1: Dollar to INR");
        System.out.println("2: Euro to INR");
        System.out.println("3: Yen to INR");
        System.out.println("4: INR to Dollar");
        System.out.println("5: INR to Euro");
        System.out.println("6: INR to Yen");
        System.out.print("Choose an option: ");
        int choice = sc.nextInt();
        double amount, result;
        switch (choice) {
            case 1:
                System.out.print("Enter amount in Dollars: ");
                amount = sc.nextDouble();
                result = amount * 75; // Example conversion rate
                System.out.println("INR: " + result);
                break;
            case 2:
                System.out.print("Enter amount in Euros: ");
                amount = sc.nextDouble();
                result = amount * 90; 
                System.out.println("INR: " + result);
                break;
            case 3:
                System.out.print("Enter amount in Yen: ");
                amount = sc.nextDouble();
                result = amount * 0.65; 
                System.out.println("INR: " + result);
                break;
            case 4:
                System.out.print("Enter amount in INR: ");
                amount = sc.nextDouble();
                result = amount / 75; 
                System.out.println("Dollars: " + result);
                break;
            case 5:
                System.out.print("Enter amount in INR: ");
                amount = sc.nextDouble();
                result = amount / 90; 
                System.out.println("Euros: " + result);
                break;
            case 6:
                System.out.print("Enter amount in INR: ");
                amount = sc.nextDouble();
                result = amount / 0.65; 
                System.out.println("Yen: " + result);
                break;
            default:
                System.out.println("Invalid choice.");
        }
    }
}
