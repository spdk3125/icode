#include <stdio.h>
void fibo(){
    int a = 0, b = 1, n = 8, f;
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            f = a + b;
            a = b;
            b = f;
    }
}

void prime() {
    int n=0, i, flag;
    if (n == 0 || n == 1) flag = 1;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) flag = 1; break;
    }
    if (flag == 0) printf("%d prime", n);
    else printf("%d not prime", n);

    
}

double my_pow(double x, int y) {
    if (y < 0)
        return 1.0 / my_pow(x, -y);
    
    double result = 1.0;
    while (y > 0) {
        if (y % 2 == 1)
            result *= x;
        x *= x;
        y /= 2;
    }
    return result;
}

int arm() {
    int num, originalNum, remainder, result = 0;

    printf("Enter a three-digit integer: ");
    scanf("%d", &num);

    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder * remainder * remainder;
        originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

int armstrong() {

    int num, originalNum, remainder, n = 0;
    float result = 0.0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Calculate the number of digits in num
    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }

    originalNum = num;

    // Compute the sum of the power of individual digits
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += my_pow(remainder, n);

        originalNum /= 10;
    }

    if ((int)result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;


   
}
int revers(int n) {
    int rev , remainder;
    while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    printf("reversed %d \n",rev); 
    return rev;
}

void palindrome(int n){
    int original, rev;
    original = n;
    rev = revers(n);

    if (original == rev)
        printf("%d is a palindrome.\n", original);
    else
        printf("%d is not a palindrome.\n", original);
}

int main() {
    // fibo();
    // prime();
    // palindrome(123);


 
    return 0;
    }