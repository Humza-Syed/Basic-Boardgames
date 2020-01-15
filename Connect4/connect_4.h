#ifndef BASIC_BOARDGAMES_CONNECT_4_H
#define BASIC_BOARDGAMES_CONNECT_4_H

#endif //BASIC_BOARDGAMES_CONNECT_4_H

#include "../universal_definitions.h"

#define NO_OF_ROWS 6
#define NO_OF_COL 7
#define MAX_MOVES NO_OF_ROWS*NO_OF_COL

enum STATUS move_c4(char **board, char play_type, int *moves_made);
bool valid_move_c4(char **board, int *col);
bool game_is_won_c4(char **board, int *col);
