#include "main.h"

uint16_t cmd[]={0xEE, 0x04, 0xFF, 0xFC, 0xFF, 0xFF};

void main(void)
{
    LED_Init();
    USARTx_GPIO_Init();   
    USART_Screen_GPIO_Init();
    
    USARTx_Init();
    USART_Screen_Init();
    
//    USART_SendString(USARTx, "xdfhhdgfj\n");
//    for(int i = 0; i < 6; i++)
//    {
//        USART_SendByte(USARTx, cmd[i]);
//    }
    printf("ÎÒ°®Äã£¬ºÎÐ¡½¿");
//    USARTx_SendData(USART_Screen, cmd, 6);
//    USARTx_SendData(USARTx, cmd, 6);

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
