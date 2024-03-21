/*************************************
 * Name: Mateusz Gumienny
 * Student Number: 041033057
 * Assignment number: Lab3
 * Course Name: CST8234
 * Lab Section: 302
 * Prof Name: Kaur Harleen 
 * Due Date: October 22, 2023
 * Submission Date: October 22, 2023
 * List of sources:
 * Purpose: Prompt user to create a 2D array then reverse, randomize, sort or print it
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

/***
 * Function Name: main
 * Purpose: prompt for user input and display menu
 * Function In Parameters: N/A
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/

int main() {
    int rows, cols;

    /* Get the dimensions of the array from the user */
    printf("Enter the number of rows:\n");
    while (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("ERROR: Invalid input. Please enter a valid integer for the number of rows:\n");
        while (getchar() != '\n');
    }

    do{
    printf("Enter the number of columns:\n");
    } while (scanf("%d", &cols) != 1 || cols <= 0 || cols != rows);


    /* Allocate memory for the 2-D array */
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    /* Get array elements from the user */
    printf("Enter %d x %d numbers (space separated):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (scanf("%d", &arr[i][j]) != 1) {
                printf("ERROR: Invalid input. Please enter valid integers:\n");
                while (getchar() != '\n');
            }
        }
    }

    print_array(arr, rows, cols);

    int choice;

    do {
        /* Display menu */
        printf("Choose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");
        printf("(4) : print array\n");

        /* Get user choice */
        while (scanf("%d", &choice) != 1) {
            printf("ERROR: Invalid input. Please enter a valid integer:\n");
            while (getchar() != '\n');
        }

        /* Perform the chosen operation */
        switch (choice) {
            case 0:
                /* Exit the program */
                break;

            case 1:
                /* Reverse the array */
                reverse_array(arr, rows, cols);
                print_array(arr, rows, cols);
                break;

            case 2:
                /* Randomize the array */
                randomize_array(arr, rows, cols);
                print_array(arr, rows, cols);
                break;

            case 3:
                /* Sort the array */
                sort_array(arr, rows, cols);
                print_array(arr, rows, cols);
                break;

            case 4:
                /* Print the array */
                print_array(arr, rows, cols);
                break;

            default:
                printf("Invalid choice\n");
        }


    } while (choice != 0);

    /* Free allocated memory */
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}