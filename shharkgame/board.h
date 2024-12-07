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
#define BOARDSTATUS_NOK          1 // ĭ�� �ı���
#define BOARDSTATUS_OK           0 // ĭ�� ���� ����

void board_initBoard(void); // ���� �ʱ�ȭ
int board_getBoardStatus(int pos); // Ư�� ĭ ���� Ȯ��
int board_getSharkPosition(void); // ��� ��ġ ��ȯ
void board_stepShark(void); // ��� �̵�
int board_getBoardCoin(int pos); // Ư�� ĭ�� ���� ��ȯ
void board_printBoardStatus(void); // ���� ���� ���
// ----- EX. 3 : board ------------

#endif /* board_h */

