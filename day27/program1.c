#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[100];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct student s;
    printf("\n-- Student Records --\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d\nName: %s\nMarks: %.2f\n\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    struct student s;
    int roll, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\nRecord Found:\nRoll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record not found.\n");
    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct student s;
    int roll, found = 0;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll)
            fwrite(&s, sizeof(s), 1, temp);
        else
            found = 1;
    }
    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    if (found) printf("Student record deleted.\n");
    else printf("Record not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}
        