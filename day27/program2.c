#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"
typedef struct {
    int id;
    char name[50];
    char department[30];
    char designation[30];
    float salary;
    char phone[15];
} Employee;

void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
int employeeExists(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

int employeeExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void addEmployee() {
    Employee emp;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    if (employeeExists(emp.id)) {
        printf("Employee with ID %d already exists!\n", emp.id);
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Phone: ");
    getchar();
    fgets(emp.phone, sizeof(emp.phone), stdin);
    emp.phone[strcspn(emp.phone, "\n")] = '\0';

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No employee records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-5s %-20s %-15s %-15s %-10s %-15s\n", "ID", "Name", "Department", "Designation", "Salary", "Phone");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("%-5d %-20s %-15s %-15s %-10.2f %-15s\n",
               emp.id, emp.name, emp.department, emp.designation, emp.salary, emp.phone);
    }
    fclose(fp);
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No employee records found.\n");
        return;
    }

    Employee emp;
    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\nPhone: %s\n",
                   emp.id, emp.name, emp.department, emp.designation, emp.salary, emp.phone);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void updateEmployee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No employee records found.\n");
        return;
    }

    Employee emp;
    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new Name: ");
            getchar();
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("Enter new Department: ");
            fgets(emp.department, sizeof(emp.department), stdin);
            emp.department[strcspn(emp.department, "\n")] = '\0';

            printf("Enter new Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = '\0';

            printf("Enter new Salary: ");
            scanf("%f", &emp.salary);

            printf("Enter new Phone: ");
            getchar();
            fgets(emp.phone, sizeof(emp.phone), stdin);
            emp.phone[strcspn(emp.phone, "\n")] = '\0';

            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Employee updated successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No employee records found.\n");
        return;
    }
}

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }



