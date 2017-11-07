#include "main.h"



void main(void)
{
    LED_Init();
  
    while(1)
    {
        GPIO_SetBits(LED0_GPIOx, LED0_Pin);
        GPIO_ResetBits(LED1_GPIOx, LED1_Pin);
        delay(5000);
        
        
        GPIO_ResetBits(LED0_GPIOx, LED0_Pin);
        GPIO_SetBits(LED1_GPIOx, LED1_Pin);
        delay(5000);
    }
}
