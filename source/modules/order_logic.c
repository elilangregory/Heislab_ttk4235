#include <order_logic.h>

int hall_up_buttons[4];
int hall_down_buttons[4];
int cab_buttons[4];

List destinations;
list_init(destinations);

void add_orders(){
    while(1){
        int current_floor = elevio_floorSensor();
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
}

int get_current_direction(){
    int actual_direction;
    int current_floor = elevio_floorSensor();
    if (list_get(&destinations, 0) - current_floor >= 0){
        int actual_direction = 1;
    }
    else{
        int actual_direction = -1;
    }
    return actual_direction;

}

void prioritize_orders(){
    int current_floor = elevio_floorSensor();
    int wanted_direction;

    for (int i = 0; i < N_FLOORS; i++){
        if (cab_buttons[i] == 1){
            list_push_front(&destinations, i);
        }

        int current_direction = get_current_direction();

        if (hall_up_buttons[i] == 1){

            if (i - current_floor >= 0){
                int wanted_direction = 1;
            }
            else{
                int wanted_direction = -1;
            }
            
            if (current_direction == wanted_direction && i < abs(list_get(&destinations, 0) - current_floor)){
                list_push_front(&destinations, i);
            }
            else{
                list_push_back(&destinations, i);
            }
        }
    }
}