#include <stdio.h>

int main(void) 
{
    int a, b;  
    float result;  

    printf("Enter two integers (a b): ");
    scanf("%d %d", &a, &b);

    if (b != 0) {
        result = (float) a / (float) b;
        
        printf("The result of %d / %d is: %f\n", a, b, result);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }

    return 0; 
}

