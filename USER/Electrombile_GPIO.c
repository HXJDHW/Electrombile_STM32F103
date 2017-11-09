#include "electrombile_gpio.h"

/* LED -- GPIO初始化 */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
  
    LED0_GPIO_CLK();
    LED1_GPIO_CLK();
    
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

/* USART - GPIO引脚初始化 */
void USARTx_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
  
    USARTx_TX_GPIO_CLK();
    USARTx_RX_GPIO_CLK();
    
    GPIO_DeInit(USARTx_TX_GPIOx);
    GPIO_DeInit(USARTx_RX_GPIOx);

    GPIO_InitStruct.GPIO_Pin = USARTx_TX_Pin;
    GPIO_InitStruct.GPIO_Mode = USARTx_TX_Mode;
    GPIO_InitStruct.GPIO_Speed = USARTx_TX_Speed;    
    GPIO_Init(USARTx_TX_GPIOx, &GPIO_InitStruct);
    
    GPIO_InitStruct.GPIO_Pin = USARTx_RX_Pin;
    GPIO_InitStruct.GPIO_Mode = USARTx_RX_Mode;    
    GPIO_Init(USARTx_RX_GPIOx, &GPIO_InitStruct);
}