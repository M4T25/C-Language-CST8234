/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/

#include "temp.h"

/***
 * Function Name: print gusts data
 * Purpose: to format the timestamp to a readable date and time, then print the information
 * Function In Parameters: Temperature *data, int size
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void printTempData(Temperature *data, int size) {
    int i;
    printf("Date      Time      Celsius\n"); /* Print header */

    /* Iterate through the Temperature structure */
    for (i = 0; i < size; i++) {
        struct tm *tm_info;
        char date_time[20];
        tm_info = localtime(&data[i].timestamp);

        /* Format the timestamp to a readable date and time */
        strftime(date_time, 20, "%Y/%m/%d %H:%M:%S", tm_info);

        /* Print the date, time, and Celsius temperature with two decimal places */
        printf("%s %.2f\n", date_time, data[i].celsius);
    }
}