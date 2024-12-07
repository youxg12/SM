#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12 // ������ �ִ� ĭ�� ����
#define MAX_COIN        4  // �� ĭ���� ���� �� �ִ� �ִ� ���� ��
// ----- EX. 3 : board ------------

// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6  // �� �� ���� �̵��� �� �ִ� �ִ� ĭ ��
#define SHARK_INITPOS   -4 // ��� �ʱ� ��ġ
// ----- EX. 5 : shark ------------

// ���� ���¿� ���õ� ���� ����
static int board_coin[N_BOARD];    // �� ĭ�� ���� ����
static int board_status[N_BOARD]; // �� ĭ�� ���� (0: ����, 1: �ı���)
static int shark_position;        // ����� ���� ��ġ

// ----- EX. 3 : board ------------
// ���� ���¸� ���
void board_printBoardStatus(void) {
    int i;
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i = 0; i < N_BOARD; i++) {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X"); // �ı��� ĭ
        else if (board_coin[i] > 0)
            printf("C"); // ������ �ִ� ĭ
        else
            printf("O"); // ���� ĭ
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

// ���� �ʱ�ȭ
void board_initBoard(void) {
    int i, coinPlaced = 0; // ���� ������ ���� �ܺη� �̵�
    // ĭ �ʱ�ȭ
    for (i = 0; i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }

    // ��� �ʱ� ��ġ ����
    shark_position = SHARK_INITPOS;

    // �������� ���� ��ġ
    while (coinPlaced < N_COINPOS) {
        int pos = rand() % N_BOARD; // 0���� N_BOARD-1 ������ ���� ��ġ
        if (board_coin[pos] == 0) { // ������ ���� ��ġ���� ��ġ
            board_coin[pos] = rand() % MAX_COIN + 1; // 1���� MAX_COIN ����
            coinPlaced++;
        }
    }
}

// Ư�� ĭ�� ���� ��ȯ
int board_getBoardStatus(int pos) {
    if (pos < 0 || pos >= N_BOARD) return BOARDSTATUS_NOK; // ���� �� ĭ�� �ı��� ����
    return board_status[pos];
}

// Ư�� ĭ�� ���� ���� ��ȯ �� �ʱ�ȭ
int board_getBoardCoin(int pos) {
    if (pos < 0 || pos >= N_BOARD) return 0; // ���� �� ĭ�� ���� ����
    int coin = board_coin[pos];
    board_coin[pos] = 0; // ������ ���������Ƿ� 0���� �ʱ�ȭ
    return coin;
}

// �� �̵�
void board_stepShark(void) {
    int step; // ���� ������ ���� �ܺη� �̵�
    step = rand() % MAX_SHARKSTEP + 1; // ����� ���� �̵� �Ÿ� (1~MAX_SHARKSTEP)
    printf("Shark moves %d steps!\n", step);

    // �� �̵��ϸ� ������ ĭ�� �ı�
    int i; // ���� ������ ���� �ܺη� �̵�
    for (i = shark_position + 1; i <= shark_position + step && i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_NOK; // ĭ�� �ı�
    }

    // ����� ��ġ ����
    shark_position += step;
    if (shark_position >= N_BOARD) {
        shark_position = N_BOARD - 1; // �� ���� ���� ����
    }
}

// ����� ���� ��ġ ��ȯ
int board_getSharkPosition(void) {
    return shark_position;
}

