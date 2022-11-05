/*
 * fsm_full.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef INC_FSM_FULL_H_
#define INC_FSM_FULL_H_

#include "button.h"
#include "fsm_button.h"
#include "timer.h"


int stateOf_FSM_FULL;
#define FSM_TIME	1000
#define COUNT_DOWN_TIME 100
#define COUNT_DOWN 	911
#define SETTING 	119
int toSETTING;

void fsm_full();

#endif /* INC_FSM_FULL_H_ */
