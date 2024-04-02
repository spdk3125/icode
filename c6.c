#include <stdio.h>

int main() {
    int num, sum = 0;

    // Input a number from the user
    printf("Enter any number to check if it is a perfect number: ");
    scanf("%d", &num);

    // Calculate the sum of proper divisors
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check whether the sum of proper divisors equals the original number
    if (sum == num && num > 0) {
        printf("%d is a PERFECT NUMBER\n", num);
    } else {
        printf("%d is NOT a perfect number\n", num);
    }

    return 0;
}
#include <stdio.h>

// Function to find the sum of elements in an array using recursion
int arraySum(int arr[], int start, int len) {
    // Base case: If the array is empty, return 0
    if (start >= len) {
        return 0;
    }
    // Recursive case: Return the sum of the current element and the rest of the array
    return arr[start] + arraySum(arr, start + 1, len);
}

int main() {
    int arr[100];
    int N, sumofarray;

    // Input size and elements in the array
    printf("Enter size of the array: ");
    scanf("%d", &N);
    printf("Enter elements in the array: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of array elements using recursion
    sumofarray = arraySum(arr, 0, N);

    printf("Sum of array elements: %d\n", sumofarray);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char *ptr1, *ptr2;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Initialize pointers
    ptr1 = str1;
    ptr2 = str2;

    // Move ptr1 to the end of str1
    while (*ptr1 != '\0') {
        ptr1++;
    }

    // Concatenate str2 to str1
    while (*ptr2 != '\0') {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0'; // Add null character at the end

    printf("Concatenated string = %s\n", str1);

    return 0;
}
#include <stdio.h>

// Structure to represent distance in feet and inches
struct Distance {
    int feet;
    float inches;
};

// Function to add two distances
struct Distance addDistances(struct Distance d1, struct Distance d2) {
    struct Distance result;
    result.feet = d1.feet + d2.feet;
    result.inches = d1.inches + d2.inches;

    // Adjust inches if greater than 12
    if (result.inches >= 12) {
        result.feet += (int)(result.inches / 12);
        result.inches = fmod(result.inches, 12);
    }

    return result;
}

int main() {
    struct Distance dist1, dist2, total;

    printf("Enter first distance in feet & inches: ");
    scanf("%d %f", &dist1.feet, &dist1.inches);

    printf("Enter second distance in feet & inches: ");
    scanf("%d %f", &dist2.feet, &dist2.inches);

    // Add distances
    total = addDistances(dist1, dist2);

    printf("Total distance - Feet: %d, Inches: %.1f\n", total.feet, total.inches);

    return 0;
}
#include <stdio.h>
#include <ctype.h> // For isalpha and isdigit functions

int main() {
    char str[100];
    int alphabets = 0, digits = 0, special = 0, i = 0;

    printf("Enter any string: ");
    gets(str); // Read the input string

    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            alphabets++; // Increment alphabet count
        } else if (isdigit(str[i])) {
            digits++; // Increment digit count
        } else {
            special++; // Increment special character count
        }
        i++; // Move to the next character
    }

    printf("Alphabets = %d\n", alphabets);
    printf("Numbers = %d\n", digits);
    printf("Special characters = %d\n", special);

    return 0;
}
#include <stdio.h>

int main() {
    int num, digit, sum = 0;

    // Prompt the user to enter a positive integer
    printf("Input a positive integer: ");
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
    printf("Sum of the squares of each digit: %d\n", sum);

    return 0; // Indicate successful program execution
}

