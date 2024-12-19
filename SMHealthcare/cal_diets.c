//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Hayoung LEE
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100       			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food

// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;

/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

    while (fscanf(file, "%49s %d", diet_list[diet_list_size].name, &diet_list[diet_list_size].calories) == 2) {
        diet_list_size++;
        if (diet_list_size >= MAX_DIETS) {
            break;
        }
    }

    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    if (diet_list_size == 0) {
        printf("No diets available. Please load diets first.\n");
        return;
    }

    int choice, i;

    // Display the list of available diets
    printf("The list of diets:\n");
    for (i = 0; i < diet_list_size; i++) {
        printf("%d. %s (%d calories)\n", i + 1, diet_list[i].name, diet_list[i].calories);
    }
    printf("0. Exit\n");

    // Prompt the user for a choice
    while (1) {
        printf("Select a diet by entering the corresponding number: ");
        if (scanf("%d", &choice) != 1 || choice < 0 || choice > diet_list_size) {
            printf("Invalid choice. Try again.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting diet selection.\n");
            return;
        }

        // Add the selected diet to health data
        strcpy(health_data->diet_name, diet_list[choice - 1].name);
        health_data->calories += diet_list[choice - 1].calories;

        printf("You selected: %s (%d calories).\n", diet_list[choice - 1].name, diet_list[choice - 1].calories);
        break;
    }
}

