#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        sum += arr[i];
    }

    average = sum / n;

    printf("Sum = %.2f", sum);
    printf("Average = %.2f", average);

    return 0;
}