#include "../universal_definitions.h"

#ifndef BASIC_BOARDGAMES_TIC_TAC_TOE_H
#define BASIC_BOARDGAMES_TIC_TAC_TOE_H

#endif //BASIC_BOARDGAMES_TIC_TAC_TOE_H

#define BOARD_SIZE 3

enum type {X,Y};

void initialise_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
void move(int x,int j);