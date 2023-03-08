/*
 * SPI.c
 *
 *  Created on: Mar 7, 2023
 *      Author: erich
 */
#include "src/SPI.h"

#include <em_usart.h>
//#include <em_usart_init_sync.h>
#include <em_cmu.h>

void init_usart0(void)
{
  GPIO_PinModeSet(gpioPortC,1, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC,2, gpioModeInput, 0);
  GPIO_PinModeSet(gpioPortC,0, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC,3, gpioModePushPull, 0);

  //Route USART0 to pins
  GPIO->USARTROUTE[0].CSROUTE = (GPIO->USARTROUTE[0].CSROUTE & ~_GPIO_USART_CSROUTE_MASK)
                            | (gpioPortC << _GPIO_USART_CSROUTE_PORT_SHIFT
                            | (0 << _GPIO_USART_CSROUTE_PIN_SHIFT));
  GPIO->USARTROUTE[0].TXROUTE = (GPIO->USARTROUTE[0].TXROUTE & ~_GPIO_USART_TXROUTE_MASK)
                            | (gpioPortC << _GPIO_USART_TXROUTE_PORT_SHIFT
                            | (1 << _GPIO_USART_TXROUTE_PIN_SHIFT));
  GPIO->USARTROUTE[0].RXROUTE = (GPIO->USARTROUTE[0].RXROUTE & ~_GPIO_USART_RXROUTE_MASK)
                            | (gpioPortC << _GPIO_USART_RXROUTE_PORT_SHIFT
                            | (2 << _GPIO_USART_RXROUTE_PIN_SHIFT));
  GPIO->USARTROUTE[0].CLKROUTE = (GPIO->USARTROUTE[0].CLKROUTE & ~_GPIO_USART_CLKROUTE_MASK)
                            | (gpioPortC << _GPIO_USART_CLKROUTE_PORT_SHIFT
                            | (3 << _GPIO_USART_CLKROUTE_PIN_SHIFT));
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_CSPEN | GPIO_USART_ROUTEEN_TXPEN |
                                GPIO_USART_ROUTEEN_RXPEN | GPIO_USART_ROUTEEN_CLKPEN;

  CMU_ClockEnable(cmuClock_USART0,true);

  USART_InitSync_TypeDef usart0_spi_config = USART_INITSYNC_DEFAULT;

  usart0_spi_config.enable = usartDisable;
  //MSB first
  usart0_spi_config.msbf = true;

  USART_InitSync(USART0,&usart0_spi_config);

  USART_Enable(USART0, usartEnable);
}

