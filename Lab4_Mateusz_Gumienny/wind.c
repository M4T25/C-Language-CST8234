/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/
#include "wind.h"

/***
 * Function Name: print gusts data
 * Purpose: to format the timestamp to a readable date and time, then print the information
 * Function In Parameters: WindSpeed *data, int size
 * Function Out Parameters: N/A
 * Version: 1
 * Author: Mateusz Gumienny
****************/
void printWindData(WindSpeed *data, int size) {
    int i;
    printf("Date      Time      Speed Direction\n"); /* Print header */
    
    /* Iterate through the WindSpeed structure */
    for (i = 0; i < size; i++) {
        struct tm *tm_info;
        char date_time[20];
        tm_info = localtime(&data[i].timestamp);
        
        /* Format the timestamp to a readable date and time */
        strftime(date_time, 20, "%Y/%m/%d %H:%M:%S", tm_info);
        
        /* Print the date, time, wind speed with two decimal places, and wind direction */
        printf("%s %.2f %d\n", date_time, data[i].kmPerH, data[i].degrees);
    }
}