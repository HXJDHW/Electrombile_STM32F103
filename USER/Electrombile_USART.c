#include "electrombile_usart.h"

/**************************************
* �����ж����ȼ�����
* ˵���������ж����ȼ�����
* ʱ�䣺2017-11-9
**************************************/
void NVIC_USART_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* ���� USART Ϊ�ж�Դ */
    NVIC_InitStruct.NVIC_IRQChannel = USARTx_IRQn;
    
    /* ��ռ���ȼ�Ϊ 2 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    
    /* �����ȼ�Ϊ 2 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    
    /* ʹ���ж� */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* ��ʼ������ NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}

/**************************************
* USART1 - GPIO���ų�ʼ�� 
* ˵�������ڳ�ʼ��
* ʱ�䣺2017-11-9
**************************************/
void USARTx_Init(void)
{
    USART_InitTypeDef USART_InitStruct;
    
    USARTx_Clk();//����ʱ��ʹ��
//    USART_StructInit(&USART_InitStruct);
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
    NVIC_EnableIRQ(USART1_IRQn);   
    /* ʹ�ܴ��� */
    USART_Cmd(USARTx, ENABLE); 

}

/**************************************
* �������ж����ȼ�����
* ˵�����������ж����ȼ�����
* ʱ�䣺2017-11-16
**************************************/
void NVIC_USART_Screen_Conf(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* ���� USART Ϊ�ж�Դ */
    NVIC_InitStruct.NVIC_IRQChannel = USART_Screen_IRQn;
    
    /* ��ռ���ȼ�Ϊ 1 */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    
    /* �����ȼ�Ϊ 1 */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    
    /* ʹ���ж� */ 
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    
    /* ��ʼ������ NVIC */ 
    NVIC_Init(&NVIC_InitStruct);
}
/**************************************
* USART_Screen - ���ڳ�ʼ�� 
* ˵������ͨ�Ŵ��ڳ�ʼ��
* ʱ�䣺2017-11-16
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
    
    /* ��ʼ������ */
    USART_Init(USART_Screen, &USART_InitStruct);
    
    /* �����ж����ȼ����� */
    NVIC_USART_Screen_Conf();
    
    /* ʹ�ܴ��ڽ����ж� */
    USART_ITConfig(USART_Screen, USART_IT_RXNE, ENABLE);
    
    /* ʹ�ܴ��� */
    USART_Cmd(USART_Screen, ENABLE); 
}
    
/**************************************
* ����1���ֽڵ����� 
* ˵�������ڷ���1���ֽڵ�����
* ʱ�䣺2017-11-16
**************************************/
void USART_SendByte(USART_TypeDef* pUSARTx, uint16_t Data)
{
    //����1�ֽ�����
    USART_SendData(pUSARTx, Data);
    
    //�ȴ���ɷ���
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/**************************************
* ����ָ�����ȵ�����
* ˵�������ڷ���ָ�����ȵ�����
* ʱ�䣺2017-11-17
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
    
    //�ȴ���ɷ���
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/**************************************
* �����ַ��� 
* ˵�������ڷ����ַ���
* ʱ�䣺2017-11-16
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
    
    //�ȴ���ɷ���
    while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

/*�ض���fputc����*/
int fputc(int ch, FILE *f)
{      
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
    USART_SendData(USART1,(uint8_t)ch);   
	return ch;
}