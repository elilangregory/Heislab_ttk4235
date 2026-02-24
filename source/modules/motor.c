#include "motor.h"

void new_destination(FSM *elevator){
    for (int i = 0; i < N_FLOORS; i++){
        if (elevator->destinations[i] && i > elevator->current_floor){
            elevio_motorDirection(DIRN_DOWN);
        }
        if (elevator->destinations[i] && i < elevator->current_floor){
            elevio_motorDirection(DIRN_UP);
        }
    }
}

void stop_at_boundries(FSM *elevator){
    if (elevator->current_floor == 3){
        elevio_motorDirection(DIRN_STOP);
    }
        if (elevator->current_floor == 0){
        elevio_motorDirection(DIRN_STOP);

    }
}