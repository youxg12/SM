#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer : ");
    scanf("%i", &num);

    if (num > 0) {
        printf("This is positive number.\n");
    } else if (num < 0) {
        printf("This is negative number.\n");
    } else {
        printf("This is 0.\n");
    }

    return 0;
}

