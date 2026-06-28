 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"
typedef struct {
    int id;
    char title[100];
    char author[100];
    int available; 
} Book;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
int bookExists(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

int bookExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Book b;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void addBook() {
    Book b;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    if (bookExists(b.id)) {
        printf("Book with ID %d already exists!\n", b.id);
        fclose(fp);
        return;
    }

    printf("Enter Book Title: ");
    getchar(); 
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; 

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    b.available = 1; 
    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------\n");

    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-30s %-20s %-10s\n", b.id, b.title, b.author, b.available ? "Available" : "Issued");
    }
    fclose(fp);
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("Book Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   b.id, b.title, b.author, b.available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) printf("Book with ID %d not found.\n", id);
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.available) {
                b.available = 0;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book issued successfully!\n");
            } else {
                printf("Book is already issued.\n");
            }
            break;
        }
    }
    fclose(fp);

    if (!found) printf("Book with ID %d not found.\n", id);
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (!b.available) {
                b.available = 1;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued.\n");
            }
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Book with ID %d not found.\n", id);
}
