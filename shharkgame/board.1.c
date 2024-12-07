//
//  board.c
//  sharkGame
//

#include "board.h"

static int board_coin[N_BOARD];        // Coin status of each board space
static int board_status[N_BOARD];      // status of board (0: 정상, 1: 파손)
static int shark_position;             // Shark's location


void board_printBoardStatus(void) {
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (int i = 0; i < N_BOARD; i++) {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}


int board_initBoard(void) {
    srand((unsigned int)time(NULL)); // Random seed setting
    for (int i = 0; i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_OK; // Set all cells to normal state
        board_coin[i] = 0;                // Coin reset
    }
    shark_position = SHARK_INITPOS;       // Set shark initial position

    // 코인 배치
    for (int i = 0; i < N_COINPOS; i++) {
        int coin_pos = rand() % N_BOARD;           // coin in random slot
        int coin_value = (rand() % MAX_COIN) + 1;  // coin value(1~MAX_COIN)
        board_coin[coin_pos] = coin_value;         // Set coin value
    }

    return N_COINPOS; // Returns the number of coins placed
}


int board_getBoardStatus(int pos) {
    if (pos < 0 || pos >= N_BOARD) return BOARDSTATUS_NOK; 
    return board_status[pos];
}


int board_getBoardCoin(int pos) {
    if (pos < 0 || pos >= N_BOARD) return 0;
    int coin = board_coin[pos]; // Save coin value
    board_coin[pos] = 0;        // Coin recovery
    return coin;
}


int board_getSharkPosition(void) {
    return shark_position;
}


int board_stepShark(void) {
    int step = (rand() % MAX_SHARKSTEP) + 1; // move 1~MAX_SHARKSTEP
    shark_position += step; 

    // Deal with damage to the moved space
    for (int i = 0; i < step; i++) {
        int pos = shark_position - i;
        if (pos >= 0 && pos < N_BOARD) {
            board_status[pos] = BOARDSTATUS_NOK;
        }
    }

 
    if (shark_position >= N_BOARD) {
        shark_position = N_BOARD - 1; // pin to last column
    }

    return shark_position;
}
