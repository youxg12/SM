#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    int result;

    printf("Enter the calculayion (e.g. 2+5): ");
    scanf("%d %c %d", &num1, &op, &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            break;
        default:
            printf("Error: Unsupported operator '%c'\n", op);
            return 1;
    }

    printf("= %d\n", result);

    return 0;
}

