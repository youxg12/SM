#include <stdio.h>

void main(void) {
    FILE *file;
    char word[30]; 

    file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("파일 열기에 실패했습니다");
        return;
    }

    printf("파일 내용:\n");
    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }

    fclose(file);
}

