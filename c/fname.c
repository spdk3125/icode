/*#include <stdio.h>

int main() {
    int number, digit, count = 0, remainder;

    printf("Enter any number: ");
    scanf("%d", &number);

    // Handle negative numbers gracefully
    if (number < 0) {
        printf("Error: Please enter a non-negative number.\n");
        return 1; // Indicate error
    }

    printf("Enter the digit: ");
    scanf("%d", &digit);

    // Extract digits and count occurrences using a while loop
    while (number > 0) {
        remainder = number % 10;
        if (remainder == digit) {
            count++;
        }
        number /= 10; // Efficiently remove the last digit
    }

    printf("Total number of occurrences: %d\n", count);

    return 0; // Indicate successful execution
}*/
/*#include <stdio.h>

int main() {
    int n;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than zero.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements in array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Total count of even numbers: %d\n", even_count);
    printf("Total count of odd numbers: %d\n", odd_count);


    return 0;
}*/
/*
#include <stdio.h>

int is_even(int num) {
  return num % 2 == 0;
}

int main() {
  float number;

  printf("Enter a number: ");
  scanf("%f", &number);

  int whole_part = (int)number;  // Convert to integer to ignore decimals

  if (is_even(whole_part)) {
    printf("%.1f is even (ignoring the fractional part).\n", number);
  } else {
    printf("%.1f is odd (ignoring the fractional part).\n", number);
  }

  return 0;
}
*/
/*#include <stdio.h>

int main() {
    char filename[100]; // Array to store the filename
    int ch;
    int count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "r"); // Open the file in read mode

    if (fptr == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Count characters until EOF (End-Of-File) is reached
    while ((ch = fgetc(fptr)) != EOF) {
        count++;
    }

    fclose(fptr); // Close the file

    printf("Total number of characters in '%s': %d\n", filename, count);

    return 0;
}*/

/*#include <stdio.h>
#include <ctype.h> // For isalpha()

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch); // Include a space before %c to handle leading whitespace

    if (isalpha(ch)) {
        ch = tolower(ch); // Convert to lowercase for case-insensitive vowel/consonant check
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            printf("%c is a vowel.\n", ch);
        } else {
            printf("%c is a consonant.\n", ch);
        }
    } else {
        printf("'%c' is not an alphabet.\n", ch);
    }

    return 0;
}*/

/*#include <stdio.h>

int is_leap_year(int year) {
  // Logic to check for leap year
  if (year % 400 == 0) return 1; // Divisible by 400 is a leap year
  else if (year % 100 == 0) return 0; // Divisible by 100 but not 400 is not a leap year
  else if (year % 4 == 0) return 1; // Divisible by 4 (except above cases) is a leap year
  else return 0; // Not divisible by 4 is not a leap year
}

int main() {
  int start_year, end_year;

  printf("Enter starting year: ");
  scanf("%d", &start_year);

  printf("Enter ending year: ");
  scanf("%d", &end_year);

  printf("Leap years between %d and %d:\n", start_year, end_year);

  // Loop from start_year to end_year (inclusive)
  for (int year = start_year; year <= end_year; year++) {
    if (is_leap_year(year)) {
      printf("%d\n", year);
    }
  }

  return 0;
}
*/
/*#include <stdio.h>

int main() {
    int num1, num2, num3, max;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Nested if-else to find maximum
    if (num1 >= num2) {
        if (num1 >= num3) {
            max = num1;
        } else {
            max = num3;
        }
    } else {
        if (num2 >= num3) {
            max = num2;
        } else {
            max = num3;
        }
    }

    printf("Maximum of %d, %d and %d is: %d\n", num1, num2, num3, max);

    return 0;
}
*/

/*#include <stdio.h>

int main() {
    int N;

    printf("Enter the number of lines (N): ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        // Print leading 1
        printf("1 ");

        // Print internal pattern (0s and 1s)
        for (int j = 2; j <= i; j++) {
            int digit = (i % j == 0) ? 1 : 0;  // Boundary condition: print 1 if divisible
            printf("%d ", digit);
        }

        printf("\n");
    }

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int num;

    printf("Enter the number to find whether it is power of 2: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("No (Non-positive numbers are not powers of 2)\n");
    } else if (num & (num - 1)) { // Efficient bitwise check
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}*/
/*
#include <stdio.h>
#include <string.h> // For strcpy()

typedef struct {
  int voter_id;
  char name[50];
  int age;
  char native[50];
} Voter; // Define the alias 'Voter' for the structure

int main() {
  Voter voter; // Create a structure variable using the typedef alias 'Voter'

  printf("Enter voter ID, Voter Name, age and native: ");
  scanf("%d %s %d %s", &voter.voter_id, voter.name, &voter.age, voter.native);

  printf("\nVoter Details:\n");
  printf("Voter ID: %d\n", voter.voter_id);
  printf("Name: %s\n", voter.name);
  printf("Age: %d\n", voter.age);
  printf("Native: %s\n", voter.native);

  return 0;
}
*/
/*#include <stdio.h>

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Assign addresses of num1 and num2 to pointers
    ptr1 = &num1;
    ptr2 = &num2;

    int sum = *ptr1 + *ptr2; // Dereference pointers to access and add values

    printf("Sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}*/

