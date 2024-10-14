#include <stdio.h>

int main() {
    int num, sum = 0;
    int i;  

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 1) {
        for (i = 1; i <= num; i++) {
            sum += i;  
        }

        printf("The result is %d\n", sum);
    } else {

        printf("The number should be 1 or greater.\n");
    }

    return 0;
}

