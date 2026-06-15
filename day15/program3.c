#include <stdio.h>

void rightRotate(int arr[], int size, int rotations) {
    int temp[rotations];

    
    for (int i = 0; i < rotations; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size - rotations; i++) {
        arr[i] = arr[i + rotations];
    }

    for (int i = 0; i < rotations; i++) {
        arr[size - rotations + i] = temp[i];
    }
}

int main() {
    int size, rotations;


    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements -\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number of positions to rotate the array to the right: ");
    scanf("%d", &rotations);

    
    rightRotate(arr, size, rotations);

    
    printf("Array after right rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}