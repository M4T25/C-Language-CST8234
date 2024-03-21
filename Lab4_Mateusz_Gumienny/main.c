/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/

#include "main.h"


int main() {
    char buffer[100]; /* A buffer to store each line of data from the file */
    char *token; /* Used to tokenize the input data */
    char *tokenFt; /* Used to store the timestamp token separately */
    int type; /* Used to determine the type of data */

    int temp_count = 0, wind_count = 0, gust_count = 0; /* Counters for each data type */
    Temperature temps[MAX_LENGTH]; /* Array to store temperature data */
    WindSpeed winds[MAX_LENGTH]; /* Array to store wind data */
    WindGust gusts[MAX_LENGTH]; /* Array to store wind gust data */

    /* Read data from the file line by line */
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        tokenFt = strtok(buffer, ",");
        token = strtok(NULL, ",");
        type = atoi(token);

        /* Check the type of data and process accordingly */
        if (type == 1) {
            /* Temperature data */
            temps[temp_count].timestamp = (time_t)atol(tokenFt);
            temps[temp_count].type = type;
            token = strtok(NULL, ",");
            temps[temp_count].celsius = atof(token);
            temp_count++;
        } else if (type == 2) {
            /* Wind Speed data */
            winds[wind_count].timestamp = (time_t)atol(tokenFt);
            winds[wind_count].type = type;
            token = strtok(NULL, ",");
            winds[wind_count].kmPerH = atof(token);
            token = strtok(NULL, ",");
            winds[wind_count].degrees = atoi(token);
            wind_count++;
        } else if (type == 3) {
            /* Wind gust data */
            gusts[gust_count].timestamp = (time_t)atol(tokenFt);
            gusts[gust_count].type = type;
            token = strtok(NULL, ",");
            gusts[gust_count].prev = atof(token);
            token = strtok(NULL, ",");
            gusts[gust_count].current = atof(token);
            gust_count++;
        }
    }

    

    /* Print the collected data */
    printTempData(temps, temp_count);
    printf("\n");
    printWindData(winds, wind_count);
    printf("\n");
    printWindGustsData(gusts, gust_count);

    return 0;
}