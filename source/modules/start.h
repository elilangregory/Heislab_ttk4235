#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"


void initialize_floor(){
    // 
    int floor = elevio_floorSensor();
    
    // Get to the first floor and initialize 

    if (floor != 0){
        elevio_motorDirection(DIRN_DOWN);
    }

    if (floor == 0){
        // 3 second pause after init
        nanosleep(&(struct timespec){3, 0}, NULL);
    }
    // Need to add logic for not accepting any orders before initialisiation. 
}