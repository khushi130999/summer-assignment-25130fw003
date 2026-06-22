#include <stdio.h>
int main() {
   int n, i, j, isSymmetric = 1;
   int matrix[20][20];
   printf("Enter the order of the square matrix: ");
   scanf("%d", &n);
   printf("Enter elements of the matrix:");
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", &matrix[i][j]);
       }
   }
   for (i = 0; i < n && isSymmetric; i++) {
       for (j = 0; j < n; j++) {
           if (matrix[i][j] != matrix[j][i]) {
               isSymmetric = 0;
               break;
           }
       }
   }
   if (isSymmetric)
       printf("The given matrix is Symmetric");
   else
       printf("The given matrix is Not Symmetric");
   return 0;
}