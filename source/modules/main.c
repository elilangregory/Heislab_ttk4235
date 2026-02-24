#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "lights.h"
#include "fsm.h"
#include "start.h"
#include "motor.h"


int main(){
    elevio_init();

    initialize_floor();

    while (1){
        printf("%d\n", elevio_floorSensor());

        FSM elevator = {0, {0,0,0,0}, IDLE}; //Initialiserer og oppdaterer heisen (inkl. destinations)
        fsm_update(&elevator);

        stop_at_boundries(&elevator);

        ignite_elevator_panel(&elevator); //Skrur på lys-funksjonene
        ignite_floor_indicator();
        ignite_stop();

        open_and_close_doors(&elevator); //Skrur på dør-funksjonen

        //Skrur på funksjon for å stoppe heisen hvis den går for høyt eller lavt
        //(selv om den egt ikke skal gjøre det)

        add_orders();
        remove_orders(&elevator);

        for (int i = 0; i < N_FLOORS; i++){
            if (elevator.destinations[i] && elevator.current_floor == i){ //Hvis vi er på riktig stopp, stopp heisen
                elevator.state = IDLE; //Setter heisen i pause-modus
                elevio_motorDirection(0);
                nanosleep(&(struct timespec){3}, NULL); //Stopper i 3 sekunder
                new_destination(&elevator); //Finner neste destinasjon og går dit
                break;
            }
        }
        nanosleep(&(struct timespec){0, 10*1000*1000}, NULL);
    }
}


/*
int main(){
    elevio_init();
    
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    while(1){
        printf("%d\n", elevio_floorSensor());
        int floor = elevio_floorSensor();

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
*/