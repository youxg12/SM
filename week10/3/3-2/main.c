#include <stdio.h>
#define SIZE 5

int main(void)
{
    int i;
    int a[SIZE] = {1, 2, 3, 4, 5};
    int b[SIZE] = {1, 2, 3, 7, 10};
    int flag_same = 1; 

    for (i = 0; i < SIZE; i++)
    {
        if (a[i] != b[i]) 
        {
            printf("���� �ٸ� ���� �ִ� index: %d\n", i);
            flag_same = 0; 
        }
    }

    if (flag_same)
        printf("�迭�� ���� ���� �����ϴ�.\n");
    else
        printf("�迭�� �ٸ� ���� �����ϴ�.\n");

    return 0;
}