/*#include <stdio.h>
#include <ctype.h> // For character classification functions

int main() {
    char str[100]; // Array to store the string
    int alp_count = 0, digit_count = 0, special_count = 0;
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read the string with fgets (safer)

    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            alp_count++;
        } else if (isdigit(ch)) {
            digit_count++;
        } else if (ispunct(ch)) { // Check for special characters using ispunct
            special_count++;
        }
    }

    printf("Number of alphabets: %d\n", alp_count);
    printf("Number of digits: %d\n", digit_count);
    printf("Number of special characters: %d\n", special_count);

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h> // Include this header for strcspn

struct Student {
    char name[50];
    int rollno;
    float marks;
};

int main() {
    int num_students, i;

    printf("Enter the number of students (at least 2): ");
    scanf("%d", &num_students);

    if (num_students < 2) {
        printf("Error: Please enter at least 2 students.\n");
        return 1; // Exit with an error code if invalid input
    }

    struct Student students[num_students]; // Array of structures to store student details

    // Read student details
    for (i = 0; i < num_students; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        getchar(); // Consume leftover newline character
        fgets(students[i].name, sizeof(students[i].name), stdin); // Read name with fgets
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline from name

        printf("Roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        // Consume leftover newline character (if any)
        while ((getchar()) != '\n'); // Optional: Clear input buffer for next iteration
    }

    // Display student information
    printf("\nStudent Details:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s", students[i].name); // Print name without newline
        printf(" %d %.2f\n", students[i].rollno, students[i].marks);
    }

    return 0;
}*/

