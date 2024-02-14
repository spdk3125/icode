/*#include <stdio.h>
// using if statement
int main() {
    char c;
    int lowercase_vowel, uppercase_vowel;

    printf("Enter an alphabet: ");
    scanf("%c", &c);

    // Evaluates to 1 if variable c is a lowercase vowel
    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // Evaluates to 1 if variable c is an uppercase vowel
    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase_vowel || uppercase_vowel)
        printf("%c is a vowel.", c);
    else
        printf("%c is a consonant.", c);

    return 0;
}*/

/*#include <stdio.h>
//using switch case
int main() {
    char ch;

    printf("Enter any character: ");
    scanf("%c", &ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("'%c' is a Vowel.", ch);
    } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("'%c' is a Consonant.", ch);
    } else {
        printf("'%c' is not an alphabet.", ch);
    }

    return 0;
}*/

/*#include <stdio.h>
// using if else ladder
int main() {
    double n1, n2, n3;
    printf("Enter three different numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    if (n1 >= n2 && n1 >= n3)
        printf("%.2f is the largest number.", n1);
    else if (n2 >= n1 && n2 >= n3)
        printf("%.2f is the largest number.", n2);
    else
        printf("%.2f is the largest number.", n3);

    return 0;
}*/

/*#include <stdio.h>
//using nested if else
int main() {
    double n1, n2, n3;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    if (n1 >= n2) {
        if (n1 >= n3)
            printf("%.2lf is the largest number.", n1);
        else
            printf("%.2lf is the largest number.", n3);
    } else {
        if (n2 >= n3)
            printf("%.2lf is the largest number.", n2);
        else
            printf("%.2lf is the largest number.", n3);
    }

    return 0;
}*/

/*#include <stdio.h>
#include <ctype.h> // For isalpha() function

int main() {
    char S1[1000], S2[1000];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(S1, sizeof(S1), stdin);

    for (i = 0; S1[i] != '\0'; i++) {
        if (isalpha(S1[i]) || S1[i] == ' ') {
            S2[j] = S1[i];
            j++;
        }
    }
    S2[j] = '\0'; // Null-terminate the output string

    printf("Output string: %s", S2);
    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    int len = strlen(str);
    int middle = len / 2;

    if (len % 2 == 1) {
        // Odd length: Print middle three characters
        printf("Middle three characters: %c%c%c\n", str[middle - 1], str[middle], str[middle + 1]);
    } else {
        // Even length: Print middle two characters on a new line
        printf("Middle two characters:\n%c%c\n", str[middle - 1], str[middle]);
    }

    return 0;
}*/

/*#include <stdio.h>

int main() {
    int n, i;
    double arr[1000], sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of all elements stored in the array is: %.2lf\n", sum);
    return 0;
}*/

/*#include <stdio.h>
// using bitwise operator
int main() {
    int num;
    printf("Enter the number you want to test: ");
    scanf("%d", &num);

    // Condition to check whether the number is a power of two
    // Performing bitwise operation
    if ((num != 0) && ((num & (num - 1)) == 0))
        printf("\n%d is a power of 2\n", num);
    else
        printf("\n%d is not a power of 2\n", num);

    return 0;
}*/

/*#include <stdio.h>

// Function prototype for checking power of two
int checkPowerofTwo(int n);

int main() {
    int num;
    printf("Enter the number you want to test: ");
    scanf("%d", &num);

    if (checkPowerofTwo(num) == 1)
        printf("\n%d is a power of 2\n", num);
    else
        printf("\n%d is not a power of 2\n", num);

    return 0;
}

// Function body
int checkPowerofTwo(int x) {
    // Checks whether a number is zero or not
    if (x == 0)
        return 0;

    // True until x is not equal to 1
    while (x != 1) {
        // Checks whether a number is divisible by 2
        if (x % 2 != 0)
            return 0;
        x /= 2;
    }
    return 1;
}*/





