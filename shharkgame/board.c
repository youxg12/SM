#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12 // 코인이 있는 칸의 개수
#define MAX_COIN        4  // 각 칸에서 가질 수 있는 최대 코인 수
// ----- EX. 3 : board ------------

// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6  // 상어가 한 번에 이동할 수 있는 최대 칸 수
#define SHARK_INITPOS   -4 // 상어 초기 위치
// ----- EX. 5 : shark ------------

// 보드 상태와 관련된 전역 변수
static int board_coin[N_BOARD];    // 각 칸의 코인 개수
static int board_status[N_BOARD]; // 각 칸의 상태 (0: 정상, 1: 파괴됨)
static int shark_position;        // 상어의 현재 위치

// ----- EX. 3 : board ------------
// 보드 상태를 출력
void board_printBoardStatus(void) {
    int i;
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i = 0; i < N_BOARD; i++) {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X"); // 파괴된 칸
        else if (board_coin[i] > 0)
            printf("C"); // 코인이 있는 칸
        else
            printf("O"); // 정상 칸
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

// 보드 초기화
void board_initBoard(void) {
    int i, coinPlaced = 0; // 변수 선언을 루프 외부로 이동
    // 칸 초기화
    for (i = 0; i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }

    // 상어 초기 위치 설정
    shark_position = SHARK_INITPOS;

    // 랜덤으로 코인 배치
    while (coinPlaced < N_COINPOS) {
        int pos = rand() % N_BOARD; // 0부터 N_BOARD-1 사이의 랜덤 위치
        if (board_coin[pos] == 0) { // 코인이 없는 위치에만 배치
            board_coin[pos] = rand() % MAX_COIN + 1; // 1부터 MAX_COIN 사이
            coinPlaced++;
        }
    }
}

// 특정 칸의 상태 반환
int board_getBoardStatus(int pos) {
    if (pos < 0 || pos >= N_BOARD) return BOARDSTATUS_NOK; // 범위 외 칸은 파괴로 간주
    return board_status[pos];
}

// 특정 칸의 코인 개수 반환 및 초기화
int board_getBoardCoin(int pos) {
    if (pos < 0 || pos >= N_BOARD) return 0; // 범위 외 칸은 코인 없음
    int coin = board_coin[pos];
    board_coin[pos] = 0; // 코인을 습득했으므로 0으로 초기화
    return coin;
}

// 상어가 이동
void board_stepShark(void) {
    int step; // 변수 선언을 루프 외부로 이동
    step = rand() % MAX_SHARKSTEP + 1; // 상어의 랜덤 이동 거리 (1~MAX_SHARKSTEP)
    printf("Shark moves %d steps!\n", step);

    // 상어가 이동하며 지나간 칸을 파괴
    int i; // 변수 선언을 루프 외부로 이동
    for (i = shark_position + 1; i <= shark_position + step && i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_NOK; // 칸을 파괴
    }

    // 상어의 위치 갱신
    shark_position += step;
    if (shark_position >= N_BOARD) {
        shark_position = N_BOARD - 1; // 상어가 보드 끝에 도달
    }
}

// 상어의 현재 위치 반환
int board_getSharkPosition(void) {
    return shark_position;
}

