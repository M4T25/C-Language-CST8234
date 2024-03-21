#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/***
 * Function Name: randomize array
 * Purpose: Function to randomize the 2D array 
 * Function In Parameters: int** arr, int rows, int cols
 * Function Out Parameters: N/A
 * Version: 3
 * Author: Mateusz Gumienny
****************/

void randomize_array(int **arr, int rows, int cols) {
    srandom(1964);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            /* Choose a random index */
            int random_row = random() % rows;
            int random_col = random() % cols;

            /* Swap elements at positions (i, j) and (random_row, random_col) */
            int temp = arr[i][j];
            arr[i][j] = arr[random_row][random_col];
            arr[random_row][random_col] = temp;
        }
    }
}