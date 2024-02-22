#ifndef  switch_H
#define  switch_H

#include  "../../LIB/STD_TYPES.h"
#include "switchCfg.h"


typedef enum
{
    SWITCH_NOK,
    SWITCH_OK
}Switch_ErrorStatus;


/*               Switch Functions                */
/*               Switch_Init                */
/*Description: This Function is used to initialize the switch
 * Input: void
 * Output: ErrorStatus
 */
Switch_ErrorStatus Switch_Init(void);

/*               Switch_SetState                */
/*Description: This Function is used to set the state of the switch
 * Input: Channel, State
 * Output: ErrorStatus
 */
Switch_ErrorStatus Switch_SetState(Switch_ChannelType Channel, uint8_t State);


/*               Switch_GetState                */
/*Description: This Function is used to get the state of the switch
 * Input: Channel, State
 * Output: ErrorStatus
 */
Switch_ErrorStatus Switch_GetState(Switch_ChannelType Channel, uint8_t *State);



#endif