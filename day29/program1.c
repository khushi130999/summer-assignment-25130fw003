#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void modulus();
void power();

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\n===== MENU DRIVEN CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Perform operation based on choice
        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: power(); break;
            case 7: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
    return 0;
}

// Addition
void add() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a + b);
}

// Subtraction
void subtract() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a - b);
}

// Multiplication
void multiply() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a * b);
}

// Division
void divide() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
    printf("Result: %.2lf\n", a / b);
}

// Modulus
void modulus() {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
        return;
    }
    printf("Result: %d\n", a % b);
}

// Power
void power() {
    double base, exp;
    printf("Enter base and exponent: ");
    if (scanf("%lf %lf", &base, &exp) != 2) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", pow(base, exp));
}

