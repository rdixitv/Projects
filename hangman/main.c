#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

#define LEN 10

int main(int argc, char *argv[]) {
  char word[LEN];
  int tries = 3;

  if (argc == 3) {
    strncpy(word, argv[1], LEN);
    tries = (int)strtol(argv[2], NULL, 10);
  }
  else if (argc == 2) {
    strncpy(word, argv[1], LEN);
  }
  else if (argc == 1) {
    printf("Enter word: ");
    fgets(word, LEN, stdin);
  }
  else {
    printf("Invalid arguments.\nUsage: hangman <word> <tries>\n");
    return -1;
  }

  system("clear");

  for (int i = 0; i < LEN; i++) {
    if (word[i] >= 'A' && word[i] <= 'Z') {
      word[i] += 32; // makes the character lowercase
    }
    else if ((word[i] < 'a' || word[i] > 'z') && word[i] != '\n' && word[i] != '\0') {
      printf("The word contains an invalid character. Please make sure to enter only alphabetic characters.\n");
      exit(EXIT_FAILURE);
    }
  }

  run(word, tries);


  printf("\n\nThe word was: %s\n", word);

  return EXIT_SUCCESS;
}
