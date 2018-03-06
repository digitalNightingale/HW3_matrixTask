/*
*  Matrix Task Processor
*  Based on Operating Systems: Three Easy Pieces by R. Arpaci-Dusseau and A. Arpaci-Dusseau
*
*  Assignment 3 code
*  Program operates on tasks submitted to the tasks_input directory
*  Results are created in the tasks_output directory
*
*  A bounded buffer is used to store pending tasks
*  A producer thread reads tasks from the tasks_input directory
*  Consumer threads perform tasks in parallel
*  Program is designed to run as a daemon (i.e. forever) until receiving a request to exit.
*
*  This program mimics the client/server processing model without the use of any networking constructs.
*
*  Wes J. Lloyd
*  University of Washington, Tacoma
*  TCSS 422 - Operating Systems
*  Spring 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "matrix.h"
#include "tasks.h"
#include "pcMatrix.h"

int main (int argc, char * argv[])
{
    // Uncomment to see example operation of the readtasks() routine
    //readtasks((void *)100);

    // Uncomment to see example operation of the dotasks() routine
    //dotasks((void *) NULL);

    /******************
    *   Task 5 Done   *
    *******************/
    int sleepIntervalDefalt = 500; // if user dose not input duration

    if (argc == 2 && argv[1] >= 0)
    {
        sleepIntervalDefalt = atoi(argv[1]);
    }

    /**************************
    *   Task 10 and 11 Done   *
    ***************************/
    // To do
    // Use pthreads
    pthread_t p1;
    // Create one pthread for readtasks()
    pthread_create(&p1, NULL, readtasks, sleepIntervalDefalt);

    // Create one or more pthreads for dotasks()
    pthread_create(&p1, NULL, dotasks, sleepIntervalDefalt);

    pthread_join(p1, NULL);

    return 0;
}
