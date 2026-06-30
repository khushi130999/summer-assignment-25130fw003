#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 20

char names[MAX_CONTACTS][NAME_LEN];
char phones[MAX_CONTACTS][PHONE_LEN];
int totalContacts = 0;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
int findContactIndex(const char* name);

int main() {
    int choice;

    while (1) {
        printf("\n========== CONTACT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Contact list full! Cannot add more.\n");
        return;
    }

    char name[NAME_LEN];
    char phone[PHONE_LEN];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone: ");
    scanf("%s", phone);

    strcpy(names[totalContacts], name);
    strcpy(phones[totalContacts], phone);

    totalContacts++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (totalContacts == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, names[i], phones[i]);
    }
}

void searchContact() {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    int index = findContactIndex(name);
    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("Contact found!\nName: %s\nPhone: %s\n", names[index], phones[index]);
    }
}

void deleteContact() {
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", name);

    int index = findContactIndex(name);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < totalContacts - 1; i++) {
        strcpy(names[i], names[i + 1]);
        strcpy(phones[i], phones[i + 1]);
    }
    totalContacts--;
    printf("Contact deleted successfully.\n");
}

int findContactIndex(const char* name) {
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}