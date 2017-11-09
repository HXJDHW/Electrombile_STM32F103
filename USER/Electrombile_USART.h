#ifndef __ELECTROMBILE_USART_H
#define __ELECTROMBILE_USART_H

#include "stm32f10x.h"
#include "electrombile_common.h"

void NVIC_USART_Conf(void);

void USARTx_Init(void);

#endif /* __ELECTROMBILE_USART_H */