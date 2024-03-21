/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/

#include "gust.h"

/***
 * Function Name: print gusts data
 * Purpose: to format the timestamp to a readable date and time, then print the information
 * Function In Parameters: WindGust *data, int size
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void printWindGustsData(WindGust *data, int size) {
    int i;
    printf("Date       Time     Wind Change\n"); /* Print header */

    /* Iterate through the WindGust structure */
    for (i = 0; i < size; i++) {
        struct tm *tm_info;
        char date_time[20];
        tm_info = localtime(&data[i].timestamp);

        /* Format the timestamp to a readable date and time */
        strftime(date_time, 20, "%Y/%m/%d %H:%M:%S", tm_info);

        /* Determine and print wind change */
        if (data[i].prev < data[i].current) {
            printf("%s Increasing\n", date_time);
        } else if (data[i].prev > data[i].current) {
            printf("%s Decreasing\n", date_time);
        } else {
            printf("%s Unchanged\n", date_time);
        }
    }
}