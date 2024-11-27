#include <stdio.h>
#define STUDENTNUM 4

struct student {
    int ID;     
    int score;  
};

int main(void) {
    struct student s[STUDENTNUM];
    int i, maxScore = 0, maxID = 0;
    float avgScore = 0.0;

    for (i = 0; i < STUDENTNUM; i++) {
        printf("Input the ID: ");
        scanf("%d", &s[i].ID);
        printf("Input the score: ");
        scanf("%d", &s[i].score);

        avgScore += s[i].score;

        if (s[i].score > maxScore) {
            maxScore = s[i].score;
            maxID = s[i].ID;
        }
    }

    avgScore /= STUDENTNUM;

    printf("The average of the score: %.2f\n", avgScore);
    printf("The highest score - ID: %d, score: %d\n", maxID, maxScore);

    return 0;
}

