#include "registration.h"

/***
 * Function Name: register student
 * Purpose: Function to prompt for and accept student ids and course ids
 * Function In Parameters: int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void registerStudent(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt) {

    displayStudentIds(students, stuNum);

    int studentIdToRegister;
    int studentIndex = -1;
    int foundStu = 0;

    do {
        printf("Enter Student's Id to register to a course: ");
        studentIdToRegister = validateInt();

        for (int i = 0; i < stuNum; i++) {
            if (studentIdToRegister == students[i]) {
                foundStu = 1;
                studentIndex = i;
                break;
            }
        }

        if (!foundStu) {
            printf("Error: Student with ID %d not found. Please enter a valid student ID.\n", studentIdToRegister);
        }

    } while (!foundStu);

    displayCourseIds(courses, corsAmt);

    char courseIdToRegister[8];
    int courseIndex = -1;
    int foundCrs = 0;

    do {
        printf("Enter Course Id to register to a course: ");
        scanf("%s", courseIdToRegister);

        for (int i = 0; i < corsAmt; i++) {
            if (strcmp(courseIdToRegister, courses[i]) == 0) {
                foundCrs = 1;
                courseIndex = i;
                break;
            }
        }

        if (!foundCrs) {
            printf("Error: Course with ID %s not found. Please enter a valid course ID.\n", courseIdToRegister);
        }

    } while (!foundCrs);

    if (studentIndex != -1 && courseIndex != -1) {
        registrationTable[studentIndex][courseIndex] = 1;
    }
}
