#include <stdio.h>
#include <stdlib.h>

#include "TicTacToe/tic_tac_toe.h"
#include "universal_definitions.h"

int main() {
    char input_number;
    int desired_game = 0;
    struct player players[MAX_PLAYERS];
    initialise_players(players);

    printf("Welcome to my program\nPlease select the corresponding game\n");
    printf("Games List\n1. Tic-Tac-Toe\n2. Connect 4\n3. MasterMind\n4. Exit program\n");

    while(desired_game <= 0 || desired_game > 4){
        fgets(&input_number, 2, stdin);
        fflush(stdin);
        desired_game = strtol(&input_number, NULL, 10);
    }

    switch(desired_game){
        case(1) :
            printf("Player wants to play:  \"Tic-Tac-Toe\"\n");
            play_tic_tac_toe();
            break;
        case(2) :
            printf("Player wants to play: \"Connect 4 \"\n");
        case(3) :
            printf("Player wants to play: \"Mastermind\"\n");
        default :
            exit(0);
    }
}

struct player initialise_players(struct player players[]){
    for(int i = 0;i < MAX_PLAYERS;i++){
        printf("Please enter the name for player 1\n");
        fgets(players[i].player_name,20,stdin);
        players[i].score = 0;
    }
}