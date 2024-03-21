#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registerStudent(int **registrationTable, int *students, int stuNum, char (*courses)[8], int corsAmt);

#endif // REGISTRATION_H