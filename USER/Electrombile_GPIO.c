#include "electrombile_gpio.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
  
    RCC_APB2PeriphClockCmd(LED0_CLK, ENABLE);
    RCC_APB2PeriphClockCmd(LED1_CLK, ENABLE);
    
    GPIO_DeInit(LED0_GPIOx);
    GPIO_DeInit(LED1_GPIOx);

    GPIO_InitStruct.GPIO_Pin = LED0_Pin;
    GPIO_InitStruct.GPIO_Mode = LED0_Mode;
    GPIO_InitStruct.GPIO_Speed = LED0_Speed;    
    GPIO_Init(LED0_GPIOx, &GPIO_InitStruct);
    
    GPIO_InitStruct.GPIO_Pin = LED1_Pin;
    GPIO_InitStruct.GPIO_Mode = LED1_Mode;
    GPIO_InitStruct.GPIO_Speed = LED1_Speed;    
    GPIO_Init(LED1_GPIOx, &GPIO_InitStruct);
}