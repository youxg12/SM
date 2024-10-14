#include <stdio.h>

int main() {
    int num;
    
    printf("Enter an integer: ");
    scanf("%i", &num);

    if (num < 0) {
        num = -num;  
    }

    printf("%i\n", num);

    return 0;
}

