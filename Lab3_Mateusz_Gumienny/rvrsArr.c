#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/***
 * Function Name: reverse array
 * Purpose: Function to reverse the 2D array
 * Function In Parameters: int** arr, int rows, int cols
 * Function Out Parameters: N/A
 * Version: 4
 * Author: Mateusz Gumienny
****************/

void reverse_array(int **arr, int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            /* Swap elements at positions (i, j) and (rows - i - 1, j) */
            int temp = arr[i][j];
            arr[i][j] = arr[rows - i - 1][j];
            arr[rows - i - 1][j] = temp;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            /* Swap elements at positions (i, j) and (i, cols - j - 1) */
            int temp = arr[i][j];
            arr[i][j] = arr[i][cols - j - 1];
            arr[i][cols - j - 1] = temp;
        }
    }
}