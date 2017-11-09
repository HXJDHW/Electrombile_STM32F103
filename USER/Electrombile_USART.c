#include "electrombile_usart.h"

/* 串口中断优先级配置 */
void NVIC_USART_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* 嵌套向量中断控制器组选择 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* 配置 USART 为中断源 */
    NVIC_InitStruct.NVIC_IRQChannel = USARTx_IRQn;
    
    /* 抢断优先级为 1 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    
    /* 子优先级为 1 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    
    /* 使能中断 */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* 初始化配置 NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}

/* 初始化串口 */
void USARTx_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    
    USARTx_Clk();
    
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_WordLength = USARTx_WordLength;
    USART_InitStruct.USART_StopBits = USARTx_StopBits;
    USART_InitStruct.USART_Parity = USARTx_Parity;
    USART_InitStruct.USART_Mode = USARTx_Mode;
    USART_InitStruct.USART_HardwareFlowControl = USARTx_HardwareFlowControl;
    
    /* 初始化串口 */
    USART_Init(USARTx, &USART_InitStruct);
    
    /* 串口中断优先级配置 */
    NVIC_USART_Conf();
    
    /* 使能串口接收中断 */
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
    
    /* 使能串口 */
    USART_Cmd(USARTx, ENABLE); 
}