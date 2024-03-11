/*
 * This file is part of the �OS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/NVIC/NVIC.h"
#include "HAL/LED/LEDCfg.h"
#include "HAL/LED/LED.h"
#include "HAL/switch/switch.h"



// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.


int
main()
{
//   uint32_t state;
//   RCC_ControlClock(RCC_HSE,CLK_ON);
//   RCC_SelectSysClk(RCC_HSE);
//   RCC_ControlPeripheralClock(RCC_AHB1,GPIOBEN,CLK_ON);
//   RCC_ControlPeripheralClock(RCC_AHB1,GPIOCEN,CLK_ON);
//   LED_Init();
//   Switch_Init();



//   while(1)
//   {
//   Switch_GetState(SWITCH_1, &state);
// if(state==SWITCH_PRESSED)

// {
//   LED_SetState(LED_GREEN,LED_ON);
// }  
// Switch_GetState(SWITCH_2, &state);
// if(state==SWITCH_PRESSED)

// {
//   LED_SetState(LED_GREEN,LED_OFF);
// }  

//   }

RCC_ControlClock(RCC_HSE,CLK_ON);
RCC_SelectSysClk(RCC_HSE);

//NVIC_Status loc_NVIC_Status = NVIC_NOK;

LED_Init();
NVIC_INIT();


NVIC_SetPremptionPriority(DMA1_Channel1_IRQn,0b0011);
NVIC_SetSubPriority(DMA1_Channel1_IRQn,0b00111);

NVIC_EnableInterrupt(EXTI0_IRQn);

NVIC_SetPendingFlag(EXTI0_IRQn);
NVIC_EnableInterrupt(EXTI1_IRQn);

NVIC_DisableInterrupt(EXTI1_IRQn);
NVIC_DisableInterrupt(EXTI0_IRQn);



  // Infinite loop
  while (1)
    {
       // Add your code here.

    }



return 0;



}

void EXTI1_IRQHandler(void)
{
	uint8_t Local_status=2;
	uint8_t Local_status2=3;
	LED_SetState(LED_RED,LED_ON);
	NVIC_SetPendingFlag(EXTI0_IRQn);

	LED_SetState(LED_GREEN,LED_ON);

}

void EXTI0_IRQHandler(void)
{
	uint8_t Local_status=2;
	uint8_t Local_status2=3;

	LED_SetState(LED_GREEN,LED_ON);


}

// ----------------------------------------------------------------------------
