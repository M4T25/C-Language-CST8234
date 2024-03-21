/*******************************************************************
* Student Name: Mateusz Gumienny
* Student Number: 041033057
* Course: 23F_CST8234_300 C Language
* Declaration: I declare that
* This is my own original work except where sources have been cited.
*******************************************************************/

#ifndef GUST_H
#define GUST_H

#include <stdio.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    int type;
    double prev;
    double current;
} WindGust;

void printWindGustsData(WindGust *data, int size);

#endif
