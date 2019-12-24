#include "tic_tac_toe.h"
#include "..\universal_definitions.h"

#include <stdio.h>
#include <stdlib.h>

void play_tic_tac_toe(){
    char board[BOARD_SIZE][BOARD_SIZE] = {"-"};
    initialise_board(board);
    print_board(board);
}

void initialise_board(char board[][BOARD_SIZE]){
   for(int i = 0;i < BOARD_SIZE;i++){
       for(int j = 0;j < BOARD_SIZE;j++){
            board[i][j] = '-';
       }
   }
}
void print_board(char board[][3]){
   for(int i = 0;i < BOARD_SIZE;i++){
       printf("|");
       for(int j = 0;j < BOARD_SIZE;j++){
           printf(" %c |",board[i][j]);
       }
       printf("\n");
   }
}