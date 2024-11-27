#include <stdio.h>

struct student {
    int ID;         
    char name[20];   
    float grade;     
};

int main(void) {
    struct student s1;

    s1.ID = 21;
    sprintf(s1.name, "jooyeon");
    s1.grade = 4.2;

    printf("ID: %d\n", s1.ID);
    printf("name: %s\n", s1.name);
    printf("grade: %.2f\n", s1.grade);

    return 0;
}

