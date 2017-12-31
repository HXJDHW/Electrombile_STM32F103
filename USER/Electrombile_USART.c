#include "electrombile_usart.h"

/**************************************
* 串口中断优先级配置
* 说明：串口中断优先级配置
* 时间：2017-11-9
**************************************/
void NVIC_USART_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* 嵌套向量中断控制器组选择 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* 配置 USART 为中断源 */
    NVIC_InitStruct.NVIC_IRQChannel = USARTx_IRQn;
    
    /* 抢占优先级为 2 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    
    /* 子优先级为 2 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    
    /* 使能中断 */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* 初始化配置 NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}

/**************************************
* USART1 - GPIO引脚初始化 
* 说明：串口初始化
* 时间：2017-11-9
**************************************/
void USARTx_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    
    USARTx_Clk();//串口时钟使能
//    USART_StructInit(&USART_InitStruct);
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
    NVIC_EnableIRQ(USART1_IRQn);   
    /* 使能串口 */
    USART_Cmd(USARTx, ENABLE); 

}

/**************************************
* 屏串口中断优先级配置
* 说明：屏串口中断优先级配置
* 时间：2017-11-16
**************************************/
void NVIC_USART_Screen_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* 嵌套向量中断控制器组选择 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* 配置 USART 为中断源 */
    NVIC_InitStruct.NVIC_IRQChannel = USART_Screen_IRQn;
    
    /* 抢占优先级为 1 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    
    /* 子优先级为 1 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    
    /* 使能中断 */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* 初始化配置 NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}
/**************************************
* USART_Screen - 串口初始化 
* 说明：屏通信串口初始化
* 时间：2017-11-16
**************************************/
void USART_Screen_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    
    USART_Screen_Clk();
    
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_WordLength = USART_Screen_WordLength;
    USART_InitStruct.USART_StopBits = USART_Screen_StopBits;
    USART_InitStruct.USART_Parity = USART_Screen_Parity;
    USART_InitStruct.USART_Mode = USART_Screen_Mode;
    USART_InitStruct.USART_HardwareFlowControl = USART_Screen_HardwareFlowControl;
    
    /* 初始化串口 */
    USART_Init(USART_Screen, &USART_InitStruct);
    
    /* 串口中断优先级配置 */
    NVIC_USART_Screen_Conf();
    
    /* 使能串口接收中断 */
    USART_ITConfig(USART_Screen, USART_IT_RXNE, ENABLE);
    
    /* 使能串口 */
    USART_Cmd(USART_Screen, ENABLE); 
}
    
/**************************************
* 发送1个字节的数据 
* 说明：串口发送1个字节的数据
* 时间：2017-11-16
**************************************/
void USART_SendByte(USART_TypeDef* pUSARTx, uint16_t Data)
{
    //发送1字节数据
    USART_SendData(pUSARTx, Data);
    
    //等待完成发送
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/**************************************
* 发送指定长度的数据
* 说明：串口发送指定长度的数据
* 时间：2017-11-17
**************************************/
void USARTx_SendData(USART_TypeDef* pUSARTx, uint16_t* data, uint16_t Length)
{
    unsigned int k = 0;
    
    USART_GetFlagStatus(pUSARTx,USART_FLAG_TC);
    do
    {
        USART_SendByte(pUSARTx, *(data + k));
        k++;
    }while(k < Length);
    
    //等待完成发送
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/**************************************
* 发送字符串 
* 说明：串口发送字符串
* 时间：2017-11-16
**************************************/
void USART_SendString(USART_TypeDef* pUSARTx, char* str)
{
    unsigned int k;
    
    USART_GetFlagStatus(pUSARTx,USART_FLAG_TC);
    do
    {
        USART_SendByte(pUSARTx, *(str + k));
        k++;
    }while(*(str + k) != '\0');
    
    //等待完成发送
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/*重定义fputc函数*/
int fputc(int ch, FILE *f)
{      
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
    USART_SendData(USART1,(uint8_t)ch);   
	return ch;
}