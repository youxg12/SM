#include <stdio.h>

int main(void) {
    int i = 10;
    char c = 'a';

    int *iptr = &i;      
    char *cptr = &c;     
    int **iptr2 = &iptr; 

    printf("iptr: %p (size: %zu)\n", iptr, sizeof(iptr));
    printf("cptr: %p (size: %zu)\n", cptr, sizeof(cptr));
    printf("iptr2: %p, %p\n", iptr2, *iptr2);

    return 0;
}

