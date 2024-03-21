/*************************************
 * Name: Mateusz Gumienny
 * Student Number: 041033057
 * Assignment number: Lab2
 * Course Name: CST8234
 * Lab Section: 302
 * Prof Name: Natalie Gluzman
 * Due Date: October 08, 2023
 * Submission Date: 
 * List of sources:
 * Purpose: Prompt user to create an array then reverse, randomize or sort it
*/

#include <stdio.h>
#include <stdlib.h>

/***
 * Function Name: reverse array
 * Purpose: Function to reverse the array
 * Function In Parameters: int arr[], int length
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void reverse_array(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        /* Swap elements at positions i and length - i - 1 */
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}


/***
 * Function Name: randomize array
 * Purpose: Function to randomize the array 
 * Function In Parameters: int arr[], int length
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void randomize_array(int arr[], int length) {
    
    srandom(1964);

    for (int i = 0; i < length; i++) {
        /* Choose a random index */
        int j = random() % length;

        /* Swap elements at positions i and j */
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/***
 * Function Name: sort array
 * Purpose: Function to sort the array 
 * Function In Parameters: int arr[], int length
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void sort_array(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key*/
        /* to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/***
 * Function Name: main
 * Purpose: prompt for user input and display menu
 * Function In Parameters: N/A
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
int main() {
    int length;

    /* Get the length of the array from the user */
    printf("Enter the length:\n");

    /* Error check user input */
    while (scanf("%d", &length) != 1 || length <= 0) {
        printf("ERROR: Invalid input. Please enter a positive integer for the length:\n");
        /* Clear input buffer */
        while (getchar() != '\n');
    }

    /* Allocate memory for the array */
    int *arr = (int *)malloc(length * sizeof(int));

    /* Get array elements from the user */
    printf("Enter %d numbers (space separated):\n", length);
    for (int i = 0; i < length; i++) {
        /* Error check user input for array elements */
        while (scanf("%d", &arr[i]) != 1) {
            printf("ERROR: Invalid input. Please enter valid integers:\n");
            /* Clear input buffer */
            while (getchar() != '\n');
        }
    }

    int choice;

    do {
        /* Display menu */
        printf("Choose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");

        /* Get user choice */
        while (scanf("%d", &choice) != 1) {
            printf("ERROR: Invalid input. Please enter a valid integer:\n");
            /* Clear input buffer */
            while (getchar() != '\n');
        }

        /* Perform the chosen operation */
        switch (choice) {
            case 0:
                /* Exit the program */
                break;

            case 1:
                /* Reverse the array */
                reverse_array(arr, length);
                break;

            case 2:
                /* Randomize the array */
                randomize_array(arr, length);
                break;

            case 3:
                /* Sort the array */
                sort_array(arr, length);
                break;

            default:
                printf("Invalid choice\n");
        }

        /* Print the array after the operation */
        printf("{ ");
        for (int i = 0; i < length; i++) {
            printf("%d ", arr[i]);
        }
        printf("}\n");

    } while (choice != 0);

    /* Free allocated memory */
    free(arr);

    return 0;
}
