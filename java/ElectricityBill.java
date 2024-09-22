import java.util.Scanner;

class ElectricityBill {
    private int consumerNumber;
    private String consumerName;
    private double prevMonthReading;
    private double currMonthReading;
    private String connectionType; // "domestic" or "commercial"

    // Constructor
    public ElectricityBill(int consumerNumber, String consumerName,
                           double prevMonthReading, double currMonthReading,
                           String connectionType) {
        this.consumerNumber = consumerNumber;
        this.consumerName = consumerName;
        this.prevMonthReading = prevMonthReading;
        this.currMonthReading = currMonthReading;
        this.connectionType = connectionType;
    }

    // Calculate bill amount
    public double calculateBill() {
        double unitsConsumed = currMonthReading - prevMonthReading;
        double ratePerUnit;

        if ("domestic".equalsIgnoreCase(connectionType)) {
            // Domestic tariff rates (example)
            ratePerUnit = 5.0; // Rs. 5 per unit
        } else if ("commercial".equalsIgnoreCase(connectionType)) {
            // Commercial tariff rates (example)
            ratePerUnit = 7.5; // Rs. 7.5 per unit
        } else {
            System.out.println("Invalid connection type. Please specify 'domestic' or 'commercial'.");
            return 0.0;
        }

        return unitsConsumed * ratePerUnit;
    }

    // Display bill details
    public void displayBill() {
        System.out.println("Electricity Bill Details:");
        System.out.println("Consumer Number: " + consumerNumber);
        System.out.println("Consumer Name: " + consumerName);
        System.out.println("Previous Month Reading: " + prevMonthReading);
        System.out.println("Current Month Reading: " + currMonthReading);
        System.out.println("Connection Type: " + connectionType);
        System.out.println("Total Bill Amount: Rs. " + calculateBill());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Consumer Number: ");
        int consumerNumber = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        System.out.print("Enter Consumer Name: ");
        String consumerName = scanner.nextLine();

        System.out.print("Enter Previous Month Reading (in units): ");
        double prevMonthReading = scanner.nextDouble();

        System.out.print("Enter Current Month Reading (in units): ");
        double currMonthReading = scanner.nextDouble();

        System.out.print("Enter Connection Type (domestic/commercial): ");
        String connectionType = scanner.next();

        ElectricityBill bill = new ElectricityBill(consumerNumber, consumerName,
                                                   prevMonthReading, currMonthReading,
                                                   connectionType);
        bill.displayBill();

        scanner.close();
    }
}

