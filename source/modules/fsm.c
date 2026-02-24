#include <fsm.h>

void fsm_update(FSM *fsm){
    if (elevio_floorSensor() == 0 || elevio_floorSensor() == 1 || elevio_floorSensor() == 2 || elevio_floorSensor() == 3){
        fsm->current_floor = elevio_floorSensor();
        update_destinations(fsm);
    }
}