#include <stdio.h>

void sortArray(int size, int arr[]) {
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

int removeDuplicates(int size, int arr[]) {
    int i, j, k;
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size;) {
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

int main() {
    int arr1[] = {4, 5, 6, 7, 8};
    int arr2[] = {4, 1, 6, 9};
    int size1 = 5, size2 = 4;
    int intersectionSize = (size1 < size2) ? size1 : size2;
    int intersection[intersectionSize];
    int k = 0, i, j;
    
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
    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if(arr1[i] == arr2[j]) {
                intersection[k] = arr1[i];
                k++;
                break; 
            }
        }
    }
    
    sortArray(k, intersection);
    int finalSize = removeDuplicates(k, intersection);
    printf("Intersection: ");
    if(finalSize > 0) {
        for(i = 0; i < finalSize; i++) {
            printf("%d ", intersection[i]);
        }
    } else {
        printf("No common elements");
    }
    printf("<br>");
    return 0;
}