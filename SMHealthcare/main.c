//
//  main.c
//  Calorie Diary
//
//  Created by Hayoung Lee
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

void inputExercise(HealthData* health_data);
void inputDiet(HealthData* health_data);

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
    // Initialize the health data object
    HealthData health_data = {0};

    // Load the list of exercises and diets
    printf("Loading exercise and diet data...\n");
    loadExercises(EXERCISEFILEPATH);
    loadDiets(DIETFILEPATH);

    do {
        // Display menu
        printf("\n=======================================================================\n");
        printf("[Healthcare Management Systems]\n");
        printf("1. Exercise\n");
        printf("2. Diet\n");
        printf("3. Show logged information\n");
        printf("4. Exit\n");
        printf("Select the desired number: ");
        scanf("%d", &choice);
        printf("=======================================================================\n");

        switch (choice) {
            case 1:
                printf("[Exercise Mode]\n");
                inputExercise(&health_data);
                break;        

            case 2:
                printf("[Diet Mode]\n");
                inputDiet(&health_data);
                break;

            case 3:
                printf("[Health Data Overview]\n");
                printHealthData(&health_data);
                break;

            case 4:
                printf("Exiting the system. Have a healthy day!\n");
                printf("=======================================================================\n");
                break;

            default:
                printf("[Error] Invalid option. Please try again!\n");
        }
    } while (choice != 4);

    // Save the health data before exiting
    saveData(HEALTHFILEPATH, &health_data);
    printf("Health data saved to %s.\n", HEALTHFILEPATH);

    return 0;
}

