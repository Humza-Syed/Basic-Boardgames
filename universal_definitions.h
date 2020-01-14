#ifndef BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H
#define BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#endif //BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLAYERS 2

enum STATUS {CONTINUE,WON,DRAW};
enum STATUS gameStatus;

 struct player{
    char player_name[20];
    int score;
};

void play_tic_tac_toe(struct player players[]);
void play_connect_4(struct player players[]);

void initialise_board(char **board, int rows, int columns);
void print_board(char **board, int rows, int columns);
int set_number_of_games();

struct player initialise_players(struct player players[]);