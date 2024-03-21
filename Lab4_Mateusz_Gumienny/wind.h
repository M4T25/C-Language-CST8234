/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/

#ifndef WIND_MESSAGE_H
#define WIND_MESSAGE_H

#include <stdio.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    int type;
    double kmPerH;
    int degrees;
} WindSpeed;

void printWindData(WindSpeed *data, int size);
#endif