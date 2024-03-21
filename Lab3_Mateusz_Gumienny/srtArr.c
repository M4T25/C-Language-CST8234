#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/***
 * Function Name: sort array
 * Purpose: Function to sort the 2D array 
 * Function In Parameters: int** arr, int rows, int cols
 * Function Out Parameters: N/A
 * Version: 3
 * Author: Mateusz Gumienny
****************/

void sort_array(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int key = arr[i][j];
            int k = j - 1;

            /* Move elements of arr[i][0..j-1] that are greater than key*/
            /* to one position ahead of their current position */
            while (k >= 0 && arr[i][k] > key) {
                arr[i][k + 1] = arr[i][k];
                k = k - 1;
            }
            arr[i][k + 1] = key;
        }
    }
}