#include "display.h"

/***
 * Function Name: display student ids
 * Purpose: Function to display list of student ids
 * Function In Parameters: int *students, int stuNum
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void displayStudentIds(int *students, int stuNum) {
    printf("List of student Ids\n");
    for (int i = 0; i < stuNum; i++) {
        printf("Index %d         %d\n", i, students[i]);
    }
}

/***
 * Function Name: display course ids
 * Purpose: Function to display list of course ids
 * Function In Parameters: char (*courses)[8], int corsAmt
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void displayCourseIds(char (*courses)[8], int corsAmt) {
    printf("List of available Course Ids\n");
    for (int i = 0; i < corsAmt; i++) {
        printf("Index %d         %s\n", i, courses[i]);
    }
}

/***
 * Function Name: display registration table
 * Purpose: Function to display the registration table
 * Function In Parameters: int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void displayRegistrationTable(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt) {
    printf("\n***************** Registration Table ************************");
    printf("\n\t%-20s|", "Student Id");

    for (int i = 0; i < corsAmt; i++) {
        printf("%-10s|", courses[i]);
    }

    for (int i = 0; i < stuNum; i++) {
        printf("\n\t%-20d ", students[i]);
        for (int j = 0; j < corsAmt; j++) {
            if (registrationTable[i][j] == 1)
                printf("%-12s", " Yes");
            else
                printf("%-12s", " No");
        }
    }

    printf("\n");
}

