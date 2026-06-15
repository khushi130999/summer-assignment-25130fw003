#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements -\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
   int freq[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    printf("Duplicate elements in the array are: ");
    for (int i = 0; i <= maxVal; i++) {
        if (freq[i] > 1) {
            printf("%d ", i);
        }
    }

    return 0;
}