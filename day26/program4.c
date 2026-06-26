#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_QUESTIONS 5
typedef struct {
   char question[256];
   char options[4][100];
   int correct_option;
} Question;
void displayQuestion(Question q) {
   printf("\n%s\n", q.question);
   for (int i = 0; i < 4; i++) {
       printf("%d. %s\n", i + 1, q.options[i]);
   }
}

int checkAnswer(Question q, int user_answer) {
   return user_answer == q.correct_option;
}
int main() {
   srand(time(0));
   Question questions[MAX_QUESTIONS] = {
       {"What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 1},
       {"Which programming language is this quiz written in?", {"Python", "C", "Java", "Ruby"}, 2},
       {"What is 5 + 3?", {"6", "7", "8", "9"}, 3},
       {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 2},
       {"Who wrote 'Hamlet'?", {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"}, 2}
   };
   int score = 0;
   int num_questions = MAX_QUESTIONS;
   printf("Welcome to the Quiz Game!\n");
   printf("Answer the following questions:\n");
   for (int i = 0; i < num_questions; i++) {
       
       displayQuestion(questions[i]);
      
       int user_answer;
       printf("Enter your answer (1-4): ");
       scanf("%d", &user_answer);
      
       if (user_answer >= 1 && user_answer <= 4) {
           if (checkAnswer(questions[i], user_answer)) {
               printf("Correct!\n");
               score++;
           } else {
               printf("Wrong! The correct answer was: %d. %s\n",
                      questions[i].correct_option,
                      questions[i].options[questions[i].correct_option - 1]);
           }
       } else {
           printf("Invalid choice. Please enter a number between 1 and 4.\n");
       }
   }
   
   printf("\nQuiz Over! Your final score is: %d/%d\n", score, num_questions);
   return 0;
}