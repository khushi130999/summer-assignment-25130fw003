#include <stdio.h>


#define M 3   

int main() {

    int a[M][M], b[M][M];
    int result[M][M] = {0};
    int i, j, k;                          
    printf("Enter elements of first matrix:");
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);            
        }
    }
    printf("Enter elements of second matrix:");
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {          
            result[i][j] = 0;                 
            for (k = 0; k < M; k++) {
                result[i][j] += a[i][k] * b[k][j];  
            }
        }
    }
    printf("Resultant matrix:");
    for (i = 0; i < M; i++) {
        for (j = 0; j < M ; j++)
         {
            printf("%d ", result[i][j]);      
        }
        printf("\n");                         
    }
    return 0;   
}