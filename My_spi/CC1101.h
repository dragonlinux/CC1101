/*
 ================================================================================
 Copyright   : Ebyte electronic co.,LTD
 Website     : http://yh-ebyte.taobao.com
 http://yiheliyong.cn.alibaba.com
 Description : This module contains the low level operations for CC1101
 ================================================================================
 */
#ifndef _CC1101_H_
#define _CC1101_H_

#include "CC1101_REG.h"		//DO NOT modify
/*
 ================================================================================
 ------------------------------Internal IMPORT functions-------------------------
 you must offer the following functions for this module
 1. u8 SPI_ExchangeByte( u8 input ); //SPI Send and Receive function
 2. CC_CSN_LOW( );                        //Pull down the CSN line
 3. CC_CSN_HIGH( );                       //Pull up the CSN Line
 ================================================================================
 */
//#include "main.h"     //import SPI_ExchangeByte( );
#include "stm32f10x.h"
#define CC_CSN_LOW( )   GPIO_ResetBits( GPIOB, GPIO_Pin_12 );while( GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_14 ) != 0 );
#define CC_CSN_HIGH( )  GPIO_SetBits( GPIOB, GPIO_Pin_12 )

/*
 ================================================================================
 -----------------------------------macro definitions----------------------------
 ================================================================================
 */
typedef enum
{
	TX_MODE, RX_MODE
} TRMODE;

/*read a byte from the specified register*/
u8 CC1101ReadReg(u8 addr);

/*Read some bytes from the rigisters continously*/
void CC1101ReadMultiReg(u8 addr, u8 *buff, u8 size);

/*Read a status register*/
u8 CC1101ReadStatus(u8 addr);

/*Set the device as TX mode or RX mode*/
void CC1101SetTRMode(TRMODE mode);

/*Write a byte to the specified register*/
void CC1101WriteReg(u8 addr, u8 value);

/*Write some bytes to the specified register*/
void CC1101WriteMultiReg(u8 addr, u8 *buff, u8 size);

/*Write a command byte to the device*/
void CC1101WriteCmd(u8 command);

/*Reset the CC1101 device*/
void CC1101Reset(void);

/*Set the CC1101 into IDLE mode*/
void CC1101SetIdle(void);

/*Flush the TX buffer of CC1101*/
void CC1101ClrTXBuff(void);

/*Flush the RX buffer of CC1101*/
void CC1101ClrRXBuff(void);

/*Send a packet*/
void CC2500SendPacket(u8 *txbuffer, u8 size);

/*Get received count of CC1101*/
u8 CC1101GetRXCnt(void);

/*Receive a packet*/
u8 CC1101RecPacket(u8 *rxBuffer, u8 *length);

void CC1101Init(void);

u8 SPI_ExchangeByte(u8 input);

#endif // _CC1101_H_
/*
 ================================================================================
 ------------------------------------THE END-------------------------------------
 ================================================================================
 */
