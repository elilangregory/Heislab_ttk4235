#include "lights.h"


void ignite_stop(){
    //Stoppknapp lyser ved stoppknapp trykket eller obstruksjon på
    if (elevio_stopButton()){
        elevio_stopLamp(1);
    }
    else if (elevio_obstruction()){
        elevio_stopLamp(1);
    }
    else{
        elevio_stopLamp(0);
    }
}

void ignite_floor_indicator(){
    int floor = elevio_floorSensor();
    if (floor != -1){
        elevio_floorIndicator(floor);
    }
}

void open_and_close_doors(FSM *elevator){
    if (elevator->state == IDLE){
        elevio_doorOpenLamp(1);
    }
    if (elevator->state != IDLE){
        elevio_doorOpenLamp(0);
    }
}

void ignite_elevator_panel(FSM *elevator){
    for(int floor = 0; floor < N_FLOORS; floor++){
        for(int button = 0; button < N_BUTTONS; button++){
            int btnPressed = elevio_callButton(floor, button);
            if(btnPressed){
                elevio_buttonLamp(floor, button, 1);
            }
            if(elevator->state == IDLE && elevator->current_floor != -1){
                elevio_buttonLamp(elevator->current_floor, button, 0);
            }
        }
    }
}