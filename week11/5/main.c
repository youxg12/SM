#include <stdio.h>

void main(void) {
    FILE *file;
    char word1[30], word2[30], word3[30];

    printf("ù ��° �ܾ �Է��ϼ���: ");
    scanf("%s", word1);
    printf("�� ��° �ܾ �Է��ϼ���: ");
    scanf("%s", word2);
    printf("�� ��° �ܾ �Է��ϼ���: ");
    scanf("%s", word3);

    file = fopen("sample.txt", "w");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    fprintf(file, "%s\n", word1);
    fprintf(file, "%s\n", word2);
    fprintf(file, "%s\n", word3);

    fclose(file);

}

