#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my program\nPlease select the corresponding game\n");
    printf("Games List\n1. Tic-Tac-Toe\n2. Connect 4\n3. MasterMind\n4. Exit program\n");
    char inputNumber;
    int desiredGame = 0;
    while(desiredGame <= 0 || desiredGame > 4){
        fgets(&inputNumber,2,stdin);
        fflush(stdin);
        desiredGame = strtol(&inputNumber,NULL,10);
    }

    switch(desiredGame){
        case(1) :
            printf("Player wants to play:  \"Tic-Tac-Toe\"");
            break;
        case(2) :
            printf("Player wants to play: \"Connect 4 \"\n");
        case(3) :
            printf("Player wants to play: \"Mastermind\"");
        default :
            exit(0);
    }
}