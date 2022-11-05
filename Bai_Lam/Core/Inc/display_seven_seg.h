/*
 * led_senven_seg.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef INC_DISPLAY_SEVEN_SEG_H_
#define INC_DISPLAY_SEVEN_SEG_H_

#include "main.h"

int index_led;
void display7SEG(int num);
void update7SEG(int index);
void updateBuffer7SEG();

#endif /* INC_DISPLAY_SEVEN_SEG_H_ */
