/*
 * GPIO.h
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "em_gpio.h"

#define LED0_PORT gpioPortB
#define LED0_PIN  2
#define LED1_PORT gpioPortB
#define LED1_PIN  4

void init_LED0(void);
void toggleLED0(void);
