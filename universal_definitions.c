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