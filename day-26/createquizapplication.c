#include <stdio.h>
#include <ctype.h>

int main() {
    char guess;
    int score = 0;

    char questions[][100] = {
        "1. What is the size of an int in C (usually)?",
        "2. Which keyword is used to prevent modification?",
        "3. Which function is used to print output?"
    };

    char options[][100] = {
        "A) 1 byte", "B) 2 bytes", "C) 4 bytes", "D) 8 bytes",
        "A) static", "B) const", "C) volatile", "D) immutable",
        "A) scanf", "B) output", "C) print", "D) printf"
    };

    char answers[3] = {'C', 'B', 'D'};
    int totalQuestions = sizeof(answers) / sizeof(answers[0]);

    printf("=== WELCOME TO THE C QUIZ ===\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("%s\n", questions[i]);

        for (int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }

        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess == answers[i]) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong. The correct answer was %c.\n\n", answers[i]);
        }
    }

    printf("=== QUIZ OVER ===\n");
    printf("Final Score: %d/%d\n", score, totalQuestions);

    return 0;
}

