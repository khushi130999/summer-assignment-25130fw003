#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));  
    int targetNumber = rand() % 20 + 1; 
    int userGuess;  
    int attempts = 0;  
    printf("Guess the number between 1 and 20:\n");
    while (1) {
        printf("Input your guess: ");
        scanf("%d", &userGuess);  
        attempts++;  
        if (userGuess == targetNumber) {
            printf("Congratulations! You guessed the correct number in %d attempts.\n", attempts);
            break;  
        } else {
            printf("Incorrect guess. Try again!\n");
    }
    return 0;  
}
}