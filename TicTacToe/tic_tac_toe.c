#include "tic_tac_toe.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void play_tic_tac_toe(struct player players[]){
    char board[BOARD_SIZE][BOARD_SIZE];
    int number_of_games = set_number_of_games();
    int games_played = 0;
    gameStatus = CONTINUE;

    while(games_played < number_of_games){
        while(gameStatus == CONTINUE){
            initialise_board(board);
            print_board(board);
        }
        games_played++;
    }

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

int set_number_of_games(){
    int number_of_games;
    printf("Please enter the number of games you wish to play\n");
    scanf("%d",&number_of_games);
    return number_of_games;
}