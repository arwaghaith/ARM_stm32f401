
#ifndef __RCC_H
#define __RCC_H
/*including the necessary libraries for The RCC peripheral*/

#include  "../../LIB/STD_TYPES.h"



#include  "../../LIB/STD_TYPES.h"

/******************************************************************/


/*this enum is for  selecting RCC clk type*/  
typedef enum{
    RCC_HSI,
    RCC_HSE,
    RCC_PLL
}RCC_CLK_TYPE;

/*this enum is for  selecting the state of the clock ON or OFF*/

typedef enum{
    CLK_OFF,
    CLK_ON
}RCC_STATE;


/*this enum is for  selecting  the error status of the RCC functions*/
typedef enum{
    RCC_NOK,
    RCC_OK
}RCC_ERROR_STATUS;

/*this enum is for  selecting the bus of the peripheral*/

typedef enum{
    RCC_AHB1,
    RCC_AHB2,
    RCC_APB1,
    RCC_APB2
}RCC_PERIPHERAL_BUS_TYPE;

/*this enum is for  selecting the bus prescalar*/
typedef enum{
    RCC_AHB_SCALER,
    RCC_APB1_SCALER,
    RCC_APB2_SCALER
}RCC_PERIPHERAL_BUS_TYPE_prescalar;



     


/*this function  is  for controlling any clock in the system as ON or OFF*/
/* it takes two parameters
    * 1- clock_type: which is the clock that you want to control
    * 2- state: what is the state of the clock ON or OFF
    * it returns:
    * 1- RCC_OK: if the clock is controlled successfully
    * 2- RCC_NOK: if the clock is not controlled successfully
 */
RCC_ERROR_STATUS RCC_ControlClock(RCC_CLK_TYPE clock_type, RCC_STATE state);

/*this function is for configuring the PLL clock*/
/* it takes four parameters
    * 1- PLL_M: the value of the PLL_M  "DIVISION FACTOR"
    * 2- PLL_N: the value of the PLL_N  "MULTIPLICATION FACTOR"
    * 3- PLL_P: the value of the PLL_P  "DIVISION FACTOR"
    * 4- PLL_Q: the value of the PLL_Q  "DIVISION FACTOR"
    * it returns:
    * 1- RCC_OK: if the PLL is configured successfully
    * 2- RCC_NOK: if the PLL is not configured successfully
 */

RCC_ERROR_STATUS RCC_ConfigurePLL(uint8_t PLL_M, uint16_t PLL_N, uint8_t PLL_P, uint8_t PLL_Q);

/*this function is for selecting the system clock*/
/* it takes one parameter
    * 1- clock_type: the clock that you want to select as a system clock
    * it returns:
    * 1- RCC_OK: if the clock is selected successfully
    * 2- RCC_NOK: if the clock is not selected successfully
 */

RCC_ERROR_STATUS RCC_SelectSysClk(RCC_CLK_TYPE clock_type);

/*this function is for controlling the clock of any peripheral in the system */
/* it takes two parameters
    * 1- peripheral: the peripheral that you want to control its clock
    * 2- state: what is the state of the peripheral clock ON or OFF
    * it returns:
    * 1- RCC_OK: if the peripheral clock is controlled successfully
    * 2- RCC_NOK: if the peripheral clock is not controlled successfully
 */

RCC_ERROR_STATUS RCC_ControlPeripheralClock(RCC_PERIPHERAL_BUS_TYPE RCC_bus,uint8_t peripheral, RCC_STATE state);



/*This function is for configuring any  prescalar in the system*/

/* it takes two parameters
    * 1- peripheral: the peripheral that you want to control its clock
    * 2- prescalar: the value of the prescalar
    * it returns:
    * 1- RCC_OK: if the prescalar is configured successfully
    * 2- RCC_NOK: if the prescalar is not configured successfully
 */

RCC_ERROR_STATUS RCC_ConfigurePrescalar(RCC_PERIPHERAL_BUS_TYPE_prescalar RCC_BUS, uint32_t prescalar);
#endif
