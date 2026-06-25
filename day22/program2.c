#include <stdio.h>
int countWords(char sentence[]) {
    int count = 1;  
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    return count;
}
int main() {
    char sentence[] = "Programming is fun and challenging";
    printf("Number of words: %d\n", countWords(sentence));
    return 0;
}