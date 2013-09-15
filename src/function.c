/*
 * function.c
 *
 *  Created on: 2013-6-20
 *      Author: dragon
 */

#include "stm32f10x.h"
#include "function.h"
#include "My_usart/my_usart.h"
#include "My_delay/my_delay.h"

void function1(u8 *data)
{
	if (BufferRead(data))
	{
		while (USART_GetFlagStatus(USART2, USART_FLAG_TXE ) == RESET)
			;
		USART_SendData(USART2, *data);

		Delay(1); //延时太多，会丢失很多数据
		GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0 ));
		GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1 ));
		GPIO_WriteBit(GPIOB, GPIO_Pin_2, (BitAction) !GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_2 ));

	}

}
