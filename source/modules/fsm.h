#include "elevio.h"

typedef enum{
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOOR_OPEN,
    STOP
} State;


typedef struct{

    int current_floor;
    MotorDirection direction;
    State state;

} FSM;


void fsm_update(FSM* fsm); // takes in a reference to fsm, and it will be changed along the way. 

