#include "order_logic.h"
#include "fsm.h"

int hall_up_buttons[4];
int hall_down_buttons[4];
int cab_buttons[4];

int destinations[4];

void add_orders(){
    for(int floor = 0; floor < N_FLOORS; floor++){
        for(int button = 0; button < N_BUTTONS; button++){
            int btnPressed = elevio_callButton(floor, button);
            if (btnPressed){
                if (button == 0){
                    hall_up_buttons[floor] = 1;
                }
                if (button == 1){
                    hall_down_buttons[floor] = 1;
                }
                if (button == 2){
                    cab_buttons[floor] = 1;
                }
            }
        }
    }
}

void remove_orders(FSM *elevator){
    if (elevator->state == IDLE){
        for (int i = 0; i < N_FLOORS; i++){
            if (elevator->current_floor == i){
                hall_up_buttons[i] = 0;
                hall_down_buttons[i] = 0;
                cab_buttons[i] = 0;
            }
        }
    }
}

void update_destinations(FSM *elevator){
    for (int i = 0; i < N_FLOORS; i++){ //Går igjennom alle cab bestillinger og legger de til destinations
        if (cab_buttons[i] == 1){
            destinations[i] = 1;
        }
        if (elevator->current_floor == i && destinations[i] == 1 && elevator->state == IDLE){ //Hvis etasjen man stopper i ligger i destinations blir den fjernet
            destinations[i] = 0;
        }
    }

    int goal = -1;

    if (elevator->state == MOVING_UP){
        for (int i = 0; i < N_FLOORS; i++){
            if (destinations[i] == 1){
                goal = i;
                break;
            }
            if ((elevator->current_floor < i && i < goal) && hall_up_buttons[i] == 1){
                destinations[i] = 1;
            }
        }
    }

    if (elevator->state == MOVING_DOWN){

        for (int i = 0; i < N_FLOORS; i++){
            if (destinations[i] == 1){
                goal = i;
                break;
            }
            if ((elevator->current_floor > i && i > goal) && hall_down_buttons[i] == 1){
                destinations[i] = 1;
            }
        }
    }
    
    for (int i = 0; i < N_FLOORS; i++){
        elevator->destinations[i] = destinations[i];
    }
}