#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int isEligibleToVote(int age)
 {
    return age >= 18;
}
int main() {
    int age;
    char ch;
    printf("=== Voting Eligibility Checker ===\n");
    while (1) {
        printf("Enter your age: ");
        if (scanf("%d", &age) != 1) {
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }
        if (age < 0 || age > 150) {
            printf("Invalid age. Please enter an age between 0 and 150.\n");
            continue;
        }
        break;
    }
    if (isEligibleToVote(age)) {
        printf("✅ You are eligible to vote.\n");
    } else {
        printf("❌ You are NOT eligible to vote. You must be at least 18 years old.\n");
    }
    return 0;
}


