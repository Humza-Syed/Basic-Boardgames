#include "tic_tac_toe.h"

void play_tic_tac_toe(struct player players[]){
    char **board = (char **)malloc(sizeof(char *));
    char play_type[] = {'X','O'};
    int player_scores[2] = {0,0};
    int number_of_games = set_number_of_games();
    int games_played = 0;
    int number_of_moves_made = 0;

    int players_turn = select_side(players, play_type[0]);
    if(players_turn == 1){
        swap_type_array(play_type);
    }

    while(games_played < number_of_games){
        initialise_board(board,BOARD_DIMENSION,BOARD_DIMENSION);
        gameStatus = CONTINUE;
        printf("Game %d\n_____________\n",games_played++);
        printf("%s (%c) %d-%d %s (%c)\n",players[0].player_name,play_type[0],player_scores[0],player_scores[1],players[1].player_name,play_type[1]);
        print_board(board,BOARD_DIMENSION,BOARD_DIMENSION);

        while(gameStatus == CONTINUE){
            gameStatus = make_move(board,play_type[players_turn],&number_of_moves_made);
            if(players_turn == 1)
                players_turn = 0;
            else
                players_turn = 1;
        }

        printf("Game has been won\n");
        number_of_moves_made = 0;
        if(gameStatus == WON){
            if(players_turn == 1)
                player_scores[0]++;
            else
                player_scores[1]++;
        }
        games_played++;

        if((player_scores[0]  || player_scores[1]) > number_of_games/2)
            break;
        else{
            swap_type_array(play_type);
            if(play_type[0] == 'X')
                players_turn = 0;
            else
                players_turn = 1;
        }

    }

    if(player_scores[0] > player_scores[1]){
        printf("Series has been won by player %s\n%s %d-%d %s\n",players[0].player_name,players[0].player_name,player_scores[0],player_scores[1],players[1].player_name);
        players[0].score++;
    }else if(player_scores[0] < player_scores[1]){
        printf("Series has been won by player %s\n%s %d-%d %s\n",players[0].player_name,players[0].player_name,player_scores[0],player_scores[1],players[1].player_name);
        players[1].score++;
    }else{
        printf("Series was a draw\n");
    }

}

enum STATUS make_move(char **board, char player_type,int* number_of_moves_made){
    int x = -1,y = -1;
    char user_input;
    do{
        while(x < 0 || x > 2){
            printf("Please enter row that you want to play\n");
            scanf("%c",&user_input);
            fflush(stdin);
            x = strtol(&user_input,NULL,10);
            x--;
        }
        while(y < 0 || y > 2){
            printf("Please enter column that you want to play\n");
            scanf("%c",&user_input);
            fflush(stdin);
            y = strtol(&user_input,NULL,10);
            y--;
        }
    }while(!is_valid_move(&x,&y,board));

    board[x][y] = player_type;
    *number_of_moves_made = *number_of_moves_made + 1;
    print_board(board,BOARD_DIMENSION,BOARD_DIMENSION);

    if(*number_of_moves_made > (BOARD_SIZE/2)){
        if(game_is_won(board,x,y))
            return WON;
        else if(*number_of_moves_made == 9)
            return DRAW;
        else
            return CONTINUE;
    }else
        return CONTINUE;

}

bool is_valid_move(int* x,int* y,char **board){
    if(board[*x][*y] == '-')
        return true;

    *x = -1;
    *y = -1;
    printf("Please enter a valid move\n");
    return false;
}

bool game_is_won(char **board, int x, int y){
    if(board[x][0] != '-' && board[x][0] == board[x][1] && board[x][1] == board[x][2])
        return true;
    else if(board[0][y] != '-' && board[0][y] == board[1][y] && board[1][y] == board[2][y])
        return true;
    else{
        //Check diagonals
        if(board[x][y] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        else if(board[x][y] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
    }

    return false;
}