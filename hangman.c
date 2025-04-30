#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_LEN 100

struct WordHint {
    char word[WORD_LEN];
    char hint[WORD_LEN];
};

void print_hangman(int tries) {
    printf("\n");
    printf("  _______\n");
    printf("  |     |\n");
    printf("  |     %c\n", (tries <= 5) ? 'O' : ' ');
    printf("  |    %c%c%c\n", (tries <= 3) ? '/' : ' ', (tries <= 4) ? '|' : ' ', (tries <= 2) ? '\\' : ' ');
    printf("  |    %c %c\n", (tries <= 1) ? '/' : ' ', (tries <= 0) ? '\\' : ' ');
    printf(" _|_\n\n");
}

int main() {
    struct WordHint list[] = {
        {"computer", "An electronic device"},
        {"programming", "The process of writing code"},
        {"hangman", "A popular word guessing game"},
        {"internet", "Global network for communication"},
        {"keyboard", "An input device with keys"}
    };
    int total_words = sizeof(list) / sizeof(list[0]);

    srand(time(0)); // Random seed
    int random_index = rand() % total_words;

    char word[WORD_LEN];
    char hint[WORD_LEN];
    strcpy(word, list[random_index].word);
    strcpy(hint, list[random_index].hint);

    char guessed[WORD_LEN];
    int word_len = strlen(word);
    int tries = MAX_TRIES;
    int correct = 0;
    char guess;
    int i;

    for (i = 0; i < word_len; i++) {
        guessed[i] = '_';
    }
    guessed[word_len] = '\0';

    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);

    while (tries > 0 && correct < word_len) {
        print_hangman(tries);
        printf("Word: ");
        for (i = 0; i < word_len; i++) {
            printf("%c ", guessed[i]);
        }
        printf("\n");

        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess); // বড় হাতের অক্ষরও ছোট করা হবে

        int found = 0;
        for (i = 0; i < word_len; i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            tries--;
            printf("Wrong guess!\n");
        } else {
            printf("Correct guess!\n");
        }
    }

    if (correct == word_len) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        print_hangman(tries);
        printf("\nGame Over! The word was: %s\n", word);
    }

    return 0;
}
