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
            printf("서로 다른 값이 있는 index: %d\n", i);
            flag_same = 0; 
        }
    }

    if (flag_same)
        printf("배열은 같은 값을 가집니다.\n");
    else
        printf("배열은 다른 값을 가집니다.\n");

    return 0;
}

