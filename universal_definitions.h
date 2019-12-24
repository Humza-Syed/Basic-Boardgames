#ifndef BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H
#define BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#endif //BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#define MAX_PLAYERS 2

#define STATUS {CONTINUE,OVER};
#define enum gameStatus

typedef struct player{
    char player_name[20];
    int score;
};

int number_of_games();
struct player initialise_players(struct player players[]);