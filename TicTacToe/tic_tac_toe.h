#include "../universal_definitions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef BASIC_BOARDGAMES_TIC_TAC_TOE_H
#define BASIC_BOARDGAMES_TIC_TAC_TOE_H

#endif //BASIC_BOARDGAMES_TIC_TAC_TOE_H

#define BOARD_SIZE 3

enum type {X,Y};

void initialise_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
void make_move(char board[][BOARD_SIZE], int which_player);
int select_side(struct player players[]);
void swap_sides();
void swap_type_array(char type_array[]);