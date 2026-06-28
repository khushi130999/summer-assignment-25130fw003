

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[100];
    float balance;
};

// Check if account exists
int accountExists(int accNo) {
    FILE *fp = fopen("bank.dat", "rb");
    struct account acc;
    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == accNo) {
            fclose(fp);
            return 1; 
        }
    }
    fclose(fp);
    return 0;
}

// Create new account
void createAccount() {
    FILE *fp = fopen("bank.dat", "ab");
    struct account acc;

    printf("Enter account number: ");
    scanf("%d", &acc.acc_no);

    if (accountExists(acc.acc_no)) {
        printf("Account number already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

// Deposit money
void depositMoney() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account acc;
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("Deposit successful!\n");
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Withdraw money
void withdrawMoney() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account acc;
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= acc.balance) {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance.\n");
            }
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Search account
void searchAccount() {
    FILE *fp = fopen("bank.dat", "rb");
    struct account acc;
    int accNo;
    printf("Enter account number to search: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no == accNo) {
            printf("\nAccount Found:\n");
            printf("Account No: %d\nName: %s\nBalance: %.2f\n", acc.acc_no, acc.name, acc.balance);
            fclose(fp);
            return;
        }
    }
    printf("Account not found.\n");
    fclose(fp);
}

// Delete account
void deleteAccount() {
    FILE *fp = fopen("bank.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct account acc;
    int accNo, found = 0;

    printf("Enter account number to delete: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.acc_no != accNo) {
            fwrite(&acc, sizeof(acc), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if (found)
        printf("Account deleted successfully!\n");
    else
        printf("Account not found.\n");
}

void displayAccounts() {
    FILE *fp = fopen("bank.dat", "rb");
    struct account acc;
    printf("\n--  Account Details --\n");
    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("Account No: %d\nName: %s\nBalance: %.2f\n\n", acc.acc_no, acc.name, acc.balance);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\nBank Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display All Accounts\n");
        printf("5. Search Account\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccounts(); break;
            case 5: searchAccount(); break;
            case 6: deleteAccount(); break;
            case 7: printf("Thank you for using our banking system!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}


        