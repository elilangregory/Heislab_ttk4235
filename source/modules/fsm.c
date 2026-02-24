#include "fsm.h"

void fsm_update(FSM *fsm){
    fsm->current_floor = elevio_floorSensor();
    update_destinations(fsm);
}