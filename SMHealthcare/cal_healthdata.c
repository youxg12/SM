//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Hayoung Lee
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

/*
    Function: saveData
    Purpose: Save exercise and diet history to a file.
*/
void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (!file) {
        printf("Error: Could not open file to save health data.\n");
        return;
    }

    // Save exercise history and total calories burned
    fprintf(file, "[Exercises] \n");
    for (int i = 0; i < health_data->exercise_count; i++) {
        fprintf(file, "%s: %d kcal burned\n", health_data->exercise_history[i].name, health_data->exercise_history[i].calories);
    }
    fprintf(file, "Total Calories Burned: %d kcal\n", health_data->total_calories_burned);

    // Save diet history and total calories intake
    fprintf(file, "\n[Diets] \n");
    for (int i = 0; i < health_data->diet_count; i++) {
        fprintf(file, "%s: %d kcal consumed\n", health_data->diet_history[i].name, health_data->diet_history[i].calories);
    }
    fprintf(file, "Total Calories Intake: %d kcal\n", health_data->total_calories_intake);

    // Save total remaining calories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Remaining Calories: %d kcal\n", health_data->remaining_calories);

    fclose(file);
    printf("Health data has been saved to %s.\n", HEALTHFILEPATH);
}

/*
    Function: printHealthData
    Purpose: Print the exercise, diet history, and calorie summary.
*/
void printHealthData(const HealthData* health_data) {
    // Print exercise history
    printf("=========================== History of Exercise =======================\n");
    for (int i = 0; i < health_data->exercise_count; i++) {
        printf("%s: %d kcal burned\n", health_data->exercise_history[i].name, health_data->exercise_history[i].calories);
    }
    printf("Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    printf("=======================================================================\n");

    // Print diet history
    printf("============================= History of Diet =========================\n");
    for (int i = 0; i < health_data->diet_count; i++) {
        printf("%s: %d kcal consumed\n", health_data->diet_history[i].name, health_data->diet_history[i].calories);
    }
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    printf("=======================================================================\n");

    // Print calorie summary
    printf("============================== Total Calories =========================\n");
    printf("Basal Metabolic Rate (BMR): %d kcal\n", health_data->bmr);
    printf("Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    printf("Remaining Calories: %d kcal\n", health_data->remaining_calories);
    printf("=======================================================================\n");

    // Provide recommendation based on remaining calories
    if (health_data->remaining_calories > 0) {
        printf("Recommendation: You can consume %d more kcal today.\n", health_data->remaining_calories);
    } else {
        printf("Recommendation: Consider exercising to burn %d kcal.\n", -health_data->remaining_calories);
    }
    printf("=======================================================================\n");
}

