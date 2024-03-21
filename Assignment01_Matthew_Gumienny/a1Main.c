/*
* Title: Assignment #1 - Student Registration System
* Course: CST8234 C Language
* @Author: <<< Matthew Gumienny 041033057 >>>
* Lab Section: 302
* Professor: Surbhi Bahri
* Due date: 11-19-23
* Submission date: 11-19-23
*
* Demo malloc(), and free() in C, Ansi-style

* Requirement #1: {complete}
* Requirement #2: {complete}
* Requirement #3: {complete}
* Requirement #4: {complete}
* Requirement #5: {complete}
* Requirement #6: {complete}
* Requirement #7: {complete}
* Requirement #8: {complete}
* Requirement #9: {complete} 
*/

#include "a1Main.h"

int main()
{
    int stuNum;

    printf("Enter the number of students to register: ");
    stuNum = validateInt();

    int *students = (int *)malloc(stuNum * sizeof(int));

    for (int i = 0; i < stuNum; i++)
    {
        do{
            printf("Enter the student id for student at index [%d]: ", i);
            students[i] = validateSN();
        }while (students[i] == -1);

    }

    int corsAmt;

    printf("Enter number of courses available: ");
    corsAmt = validateInt();

    getchar();

    char (*courses)[8] = malloc(corsAmt * sizeof(char[8]));

    for (int i = 0; i < corsAmt; i++)
    {
        do{
            printf("Enter the course id ([3-Alphas][4-digits]) for course at index [%d]: ", i);
            validateCourse(&courses[i]);
        }while (courses[i][0] == '\0');
    }

    int **registrationTable = NULL;

    registrationTable = (int **)malloc(stuNum * sizeof(int *));
    for(int i = 0; i < stuNum;  i++) {
      registrationTable[i] = (int *)malloc(corsAmt * sizeof(int));
      for (int j = 0; j < corsAmt; j++)
        registrationTable[i][j] = 0;
    }

        int choice;

    do {
        /* Display menu */
        printf("Choose an operation:\n");
        printf("[1] Register a student into a course\n");
        printf("[2] Drop a student from a course\n");
        printf("[3] Display Registration table\n");
        printf("[4] Exit\n");
        printf("\nEnter option: ");
        fflush(stdout);

        /* Get user choice */
        while (scanf("%d", &choice) != 1) {
            printf("ERROR: Invalid input. Please enter a valid integer:\n");
            while (getchar() != '\n');
        }
    

      switch (choice) {
        case 1:
            registerStudent(registrationTable, students, stuNum, courses, corsAmt);
            break;
        case 2:
            dropStudent(registrationTable, students, stuNum, courses, corsAmt);
            break;
        case 3:
            displayRegistrationTable(registrationTable, students, stuNum, courses, corsAmt);
            break;
        case 4:
            break;
      }

    }while (choice != 4);

    free(students);
    free(courses);
    for (int i = 0; i < stuNum; i++) {
        free(registrationTable[i]);
    }
    free(registrationTable);

    return 0;
}

