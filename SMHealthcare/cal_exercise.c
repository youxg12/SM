//
//  cal_exercise.c
//  Exercise for Calorie Diary
//
//  Created by Hayoung Lee
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100          // Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50   // Maximum length of the name of an exercise

// Array to store exercise information
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;

/*
    Function: loadExercises
    Purpose: Load exercise data from a file and store it in the exercise_list array.
*/
void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (!file) {
        printf("Unable to locate the exercise file. Please check the file path.\n");
        return;
    }

    char exercise_name[MAX_EXERCISE_NAME_LEN];
    int calories_burned_per_minute;

    while (fscanf(file, "%49s %d", exercise_name, &calories_burned_per_minute) == 2) {
        if (exercise_list_size < MAX_EXERCISES) {
            strncpy(exercise_list[exercise_list_size].exercise_name, exercise_name, MAX_EXERCISE_NAME_LEN - 1);
            exercise_list[exercise_list_size].exercise_name[MAX_EXERCISE_NAME_LEN - 1] = '\0'; // Null-terminate
            exercise_list[exercise_list_size].calories_burned_per_minute = calories_burned_per_minute;
            exercise_list_size++;
        } else {
            printf("Exercise list capacity reached. Unable to load more items.\n");
            break;
        }
    }

    fclose(file);
}

