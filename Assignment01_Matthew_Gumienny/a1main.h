#ifndef REGISTRATION_SYSTEM_H
#define REGISTRATION_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int validateInt();
int validateSN();
void validateCourse(char *course);
void displayStudentIds(int *students, int stuNum);
void displayCourseIds(char (*courses)[8], int corsAmt);
void displayRegistrationTable(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt);
void registerStudent(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt);
void dropStudent(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt);

#endif // REGISTRATION_SYSTEM_H