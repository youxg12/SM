#include <stdio.h>

int main() {
    int num1, num2;
    int sum, sub, mul, div, mod;

    printf("Enter two integers (e.g., 3 5): ");
    scanf("%i %i", &num1, &num2);

    sum = num1 + num2;  
    sub = num1 - num2;  
    mul = num1 * num2; 
    
    if (num2 != 0) {
        div = num1 / num2; 
        mod = num1 % num2;  
        printf("+ result : %d + %d = %d\n", num1, num2, sum);
        printf("- result : %d - %d = %d\n", num1, num2, sub);
        printf("* result : %d * %d = %d\n", num1, num2, mul);
        printf("/ result : %d / %d = %d\n", num1, num2, div);
        printf("%% result : %d %% %d = %d\n", num1, num2, mod);
    } else {
        printf("+ result: %d + %d = %d\n", num1, num2, sum);
        printf("- result: %d - %d = %d\n", num1, num2, sub);
        printf("* result: %d * %d = %d\n", num1, num2, mul);
        printf("/ result: Cannot divide by 0!\n");
        printf("%% result: Cannot calculate remainder with 0!\n");
    }

    return 0;
}

