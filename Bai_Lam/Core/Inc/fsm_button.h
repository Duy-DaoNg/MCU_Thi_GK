/*
 * fsm_button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_
#include "button.h"
#include "timer.h"
#include "fsm_full.h"
//Global
#define NORMAL_BUTTON 	101
#define PRESS_BUTTON 	102
#define HOLD_BUTTON 	103
#define CHECK_DOUBLE	104
#define DOUBLE_CLICK	105
#define SEMI_PRESS_BUTTON 10
int displayNumberOnSeg;
int buttonState[NO_OF_BUTTONS];
////////////////
#define BUTTON_DELAY_TIME 5
#define BUTTON_DELAY_HOLD 100
#define BUTTON_DELAY_CHECK_DOUBLE_TIME 30
#define BUTTON_DELAY_DOUBLE_CLICK_TIME 20
void fsm_button();

#endif /* INC_FSM_BUTTON_H_ */
