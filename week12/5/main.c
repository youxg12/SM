#include <stdio.h>

int main(void) {
    char *pc;
    int *pi;
    double *pd;

    pc = (char*)10000;
    pi = (int*)10000;
    pd = (double*)10000;

    printf("���� �� : pc = %p, pi = %p, pd = %p\n", pc, pi, pd);

    pc++;
    pi++;
    pd++;

    printf("���� �� : pc = %p, pi = %p, pd = %p\n", pc, pi, pd);

    return 0;
}

