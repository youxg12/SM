#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_PLAYER 3    
#define N_BOARD 20    
#define SHARK_SPEED 3 

int player_position[N_PLAYER];  
int player_coin[N_PLAYER];      
char player_name[N_PLAYER][100];
int player_status[N_PLAYER];    

char board[3][N_BOARD];         
int shark_position = -1;       

void opening(void) {
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
}

void initializePlayers(void) {
    for (int i = 0; i < N_PLAYER; i++) {
        player_position[i] = 0;           
        player_coin[i] = 0;               
        player_status[i] = 1;             
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", player_name[i]);
    }
    printf("All players have been registered!\n");
}

void initializeBoard(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N_BOARD; j++) {
            board[i][j] = 'O'; 
        }
    }
}

void printBoard(void) {
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < N_BOARD; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("------------------------------------------------------------\n");
}

int rollDie(void) {
    return (rand() % 6) + 1; 
}

void updateBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N_BOARD; j++) {
            if (board[i][j] != 'X') {
                board[i][j] = 'O';
            }
        }
    }

    for (int i = 0; i < N_PLAYER; i++) {
        if (player_status[i] == 1) { 
            board[0][player_position[i]] = player_name[i][0];
        }
    }
}

void playerTurn(int turn) {
    if (player_status[turn] == 0) {
        return; 
    }

    printf("%s's turn!\n", player_name[turn]);
    printf("Press Enter to roll the die!\n");
    getchar(); 
    int dieRoll = rollDie();
    printf("%s rolled a %d!\n", player_name[turn], dieRoll);

    player_position[turn] += dieRoll;
    if (player_position[turn] >= N_BOARD) {
        player_position[turn] = N_BOARD - 1; 
        printf("%s has reached the end of the board!\n", player_name[turn]);
    }

    if (board[0][player_position[turn]] == 'X') {
        printf("%s was caught by the shark and died!\n", player_name[turn]);
        player_status[turn] = 0; 
    } else {
        player_coin[turn] += 1; 
        printf("%s collected 1 coin! Total coins: %d\n", player_name[turn], player_coin[turn]);
    }

    printf("%s's current position: %d\n", player_name[turn], player_position[turn]);
    updateBoard();
}

void moveShark(void) {
    int sharkMove = (rand() % SHARK_SPEED) + 1; 
    int previousPosition = shark_position;
    shark_position += sharkMove;

    if (shark_position >= N_BOARD) {
        shark_position = N_BOARD - 1; 
    }

    for (int i = 0; i < 3; i++) {
        for (int j = previousPosition + 1; j <= shark_position; j++) {
            if (j >= 0 && j < N_BOARD) {
                board[i][j] = 'X';
            }
        }
    }

    printf("The shark moved to position %d!\n", shark_position);
}

int checkGameOver(void) {
    int alivePlayers = 0;
    for (int i = 0; i < N_PLAYER; i++) {
        if (player_status[i] == 1) {
            alivePlayers++;
        }
    }

    if (alivePlayers == 0) {
        printf("All players are dead. Game over.\n");
        return 1; 
    }

    int allFinished = 1;
    for (int i = 0; i < N_PLAYER; i++) {
        if (player_position[i] < N_BOARD - 1 && player_status[i] == 1) {
            allFinished = 0;
            break;
        }
    }

    if (allFinished) {
        printf("All players have reached the end. Determining the winner...\n");
        int maxCoins = 0, winner = -1;
        for (int i = 0; i < N_PLAYER; i++) {
            if (player_status[i] == 1 && player_coin[i] > maxCoins) {
                maxCoins = player_coin[i];
                winner = i;
            }
        }
        printf("The winner is %s with %d coins!\n", player_name[winner], maxCoins);
        return 1; 
    }

    return 0; 
}

int main(void) {
    srand(time(NULL));
    opening();
    initializeBoard();
    initializePlayers();

    int round = 1, turn = 0;
    while (1) {
        printf("\n--- Round %d ---\n", round);
        playerTurn(turn);
        printBoard();

        if ((turn + 1) % N_PLAYER == 0) {
            printf("\n--- Shark's Move ---\n");
            moveShark();
            printBoard();
            round++;
        }

        if (checkGameOver()) {
            break; 
        }

        turn = (turn + 1) % N_PLAYER; 
    }

    return 0;
}

