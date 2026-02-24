#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "../driver/elevio.h"
#include "fsm.h"

void ignite_stop();
void ignite_floor_indicator();
void open_and_close_doors(FSM *elevator);
void ignite_elevator_panel(FSM *elevator);