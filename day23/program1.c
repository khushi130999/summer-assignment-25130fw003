
#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "programming"; 
    int len = strlen(str);
    char firstNonRepeating = '0'; 
    for (int i = 0; i < len; i++) {
        int count = 0; 
        for (int j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }
        if (count == 1) {
            firstNonRepeating = str[i]; 
            break; 
        }
    }
    if (firstNonRepeating != '0') {
        printf("The first non-repeating character is: %c\\n", firstNonRepeating);
    } else {
        printf("No non-repeating character found.\\n");
    }
    return 0;
}