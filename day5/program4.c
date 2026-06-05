#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long largestPrimeFactor(long long n) {
    if (n <= 1) return -1; 

    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    long long num;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Invalid input. Please enter a positive integer.");
        return 1;
    }

    long long result = largestPrimeFactor(num);

    if (result == -1) {
        printf("No prime factors found.");
    } else {
        printf("Largest prime factor of %lld is: %lld", num, result);
    }

    return 0;
}