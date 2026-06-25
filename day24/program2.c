#include <stdio.h>
#include <string.h>
void compressString(char *str) {
    int len = strlen(str);
    int count = 1;
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%d", count);
        count = 1; 
    }
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Compressed string: ");
    compressString(str);
    return 0;
}
