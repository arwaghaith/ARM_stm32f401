
#include "../../LIB/STD_TYPES.h"
#include "switchCfg.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "switch.h"

/*               Switch Functions                */
/*               Switch_Init                */
/*Description: This Function is used to initialize the switch
 * Input: void
 * Output: ErrorStatus
 */

extern Switch_t Switches[Switch_NUM];
Switch_ErrorStatus Switch_Init(void)

{
    Switch_ErrorStatus local_Error_status = SWITCH_NOK;
    GPIO_PIN_t Switch_PIN;
    for(uint32_t i=0;i<Switch_NUM;i++)
    {
        Switch_PIN.port=Switches[i].Switch_Port;
        Switch_PIN.pin=Switches[i].Switch_Pin;
        Switch_PIN.mode=GPIO_MODE_INPUT;
        Switch_PIN.speed=GPIO_SPEED_HIGH;
        Switch_PIN.pull=Switches[i].Switch_Mode+SWITCH_PULL_OFFSET;
        Switch_PIN.value=Switches[i].Switch_State^Switches[i].Switch_State;

        local_Error_status=GPIO_Init(&Switch_PIN);

    }

    return local_Error_status;
}

        

/*               Switch_SetState                */
/*Description: This Function is used to set the state of the switch
 * Input: Channel, State
 * Output: ErrorStatus
 */
Switch_ErrorStatus Switch_SetState(Switch_ChannelType Channel, uint8_t State)
{
    Switch_ErrorStatus local_Error_status = SWITCH_NOK;
    local_Error_status=GPIO_SET_PIN_VALUE(Switches[Channel].Switch_Port,Switches[Channel].Switch_Pin,State^Switches[Channel].Switch_State);
    return local_Error_status;
}
    


/*               Switch_GetState                */
/*Description: This Function is used to get the state of the switch
 * Input: Channel, State
 * Output: ErrorStatus
 */
Switch_ErrorStatus Switch_GetState(Switch_ChannelType Channel, uint8_t *State)
{
    Switch_ErrorStatus local_Error_status = SWITCH_NOK;
    local_Error_status=GPIO_GET_PIN_VALUE(Switches[Channel].Switch_Port,Switches[Channel].Switch_Pin,State);
    return local_Error_status;
}


