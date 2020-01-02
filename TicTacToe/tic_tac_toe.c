#include "tic_tac_toe.h"

void play_tic_tac_toe(struct player players[]){
    char board[BOARD_SIZE][BOARD_SIZE];
    char play_type[] = {'X','O'};
    int number_of_games = set_number_of_games();
    int games_played = 0;

    gameStatus = CONTINUE;

    int players_turn = select_side(players);
    if(players_turn == 1){
        swap_type_array(play_type);
    }

    while(games_played < number_of_games){
        initialise_board(board);
        while(gameStatus == CONTINUE){
            print_board(board);
            make_move(board,players_turn);
        }
        games_played++;
    }

}

int set_number_of_games(){
    int number_of_games;
    char input;
    printf("Please enter the number of games you wish to play\n");
    fgets(&input,2,stdin);
    fflush(stdin);
    number_of_games = strtol(&input,NULL,10);
    return number_of_games;
}

int select_side(struct player players[]){
    int decision = 0;
    char input_number;
    printf("Please enter which player will start as 'X'.\nPlayers will swap in each successive game\nPlease enter the corresponding number\n1.%s\n2.%s",players[0].player_name,players[1].player_name);
    while(decision < 1 || decision > 2){
        fgets(&input_number,2,stdin);
        fflush(stdin);
        decision = strtol(&input_number,NULL,10);
    }

    return --decision;
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

void make_move(char board[][BOARD_SIZE], int which_player){

}

void swap_type_array(char type_array[]){
    char temp = type_array[0];
    type_array[0] = type_array[1];
    type_array[1] = temp;
}