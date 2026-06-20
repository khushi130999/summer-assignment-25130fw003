#include <stdio.h>
int main() {
    
    int rows, columns;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    int A[rows][columns], B[rows][columns], C[rows][columns];
    printf("Enter elements of Matrix A:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &A[i][j]);  
        }
    }
    printf("Enter elements of Matrix B:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &B[i][j]);  
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Resultant Matrix (A + B):");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", C[i][j]);  
        }
        printf("\n");  
    }

    return 0;
}