
#include "GPIO_private.h"
#include "GPIO.h"
#include  "../../LIB/STD_TYPES.h"

#include "../../LIB/STD_MATH.h"



uint32_t* GPIO_PORT[3] =
{
   (volatile uint32_t*)GPIOA_BASE_ADDRESS,
    (volatile uint32_t*)GPIOB_BASE_ADDRESS,
    (volatile uint32_t*)GPIOC_BASE_ADDRESS
};

GPIO_Error_t GPIO_Init(GPIO_PIN_t *GPIO_PIN)
{

    GPIO_Error_t local_Error_status = GPIO_NOK;
 
   uint32_t temp=0;

    if(GPIO_PIN->port <= GPIO_PORTC && GPIO_PIN->port>=GPIO_PORTA)
    {
       
        if((GPIO_PIN->port==GPIO_PORTC && GPIO_PIN->pin>=GPIO_PIN13 && GPIO_PIN->pin<=GPIO_PIN15) || (GPIO_PIN->port!=GPIO_PORTC && GPIO_PIN->pin<=GPIO_PIN15 && GPIO_PIN->pin>=GPIO_PIN0))
        {
            if(GPIO_PIN->mode<=GPIO_MODE_ANALOG && GPIO_PIN->mode >=GPIO_MODE_INPUT)
            {
                
                temp=*((GPIO_PORT[GPIO_PIN->port]+GPIO_MODER_OFFSET));
                temp&=~(GPIO_MODER_MASK<<((GPIO_PIN->pin)*GPIO_MODER_BITS));
                temp|=(GPIO_PIN->mode<<((GPIO_PIN->pin)*GPIO_MODER_BITS));
                *(((GPIO_PORT[GPIO_PIN->port])+GPIO_MODER_OFFSET))=temp;
              
            }
            else
            {
                local_Error_status=GPIO_NOK;
            }

            if(GPIO_PIN->speed<=GPIO_SPEED_HIGH && GPIO_PIN->speed >=GPIO_SPEED_LOW)
            {
                temp=*((GPIO_PORT[GPIO_PIN->port]+GPIO_OSPEEDR_OFFSET));
                temp&=~(GPIO_OSPEEDR_MASK<<((GPIO_PIN->pin)*GPIO_OSPEEDR_BITS));
                temp|=(GPIO_PIN->speed<<((GPIO_PIN->pin)*GPIO_OSPEEDR_BITS));
                *(((GPIO_PORT[GPIO_PIN->port])+GPIO_OSPEEDR_OFFSET))=temp;
            }
            else
            {
                local_Error_status=GPIO_NOK;
            }

            if(GPIO_PIN->mode ==GPIO_MODE_INPUT  &&GPIO_PIN->pull<=GPIO_PUPDR_NO_PULL && GPIO_PIN->pull >=GPIO_PUPDR_PULL_DOWN)
            {
                temp=*((GPIO_PORT[GPIO_PIN->port]+GPIO_PUPDR_OFFSET));
                temp&=~(GPIO_PUPDR_MASK<<((GPIO_PIN->pin)*GPIO_PUPDR_BITS));
                temp|=(GPIO_PIN->pull<((GPIO_PIN->pin)*GPIO_PUPDR_BITS));

                *(((GPIO_PORT[GPIO_PIN->port])+GPIO_PUPDR_OFFSET))=temp;
            }
            else if (GPIO_PIN->mode ==GPIO_MODE_OUTPUT  &&GPIO_PIN->pull<=GPIO_OUTPUT_TYPE_PUSH_PULL && GPIO_PIN->pull >=GPIO_OUTPUT_TYPE_OPEN_DRAIN)
            {
                temp=*((GPIO_PORT[GPIO_PIN->port]+GPIO_PUPDR_OFFSET));
                temp&=~(GPIO_PUPDR_MASK<<((GPIO_PIN->pin)*GPIO_PUPDR_BITS));
                temp|=((GPIO_PIN->pull-GPIO_OUTPUT_OFFSET)<<((GPIO_PIN->pin)*GPIO_PUPDR_BITS));
                *(((GPIO_PORT[GPIO_PIN->port])+GPIO_PUPDR_OFFSET))=temp;
            }
            else
            
            {
                local_Error_status=GPIO_NOK;
            }
        }
        else
        {
            local_Error_status=GPIO_NOK;
        }
    }
    else
    {
        local_Error_status=GPIO_NOK;
    }
    
    return local_Error_status;
}

            

GPIO_Error_t GPIO_SET_PIN_VALUE(uint32_t port, uint32_t pin, uint32_t value)
{
    GPIO_Error_t local_Error_status = GPIO_NOK;
    

    if(port <= GPIO_PORTC && port>=GPIO_PORTA)
    {
        if((port==GPIO_PORTC && pin>=GPIO_PIN13 && pin<=GPIO_PIN15) || (port!=GPIO_PORTC && pin<=GPIO_PIN15 && pin>=GPIO_PIN0))
        {
            if(GPIO_GETMODE(port,pin,&value)==GPIO_OK)
            {
                if(value==GPIO_MODE_OUTPUT)
                {
                   *(uint32_t *) (GPIO_PORT[port]+GPIO_ODR_OFFSET+pin*GPIO_ODR_BITS)=value;
                    local_Error_status=GPIO_OK;
                }
                else
                {
                    local_Error_status=GPIO_NOK;
                }

        }
        else
        {
            local_Error_status=GPIO_NOK;
        }
    }
    else
    {
        local_Error_status=GPIO_NOK;
    }
}
    return local_Error_status;

}


           




GPIO_Error_t GPIO_GET_PIN_VALUE(uint32_t port, uint32_t pin, uint32_t *value)

{
    GPIO_Error_t local_Error_status = GPIO_NOK;
    if(port <= GPIO_PORTC && port>=GPIO_PORTA)
    {
        if((port==GPIO_PORTC && pin>=GPIO_PIN13 && pin<=GPIO_PIN15) || (port!=GPIO_PORTC && pin<=GPIO_PIN15 && pin>=GPIO_PIN0))
        {
           *value=*(uint32_t *) (GPIO_PORT[port]+GPIO_IDR_OFFSET+pin*GPIO_IDR_BITS);
            local_Error_status=GPIO_OK;
        }
        else
        {
            local_Error_status=GPIO_NOK;
        }
    }
    else
    {
        local_Error_status=GPIO_NOK;
    }
    return local_Error_status;
   



}
GPIO_Error_t GPIO_GETMODE(uint32_t port, uint32_t pin, uint32_t *mode)
{
    GPIO_Error_t local_Error_status = GPIO_NOK;
    if(port <= GPIO_PORTC && port>=GPIO_PORTA)
    {
        if((port==GPIO_PORTC && pin>=GPIO_PIN13 && pin<=GPIO_PIN15) || (port!=GPIO_PORTC && pin<=GPIO_PIN15 && pin>=GPIO_PIN0))
        {
          *mode=(GPIO_PORT[port]+GPIO_MODER_OFFSET) && ~(GPIO_MODER_MASK<<((pin)*GPIO_MODER_BITS))>>((pin)*GPIO_MODER_BITS);
            local_Error_status=GPIO_OK;
        }
        else
        {
            local_Error_status=GPIO_NOK;
        }
    }
    else
    {
        local_Error_status=GPIO_NOK;
    }
    return local_Error_status;
}