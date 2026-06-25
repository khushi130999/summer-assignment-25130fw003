#include <stdio.h>
#include <string.h>
#include <ctype.h>
void removeDuplicates(char *str) {
    int seen[256] = {0}; 
    int len = strlen(str);
    int index = 0;

    for (int i = 0; i < len; i++) {
        unsigned char ch = str[i];
        if (!seen[ch]) {
            seen[ch] = 1;
            str[index++] = ch;
        }
    }
    str[index] = '\0'; 
}

int main() {
    char str[256];
    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);
    return 0;
}