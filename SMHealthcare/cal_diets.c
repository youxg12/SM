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

#define MAX_DIETS 100               // Maximum number of diets
#define MAX_FOOD_NAME_LEN 50        // Maximum length of the name of food

// List of diets
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;

/*
    description: read the information in "diets.txt"
*/
void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("[Error] Failed to open the file '%s'. Ensure the file exists.\n", DIETFILEPATH);
        return;
    }

    while (fscanf(file, "%49s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) == 2) {
        diet_list_size++;
        if (diet_list_size >= MAX_DIETS) {
            printf("[Warning] Maximum number of diets (%d) reached. Some diets were not loaded.\n", MAX_DIETS);
            break;
        }
    }

    fclose(file);
    printf("[Info] Successfully loaded %d diets from '%s'.\n", diet_list_size, DIETFILEPATH);
}

/*
    description: enter the selected diet and the total calories intake in the health data
    input parameters: health_data - data object to which the selected diet and its calories are added 
    return value: None
*/
void inputDiet(HealthData* health_data) {
    if (diet_list_size == 0) {
        printf("[Error] No diets available. Please load diets first.\n");
        return;
    }

    int choice;

    // Display the list of available diets
    printf("\nAvailable diets:\n");
    for (int i = 0; i < diet_list_size; i++) {
        printf("%d. %s (%d calories)\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake);
    }
    printf("0. Exit\n");

    // Prompt the user for a choice
    while (1) {
        printf("Select a diet by entering the corresponding number: ");
        if (scanf("%d", &choice) != 1 || choice < 0 || choice > diet_list_size) {
            printf("[Error] Invalid choice. Please enter a number between 0 and %d.\n", diet_list_size);
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting diet selection.\n");
            return;
        }

        // Add the selected diet to health data
        if (health_data->diet_count >= MAX_DIETS) {
            printf("[Error] Cannot add more diets. Maximum limit reached.\n");
            return;
        }

        // Copy the selected diet's data to health_data
        strncpy(health_data->diet[health_data->diet_count].food_name, diet_list[choice - 1].food_name, MAX_FOOD_NAME_LEN - 1);
        health_data->diet[health_data->diet_count].food_name[MAX_FOOD_NAME_LEN - 1] = '\0'; // Ensure null termination
        health_data->diet[health_data->diet_count].calories_intake = diet_list[choice - 1].calories_intake;

        // Update health data
        health_data->diet_count++;
        health_data->total_calories_intake += diet_list[choice - 1].calories_intake;

        printf("You selected: %s (%d calories).\n", diet_list[choice - 1].food_name, diet_list[choice - 1].calories_intake);
        break;
    }
}

