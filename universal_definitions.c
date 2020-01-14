#include "universal_definitions.h"

void initialise_board(char **board, int rows, int columns){
    for(int i = 0;i < rows;i++)
        board[i] = (char *)malloc(rows * sizeof(char));

    for(int i = 0;i < rows;i++)
        for(int j = 0;j < columns;j++)
            board[i][j] = '-';
}

void print_board(char **board, int rows, int columns){
    for(int i = 0;i < rows;i++){
        printf("|");
        for(int j = 0;j < columns;j++)
            printf(" %c |",board[i][j]);
        printf("\n");
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

int select_side(struct player players[], char first_player_type){
    int decision = 0;
    char input_number;
    printf("Please enter which player will start as '%c'.\nPlayers will swap in each successive game\nPlease enter the corresponding number\n1.%s\n2.%s",first_player_type,players[0].player_name,players[1].player_name);
    while(decision < 1 || decision > 2){
        fgets(&input_number,2,stdin);
        fflush(stdin);
        decision = strtol(&input_number,NULL,10);
    }

    return --decision;
}

void swap_type_array(char type_array[]){
    char temp = type_array[0];
    type_array[0] = type_array[1];
    type_array[1] = temp;
}