/*#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter row size: ");
    scanf("%d", &rows);

    printf("Enter column size: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Transpose of the given matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]); // Access elements in transposed order
        }
        printf("\n"); // Add newline after each row of the transpose
    }

    return 0;
}
*/
/*
#include <stdio.h>

// Recursive function to print natural numbers in reverse order
void PrintReverseNaturalNumbers(int n) {
    if (n <= 0) {
        return; // Base case: Stop recursion when n becomes non-positive
    } else {
        printf("%d ", n); // Print the current number
        PrintReverseNaturalNumbers(n - 1); // Recur with n-1
    }
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Output:\n");
    PrintReverseNaturalNumbers(num);

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int num, digit, sum = 0;

    // Prompt the user to enter a positive integer
    printf("Enter any positive number: ");
    scanf("%d", &num);

    // Check if the entered number is positive
    if (num <= 0) {
        printf("Please input a positive integer.\n");
        return 1; // Return an error code
    }

    // Calculate the sum of the squares of each digit
    do {
        digit = num % 10; // Extract the last digit
        sum += digit * digit; // Add the square of the digit to the sum
        num /= 10; // Remove the last digit
    } while (num != 0); // Continue the loop until there are no more digits

    // Print the sum of the squares of each digit
    printf("Sum of the squares of individual digits is %d\n", sum);

    return 0; // Indicate successful program execution
}
*/
/*#include <stdio.h>

int main() {
    int n, i;
    float num[100], sum = 0, avg;

    // Prompt the user to input the number of elements
    printf("Enter the number of elements (N): ");
    scanf("%d", &n);

    // Read N numbers from the user
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &num[i]);
        sum += num[i]; // Accumulate the sum
    }

    // Calculate the average
    avg = sum / n;

    // Display the sum and average
    printf("\nSum of the numbers: %.2f\n", sum);
    printf("Average of the numbers: %.2f\n", avg);

    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *data;

    // Prompt the user to enter the total number of elements
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    // Allocate memory for n elements
    data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Read numbers entered by the user
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", data + i);
    }

    // Find the largest number
    double max = *data;
    for (int i = 1; i < n; ++i) {
        if (*(data + i) > max) {
            max = *(data + i);
        }
    }

    // Print the largest number
    printf("Largest number = %.2lf\n", max);

    // Free the allocated memory
    free(data);

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int totalDays, years, weeks, remainingDays;

    // Prompt the user to enter the total number of days
    printf("Enter total number of days: ");
    scanf("%d", &totalDays);

    // Calculate years, weeks, and remaining days
    years = totalDays / 365;
    totalDays %= 365;

    weeks = totalDays / 7;
    remainingDays = totalDays % 7;

    // Display the result
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", remainingDays);

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int N, i;
    long sum = 0, term = 0;

    // Prompt the user to input the value of N
    printf("Enter the value of N (1 <= N <= 10): ");
    scanf("%d", &N);

    if (N < 1 || N > 10) {
        printf("Invalid input. N must be between 1 and 10.\n");
        return 1; // Exit with an error code
    }

    // Calculate the sum of the series
    for (i = 1; i <= N; i++) {
        term = term * 10 + 1; // Generate the next term (e.g., 1, 11, 111, ...)
        sum += term; // Add the current term to the sum
    }

    // Display the series and its sum
    printf("Series: ");
    for (i = 1; i <= N; i++) {
        printf("%ld", term);
        if (i < N) {
            printf(" + ");
        }
    }
    printf("\nSum: %ld\n", sum);

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int employeeID;
    float hoursWorked, wagePerHour, salary;

    // Prompt the user to input employee details
    printf("Enter employee's ID: ");
    scanf("%d", &employeeID);

    printf("Enter total hours worked in a month: ");
    scanf("%f", &hoursWorked);

    printf("Enter wage per hour: ");
    scanf("%f", &wagePerHour);

    // Calculate the salary
    salary = hoursWorked * wagePerHour;

    // Display the result with two decimal places
    printf("Employee ID: %d\n", employeeID);
    printf("Salary for the month: %.2f\n", salary);

    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    double sum = 0.0;

    if (argc < 2) {
        printf("Please use: \"%s value1 value2 ...\"\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; i++) {
        sum += atof(argv[i]); // Convert string to double and add to sum
    }

    printf("SUM of all values: %.2lf\n", sum);

    return 0;
}*/
/*#include <stdio.h>
#include <ctype.h> // For isalpha function

int main() {
    char S1[100], S2[100];
    int i, j = 0;

    // Prompt the user to enter the source string S1
    printf("Enter the source string S1: ");
    fgets(S1, sizeof(S1), stdin);

    // Copy alphabets and spaces from S1 to S2
    for (i = 0; S1[i] != '\0'; ++i) {
        if (isalpha(S1[i]) || S1[i] == ' ') {
            S2[j++] = S1[i];
        }
    }
    S2[j] = '\0'; // Null-terminate S2

    // Display the result
    printf("S2 = %s", S2);

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int amount, notes;
    int denominations[] = {100, 50, 20, 10, 5, 2, 1};

    // Input the cash amount
    printf("Enter the cash amount: ");
    scanf("%d", &amount);

    printf("Smallest possible denominations are:\n");

    // Calculate and print the number of each denomination
    for (int i = 0; i < 7; i++) {
        notes = amount / denominations[i];
        if (notes) {
            printf("%d Note(s) of %d\n", notes, denominations[i]);
            amount %= denominations[i]; // Remaining amount
        }
    }

    return 0;
}*/
/*#include <stdio.h>
#include <string.h> // Include the string.h library for strcpy

int main() {
    char str1[100], str2[100], temp[100];

    // Input two strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Swap the strings using strcpy
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    // Display the swapped strings
    printf("After swapping:\n");
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);

    return 0;
}*/
/*#include <stdio.h>

// Function to calculate the square of a number
double calculateSquare(double num) {
    return num * num;
}

int main() {
    double number, square;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%lf", &number);

    // Calculate the square using the user-defined function
    square = calculateSquare(number);

    // Display the result
    printf("Square of %.2lf = %.2lf\n", number, square);

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int N, firstNumber, increment, sum = 0, term;

    // Input the number of terms, first number, and increment
    printf("Enter the number of terms (N) in AP series: ");
    scanf("%d", &N);

    printf("Enter the starting number: ");
    scanf("%d", &firstNumber);

    printf("Enter the increment value: ");
    scanf("%d", &increment);

    // Calculate the sum of the AP series
    for (int i = 0; i < N; i++) {
        term = firstNumber + i * increment;
        sum += term;
        if (i < N - 1) {
            printf("%d + ", term);
        } else {
            printf("%d", term);
        }
    }

    printf("\nThe Sum of A.P Series: %d\n", sum);

    return 0;
}*/
/*#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Using index operator
    printf("Characters in reverse order (using index operator):\n");
    for (i = len - 1; i >= 0; i--) {
        printf("%c ", str[i]);
    }
    printf("\n");

    // Using pointer arithmetic
    printf("Characters in reverse order (using pointer arithmetic):\n");
    char *ptr = str + len - 1;
    while (ptr >= str) {
        printf("%c ", *ptr);
        ptr--;
    }
    printf("\n");

    return 0;
}*/
/*#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    // Calculate the sum of proper divisors
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of proper divisors equals the original number
    if (sum == num && num > 0) {
        return 1; // It's a perfect number
    } else {
        return 0; // It's not a perfect number
    }
}

int main() {
    int number;

    // Input a number from the user
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Check if it's a perfect number
    if (isPerfect(number)) {
        printf("%d is a PERFECT NUMBER\n", number);
    } else {
        printf("%d is NOT a PERFECT NUMBER\n", number);
    }

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int N, num = 1;

    // Input the value of N
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Print the pyramid pattern
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
            if (num > 9) {
                num = 1; // Reset to 1 if it exceeds 9
            }
        }
        printf("\n");
    }

    return 0;
}*/
/*#include <stdio.h>

// Recursive function to find the sum of array elements
int findSum(int arr[], int n) {
    if (n == 0) {
        return 0; // Base case: empty array
    } else {
        return arr[n - 1] + findSum(arr, n - 1); // Recur with one less element
    }
}

int main() {
    int N, i;
    int arr[100];

    // Input the number of elements
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);

    // Input the array elements
    printf("Enter %d elements:\n", N);
    for (i = 0; i < N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Calculate the sum using the recursive function
    int sum = findSum(arr, N);

    // Display the result
    printf("Sum of array elements: %d\n", sum);

    return 0;
}*/
















