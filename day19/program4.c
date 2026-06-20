#include <stdio.h>
int main() {
   int i, j, n;
   int matrix[10][10];
   int mainSum = 0, offSum = 0;
   printf("Enter the order of the square matrix: ");
   scanf("%d", &n);
   printf("Enter the elements of the matrix:\n");
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", &matrix[i][j]);
       }
   }
   printf("\nThe matrix is:\n");
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           printf("%d ", matrix[i][j]);
           if (i == j) {
               mainSum += matrix[i][j]; 
           }
           if (i + j == n - 1) {
               offSum += matrix[i][j];
           }
       }
       printf("\n");
   }
   printf("Main diagonal sum = %d", mainSum);
   printf("Secondary diagonal sum = %d", offSum);
   return 0;
}