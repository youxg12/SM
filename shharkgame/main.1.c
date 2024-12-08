#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.1.h"

#define N_PLAYER 3 

int player_position[N_PLAYER]; 
int player_coin[N_PLAYER];     
char player_name[N_PLAYER][100];

#define N_BOARD 20 
char board[N_BOARD][N_PLAYER]; 

void opening(void) {
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
}

void initializePlayers(void) {
    for (int i = 0; i < N_PLAYER; i++) {
        player_position[i] = 0;          
        player_coin[i] = 0;              
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", player_name[i]);   
    }
    printf("All players are initialized!\n");
}

void initializeBoard(void) {
    for (int i = 0; i < N_BOARD; i++) {
        for (int j = 0; j < N_PLAYER; j++) {
            board[i][j] = ' '; 
        }
    }
}

void printBoard(void) {
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (int i = 0; i < N_PLAYER; i++) {
        printf("|");
        for (int j = 0; j < N_BOARD; j++) {
            if (board[j][i] == ' ') {
                printf("O"); 
            } else {
                printf("%c", board[j][i]); 
            }
        }
        printf("|\n");
    }
    printf("------------------------------------------------------------\n");
}

int rollDie(void) {
    return (rand() % 6) + 1; 
}

void playerTurn(int turn) {
    printf("%s's turn!\n", player_name[turn]);
    printf("Press any key to roll the dice!\n");
    getchar(); 
    int dieRoll = rollDie();
    printf("%s rolled a %d!\n", player_name[turn], dieRoll);

    int previousPosition = player_position[turn];
    board[previousPosition][turn] = ' '; 

    player_position[turn] += dieRoll;
    if (player_position[turn] >= N_BOARD) {
        player_position[turn] = N_BOARD - 1; 
        printf("%s has reached the end of the board!\n", player_name[turn]);
    }

    board[player_position[turn]][turn] = player_name[turn][0];

    int coin = board_getBoardCoin(player_position[turn]);
    if (coin > 0) {
        player_coin[turn] += coin;
        printf("%s collected %d coins!\n", player_name[turn], coin);
    } else {
        printf("There are no coins at this position.\n");
    }

    printf("%s's position: %d | Coins: %d\n", player_name[turn], player_position[turn], player_coin[turn]);
}


int main(void) {
    srand(time(NULL)); 
    opening();         

    board_initBoard();
    initializeBoard();

    initializePlayers();

    int turn = 0;
    for (int round = 0; round < 10; round++) { // repeat 10 times
        printf("\n--- Round %d ---\n", round + 1);
        playerTurn(turn);
        printBoard();
        turn = (turn + 1) % N_PLAYER; 
    }

    return 0;
}

