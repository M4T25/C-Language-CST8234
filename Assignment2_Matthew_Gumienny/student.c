/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_302
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/

#include "student.h"

/***
 * Function Name: process command line arguments
 * Purpose: Processes command line arguments to ensure the correct number is provided.
 * Sets the filename pointer to the specified filename.
 * Function In Parameters: int argc, char *argv[], char **filename
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void processCommandLineArguments(int argc, char *argv[], char **filename) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    *filename = argv[1];
}

/***
 * Function Name: read binary file
 * Purpose: Reads a binary file with student data, allocates memory for students, and populates the structure.
 * Closes the file after reading.
 * Function In Parameters: const char *filename, struct student **students, int *numStudents
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void readBinaryFile(const char *filename, struct student **students, int *numStudents) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *numStudents = fileSize / sizeof(struct student);
    *students = (struct student *)malloc(fileSize);

    if (!*students) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    fread(*students, sizeof(struct student), *numStudents, file);
    fclose(file);
}

/***
 * Function Name: compare student id
 * Purpose: Compares two students based on their student ID for sorting purposes.
 * Function In Parameters: const void *a, const void *b
 * Function Out Parameters: (struct student *)a)->studentID - ((struct student *)b)->studentID
 * Version: 1
 * Author: Mateusz Gumienny
****************/
int compareStudentID(const void *a, const void *b) {
    return ((struct student *)a)->studentID - ((struct student *)b)->studentID;
}

/***
 * Function Name: convert to letter grade
 * Purpose: Converts a percentage mark to a corresponding letter grade. Uses standard grading scale with '+' and '-'.
 * Function In Parameters: double percentMark
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
char* convertToLetterGrade(double percentMark) {
    if (percentMark >= 90.0) {
        return "A+";
    } else if (percentMark >= 85.0) {
        return "A";
    } else if (percentMark >= 80.0) {
        return "A-";        
    } else if (percentMark >= 77.0) {
        return "B+";    
    } else if (percentMark >= 73.0) {
        return "B";            
    } else if (percentMark >= 70.0) {
        return "B-";
    } else if (percentMark >= 67.0) {
        return "C+";
    } else if (percentMark >= 63.0) {
        return "C";
    } else if (percentMark >= 60.0) {
        return "C-";
    } else if (percentMark >= 57.0) {
        return "D+";
    } else if (percentMark >= 53.0) {
        return "D";
    } else if (percentMark >= 50.0) {
        return "D-";
    } else {
        return "F";
    }
}