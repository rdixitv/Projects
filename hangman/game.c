#include <stdio.h>
#include "game.h"

#define LEN 10

void run(char word[LEN], int tries) {
  char revealed[LEN] = "          ";
  short wrong = 0;
  char guess;
  short found = 0;
  short done = 0;
  short repeat_message = 0;

  for (int i = 0; i < LEN; i++) {
    if (word[i] >= 'a' && word[i] <= 'z') {
      revealed[i] = '_';
    }
  }

  while (wrong < tries && !done) {
    found = 0;
    repeat_message = 0;
    printf("%s\n", revealed);
    printf("Guess: ");
    scanf(" %c", &guess);

    for (int i = 0; i < LEN; i++) {
      if (revealed[i] == guess && repeat_message == 0) {
        printf("'%c' has already been guessed.\n", guess);  
        repeat_message = 1;
      }
      if (word[i] == guess) {
        found = 1;
        revealed[i] = word[i];
      }
    }

    for (int i = 0; i < LEN; i++) {
      if (revealed[i] == '_') {
        break;
      }

      if (i == LEN - 1) {
        done = 1;
      }
    }

    if (!found) {
      wrong++;   
    }

    printf("Wrong: %d\n\n", wrong);
  }

  if (done) {
    printf("You got it!\n");
  } else {
    printf("You have run out of guesses.");
  }
}
