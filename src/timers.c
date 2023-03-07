/*
 * timers.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/timers.h"
#include "src/adxl343.h"

#include <em_timer.h>
#include <em_cmu.h>

#include <assert.h>

#define ONE_SEC_PERIOD_LOAD_VAL   (39000000)

void init_timer0(void)
{
  CMU_ClockEnable(cmuClock_TIMER0, true);

  TIMER_Init_TypeDef timer0_config = TIMER_INIT_DEFAULT;

  //Do no enable on init
  timer0_config.enable=false;

  //Down-counting
  timer0_config.mode=timerModeDown;

  TIMER_Init(TIMER0,&timer0_config);

  TIMER_TopSet(TIMER0,ONE_SEC_PERIOD_LOAD_VAL);

  TIMER_Enable(TIMER0,true);

  //Clear any interrupt flags that are being used, then set them
  TIMER_IntClear(TIMER0, TIMER_IEN_UF);
  TIMER_IntEnable(TIMER0, TIMER_IEN_UF);

  NVIC_ClearPendingIRQ(TIMER0_IRQn);
  NVIC_EnableIRQ(TIMER0_IRQn);

}

