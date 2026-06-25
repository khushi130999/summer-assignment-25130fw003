#include <stdio.h>
#include <stdlib.h>
int compare(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}
void mergeArrays(int arr1[], int arr2[], int n, int m) {
    int* merged = (int*)malloc((n + m) * sizeof(int));
    for (int i = 0; i < n; ++i) {
        merged[i] = arr1[i];
    }
    for (int j = 0; j < m; ++j) {
        merged[n + j] = arr2[j];
    }
    qsort(merged, n + m, sizeof(int), compare);
    for (int i = 0; i < n; ++i) {
        arr1[i] = merged[i];
    }
    for (int j = 0; j < m; ++j) {
        arr2[j] = merged[n + j];
    }
    free(merged);
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    mergeArrays(arr1, arr2, n, m);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < m; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}