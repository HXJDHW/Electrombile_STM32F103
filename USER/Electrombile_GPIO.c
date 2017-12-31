#include "electrombile_gpio.h"

/**************************************
* LED -- GPIO初始化
* 说明：LED灯驱动I/O口初始化
* 时间：2017-11-7
**************************************/
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

/**************************************
* USART1 - GPIO引脚初始化 
* 说明：串口初始化
* 时间：2017-11-9
**************************************/
void USARTx_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
  
    USARTx_TX_GPIO_CLK();

    GPIO_InitStruct.GPIO_Pin = USARTx_TX_Pin;
    GPIO_InitStruct.GPIO_Mode = USARTx_TX_Mode;
    GPIO_InitStruct.GPIO_Speed = USARTx_TX_Speed;
    GPIO_Init(USARTx_TX_GPIOx, &GPIO_InitStruct);
    
    GPIO_InitStruct.GPIO_Pin = USARTx_RX_Pin;
    GPIO_InitStruct.GPIO_Mode = USARTx_RX_Mode;
    GPIO_Init(USARTx_RX_GPIOx, &GPIO_InitStruct);
  
//    GPIO_InitTypeDef GPIO_InitStructure;
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//    GPIO_StructInit(&GPIO_InitStructure);
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/**************************************
* USART_Screen - GPIO引脚初始化 
* 说明：屏通信串口初始化
* 时间：2017-11-16
**************************************/
void USART_Screen_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
  
    USART_Screen_TX_GPIO_CLK();

    GPIO_InitStruct.GPIO_Pin = USART_Screen_TX_Pin;
    GPIO_InitStruct.GPIO_Mode = USART_Screen_TX_Mode;
    GPIO_InitStruct.GPIO_Speed = USART_Screen_TX_Speed;
    GPIO_Init(USART_Screen_TX_GPIOx, &GPIO_InitStruct);
    
    GPIO_InitStruct.GPIO_Pin = USART_Screen_RX_Pin;
    GPIO_InitStruct.GPIO_Mode = USART_Screen_RX_Mode;
    GPIO_Init(USART_Screen_RX_GPIOx, &GPIO_InitStruct);
}