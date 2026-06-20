#include <stdio.h>
int main() {
   int rows, cols;
   int i, j;
   printf("Enter number of rows and columns: ");
   scanf("%d %d", &rows, &cols);
   int a[rows][cols], b[rows][cols], result[rows][cols];
   printf("Enter elements of first matrix:\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           scanf("%d", &a[i][j]);
       }
   }
   printf("Enter elements of second matrix:\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           scanf("%d", &b[i][j]);
       }
   }
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           result[i][j] = a[i][j] - b[i][j];
       }
    }
    
        printf("Resultant Matrix after subtraction:\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           printf("%d", result[i][j]);
       }
       printf("\n");
   }
   return 0;
}