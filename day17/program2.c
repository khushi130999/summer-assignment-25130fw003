#include <stdio.h>

int removeDuplicates(int size, int arr[]);
void sort(int size, int arr[]);

int main() {
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {1, 2, 5, 6, 7};
    int size1 = 5;
    int size2 = 5;
    int uni[size1 + size2];
    int i, j = 0;
    
    printf("Array 1: ");
    for(i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("<br>");
    
    printf("Array 2: ");
    for(i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("<br>");
    
    /* Copy all elements from both arrays */
    for(i = 0; i < size1; i++) {
        uni[j] = arr1[i];
        j++;
    }
    for(i = 0; i < size2; i++) {
        uni[j] = arr2[i];
        j++;
    }
    
    sort(size1 + size2, uni);
    int finalSize = removeDuplicates(size1 + size2, uni);
    printf("Union of arrays: ");
    for(i = 0; i < finalSize; i++) {
        printf("%d ", uni[i]);
    }
    printf("<br>");
    return 0;
}

int removeDuplicates(int size, int arr[]) {
    int i, j, k;
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; ) {
            if(arr[i] == arr[j]) {
                for(k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
    return size;
}

void sort(int size, int arr[]) {
    int i, j, temp;
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}