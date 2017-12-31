#ifndef __ELECTROMBILE_COMMON_H
#define __ELECTROMBILE_COMMON_H

#include "stm32f10x.h"

/* LED0--GPIO端口宏定义 */
#define LED0_GPIO_CLK()   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define LED0_GPIOx      GPIOB
#define LED0_Pin        GPIO_Pin_5
#define LED0_Mode       GPIO_Mode_Out_PP
#define LED0_Speed      GPIO_Speed_10MHz

/* LED1--GPIO端口宏定义 */
#define LED1_GPIO_CLK()   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE)
#define LED1_GPIOx      GPIOE
#define LED1_Pin        GPIO_Pin_5
#define LED1_Mode       GPIO_Mode_Out_PP
#define LED1_Speed      GPIO_Speed_10MHz

/* USART1 -- GPIO端口宏定义 */
/* USART1 -- TX -- PA9*/
#define USARTx_TX_GPIO_CLK()  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)
#define USARTx_TX_GPIOx      GPIOA
#define USARTx_TX_Pin        GPIO_Pin_9
#define USARTx_TX_Mode       GPIO_Mode_AF_PP
#define USARTx_TX_Speed      GPIO_Speed_10MHz

/* USART1 -- RX -- PA10*/
#define USARTx_RX_GPIO_CLK()   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)
#define USARTx_RX_GPIOx      GPIOA
#define USARTx_RX_Pin        GPIO_Pin_10
#define USARTx_RX_Mode       GPIO_Mode_IN_FLOATING

#define USARTx    USART1
#define USARTx_IRQHandler       USART1_IRQHandler
#define USARTx_IRQn             USART1_IRQn
#define USARTx_Clk()            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE)
#define USARTx_WordLength       USART_WordLength_8b
#define USARTx_StopBits         USART_StopBits_1
#define USARTx_Parity           USART_Parity_No
#define USARTx_Mode             (USART_Mode_Rx|USART_Mode_Tx)
#define USARTx_HardwareFlowControl      USART_HardwareFlowControl_None

/* USART2 -- GPIO端口宏定义 */
/* USART2 -- TX -- PA2*/
#define USART_Screen_TX_GPIO_CLK()      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)
#define USART_Screen_TX_GPIOx           GPIOA
#define USART_Screen_TX_Pin             GPIO_Pin_2
#define USART_Screen_TX_Mode            GPIO_Mode_AF_PP
#define USART_Screen_TX_Speed           GPIO_Speed_10MHz

/* USART2 -- RX -- PA3*/
#define USART_Screen_RX_GPIO_CLK()      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)
#define USART_Screen_RX_GPIOx           GPIOA
#define USART_Screen_RX_Pin             GPIO_Pin_3
#define USART_Screen_RX_Mode            GPIO_Mode_IN_FLOATING

#define USART_Screen    USART2
#define USART_Screen_IRQHandler         USART2_IRQHandler
#define USART_Screen_IRQn               USART2_IRQn
#define USART_Screen_Clk()              RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE)
#define USART_Screen_WordLength         USART_WordLength_8b
#define USART_Screen_StopBits           USART_StopBits_1
#define USART_Screen_Parity             USART_Parity_No
#define USART_Screen_Mode               (USART_Mode_Rx|USART_Mode_Tx)
#define USART_Screen_HardwareFlowControl      USART_HardwareFlowControl_None

void delay(uint32_t n);

#endif /* __ELECTROMBILE_COMMON_H */