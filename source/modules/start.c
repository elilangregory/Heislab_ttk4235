#include "start.h"


void initialize_floor(){
    // Get to the first floor and initialize 
    int floor = elevio_floorSensor();
    elevio_motorDirection(DIRN_DOWN);
    while (floor != 0){
        floor = elevio_floorSensor(); //Hvorfor i helvete funker ikke dette????
    }
    
    elevio_motorDirection(DIRN_STOP);

    // 3 second pause after init
    nanosleep(&(struct timespec){3, 0}, NULL);
}