/*
 * I2C.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/I2C.h"
#include <em_cmu.h>

void clockToI2C0()
{

  //Wait for oscillator to set up before returning
  //by setting third argument to "true"
  CMU_OscillatorEnable(cmuClock_I2C0,true,true);

  CMU_ClockSelectSet(cmuClock_I2C0, cmuSelect_SYSCLK);

}

void init_I2C0()
{



}
