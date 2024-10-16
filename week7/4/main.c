#include <stdio.h>

int factorial(int num) {
    int res = 1;
    int i;  
    for (i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int get_integer() {
    int input;
    printf("Enter the value: ");
    scanf("%d", &input);
    return input;
}

int main(void) {
    int n = get_integer(); 
    int r = get_integer(); 

    int result = combination(n, r);
    printf("The result of C(%d, %d) is %d\n", n, r, result);

    return 0;
}

