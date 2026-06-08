#include <stdio.h>
#include <stdlib.h>
int main() {
    int rows;
    printf("Enter the number of rows for the number triangle: ");
    if (scanf("%d", &rows) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }


    if (rows <= 0) {
        printf("Number of rows must be a positive integer.\n");
        return 1;
    }

    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        for (int num = 1; num <= i; num++) {
            printf("%d ", num);
        }

        printf("\n");
    }

    return 0;
}
