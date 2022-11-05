/*
 * fsm_button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */




#include "fsm_button.h"
int displayNumberOnSeg = 9;

void changeNum(int index){
	switch(index){
	case 0:
		displayNumberOnSeg++;
		displayNumberOnSeg %= 10;
		break;
	case 1:
		displayNumberOnSeg--;
		if(displayNumberOnSeg <= -1) displayNumberOnSeg = 9;
		break;
	case 2:
		displayNumberOnSeg = 0;
		break;
	default:
		break;
	}
}

int buttonState[NO_OF_BUTTONS] = {NORMAL_BUTTON,NORMAL_BUTTON,NORMAL_BUTTON};
int countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
void fsm_button(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonState[i]){
		case NORMAL_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 1){
					buttonState[i] = PRESS_BUTTON;
					HAL_GPIO_TogglePin(GPIOA, RED_Pin);
					stateOf_FSM_FULL = SETTING;
					setTimer2(FSM_TIME);
					changeNum(i);
					setTimer1(BUTTON_DELAY_TIME);
				}
			}
			break;
		case PRESS_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 0){
					buttonState[i] = NORMAL_BUTTON;
					countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
					setTimer1(BUTTON_DELAY_TIME);
				}
				else{
					if(countTimerForHoldEventStart <= 0){
						countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
						buttonState[i] = HOLD_BUTTON;
						changeNum(i);
						stateOf_FSM_FULL = SETTING;
						setTimer2(FSM_TIME);
						setTimer1(BUTTON_DELAY_HOLD);
					}
					else{
						countTimerForHoldEventStart--;
						setTimer1(BUTTON_DELAY_TIME);
					}
				}
			}
			break;
		case HOLD_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 0)
					buttonState[i] = NORMAL_BUTTON;
				else{
					changeNum(i);
					HAL_GPIO_TogglePin(GPIOA, RED_Pin);
					stateOf_FSM_FULL = SETTING;
					setTimer2(FSM_TIME);
					setTimer1(BUTTON_DELAY_HOLD);
				}
			}
			break;
		case CHECK_DOUBLE:
			if(isButtonPressed(i) == 1){
				buttonState[i] = DOUBLE_CLICK;
				setTimer1(BUTTON_DELAY_DOUBLE_CLICK_TIME);
			}
			if(timer1Flag == 1){

				if(isButtonPressed(i) == 0){
					buttonState[i] = NORMAL_BUTTON;
				}
					setTimer1(5);
			}
			break;
		case DOUBLE_CLICK:
			if(timer1Flag == 1){
				buttonState[i] = NORMAL_BUTTON;
				setTimer1(BUTTON_DELAY_DOUBLE_CLICK_TIME);
			}
			break;
		default:
			break;
		}
	}
}
