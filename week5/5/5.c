#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two integers : ");
    scanf("%i %i", &num1, &num2);

    printf("& result : %d\n", num1 & num2);
    printf("| result : %d\n", num1 | num2);
    printf("^ result : %d\n", num1 ^ num2);


    printf("<< 1 result : %d\n", num1 << 1);  
    printf(">> 1 result : %d\n", num1 >> 1); 

    return 0;
}

