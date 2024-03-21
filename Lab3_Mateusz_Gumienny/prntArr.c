#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/***
 * Function Name: print array
 * Purpose: Function to print the 2D array 
 * Function In Parameters: int** arr, int rows, int cols
 * Function Out Parameters: N/A
 * Version: 2
 * Author: Mateusz Gumienny
****************/

void print_array(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}