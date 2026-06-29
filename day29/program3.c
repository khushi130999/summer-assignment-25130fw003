
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
    printf("Uppercase: %s\n", str);
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
    printf("Lowercase: %s\n", str);
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed: %s\n", str);
}

void countCharacter(char str[]) {
    char ch;
    printf("Enter character to count: ");
    scanf(" %c", &ch);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    printf("Character '%c' occurs %d times.\n", ch, count);
}

void capitalizeWords(char str[]) {
    int newWord = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace((unsigned char)str[i])) {
            newWord = 1;
        } else if (newWord) {
            str[i] = toupper((unsigned char)str[i]);
            newWord = 0;
        } else {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
    printf("Capitalized: %s\n", str);
}

void stringLength(char str[]) {
    printf("Length of string: %zu\n", strlen(str));
}

void checkPalindrome(char str[]) {
    int len = strlen(str);
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (tolower((unsigned char)str[i]) != tolower((unsigned char)str[len - i - 1])) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");
}

int main() {
    char str[200];
    int choice;

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0'; 
    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Convert to Uppercase\n");
        printf("2. Convert to Lowercase\n");
        printf("3. Reverse String\n");
        printf("4. Count Character Occurrences\n");
        printf("5. Capitalize Each Word\n");
        printf("6. Find String Length\n");
        printf("7. Check Palindrome\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        char temp[200];
        strcpy(temp, str); 
        switch (choice) {
            case 1: toUpperCase(temp); break;
            case 2: toLowerCase(temp); break;
            case 3: reverseString(temp); break;
            case 4: countCharacter(temp); break;
            case 5: capitalizeWords(temp); break;
            case 6: stringLength(temp); break;
            case 7: checkPalindrome(temp); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
