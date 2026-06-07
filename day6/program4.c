#include <stdio.h>
double power(double base, int exponent) {
    double result = 1.0;
    int exp = exponent;
    if (exp < 0) {
        exp = -exp;
    }
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result *= base;
        }
        base *= base; 
        exp /= 2;     
    }
    if (exponent < 0) {
        return 1.0 / result;
    }
    return result;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input for base.\n");
        return 1;
    }

    printf("Enter exponent (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for exponent.\n");
        return 1;
    }

    double result = power(x, n);
    printf("%.6lf ^ %d = %.6lf\n", x, n, result);

    return 0;
}
