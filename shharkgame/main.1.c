#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define N_PLAYER 3 // # of player


int player_position[N_PLAYER]; 
int player_coin[N_PLAYER];    
int player_status[N_PLAYER];   //  (0: LIVE, 1: DIE, 2: END)
char player_name[N_PLAYER][100]; 

void opening(void) {
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
}

void initializePlayers(void) {
    for (int i = 0; i < N_PLAYER; i++) {
        player_position[i] = 0;          
        player_coin[i] = 0;              // Initial coin number is 0
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", player_name[i]);
    }
    printf("All players are initialized!\n");
}

int main(void) {
    srand(time(NULL)); 
    opening();         

    board_initBoard();       
    board_printBoardStatus(); 

    initializePlayers(); 

    return 0;
}

