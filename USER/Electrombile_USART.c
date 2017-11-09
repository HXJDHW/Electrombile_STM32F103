#include "electrombile_usart.h"

/* �����ж����ȼ����� */
void NVIC_USART_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* ���� USART Ϊ�ж�Դ */
    NVIC_InitStruct.NVIC_IRQChannel = USARTx_IRQn;
    
    /* �������ȼ�Ϊ 1 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    
    /* �����ȼ�Ϊ 1 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    
    /* ʹ���ж� */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* ��ʼ������ NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}

/* ��ʼ������ */
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
    
    /* ��ʼ������ */
    USART_Init(USARTx, &USART_InitStruct);
    
    /* �����ж����ȼ����� */
    NVIC_USART_Conf();
    
    /* ʹ�ܴ��ڽ����ж� */
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
    
    /* ʹ�ܴ��� */
    USART_Cmd(USARTx, ENABLE); 
}