#include <stdio.h>

void main(void) {
    FILE *file;
    char word[30]; 

    file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("���� ���⿡ �����߽��ϴ�");
        return;
    }

    printf("���� ����:\n");
    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }

    fclose(file);
}

