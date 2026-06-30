#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "employees.db"

typedef struct {
    int id;
    char name[60];
    int age;
    float salary;
} Employee;

void addEmployee();
void listEmployees();
void findEmployee();
void editEmployee();
void removeEmployee();
void getString(char *buffer, int size);

int main() {
    int choice;

    while (1) {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. List All Employees\n");
        printf("3. Find Employee by ID\n");
        printf("4. Edit Employee\n");
        printf("5. Remove Employee\n");
        printf("0. Exit\n");
        printf("Select an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: findEmployee(); break;
            case 4: editEmployee(); break;
            case 5: removeEmployee(); break;
            case 0: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

void getString(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}

void addEmployee() {
    FILE *file = fopen(DATA_FILE, "ab");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        fclose(file);
        return;
    }
    getchar(); 

    printf("Enter Name: ");
    getString(emp.name, sizeof(emp.name));

    printf("Enter Age: ");
    if (scanf("%d", &emp.age) != 1) {
        fclose(file);
        return;
    }

    printf("Enter Salary: ");
    if (scanf("%f", &emp.salary) != 1) {
        fclose(file);
        return;
    }

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    printf("Employee added successfully.\n");
}

void listEmployees() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No employee records available.\n");
        return;
    }

    Employee emp;
    printf("\n--- Employee List ---\n");
    printf("%-5s  %-20s  %-5s  %-10s\n", "ID", "Name", "Age", "Salary");

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("%-5d  %-20s  %-5d  %.2f\n",
               emp.id, emp.name, emp.age, emp.salary);
    }

    fclose(file);
}

void findEmployee() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No data available.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        fclose(file);
        return;
    }

    Employee emp;
    int found = 0;

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nSalary: %.2f\n",
                   emp.id, emp.name, emp.age, emp.salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");

    fclose(file);
}

void editEmployee() {
    FILE *file = fopen(DATA_FILE, "rb+");
    if (!file) {
        printf("No data available.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to edit: ");
    if (scanf("%d", &id) != 1) {
        fclose(file);
        return;
    }
    getchar();

    Employee emp;
    int found = 0;

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == id) {
            found = 1;

            printf("Enter new name: ");
            getString(emp.name, sizeof(emp.name));

            printf("Enter new age: ");
            scanf("%d", &emp.age);

            printf("Enter new salary: ");
            scanf("%f", &emp.salary);

            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);

            printf("Record updated.\n");
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");

    fclose(file);
}

void removeEmployee() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No data available.\n");
        return;
    }

    FILE *temp = fopen("temp.db", "wb");
    if (!temp) {
        fclose(file);
        printf("Error creating temp file.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to delete: ");
    if (scanf("%d", &id) != 1) {
        fclose(file);
        fclose(temp);
        return;
    }

    Employee emp;
    int removed = 0;

    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        if (emp.id == id) {
            removed = 1;
            continue;
        }
        fwrite(&emp, sizeof(Employee), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove(DATA_FILE);
    rename("temp.db", DATA_FILE);

    if (removed)
        printf("Employee removed.\n");
    else
        printf("Employee not found.\n");
}
