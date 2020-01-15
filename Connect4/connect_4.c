#include "connect_4.h"

void play_connect_4(struct player players[]){
    char **board = (char **)malloc(NO_OF_ROWS * sizeof(char *));
    char play_type[] = {'R','Y'};
    int player_scores[] = {0,0};
    int number_of_games = set_number_of_games();

    int games_played = 0;
    int moves_made;

    int players_turn = select_side(players, play_type[0]);
    if(players_turn == 1){
        swap_type_array(play_type);
    }

    while(games_played < number_of_games){
        gameStatus = CONTINUE;
        moves_made = 0;

        initialise_board(board,NO_OF_ROWS,NO_OF_COL);
        printf("Game %d\n_______\n%s (%c) %d-%d %s (%c)\n",games_played+1,players[0].player_name,play_type[0],
                player_scores[0],player_scores[1],players[1].player_name,play_type[1]);
        print_board(board,NO_OF_ROWS,NO_OF_COL);
        while(gameStatus == CONTINUE){
            gameStatus = move_c4(board,play_type[players_turn],&moves_made);
            if(players_turn == 1)
                players_turn = 0;
            else
                players_turn = 1;
        }

        printf("Game is won\n");
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
        games_played++;
    }
}

enum STATUS move_c4(char **board, char player_type, int *moves_made){
    int column = -1;
    char user_input;

    do{
        printf("Please enter the column you wish to play\n");
        while(column < 0 || column > 7){
            scanf("%c",&user_input);
            fflush(stdin);
            column = strtol(&user_input, NULL, 10);
            column--;
        }
    }while(!valid_move_c4(board,&column));

    int row = 0;
    for(int i = NO_OF_ROWS-1;i >= 0;i--){
        if(board[i][column] == '-'){
            board[i][column] = player_type;
            row = i;
            break;
        }
    }
    *moves_made = *moves_made+1;
    print_board(board,NO_OF_ROWS,NO_OF_COL);

    if(*moves_made >= 7){
        if(game_is_won_c4(board,row,column))
            return WON;
        else if(*moves_made == MAX_MOVES)
            return DRAW;
        else
            return CONTINUE;
    }else
        return CONTINUE;
}

bool valid_move_c4(char **board, int *column){
    if(board[0][*column] == '-')
        return true;

    *column = -1;
    printf("Please enter a valid column\n");
    return false;
}

bool game_is_won_c4(char **board, int row, int col){
    if(row <= 2 && board[row][col] == board[row+1][col] && board[row+1][col] == board[row+2][col] && board[row+2][col] == board[row+3][col])
        return true;
    else if(check_horizontal(board,row,col))
        return true;
    else
        return check_diagonals(board,row,col);
}

bool check_horizontal(char **board, int row, int col){
    int i = col, j = col,colour_match = 1;
    bool check_right = false, check_left = false;
    while(!check_left || !check_right){
        if(!check_left){
            i--;
            if(i < 0)
                check_left = true;
            else if(board[row][i] == board[row][col])
                colour_match++;
            else
                check_left = true;
        }
        if(!check_right){
            j++;
            if(j >= NO_OF_COL)
                check_right = true;
            else if(board[row][j] == board[row][col])
                colour_match++;
            else
                check_right = true;
        }

        if(colour_match >= 4)
            return true;
    }
    return false;
}

bool check_diagonals(char **board, int row, int col){
    return false;
}