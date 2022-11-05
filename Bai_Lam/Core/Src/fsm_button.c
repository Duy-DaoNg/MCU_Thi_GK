/*
 * fsm_button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */




#include "fsm_button.h"
int displayNumberOnSeg = 9;
/* changeNum(): Change Value display on 7-seg LED */
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
/* buttonState: buffer for saving buttons State*/
int buttonState[NO_OF_BUTTONS] = {NORMAL_BUTTON,NORMAL_BUTTON,NORMAL_BUTTON};
/* countTimerForHoldEventStart ratio to make sure button is Pressed 3s */
int countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
void fsm_button(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonState[i]){
		case NORMAL_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 1){
					buttonState[i] = PRESS_BUTTON;
					/*toSETTING is variable to change FSM_FULL state*/
					toSETTING = SETTING;
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
					/*reset Value countTimerForHoldEventStart*/
					countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
					setTimer1(BUTTON_DELAY_TIME);
				}
				else{
					if(countTimerForHoldEventStart <= 0){
						/*reset Value countTimerForHoldEventStart*/
						countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
						buttonState[i] = HOLD_BUTTON;
						changeNum(i);
						toSETTING = SETTING;
						setTimer2(FSM_TIME);
						setTimer1(BUTTON_DELAY_HOLD);
					}
					else{
						/*	Timer is set flag every 50ms,
						 *  so in this case, countTimerForHoldEventStart = 60 to make sure button
						 *  must be pressed 3s to change state to long_press state
						 */
						countTimerForHoldEventStart--;
						setTimer1(BUTTON_DELAY_TIME);
					}
				}
			}
			break;
		case HOLD_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 0){
					buttonState[i] = NORMAL_BUTTON;
					setTimer1(BUTTON_DELAY_TIME);
				}
				else{
					changeNum(i);
					toSETTING = SETTING;
					setTimer2(FSM_TIME);
					setTimer1(BUTTON_DELAY_HOLD);
				}
			}
			break;
		default:
			break;
		}
	}
}
