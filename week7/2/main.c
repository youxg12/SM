#include <stdio.h>

int sumTwo(int a, int b) {
    return a + b;
}

int square(int n) {
    return n * n;
}
int get_max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int a, b;

    printf("Enter the integers: ");
    scanf("%d %d", &a, &b);

    int sum = sumTwo(a, b);      
    int sq_a = square(a);        
    int sq_b = square(b);        
    int max_val = get_max(a, b); 

    printf("result - sum: %d, square: %d, max: %d\n", sum, sq_a, max_val);

    return 0;
}

