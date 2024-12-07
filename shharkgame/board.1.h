//
//  board.h
//  sharkGame
//

#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N_BOARD                 20    
#define BOARDSTATUS_NOK          1    
#define BOARDSTATUS_OK           0    

#define N_COINPOS               12    
#define MAX_COIN                 4    

#define MAX_SHARKSTEP            6    
#define SHARK_INITPOS           -4    

int board_initBoard(void);
int board_getBoardStatus(int pos);
int board_getBoardCoin(int pos);
int board_getSharkPosition(void);
int board_stepShark(void);
void board_printBoardStatus(void);

#endif /* board_h */

