/*#include <stdio.h>

// Define the structure
struct student {
    char name[50];
    int rollno;
    int marks;
};

int main() {
    struct student stu1, stu2;

    // Get details for stu1
    printf("Enter name, rollno and marks for stu1 : ");
    scanf("%s %d %d", stu1.name, &stu1.rollno, &stu1.marks);

    // Get details for stu2
    printf("Enter name, rollno and marks for stu2 : ");
    scanf("%s %d %d", stu2.name, &stu2.rollno, &stu2.marks);

    // Display details
    printf("stu1 : %s %d %d\n", stu1.name, stu1.rollno, stu1.marks);
    printf("stu2 : %s %d %d\n", stu2.name, stu2.rollno, stu2.marks);

    return 0;
}*/

/*#include <stdio.h>

// Function to calculate square
double square(double num) {
    return num * num;
}

int main() {
    double num;

    // Get the number from the user
    printf("Input any number for square : ");
    scanf("%lf", &num);

    // Calculate and display the square
    printf("The square of %.2lf is : %.2lf\n", num, square(num));

    return 0;
}*/

/*#include <stdio.h>

int main() {
    int num1, num2, sum;
    int *ptr1, *ptr2;

    // Get the numbers from the user
    printf("Input the first number : ");
    scanf("%d", &num1);
    printf("Input the second number : ");
    scanf("%d", &num2);

    // Set the pointers to the numbers
    ptr1 = &num1;
    ptr2 = &num2;

    // Calculate and display the sum
    sum = *ptr1 + *ptr2;
    printf("The sum of the entered numbers is : %d\n", sum);

    return 0;
}*/

/*#include <stdio.h>

// Recursive function to print numbers in reverse order
void print_reverse(int n) {
    if(n > 0) {
        printf("%d ", n);
        print_reverse(n - 1);
    }
}

int main() {
    int n;

    // Get the number from the user
    printf("print n value : ");
    scanf("%d", &n);

    // Print the numbers in reverse order
    print_reverse(n);
    printf("\n");

    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

void print_reverse(char *str) {
    int length, i;
    
    // Compute string length
    length = strlen(str);
    
    // Print characters in reverse order
    for(i = length - 1; i >= 0; i--) {
        printf("%c ", str[i]);
    }
}

int main() {
    char str[100];
    
    // Get the string from the user
    printf("Input the string : ");
    scanf("%s", str);
    
    // Print the characters in reverse order
    printf("The characters of the string in reverse are :\n");
    print_reverse(str);
    printf("\n");

    return 0;
}*/

#include <stdio.h>

int main() {
    int i, j, n, count = 1;

    // Get the number from the user
    printf("Enter the value of n : ");
    scanf("%d", &n);

    // Print the pyramid
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}






