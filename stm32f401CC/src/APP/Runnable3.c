#include "../LIB/STD_TYPES.h"
#include "../HAL/LED/LED.h"
#include "../HAL/HSWITCH/HSWITCH.h"



void SW_app()

{



             uint32_t state;
              Switch_GetState(SWITCH_1, &state);
if(state==SWITCH_PRESSED)

{
  LED_SetState(LED_BLUE,LED_ON);
}  
Switch_GetState(SWITCH_2, &state);
if(state==SWITCH_PRESSED)

{
  LED_SetState(LED_BLUE,LED_OFF);
}  

  }


