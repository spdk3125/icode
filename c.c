/*#include <stdio.h>
int main()
{
    int num, digit, count = 0, temp;
    printf("Enter any number :: ");
    scanf("%d", &num);
    printf("Enter the digit :: ");
    scanf("%d", &digit);
    temp = num; // store the original number in a temporary variable
    while (temp > 0) // loop until the number becomes zero
    {
        if (temp % 10 == digit) // check if the last digit is equal to the given digit
        {
            count++; // increment the count
        }
        temp = temp / 10; // remove the last digit
    }
    printf("The occurrence of %d is %d times\n", digit, count); // print the result
    return 0;
}*/
/*#include <stdio.h>

int main()
{
    // Declare variables to store length, breadth, area and perimeter
    float length, breadth, area, perimeter;

    // Prompt the user to enter length and breadth of the rectangle
    printf("Enter length of the rectangle = ");
    scanf("%f", &length);

    printf("Enter breadth of the rectangle = ");
    scanf("%f", &breadth);

    // Compute the area and perimeter using the formulae
    area = length * breadth;
    perimeter = 2 * (length + breadth);

    // Display the results
    printf("Area of rectangle = %f\n", area);
    printf("Perimeter of rectangle = %f\n", perimeter);

    return 0;
}*/
/*#include <stdio.h>

int main()
{
    // Declare a variable to store the number of days
    float days;

    // Declare variables to store the converted years, weeks and days
    int years, weeks, remaining_days;

    // Prompt the user to enter the number of days
    printf("Enter the number of days: ");
    scanf("%f", &days);

    // Calculate the years, weeks and days
    years = (int) days / 365; // Ignore leap year
    weeks = (int) (days - years * 365) / 7;
    remaining_days = (int) (days - years * 365 - weeks * 7);

    // Display the result
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", remaining_days);

    return 0;
}*/
/*#include <stdio.h>

int main()
{
    // Declare variables to store the employee's ID, working hours and salary amount
    char id[11];
    int hours;
    float amount;

    // Declare a variable to store the employee's salary
    float salary;

    // Prompt the user to input the employee's ID, working hours and salary amount
    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%s", id);
    printf("Input the working hrs: ");
    scanf("%d", &hours);
    printf("Salary amount/hr: ");
    scanf("%f", &amount);

    // Calculate the employee's salary
    salary = hours * amount;

    // Display the employee's ID and salary
    printf("Employees ID = %s\n", id);
    printf("Salary = %.2f\n", salary);

    return 0;
}*/
/*#include <stdio.h>

// Declare a function to check if a number is even or odd
int is_even(float num)
{
    // If the number is divisible by 2, return 1 (true)
    if ((int) num % 2 == 0)
    {
        return 1;
    }
    // Otherwise, return 0 (false)
    else
    {
        return 0;
    }
}

int main()
{
    // Declare a variable to store the input number
    float number;

    // Prompt the user to input any number
    printf("Input any number: ");
    scanf("%f", &number);

    // Call the function to check if the number is even or odd
    int result = is_even(number);

    // Display the result
    if (result == 1)
    {
        printf("The entered number is even.\n");
    }
    else
    {
        printf("The entered number is odd.\n");
    }

    return 0;
}*/
#include <stdio.h>

int main()
{
    // Declare a variable to store the amount
    int amount;

    // Declare variables to store the number of notes of each denomination
    int notes_100, notes_50, notes_20, notes_10, notes_5, notes_1;

    // Prompt the user to input the amount
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Calculate the number of notes of each denomination
    notes_100 = (int) amount / 100; // Use typecast to get the integer quotient
    amount = amount % 100; // Get the remaining amount
    notes_50 = (int) amount / 50;
    amount = amount % 50;
    notes_20 = (int) amount / 20;
    amount = amount % 20;
    notes_10 = (int) amount / 10;
    amount = amount % 10;
    notes_5 = (int) amount / 5;
    amount = amount % 5;
    notes_1 = (int) amount / 1;

    // Display the result
    printf("There are:\n");
    printf("%d Note(s) of 100\n", notes_100);
    printf("%d Note(s) of 50\n", notes_50);
    printf("%d Note(s) of 20\n", notes_20);
    printf("%d Note(s) of 10\n", notes_10);
    printf("%d Note(s) of 5\n", notes_5);
    printf("%d Note(s) of 1\n", notes_1);

    return 0;
}








