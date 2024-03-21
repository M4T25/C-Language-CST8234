/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_302
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/

#include "student.h"

int main(int argc, char *argv[]) {
    int i = 0;
    char *filename;
    processCommandLineArguments(argc, argv, &filename);

    /* Read binary file and store data in an array*/
    struct student *students;
    int numStudents;
    readBinaryFile(filename, &students, &numStudents);

    /* Sort the data using qsort*/
    qsort(students, numStudents, sizeof(struct student), compareStudentID);

    /* Print sorted student data*/
    printf("Sorted Student Data:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student ID: %d, Percent Mark: %.2lf, Letter Grade: %s\n",
               students[i].studentID, students[i].percentMark, convertToLetterGrade(students[i].percentMark));
    }

    /* Calculate average and median numeric grade*/
    double totalMarks = 0.0;
    for (i = 0; i < numStudents; i++) {
        totalMarks += students[i].percentMark;
    }

    double average = totalMarks / numStudents;

    /* Calculate median numeric grade*/
    double median;
    if (numStudents % 2 == 0) {
        median = (students[numStudents / 2 - 1].percentMark + students[numStudents / 2].percentMark) / 2.0;
    } else {
        median = students[numStudents / 2].percentMark;
    }

    printf("\nMedian Percent Mark: %.2lf\n", median);
    printf("Average Percent Mark: %.2lf\n", average);

    /* Free allocated memory*/
    free(students);

    return 0;
}