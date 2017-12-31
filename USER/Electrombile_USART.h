#ifndef __ELECTROMBILE_USART_H
#define __ELECTROMBILE_USART_H

#include "stm32f10x.h"
#include "electrombile_common.h"
#include "stm32f10x_usart.h"
#include "stdio.h"

void NVIC_USART_Conf(void);

void USARTx_Init(void);

void NVIC_USART_Screen_Conf(void);

void USART_Screen_Init(void);

void USART_SendByte(USART_TypeDef* pUSARTx, uint16_t Data);

void USART_SendString(USART_TypeDef* pUSARTx, char* str);

void USARTx_SendData(USART_TypeDef* pUSARTx, uint16_t* data, uint16_t Length);

#endif /* __ELECTROMBILE_USART_H */