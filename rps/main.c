#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scores[2] = {0, 0};

int game(char player_choice, char computer_choice) {
    if (player_choice == computer_choice) {
        return 0;
    }
    else if (player_choice == 'r' && computer_choice == 's' || player_choice == 's' && computer_choice == 'p' || player_choice == 'p' && player_choice == 'r') {
        return 1;
    }
    else {
        return -1;
    }
}

void printScores() {
    printf("You: %d\nComputer: %d\n\n", scores[0], scores[1]);
}

int main(int argc, char *argv[]) {
    int best_of;
    char player_choice;
    char computer_choice;
    int n;
    int result;


    if (argc == 2) {
        best_of = atoi(argv[1]);
    } else {
        printf("Best of: ");
        scanf("%d", &best_of);
    }

    for (int i = 1; i <= best_of; i++) {
        printf("Rock, paper, or scissors [r/p/s]? ");
        scanf(" %c", &player_choice);

        srand(time(NULL));
        n = rand() % 3;
        
        printf("Computer played: ");
        switch (n) {
            case 0:
                printf("Rock");
                computer_choice = 'r';
                break;
            case 1:
                printf("Paper");
                computer_choice = 'p';
                break;
            case 2:
                printf("Scissors");
                computer_choice = 's';
                break;
        }
        printf("\n");

        result = game(player_choice, computer_choice);

        switch (result) {
            case 0:
                printf("Round drawn!\n");
                break;
            case 1:
                printf("Round won!\n");
                scores[0] += 1;
                break;
            case -1:
                printf("Round lost!\n");
                scores[1] += 1;
                break;
        }
        printScores();

        if (scores[0] > best_of / 2 || scores[1] > best_of / 2) {
            break;
        }
    }

    if (scores[0] > scores[1]) {
        printf("Game won %d to %d!\n", scores[0], scores[1]);
    }
    else if (scores[0] < scores[1]) {
        printf("Game lost %d to %d!\n", scores[0], scores[1]);
    }
    else {
        printf("Game drawn %d to %d!\n", scores[0], scores[1]);
    }

    return 0;
}
