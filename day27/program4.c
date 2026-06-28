#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define NAME_LEN 50

char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 50) return 'D';
    else return 'F';
}

int isPass(int marks[], int subjectCount) {
    for (int i = 0; i < subjectCount; i++) {
        if (marks[i] < 33) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char studentName[NAME_LEN];
    int rollNumber;
    int subjectCount;
    char subjectNames[MAX_SUBJECTS][NAME_LEN];
    int marks[MAX_SUBJECTS];
    int totalMarks = 0;
    float percentage;
    char grade;
    int passStatus;

    printf("===== Student Marksheet Generation System =====\n");
    printf("Enter Student Name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0'; 

    printf("Enter Roll Number: ");
    if (scanf("%d", &rollNumber) != 1) {
        printf("Invalid roll number.\n");
        return 1;
    }

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    if (scanf("%d", &subjectCount) != 1 || subjectCount <= 0 || subjectCount > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    for (int i = 0; i < subjectCount; i++) {
        printf("\nEnter name of subject %d: ", i + 1);
        scanf(" %[^\n]", subjectNames[i]); 

        printf("Enter marks for %s (0-100): ", subjectNames[i]);
        if (scanf("%d", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks entered.\n");
            return 1;
        }
        totalMarks += marks[i];
    }

    percentage = (float)totalMarks / subjectCount;
    grade = calculateGrade(percentage);
    passStatus = isPass(marks, subjectCount);

    printf("\n\n========== STUDENT MARKSHEET ==========\n");
    printf("Name       : %s\n", studentName);
    printf("Roll No.   : %d\n", rollNumber);
    printf("---------------------------------------\n");
    printf("%-20s %-10s\n", "Subject", "Marks");
    printf("---------------------------------------\n");
    for (int i = 0; i < subjectCount; i++) {
        printf("%-20s %-10d\n", subjectNames[i], marks[i]);
    }
    printf("---------------------------------------\n");
    printf("Total Marks: %d / %d\n", totalMarks, subjectCount * 100);
    printf("Percentage : %.2f%%\n", percentage);
    printf("Grade      : %c\n", grade);
    printf("Result     : %s\n", passStatus ? "PASS" : "FAIL");
    printf("=======================================\n");

    return 0;
}
