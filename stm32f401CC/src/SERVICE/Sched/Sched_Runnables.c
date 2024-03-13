

#include "Sched_Runnables.h"
#include "../../HAL/LED/LED.h"



extern void Toggle_LED_GREEN(void);
extern void Toggle_LED_RED(void);
extern void Traffic_Light();
extern void Switch_GetInstant(void);
extern void SW_app();




const Runnables_t sys_Runnables[MAX_RUNNABLES]

={

       [0]={switches,10,Switch_GetInstant},
       [3]={RUNNABLE1, 5000,Toggle_LED_GREEN},
       [1]={RUNNABLE2, 10000,Toggle_LED_RED},
       [2]={TrafficLight,1000,Traffic_Light},
       [4]={SWITCH_APP,10,SW_app}

       

    
};