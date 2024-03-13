#include "../LIB/STD_TYPES.h"
#include "../HAL/LED/LED.h"
#define G_Y  6
#define Y_G 2
#define R_Y 20
#define Y_R 2

typedef enum{

    GREEN,
    YELLOW,
    RED

}LIGHTS;

void Traffic_Light()
{

    static LIGHTS current_Light=GREEN;
        static LIGHTS Prev_Light=YELLOW;

     static uint8_t traffic_counter=0;

      

    switch (current_Light)
    {
        case GREEN:
        if(traffic_counter==G_Y)
        {
        current_Light=YELLOW;
        Prev_Light=GREEN;
        LED_SetState(LED_yellow,LED_ON);
        LED_SetState(LED_RED,LED_OFF);
        LED_SetState(LED_GREEN,LED_OFF);




        traffic_counter=0;
        }
        break;
        case YELLOW:
        if(Prev_Light==GREEN && traffic_counter==Y_R)
        {
        current_Light=RED;
        
        LED_SetState(LED_RED,LED_ON);
         LED_SetState(LED_yellow,LED_OFF);
        LED_SetState(LED_GREEN,LED_OFF);


        traffic_counter=0;
                Prev_Light=YELLOW;

        }
        else if (Prev_Light==RED && traffic_counter==Y_G)
        {
              current_Light=GREEN;
        
        LED_SetState(LED_GREEN,LED_ON);
         LED_SetState(LED_yellow,LED_OFF);
        LED_SetState(LED_RED,LED_OFF);
                        traffic_counter=0;
                                Prev_Light=YELLOW;


        }

        
        break;
        case RED:
        if(traffic_counter==R_Y)
        {
        current_Light=YELLOW;
        Prev_Light=RED;
        LED_SetState(LED_yellow,LED_ON);
          LED_SetState(LED_RED,LED_OFF);
         LED_SetState(LED_GREEN,LED_OFF);

        traffic_counter=0;
        }
        
        break;
        default:
        break;
      
        }


    
    traffic_counter++;
}



        



        
  



