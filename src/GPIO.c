/*
 * GPIO.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/GPIO.h"

void init_LED0(void)
{

  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, false);

}

void toggleLED0(void)
{
  GPIO_PinOutToggle(LED0_PORT,LED0_PIN);
}


