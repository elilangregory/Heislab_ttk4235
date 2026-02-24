#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "../driver/elevio.h"

typedef struct FSM FSM;
void add_orders();
void remove_orders(FSM *elevator);

void update_destinations(FSM *elevator);