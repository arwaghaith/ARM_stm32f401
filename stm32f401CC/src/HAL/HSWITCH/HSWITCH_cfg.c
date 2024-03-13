#include "HSWITCH_cfg.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../LIB/STD_TYPES.h"

Switch_t Switches[Switch_NUM]=
{
    {GPIO_PORTB,GPIO_PIN0,SWITCH_PULLUP,SWITCH_RELEASED,0,SWITCH_RELEASED,SWITCH_RELEASED},
    {GPIO_PORTB,GPIO_PIN1,SWITCH_PULLUP,SWITCH_RELEASED,0,SWITCH_RELEASED,SWITCH_RELEASED},
    {GPIO_PORTB,GPIO_PIN2,SWITCH_PULLDOWN,SWITCH_PRESSED,0,SWITCH_RELEASED,SWITCH_RELEASED},
    {GPIO_PORTB,GPIO_PIN3,SWITCH_PULLDOWN,SWITCH_RELEASED,0,SWITCH_RELEASED,SWITCH_RELEASED}
};