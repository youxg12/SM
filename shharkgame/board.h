//
//  board.h
//  sharkGame
//

#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>

// ----- EX. 3 : board ------------
#define N_BOARD                 20
#define BOARDSTATUS_NOK          1 // 칸이 파괴됨
#define BOARDSTATUS_OK           0 // 칸이 정상 상태

void board_initBoard(void); // 보드 초기화
int board_getBoardStatus(int pos); // 특정 칸 상태 확인
int board_getSharkPosition(void); // 상어 위치 반환
void board_stepShark(void); // 상어 이동
int board_getBoardCoin(int pos); // 특정 칸의 코인 반환
void board_printBoardStatus(void); // 보드 상태 출력
// ----- EX. 3 : board ------------

#endif /* board_h */

