/*#include <stdio.h>

int main() {
    int n, i;
    long sum = 0;
    long int t = 1;

    printf("Input the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%ld  ", t);

        if (i < n) {
            printf("+ "); // Print addition sign between terms (except the last term).
        }

        sum = sum + t; // Add the current term to the running sum.
        t = (t * 10) + 1; // Generate the next term of the series.
    }

    printf("\nThe Sum is: %ld\n", sum); // Print the final sum of the series.
    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size, i, even = 0, odd = 0;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1; // Exit with an error code
    }

    printf("Enter %d elements in array: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even++; // Increment even count
        } else {
            odd++; // Increment odd count
        }
    }

    printf("Total even elements: %d\n", even);
    printf("Total odd elements: %d\n", odd);

    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h> // For atoi() function

int main(int argc, char *argv[]) {
    int sum = 0;
    int i;

    if (argc < 2) {
        printf("Please use \"%s value1 value2 ...\"\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; i++) {
        printf("arg[%2d]: %d\n", i, atoi(argv[i]));
        sum += atoi(argv[i]);
    }

    printf("Sum of all values: %d\n", sum);
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

int main() {
    FILE* fp;
    char filename[MAX_FILE_NAME];
    char c;
    int count = 0;

    printf("Type a file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        count++;
    }

    fclose(fp);

    printf("File has %d characters.\n", count);
    return 0;
}*/
/*#include <stdio.h>
#include <string.h> // For strcpy()

int main() {
    char firstString[100], secondString[100], temp[100];

    printf("Enter the First String: ");
    scanf("%s", firstString);

    printf("Enter the Second String: ");
    scanf("%s", secondString);

    printf("String before Swap:\n");
    printf("First String = %s Second String = %s\n", firstString, secondString);

    // Swap the strings using strcpy
    strcpy(temp, firstString);
    strcpy(firstString, secondString);
    strcpy(secondString, temp);

    printf("String after Swap:\n");
    printf("First String = %s Second String = %s\n", firstString, secondString);

    return 0;
}*/
#include <stdio.h>

int main() {
    int startYear, endYear, i;

    printf("Enter the value of starting year and ending year: ");
    scanf("%d %d", &startYear, &endYear);

    printf("Leap years from %d to %d:\n", startYear, endYear);

    for (i = startYear; i <= endYear; i++) {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}




