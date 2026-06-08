#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
     if (n != 1 || n <= 0)
      {
        printf("Invalid input. Please enter a positive integer");
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n"); 
    }
    return 0;
}