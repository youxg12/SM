#include <stdio.h>
int all_files;

extern void sub();

int main(void)
{
    sub();
    printf("%d\n", all_files);
    return 0;
}

