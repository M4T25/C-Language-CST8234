#include "withdraw.h"

/***
 * Function Name: drop student
 * Purpose: Function to ensure the student is registered to
 * a course then withdraw them from the course
 * Function In Parameters: int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void dropStudent(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt) {
    displayStudentIds(students, stuNum);

    int studentIdToWithdraw;
    int studentIndexW = -1;
    int foundStuW = 0;

    do {
        printf("Enter Student's Id to withdraw from a course: ");
        studentIdToWithdraw = validateInt();

        for (int i = 0; i < stuNum; i++) {
            if (studentIdToWithdraw == students[i]) {
                foundStuW = 1;
                studentIndexW = i;
                break;
            }
        }

        if (!foundStuW) {
            printf("Error: Student with ID %d not found. Please enter a valid student ID.\n", studentIdToWithdraw);
        }

    } while (!foundStuW);

    displayCourseIds(courses, corsAmt);

    char courseIdToWithdraw[8];
    int courseIndexW = -1;
    int foundCrsW = 0;

    do {
        printf("Enter Course Id to withdraw from a course: ");
        scanf("%s", courseIdToWithdraw);

        for (int i = 0; i < corsAmt; i++) {
            if (strcmp(courseIdToWithdraw, courses[i]) == 0) {
                foundCrsW = 1;
                courseIndexW = i;
                break;
            }
        }

        if (!foundCrsW) {
            printf("Error: Course with ID %s not found. Please enter a valid course ID.\n", courseIdToWithdraw);
        }

    } while (!foundCrsW);

    if (studentIndexW != -1 && courseIndexW != -1) {
        if (registrationTable[studentIndexW][courseIndexW] == 1){
        registrationTable[studentIndexW][courseIndexW] = 0;
        } else {
            printf("Error: Student %d is not registered for course %s. Cannot withdraw.\n", students[studentIndexW], courses[courseIndexW]);
        }
    }
}
