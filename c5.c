/*#include <stdio.h>

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Print the pattern
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}
*/
/*#include <stdio.h>

// Function to find the HCF using recursion
long int hcf(long int a, long int b) {
    if (b == 0) {
        return a;
    } else {
        return hcf(b, a % b);
    }
}

int main() {
    long int num1, num2;
    printf("Enter any two numbers to find HCF: ");
    scanf("%ld %ld", &num1, &num2);

    // Calculate the HCF
    long int gcd = hcf(num1, num2);

    printf("The Highest Common Factor is: %ld\n", gcd);
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many numbers do you want? ");
    scanf("%d", &n);

    // Allocate memory for n elements
    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Error! Memory allocation failed.\n");
        exit(1);
    }

    // Input n numbers and store them in the allocated memory
    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", data + i);
    }

    // Find the largest number
    double largest = *data;
    for (int i = 1; i < n; ++i) {
        if (*(data + i) > largest) {
            largest = *(data + i);
        }
    }

    printf("The Largest Number is %.2lf\n", largest);

    // Free allocated memory
    free(data);
    return 0;
}
*/
/*#include <stdio.h>
#include <string.h>

// Define a structure for employee details
typedef struct {
    char name[50];
    int id;
    int age;
    char native[50];
} Employee;

int main() {
    Employee emp;

    // Read employee details
    printf("Enter empname, id, age, and native: ");
    scanf("%s %d %d %s", emp.name, &emp.id, &emp.age, emp.native);

    // Display employee details
    printf("Employee detail:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("id: %d\n", emp.id);
    printf("native: %s\n", emp.native);

    return 0;
}*/
/*#include <stdio.h>

int main() {
    int a, n, d, tn, i;
    int sum = 0;

    printf("Please Enter First Number of an A.P Series: ");
    scanf("%d", &a);
    printf("Please Enter the Total Numbers in this A.P Series: ");
    scanf("%d", &n);
    printf("Please Enter the Common Difference: ");
    scanf("%d", &d);

    sum = (n * (2 * a + (n - 1) * d)) / 2;
    tn = a + (n - 1) * d;

    printf("\nThe Sum of Series A.P. : ");
    for (i = a; i <= tn; i = i + d) {
        if (i != tn)
            printf("%d + ", i);
        else
            printf("%d = %d", i, sum);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

int main() {
    int a, n, d, tn, i;
    int sum = 0;

    printf("Please Enter First Number of an A.P Series: ");
    scanf("%d", &a);
    printf("Please Enter the Total Numbers in this A.P Series: ");
    scanf("%d", &n);
    printf("Please Enter the Common Difference: ");
    scanf("%d", &d);

    sum = (n * (2 * a + (n - 1) * d)) / 2;
    tn = a + (n - 1) * d;
    i = a;

    printf("\nThe Sum of Series A.P. : ");
    while (i <= tn) {
        if (i != tn)
            printf("%d + ", i);
        else
            printf("%d = %d", i, sum);
        i = i + d;
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

int main() {
    int a, n, d, value, i;
    int sum = 0;

    printf("Please Enter First Number of an A.P Series: ");
    scanf("%d", &a);
    printf("Please Enter the Total Numbers in this A.P Series: ");
    scanf("%d", &n);
    printf("Please Enter the Common Difference: ");
    scanf("%d", &d);

    for (i = 0; i < n; i++) {
        value = a + i * d;
        sum += value;
    }

    printf("\nThe Sum of Series A.P. : %d\n", sum);

    return 0;
}
*/
/*#include <stdio.h>

int main() {
    int a[10][10], transpose[10][10], r, c;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    // Input matrix elements
    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Compute the transpose
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            transpose[j][i] = a[i][j];
        }
    }

    // Print the original matrix
    printf("\nEntered matrix:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", a[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
        }
    }

    // Print the transpose
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            printf("%d ", transpose[i][j]);
            if (j == r - 1) {
                printf("\n");
            }
        }
    }

    return 0;
}*/

