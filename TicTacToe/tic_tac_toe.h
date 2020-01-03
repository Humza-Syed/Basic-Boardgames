#include "../universal_definitions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BASIC_BOARDGAMES_TIC_TAC_TOE_H
#define BASIC_BOARDGAMES_TIC_TAC_TOE_H

#endif //BASIC_BOARDGAMES_TIC_TAC_TOE_H

#define BOARD_DIMENSION 3
#define BOARD_SIZE BOARD_DIMENSION*BOARD_DIMENSION

enum type {X,Y};

void initialise_board(char board[][BOARD_DIMENSION]);
void print_board(char board[][BOARD_DIMENSION]);
enum STATUS make_move(char board[][BOARD_DIMENSION], char player_type, int* number_of_moves_made);
int select_side(struct player players[]);
void swap_sides();
void swap_type_array(char type_array[]);
bool is_valid_move(int* x,int* y,char board[][BOARD_DIMENSION]);
bool game_is_won(char board[][BOARD_DIMENSION]);