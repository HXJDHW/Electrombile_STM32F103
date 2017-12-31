#ifndef __ELECTROMBILE_GPIO_H
#define __ELECTROMBILE_GPIO_H

#include "stm32f10x.h"
#include "electrombile_common.h"

void LED_Init(void);
void USARTx_GPIO_Init(void);
void USART_Screen_GPIO_Init(void);

#endif /* __ELECTROMBILE_COMMON_H */