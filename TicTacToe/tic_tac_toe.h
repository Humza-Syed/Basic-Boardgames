#include "../universal_definitions.h"

#ifndef BASIC_BOARDGAMES_TIC_TAC_TOE_H
#define BASIC_BOARDGAMES_TIC_TAC_TOE_H

#endif //BASIC_BOARDGAMES_TIC_TAC_TOE_H

#define BOARD_DIMENSION 3
#define BOARD_SIZE BOARD_DIMENSION*BOARD_DIMENSION

enum type {X,Y};

enum STATUS make_move(char **board, char player_type, int* number_of_moves_made);

void swap_sides();

bool is_valid_move(int* x,int* y,char **board);
bool game_is_won(char **board, int x, int y);