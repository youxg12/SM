#include <stdio.h>

int main() {
    int total_seconds, minutes, seconds;

    printf("Enter the total seconds: ");
    scanf("%d", &total_seconds);


    minutes = total_seconds / 60;  
    seconds = total_seconds % 60;  

  
    printf("The time is %d : %d\n", minutes, seconds);

    return 0;
}

