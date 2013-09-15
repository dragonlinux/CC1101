/*
 * my_spi.c
 *
 *  Created on: 2013-8-31
 *      Author: root
 *      slave
 */

#include "stm32f10x.h"
#include "stdio.h"
#include "my_spi.h"
#include "CC1101.h"
/* 自定义同义关键字    --------------------------------------------------------*/
SPI_InitTypeDef SPI_InitStructure; /* 定义 SPI 初始化结构体 */
void SPI_RCC_Configuration(void)
{
	/* 打开 SPI2 时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
}

/*******************************************************************************
 * 函数名  		: GPIO_Configuration
 * 函数描述    	: 设置各GPIO端口功能
 * 输入参数      : 无
 * 输出结果      : 无
 * 返回值        : 无
 *******************************************************************************/
void SPI_GPIO_Configuration(void)
{
	//初始化SPI接口
//	SPI_I2S_DeInit(SPI2);

	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure SPI2 pins: SCK, MISO and MOSI ---------------------------------*/
	/* Confugure SCK and MOSI pins as Input Floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/* Confugure MISO pin as Alternate Function Push Pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/*******************************************************************************
 * 函数名  		: SPI_Configuration
 * 函数描述    	: 设置 SPI 参数
 * 输入参数      : 无
 * 输出结果      : 无
 * 返回值        : 无
 *******************************************************************************/
void SPI_Configuration(void)
{
	/*
	 *	SPI 设置为双线双向全双工
	 *  	SPI 发送接收 8 位帧结构
	 *  	时钟悬空低
	 *  	数据捕获于第二个时钟沿
	 *	内部 NSS 信号由 SSI 位控制
	 *	波特率预分频值为 4
	 *	数据传输从 LSB 位开始
	 *	用于 CRC 值计算的多项式
	 */
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master; /* 设置 SPI2 为主机*/
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);
	/* 使能 SPI2 */
	SPI_Cmd(SPI2, ENABLE);

	GPIO_SetBits( GPIOB, GPIO_Pin_12);
	GPIO_ResetBits( GPIOB, GPIO_Pin_12);
	GPIO_SetBits( GPIOB, GPIO_Pin_12);

}

/***********************************************
 * 在同一块Discovery的开发板上
 * SPI1连接SPI2，相互胡传数据。
 *
 **********************************************/
void SPI_test(void)
{

	u8 txBuffer[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	u32 x;

	SPI_RCC_Configuration();

	SPI_GPIO_Configuration();

	SPI_Configuration();

	printf("SPI_Configuration\n");
	CC1101Init();
	printf("CC1101Init\n");

	while (1)
	{
		CC2500SendPacket(txBuffer, 10);
		printf("CC2500SendPacket_out\n");
		Delay(300);
		GPIO_ResetBits( GPIOC, GPIO_Pin_8);
		Delay(300);
		GPIO_SetBits( GPIOC, GPIO_Pin_8);
//		Delay(2000);

	}
}

