/*
 * fsm_full.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "fsm_full.h"
int stateOF_FSM_FULL = COUNT_DOWN;
void fsm_full(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(stateOF_FSM_FULL){
		case COUNT_DOWN:
			if(timer2Flag == 1){
				displayNumberOnSeg--;
				if(displayNumberOnSeg <= 0) displayNumberOnSeg = 0;
				setTimer2(COUNT_DOWN_TIME);
			}
			break;
		case SETTING:
			if(timer2Flag == 1){
				stateOF_FSM_FULL = COUNT_DOWN;
				setTimer2(COUNT_DOWN_TIME);
			}
			break;
		default:
			break;
		}
	}
}

