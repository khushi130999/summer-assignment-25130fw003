#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isArmstrong(int num) {
    if (num < 0) return 0;
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int lower, upper;

    printf("Enter lower and upper range: ");
    if (scanf("%d %d", &lower, &upper) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    if (lower > upper) {
        int temp = lower;
        lower = upper;
        upper = temp;
    }

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);
    int found = 0;
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");

    return 0;
}
