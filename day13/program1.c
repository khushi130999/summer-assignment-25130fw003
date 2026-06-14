#include <stdio.h>
 
int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}