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
    for (int exercise_index = 0; exercise_index < health_data->exercise_count; exercise_index++) { // 'i'를 'exercise_index'로 변경
        fprintf(file, "%s: %d kcal burned\n", health_data->exercises[exercise_index].exercise_name, health_data->exercises[exercise_index].calories_burned_per_minute);
    }
    fprintf(file, "Total Calories Burned: %d kcal\n", health_data->total_calories_burned);

    // Save diet history and total calories intake
    fprintf(file, "\n[Diets] \n");
    for (int diet_index = 0; diet_index < health_data->diet_count; diet_index++) { // 'i'를 'diet_index'로 변경
        fprintf(file, "%s: %d kcal consumed\n", health_data->diet[diet_index].food_name, health_data->diet[diet_index].calories_intake);
    }
    fprintf(file, "Total Calories Intake: %d kcal\n", health_data->total_calories_intake);

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
    for (int exercise_index = 0; exercise_index < health_data->exercise_count; exercise_index++) { // 'i'를 'exercise_index'로 변경
        printf("%s: %d kcal burned\n", health_data->exercises[exercise_index].exercise_name, health_data->exercises[exercise_index].calories_burned_per_minute);
    }
    printf("Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    printf("=======================================================================\n");

    // Print diet history
    printf("============================= History of Diet =========================\n");
    for (int diet_index = 0; diet_index < health_data->diet_count; diet_index++) { // 'i'를 'diet_index'로 변경
        printf("%s: %d kcal consumed\n", health_data->diet[diet_index].food_name, health_data->diet[diet_index].calories_intake);
    }
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    printf("=======================================================================\n");

    // Print calorie summary
    printf("============================== Total Calories =========================\n");
    printf("Basal Metabolic Rate (BMR): %d kcal\n", BASAL_METABOLIC_RATE);
    printf("Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    printf("Remaining Calories: %d kcal\n", DAILY_CALORIE_GOAL - health_data->total_calories_intake + health_data->total_calories_burned);
    printf("=======================================================================\n");

    // Provide recommendation based on remaining calories
    int remaining_calories = DAILY_CALORIE_GOAL - health_data->total_calories_intake + health_data->total_calories_burned;
    if (remaining_calories > 0) {
        printf("Recommendation: You can consume %d more kcal today.\n", remaining_calories);
    } else {
        printf("Recommendation: Consider exercising to burn %d kcal.\n", -remaining_calories);
    }
    printf("=======================================================================\n");
}

