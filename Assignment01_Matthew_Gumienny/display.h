#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayStudentIds(int *students, int stuNum);
void displayCourseIds(char (*courses)[8], int corsAmt);
void displayRegistrationTable(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt);

#endif // DISPLAY_H