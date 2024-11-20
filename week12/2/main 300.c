#include <stdio.h>

void main(void) {
    int i = 300;          
    int *pi = &i;         
    char *pc = (char *)&i; 

    printf("i: %i\n", i);          
    printf("*pi: %i\n", *pi);      
    printf("*pc: %i\n", *pc);      
}

