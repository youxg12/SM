#include <stdio.h>

void main(void) {
    FILE *file;
    char word1[30], word2[30], word3[30];

    printf("첫 번째 단어를 입력하세요: ");
    scanf("%s", word1);
    printf("두 번째 단어를 입력하세요: ");
    scanf("%s", word2);
    printf("세 번째 단어를 입력하세요: ");
    scanf("%s", word3);

    file = fopen("sample.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    fprintf(file, "%s\n", word1);
    fprintf(file, "%s\n", word2);
    fprintf(file, "%s\n", word3);

    fclose(file);

}

