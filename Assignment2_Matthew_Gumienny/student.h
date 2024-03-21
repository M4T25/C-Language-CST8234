/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_302
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

struct student {
    int studentID;
    double percentMark;
};

void processCommandLineArguments(int argc, char *argv[], char **filename);
void readBinaryFile(const char *filename, struct student **students, int *numStudents);
int compareStudentID(const void *a, const void *b);
char *convertToLetterGrade(double percentMark);

#endif