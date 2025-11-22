#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Word Jumble Puzzle Game

// Function to shuffle letters of a word
void shuffle(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    char *words[] = {"computer", "puzzle", "language", "program", "science", "player", "country"};
    int totalWords = sizeof(words) / sizeof(words[0]);

    int index = rand() % totalWords;
    char selected[50];
    strcpy(selected, words[index]);

    char jumbled[50];
    strcpy(jumbled, selected);
    shuffle(jumbled);

    char guess[50];

    printf("\\n*** WORD JUMBLE PUZZLE GAME ***\\n");
    printf("Unscramble the word: %s\\n", jumbled);

    printf("Your guess: ");
    scanf("%s", guess);

    if (strcmp(guess, selected) == 0) {
        printf("\\nCorrect! The word is: %s\\n", selected);
    } else {
        printf("\\nWrong! The correct word was: %s\\n", selected);
    }

    return 0;
}