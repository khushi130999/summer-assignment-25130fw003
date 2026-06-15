#include <stdio.h>
void PickOutZeros(int *arr1, int arr_size) {
    int tmp, lft = 0, rgt = arr_size - 1;

    while (rgt > lft) {
        
        while (arr1[lft] != 0)
            lft++;

        
        while (arr1[rgt] == 0)
            rgt--;

        
        if (lft < rgt) {
            tmp = arr1[lft];
            arr1[lft] = arr1[rgt];
            arr1[rgt] = tmp;
        }
    }
}

int main() {
    int arr1[] = {2, 5, 7, 0, 4, 0, 7, -5, 8, 0};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int i;

    printf("The given array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    } 
    printf("\n");
  
    PickOutZeros(arr1, n);

    printf("The new array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}
