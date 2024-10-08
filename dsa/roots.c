#include <stdio.h>

double sqroot(double square) {
        double root = square / 3;
        if (square <= 0) return 0;
        for (int i = 0; i < 32; i++)
            root = (root + square / root) / 2;
        return root;
        
    }

int main() {
    double a, b, c, D, r1, r2, rp, ip;

    // Input coefficients a, b, and c
    printf("Enter coefficients (a, b, c): \n");
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
