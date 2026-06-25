#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    char longest[50] = "";
    char current[50] = "";
    int i = 0, j = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

     str[strcspn(str, "\n")] = '\0';

    while (1) {
        if (str[i] != ' ' && str[i] != '\0') {
            current[j++] = str[i];
        } else {
            current[j] = '\0';
            if (strlen(current) > strlen(longest)) {
                strcpy(longest, current);
            }
            j = 0; 
        }
        if (str[i] == '\0') break;
        i++;
    }
    printf("Longest word: %s\n", longest);
    printf("Length: %zu\n", strlen(longest));
    return 0;
}