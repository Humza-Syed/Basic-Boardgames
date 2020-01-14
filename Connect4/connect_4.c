#include "connect_4.h"

void play_connect_4(struct player players[]){
    char **board = (char **)malloc(NO_OF_ROWS * sizeof(char *));
    char play_type[] = {'R','Y'};
    int player_scores[] = {0,0};
    int number_of_games = set_number_of_games();

    int games_played = 0;
    int max_moves = NO_OF_ROWS*NO_OF_COL;
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

        }
        games_played++;
    }
}