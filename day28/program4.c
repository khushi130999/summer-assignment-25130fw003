#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "contacts.dat"
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50

// Structure to store contact details
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

// Function prototypes
void addContact();
void listContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Add a new contact
void addContact() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Contact c;
    clearInputBuffer();
    printf("Enter Name: ");
    fgets(c.name, NAME_LEN, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(c.phone, PHONE_LEN, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(c.email, EMAIL_LEN, stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);
    printf("Contact added successfully!\n");
}

// List all contacts
void listContacts() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    Contact c;
    int count = 0;
    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(Contact), 1, fp)) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n-------------------\n",
               c.name, c.phone, c.email);
        count++;
    }
    if (count == 0) {
        printf("No contacts available.\n");
    }
    fclose(fp);
}

// Search contact by name
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[NAME_LEN];
    clearInputBuffer();
    printf("Enter name to search: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("Contact Found:\nName: %s\nPhone: %s\nEmail: %s\n",
                   c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(fp);
}

// Delete contact by name
void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temp file");
        fclose(fp);
        return;
    }

    char deleteName[NAME_LEN];
    clearInputBuffer();
    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    Contact c;
    int deleted = 0;
    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (strcasecmp(c.name, deleteName) != 0) {
            fwrite(&c, sizeof(Contact), 1, temp);
        } else {
            deleted = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (deleted) {
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}
