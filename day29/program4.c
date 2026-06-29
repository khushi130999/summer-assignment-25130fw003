#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.dat"
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem();
void viewItems();
void searchItem();
void updateItem();
void deleteItem();
int getNextID();

int main() {
    int choice;

    while (1) {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Item\n");
        printf("2. View All Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

int getNextID() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 1; 

    Item temp;
    int maxID = 0;
    while (fread(&temp, sizeof(Item), 1, fp)) {
        if (temp.id > maxID) maxID = temp.id;
    }
    fclose(fp);
    return maxID + 1;
}

void addItem() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Item newItem;
    newItem.id = getNextID();
    printf("Enter item name: ");
    getchar(); 
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; 

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    fwrite(&newItem, sizeof(Item), 1, fp);
    fclose(fp);

    printf("Item added successfully with ID %d.\n", newItem.id);
}

void viewItems() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    Item temp;
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");

    while (fread(&temp, sizeof(Item), 1, fp)) {
        printf("%-5d %-20s %-10d %-10.2f\n", temp.id, temp.name, temp.quantity, temp.price);
    }
    fclose(fp);
}

void searchItem() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter item ID to search: ");
    scanf("%d", &id);

    Item temp;
    while (fread(&temp, sizeof(Item), 1, fp)) {
        if (temp.id == id) {
            printf("Item found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n",
                   temp.id, temp.name, temp.quantity, temp.price);
            found = 1;
            break;
        }
    }
    if (!found) printf("Item with ID %d not found.\n", id);
    fclose(fp);
}

void updateItem() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    Item temp;
    while (fread(&temp, sizeof(Item), 1, fp)) {
        if (temp.id == id) {
            printf("Enter new name: ");
            getchar();
            fgets(temp.name, NAME_LEN, stdin);
            temp.name[strcspn(temp.name, "\n")] = '\0';

            printf("Enter new quantity: ");
            scanf("%d", &temp.quantity);

            printf("Enter new price: ");
            scanf("%f", &temp.price);

            fseek(fp, -sizeof(Item), SEEK_CUR);
            fwrite(&temp, sizeof(Item), 1, fp);
            printf("Item updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Item with ID %d not found.\n", id);
    fclose(fp);
}

void deleteItem() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Error creating temp file.\n");
        fclose(fp);
        return;
    }

    int id, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    Item temp;
    while (fread(&temp, sizeof(Item), 1, fp)) {
        if (temp.id == id) {
            found = 1;
            continue; 
        }
        fwrite(&temp, sizeof(Item), 1, tempFile);
    }
    fclose(fp);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) printf("Item deleted successfully.\n");
    else printf("Item with ID %d not found.\n", id);
}
