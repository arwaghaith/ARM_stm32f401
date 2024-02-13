
/***************************************including the necessary libraries******************************/

/*******************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_MATH.h"
#include "RCC.h"
#include "RCC_Private.h"

/*******************************************************************************************************/

/*this function  is  for controlling any clock in the system as ON or OFF*/
/* it takes two parameters
 * 1- clock_type: which is the clock that you want to control
 * 2- state: what is the state of the clock ON or OFF
 * it returns:
 * 1- RCC_OK: if the clock is controlled successfully
 * 2- RCC_NOK: if the clock is not controlled successfully
 */
RCC_ERROR_STATUS RCC_ControlClock(RCC_CLK_TYPE clock_type, RCC_STATE state)

{

    /*defining  an error status variable */

    RCC_ERROR_STATUS loc_RCC_err_status = RCC_NOK;

    /*defining a counter variable to check the status of the clock*/
    uint32_t loc_RCC_CR_counter = 0;

    /*defining a variable to store the value of the current clock type*/
    uint32_t loc_RCC_CFGR_temp = (RCC_CFGR & RCC_CFGR_SWS_MASK) >> 2;

    /*check if the current clock type is equal to the clock type that we want to control*/

    if (loc_RCC_CFGR_temp == clock_type)
    {
        loc_RCC_err_status = RCC_NOK;
    }
    else
    {
        switch (clock_type)
        {
        case RCC_HSI:

            switch (state)
            {
            case CLK_ON:

                /*enable the HSI clock*/
                RCC_CR |= (1 << RCC_CR_HSION);
                /*check if the HSI is ready or not*/
                while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY) && loc_RCC_CR_counter < 1000000)
                {

                    loc_RCC_CR_counter++;
                }
                /*check if the HSI is ready or not*/
                if (loc_RCC_CR_counter == 1000000)
                {
                    loc_RCC_err_status = RCC_NOK;
                }
                else
                {
                    loc_RCC_err_status = RCC_OK;
                }
                loc_RCC_CR_counter = 0;

                break;
            case CLK_OFF:

                /*disable the HSI clock*/
                RCC_CR &= ~(1 << RCC_CR_HSION);

                loc_RCC_err_status = RCC_OK;
                break;
            default:
                loc_RCC_err_status = RCC_NOK;
                break;
            }

            break;
        case RCC_HSE:

            switch (state)
            {

            case CLK_ON:
                /*enable the HSE clock*/
                RCC_CR |= (1 << RCC_CR_HSEON);
                while (!GET_BIT(RCC_CR, RCC_CR_HSERDY) && loc_RCC_CR_counter < 1000000)
                {
                    loc_RCC_CR_counter++;
                }
                if (loc_RCC_CR_counter == 1000000)
                {
                    loc_RCC_err_status = RCC_NOK;
                }
                else
                {
                    loc_RCC_err_status = RCC_OK;
                    loc_RCC_CR_counter = 0;
                }
                break;
            case CLK_OFF:

                /*disable the HSE clock*/
                RCC_CR &= ~(1 << RCC_CR_HSEON);
                loc_RCC_err_status = RCC_OK;
                break;
            default:
                loc_RCC_err_status = RCC_NOK;
                break;
            }

            break;
        case RCC_PLL:

            switch (state)
            {
            case CLK_ON:

                /*enable the PLL clock*/
                RCC_CR |= (1 << RCC_CR_PLLON);

                /*checking if the PLL is ready or not*/

                while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY) && loc_RCC_CR_counter < 1000000)
                {
                    loc_RCC_CR_counter++;
                }

                /*check if the PLL is ready or not*/
                if (loc_RCC_CR_counter == 1000000)
                {
                    loc_RCC_err_status = RCC_NOK;
                }
                else
                {
                    loc_RCC_err_status = RCC_OK;
                    loc_RCC_CR_counter = 0;
                }
                break;
            case CLK_OFF:
                /*disable the PLL clock*/
                RCC_CR &= ~(1 << RCC_CR_PLLON);
                loc_RCC_err_status = RCC_OK;
                break;
            default:
                loc_RCC_err_status = RCC_NOK;
                break;
            }

            break;
        default:
            loc_RCC_err_status = RCC_NOK;
            break;
        }
    }

    return loc_RCC_err_status;
}

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

