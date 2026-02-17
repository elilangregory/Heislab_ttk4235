#include <lights.h>


void ignite_stop(){
    while (1){
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
}

void ignite_floor_indicator(){
    while(1){
        int floor = elevio_floorSensor();
        elevio_floorIndicator(floor);
    }
}

void ignite_elevator_panel(){
    while(1){
        int floor_goal = get_floor_goal();
        int current_floor = elevio_floorSensor();

        for(int floor = 0; floor < N_FLOORS; floor++){
            for(int button = 0; button < N_BUTTONS; button++){
                int btnPressed = elevio_callButton(floor, button);
                if(btnPressed){
                    elevio_buttonLamp(floor, button, 1);
                }
            }
        }
    }
}