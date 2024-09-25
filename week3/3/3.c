#include <stdio.h>

int main(void) 
{
    char c;  
    
    printf("Enter a letter: ");
    scanf("%c", &c);
    
    printf("Next letter of %c is %c\n", c, c + 1);

    return 0;
}

