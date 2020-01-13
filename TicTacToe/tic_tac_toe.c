#include "tic_tac_toe.h"

void play_tic_tac_toe(struct player players[]){
    char board[BOARD_DIMENSION][BOARD_DIMENSION];
    char play_type[] = {'X','O'};
    int player_scores[2] = {0,0};
    int number_of_games = set_number_of_games();
    int games_played = 0;
    int number_of_moves_made = 0;

    int players_turn = select_side(players);
    if(players_turn == 1){
        swap_type_array(play_type);
    }

    while(games_played < number_of_games){
        initialise_board(board);
        gameStatus = CONTINUE;
        while(gameStatus == CONTINUE){
            print_board(board);
            gameStatus = make_move(board,play_type[players_turn],&number_of_moves_made);
            if(players_turn == 1)
                players_turn = 0;
            else
                players_turn = 1;
        }
        games_played++;
    }

}

int set_number_of_games(){
    int number_of_games;
    char input;
    printf("Please enter the set number of games you wish to play (best of n series)\n");
    do{
        fgets(&input,2,stdin);
        fflush(stdin);
        number_of_games = strtol(&input,NULL,10);
        if(number_of_games % 2 == 0)
            printf("Please enter an odd number of games\n");
    }while(number_of_games % 2 == 0);
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

void initialise_board(char board[][BOARD_DIMENSION]){
   for(int i = 0; i < BOARD_DIMENSION; i++){
       for(int j = 0; j < BOARD_DIMENSION; j++){
            board[i][j] = '-';
       }
   }
}

void print_board(char board[][3]){
   for(int i = 0; i < BOARD_DIMENSION; i++){
       printf("|");
       for(int j = 0; j < BOARD_DIMENSION; j++){
           printf(" %c |",board[i][j]);
       }
       printf("\n");
   }
}

enum STATUS make_move(char board[][BOARD_DIMENSION], char player_type,int* number_of_moves_made){
    int x = -1,y = -1;
    char user_input;
    do{
        while(x < 0 || x > 2){
            printf("Please enter x co-ordinate that you want to play\n");
            scanf("%c",&user_input);
            fflush(stdin);
            x = strtol(&user_input,NULL,10);
            x--;
        }
        while(y < 0 || y > 2){
            printf("Please enter y co-ordinate that you want to play\n");
            scanf("%c",&user_input);
            fflush(stdin);
            y = strtol(&user_input,NULL,10);
            y--;
        }
    }while(!is_valid_move(&x,&y,board));

    board[x][y] = player_type;
    *number_of_moves_made = *number_of_moves_made + 1;

    if(*number_of_moves_made > ((BOARD_SIZE/2) + 1)){
        if(game_is_won(board))
            return OVER;
        else
            return CONTINUE;
    }else
        return CONTINUE;

}

bool is_valid_move(int* x,int* y,char board[][BOARD_DIMENSION]){
    if(board[*x][*y] == '-')
        return true;

    *x = -1;
    *y = -1;
    printf("Please enter a valid move\n");
    return false;
}

bool game_is_won(char board[][BOARD_DIMENSION]){
    return false;
}

void swap_type_array(char type_array[]){
    char temp = type_array[0];
    type_array[0] = type_array[1];
    type_array[1] = temp;
}