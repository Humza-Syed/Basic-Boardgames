#ifndef BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H
#define BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#endif //BASIC_BOARDGAMES_UNIVERSAL_DEFINITIONS_H

#define MAX_PLAYERS 2

enum STATUS {CONTINUE,WON,DRAW};
enum STATUS gameStatus;

 struct player{
    char player_name[20];
    int score;
};

void play_tic_tac_toe(struct player players[]);
void play_connect_4(struct player players[]);
int set_number_of_games();

struct player initialise_players(struct player players[]);