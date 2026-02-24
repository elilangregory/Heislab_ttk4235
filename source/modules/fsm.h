#pragma once

#include "../driver/elevio.h"
#include "order_logic.h"

typedef enum{
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPEN,
    STOP
} State;


typedef struct FSM{
    int current_floor;
    int destinations[4];
    State state;
} FSM;


void fsm_update(FSM* fsm); // takes in a reference to fsm, and it will be changed along the way. 