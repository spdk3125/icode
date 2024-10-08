#include <stdio.h>
#include<math.h>

double sqroot(double square) {
    double root = square; // Initial guess (can be any positive value)
    double epsilon = 1e-10; // Tolerance for convergence

    if (square <= 0) return 0; // Handle non-positive input

    // Iterative approximation using Newton-Raphson method
    while (1) {
        double newRoot = 0.5 * (root + square / root);
        if (fabs(newRoot - root) < epsilon) // Check for convergence
            break;
        root = newRoot;
    }

    return root;
}

int main() {
    double a, b, c, D, r1, r2, rp, ip;

    // Input coefficients a, b, and c
    printf("Enter coefficients (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate discriminant
    D = b * b - 4 * a * c;

    if (D >= 0) {
        // Real roots
        r1 = (-b + sqroot(D)) / (2 * a);
        r2 = (-b - sqroot(D)) / (2 * a);
        printf("Roots: %.4lf and %.4lf\n", r1, r2);
    } else {
        // Complex roots
        rp = -b / (2 * a);
        ip = sqroot(-D) / (2 * a);
        printf("Roots: %.4lf + j(%.4lf) and %.4lf - j(%.4lf)\n", rp, ip, rp, ip);
    }

    return 0;
}
