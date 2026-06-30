#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

struct Student {
    int roll;
    char name[NAME_LEN];
    float marks;
};

void addStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum limit reached!\n");
        return;
    }

    printf("\nEnter roll number: ");
    scanf("%d", &students[*count].roll);

    printf("Enter name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

void viewStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               students[i].roll,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students available to search.\n");
        return;
    }

    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n",
                   students[i].roll,
                   students[i].name,
                   students[i].marks);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}
