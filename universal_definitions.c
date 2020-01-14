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