RCC_ERROR_STATUS RCC_ConfigurePLL(uint8_t PLL_M, uint16_t PLL_N, uint8_t PLL_P, uint8_t PLL_Q)
{

    /*reset the value of the PLLCFGR register*/

    RCC_PLLCFGR = RCC_PLLCFGR_RESET_VALUE;

    /*defining a variable to store the value of the PLLCFGR register*/

    uint32_t loc_RCC_PLL_CFGR_temp = RCC_PLLCFGR;

    /*check if the values of the PLL_M, PLL_N, PLL_P, PLL_Q are in the allowed range or not*/

    if ((PLL_M > 1) && (PLL_M < 64) && (PLL_N > 191) && (PLL_N < 433) && (PLL_P == 2 || PLL_P == 4 || PLL_P == 6 || PLL_P == 8) && (PLL_Q > 1) && (PLL_Q < 16))
    {

        /*assign the values of the PLL_M, PLL_N, PLL_P, PLL_Q to the PLLCFGR register*/
        loc_RCC_PLL_CFGR_temp = (loc_RCC_PLL_CFGR_temp & ~(PLL_M_MASK)) | ((PLL_M) << (RCC_PLLCFGR_PLLM_SHIFT));
        loc_RCC_PLL_CFGR_temp = (loc_RCC_PLL_CFGR_temp & ~(PLL_N_MASK)) | ((PLL_N) << (RCC_PLLCFGR_PLLN_SHIFT));
        loc_RCC_PLL_CFGR_temp = (loc_RCC_PLL_CFGR_temp & ~(PLL_P_MASK)) | ((PLL_P) << (RCC_PLLCFGR_PLLP_SHIFT));
        loc_RCC_PLL_CFGR_temp = (loc_RCC_PLL_CFGR_temp & ~(PLL_Q_MASK)) | ((PLL_Q) << (RCC_PLLCFGR_PLLQ_SHIFT));

        RCC_PLLCFGR = loc_RCC_PLL_CFGR_temp;
    }
    else
    {
        /*return an error status if the values are not in the allowed range*/
        return RCC_NOK;
    }

    return RCC_OK;
}

/*this function is for selecting the system clock*/
/* it takes one parameter
 * 1- clock_type: the clock that you want to select as a system clock
 * it returns:
 * 1- RCC_OK: if the clock is selected successfully
 * 2- RCC_NOK: if the clock is not selected successfully
 */

RCC_ERROR_STATUS RCC_SelectSysClk(RCC_CLK_TYPE clock_type)
{

    /*defining  an error status variable */
    RCC_ERROR_STATUS loc_RCC_err_status = RCC_NOK;
    /*defining a variable to store the value of the RCC_CFGR register*/

    uint32_t loc_RCC_CFGR_temp = RCC_CFGR & ~(RCC_CFGR_SW_MASK);

    /*check the value of the clock type and select the system clock*/
    switch (clock_type)

    {

    /*select the HSI clock as a system clock*/
    case RCC_HSI:

        /*check if the HSI is ready  and enabled or not*/

        if (GET_BIT(RCC_CR, RCC_CR_HSION) && GET_BIT(RCC_CR, RCC_CR_HSIRDY))
        {

            /*assign the value of the HSI clock to the RCC_CFGR register*/

            RCC_CFGR = loc_RCC_CFGR_temp | HSI_SW_MASK;
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            /*return an error status if the HSI is not ready  and enabled*/
            loc_RCC_err_status = RCC_NOK;
        }

        break;

    /*select the HSE clock as a system clock*/
    case RCC_HSE:
        /*check if the HSE is ready  and enabled or not*/
        if (GET_BIT(RCC_CR, RCC_CR_HSEON) && GET_BIT(RCC_CR, RCC_CR_HSERDY))
        {

            /*assign the value of the HSE clock to the RCC_CFGR register*/
            RCC_CFGR = loc_RCC_CFGR_temp | HSE_SW_MASK;
            /*return OK status if the HSE is ready and enabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else
        {

            /*return an error status if the HSE is not ready  and enabled*/
            loc_RCC_err_status = RCC_NOK;
        }

        break;
    case RCC_PLL:
        /*check if the PLL is ready  and enabled or not*/
        if (GET_BIT(RCC_CR, RCC_CR_PLLON) && GET_BIT(RCC_CR, RCC_CR_PLLRDY))
        {
            /*assign the value of the PLL clock to the RCC_CFGR register*/
            RCC_CFGR = loc_RCC_CFGR_temp | PLL_SW_MASK;

            /*return OK status if the HSE is ready and enabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            /*return an error status if the PLL is not ready  nor enabled*/
            loc_RCC_err_status = RCC_NOK;
        }

        break;
    default:
        loc_RCC_err_status = RCC_NOK;
        break;
    }
}

/*this function is for controlling the clock of any peripheral in the system */
/* it takes two parameters
 * 1- peripheral: the peripheral that you want to control its clock
 * 2- state: what is the state of the peripheral clock ON or OFF
 * it returns:
 * 1- RCC_OK: if the peripheral clock is controlled successfully
 * 2- RCC_NOK: if the peripheral clock is not controlled successfully
 */

