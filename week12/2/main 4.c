#include <stdio.h>

void main(void) {
    int i = 4;         
    int *pi = &i;      
    char *pc = (char *)&i; 

    printf("%i, %i, %i\n", i, *pi, *pc); 
}

