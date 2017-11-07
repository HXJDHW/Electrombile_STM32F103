#ifndef __ELECTROMBILE_COMMON_H
#define __ELECTROMBILE_COMMON_H

#include "stm32f10x.h"

/* LED0--GPIO端口宏定义 */
#define LED0_CLK        RCC_APB2Periph_GPIOB
#define LED0_GPIOx      GPIOB
#define LED0_Pin        GPIO_Pin_5
#define LED0_Mode       GPIO_Mode_Out_PP
#define LED0_Speed      GPIO_Speed_10MHz

/* LED1--GPIO端口宏定义 */
#define LED1_CLK        RCC_APB2Periph_GPIOE
#define LED1_GPIOx      GPIOE
#define LED1_Pin        GPIO_Pin_5
#define LED1_Mode       GPIO_Mode_Out_PP
#define LED1_Speed      GPIO_Speed_10MHz


void delay(uint32_t n);

#endif /* __ELECTROMBILE_COMMON_H */