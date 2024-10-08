#include <stdio.h>

double sqroot(double square) {
    double root = square / 3;
    int i;
    if (square <= 0) return 0;
    for (i = 0; i < 32; i++)
        root = (root + square / root) / 2;
    return root;
}

int main() {
    double input;
    printf("Enter a positive number: ");
    scanf("%lf", &input);

    double result = sqroot(input);
    printf("Approximate square root of %.4lf: %.4lf\n", input, result);

    return 0;
}
