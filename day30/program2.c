#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int isbn;
    int copies;
} Book;

void addBook(Book library[], int *count);
void displayBooks(Book library[], int count);
void searchBook(Book library[], int count);

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by ISBN\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter numbers only.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", library[*count].title);

    printf("Enter author: ");
    scanf("%s", library[*count].author);

    printf("Enter ISBN (integer): ");
    if (scanf("%d", &library[*count].isbn) != 1) {
        printf("Invalid ISBN! Book not added.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    printf("Enter number of copies: ");
    if (scanf("%d", &library[*count].copies) != 1 || library[*count].copies < 0) {
        printf("Invalid copies value! Book not added.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Title : %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("ISBN  : %d\n", library[i].isbn);
        printf("Copies: %d\n\n", library[i].copies);
    }
}

void searchBook(Book library[], int count) {
    if (count == 0) {
        printf("No books to search.\n");
        return;
    }

    int isbn;
    printf("Enter ISBN to search: ");
    if (scanf("%d", &isbn) != 1) {
        printf("Invalid ISBN input.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (library[i].isbn == isbn) {
            printf("Book Found:\n");
            printf("Title : %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Copies: %d\n", library[i].copies);
            return;
        }
    }

    printf("Book not found.\n");
}

