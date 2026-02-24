#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "../driver/elevio.h"
#include "fsm.h"

void new_destination(FSM *elevator);

void stop_at_boundries(FSM *elevator);