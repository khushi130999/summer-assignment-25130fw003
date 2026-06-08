#include <stdio.h> 
int main() {
    int rows;

    printf("Enter number of rows (1-26): ");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 26) {
        printf("Invalid input. Please enter an integer between 1 and 26.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        char ch = 'A';
        for (int j = 0; j <= i; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }

    return 0;
}