RCC_ERROR_STATUS RCC_ControlPeripheralClock(RCC_PERIPHERAL_BUS_TYPE RCC_bus, uint8_t peripheral, RCC_STATE state)
{

    /*defining  an error status variable */
    RCC_ERROR_STATUS loc_RCC_err_status = RCC_NOK;

    /*check the value of the bus and control the clock of the peripheral*/
    switch (RCC_bus)
    {
    /*control the clock of the peripheral in the AHB1 bus*/
    case RCC_AHB1:
        /*check the value of the state and control the clock of the peripheral*/
        if (state == CLK_ON)
        {
            /*enable the clock of the peripheral*/
            RCC_AHB1ENR |= (1 << peripheral);

            /*return OK status if the clock is enabled*/
            loc_RCC_err_status = RCC_OK;
        }
        /*check the value of the state and control the clock of the peripheral*/
        else if (state == CLK_OFF)
        {
            /*disable the clock of the peripheral*/
            RCC_AHB1ENR &= ~(1 << peripheral);
            /*return OK status if the clock is disabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            loc_RCC_err_status = RCC_NOK;
        }
        break;
        /*control the clock of the peripheral in the AHB2 bus*/
    case RCC_AHB2:

        /*check the value of the state and control the clock of the peripheral*/
        if (state == CLK_ON)
        {
            /*enable the clock of the peripheral*/
            RCC_AHB2ENR |= (1 << peripheral);
            /*return OK status if the clock is enabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else if (state == CLK_OFF)
        {
            /*disable the clock of the peripheral*/
            RCC_AHB2ENR &= ~(1 << peripheral);
            /*return OK status if the clock is disabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            loc_RCC_err_status = RCC_NOK;
        }
        break;

    /*control the clock of the peripheral in the APB1 bus*/
    case RCC_APB1:

        /*check the value of the state and control the clock of the peripheral*/
        if (state == CLK_ON)
        {
            /*enable the clock of the peripheral*/
            RCC_APB1ENR |= (1 << peripheral);
            /*return OK status if the clock is enabled*/
            loc_RCC_err_status = RCC_OK;
        }
        else if (state == CLK_OFF)
        {
            /*disable the clock of the peripheral*/
            RCC_APB1ENR &= ~(1 << peripheral);
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            loc_RCC_err_status = RCC_NOK;
        }
        break;

    /*control the clock of the peripheral in the APB2 bus*/
    case RCC_APB2:

        /*check the value of the state and control the clock of the peripheral*/
        if (state == CLK_ON)
        {
            /*enable the clock of the peripheral*/
            RCC_APB2ENR |= (1 << peripheral);
            loc_RCC_err_status = RCC_OK;
        }
        else if (state == CLK_OFF)
        {
            /*disable the clock of the peripheral*/
            RCC_APB2ENR &= ~(1 << peripheral);
            loc_RCC_err_status = RCC_OK;
        }
        else
        {
            loc_RCC_err_status = RCC_NOK;
        }
        break;
    default:
        loc_RCC_err_status = RCC_NOK;
        break;
    }
    return loc_RCC_err_status;
}

/*This function is for configuring any  prescalar in the system*/

/* it takes two parameters
 * 1- peripheral: the peripheral that you want to control its clock
 * 2- prescalar: the value of the prescalar
 * it returns:
 * 1- RCC_OK: if the prescalar is configured successfully
 * 2- RCC_NOK: if the prescalar is not configured successfully
 */

RCC_ERROR_STATUS RCC_ConfigurePrescalar(RCC_PERIPHERAL_BUS_TYPE_prescalar RCC_BUS, uint32_t prescalar)
{

    /*defining a variable to store the value of the RCC_CFGR register*/
    uint32_t loc_RCC_CFGR_temp = RCC_CFGR;

    /*defining  an error status variable */
    RCC_ERROR_STATUS loc_RCC_err_status = RCC_NOK;

    /*check the value of the bus and configure the prescalar*/
    switch (RCC_BUS)
    {
    /*configure the prescalar of the AHB bus*/
    case RCC_AHB_SCALER:
        /*assign the value of the prescalar to the RCC_CFGR register*/
        loc_RCC_CFGR_temp = (loc_RCC_CFGR_temp & ~(RCC_HPRE_MASK)) | (prescalar << RCC_HPRE_SHIFT);

        RCC_CFGR = loc_RCC_CFGR_temp;

        loc_RCC_err_status = RCC_OK;
        break;
    case RCC_APB1_SCALER:
        /*assign the value of the prescalar to the RCC_CFGR register*/
        loc_RCC_CFGR_temp = (loc_RCC_CFGR_temp & ~(RCC_PPRE1_MASK)) | (prescalar << RCC_PPRE1_SHIFT);
        RCC_CFGR = loc_RCC_CFGR_temp;
        loc_RCC_err_status = RCC_OK;
        break;
    case RCC_APB2_SCALER:
        /*assign the value of the prescalar to the RCC_CFGR register*/
        loc_RCC_CFGR_temp = (loc_RCC_CFGR_temp & ~(RCC_PPRE2_MASK)) | (prescalar << RCC_PPRE2_SHIFT);
        RCC_CFGR = loc_RCC_CFGR_temp;
        loc_RCC_err_status = RCC_OK;
        break;
    default:
        loc_RCC_err_status = RCC_NOK;
        break;
    }
    return loc_RCC_err_status;
}
