/*
 ================================================================================
 Copyright   : Ebyte electronic co.,LTD
 Website     : http://yh-ebyte.taobao.com
 http://yiheliyong.cn.alibaba.com
 Description : This module contains the low level operations for CC1101
 ================================================================================
 */
#include "CC1101.h"

#define halRfWriteReg CC1101WriteReg
#define TI_CC_SPIWriteReg CC1101WriteReg
void halRfWriteRfSettings(void)
{
	// Write register settings, 433m ,250k
	/*  TI_CC_SPIWriteReg(CCxxx0_IOCFG2,   0x06); // GDO2 output pin config.
	 TI_CC_SPIWriteReg(CCxxx0_IOCFG0,   0x06); // GDO0 output pin config.
	 TI_CC_SPIWriteReg(CCxxx0_PKTLEN,   0xFF); // Packet length.
	 TI_CC_SPIWriteReg(CCxxx0_PKTCTRL1, 0x05); // Packet automation control.
	 TI_CC_SPIWriteReg(CCxxx0_PKTCTRL0, 0x05); // Packet automation control.
	 TI_CC_SPIWriteReg(CCxxx0_ADDR,     0x01); // Device address.
	 TI_CC_SPIWriteReg(CCxxx0_CHANNR,   0x00); // Channel number.
	 TI_CC_SPIWriteReg(CCxxx0_FSCTRL1,  0x0B); // Freq synthesizer control.
	 TI_CC_SPIWriteReg(CCxxx0_FSCTRL0,  0x00); // Freq synthesizer control.
	 TI_CC_SPIWriteReg(CCxxx0_FREQ2,    0x10); // Freq control word, high byte
	 TI_CC_SPIWriteReg(CCxxx0_FREQ1,    0xA7); // Freq control word, mid byte.
	 TI_CC_SPIWriteReg(CCxxx0_FREQ0,    0x62); // Freq control word, low byte.
	 TI_CC_SPIWriteReg(CCxxx0_MDMCFG4,  0x2D); // Modem configuration.
	 TI_CC_SPIWriteReg(CCxxx0_MDMCFG3,  0x3B); // Modem configuration.
	 TI_CC_SPIWriteReg(CCxxx0_MDMCFG2,  0x73); // Modem configuration.
	 TI_CC_SPIWriteReg(CCxxx0_MDMCFG1,  0x22); // Modem configuration.
	 TI_CC_SPIWriteReg(CCxxx0_MDMCFG0,  0xF8); // Modem configuration.
	 TI_CC_SPIWriteReg(CCxxx0_DEVIATN,  0x00); // Modem dev (when FSK mod en)
	 TI_CC_SPIWriteReg(CCxxx0_MCSM1 ,   0x3F); //MainRadio Cntrl State Machine
	 TI_CC_SPIWriteReg(CCxxx0_MCSM0 ,   0x18); //MainRadio Cntrl State Machine
	 TI_CC_SPIWriteReg(CCxxx0_FOCCFG,   0x1D); // Freq Offset Compens. Config
	 TI_CC_SPIWriteReg(CCxxx0_BSCFG,    0x1C); //  Bit synchronization config.
	 TI_CC_SPIWriteReg(CCxxx0_AGCCTRL2, 0xC7); // AGC control.
	 TI_CC_SPIWriteReg(CCxxx0_AGCCTRL1, 0x00); // AGC control.
	 TI_CC_SPIWriteReg(CCxxx0_AGCCTRL0, 0xB2); // AGC control.
	 TI_CC_SPIWriteReg(CCxxx0_FREND1,   0xB6); // Front end RX configuration.
	 TI_CC_SPIWriteReg(CCxxx0_FREND0,   0x10); // Front end RX configuration.
	 TI_CC_SPIWriteReg(CCxxx0_FSCAL3,   0xEA); // Frequency synthesizer cal.
	 TI_CC_SPIWriteReg(CCxxx0_FSCAL2,   0x0A); // Frequency synthesizer cal.
	 TI_CC_SPIWriteReg(CCxxx0_FSCAL1,   0x00); // Frequency synthesizer cal.
	 TI_CC_SPIWriteReg(CCxxx0_FSCAL0,   0x11); // Frequency synthesizer cal.
	 TI_CC_SPIWriteReg(CCxxx0_FSTEST,   0x59); // Frequency synthesizer cal.
	 TI_CC_SPIWriteReg(CCxxx0_TEST2,    0x88); // Various test settings.
	 TI_CC_SPIWriteReg(CCxxx0_TEST1,    0x31); // Various test settings.
	 TI_CC_SPIWriteReg(CCxxx0_TEST0,    0x0B); // Various test settings. */
//--------------------------------------------------------------------------	
	//
	// Rf settings for CC1101, 433M, 2.4KBPS
	//
	TI_CC_SPIWriteReg(CCxxx0_IOCFG2, 0x06); //GDO0 Output Pin Configuration
	TI_CC_SPIWriteReg(CCxxx0_IOCFG0, 0x06); //GDO0 Output Pin Configuration
	TI_CC_SPIWriteReg(CCxxx0_FIFOTHR, 0x47); //RX FIFO and TX FIFO Thresholds
	TI_CC_SPIWriteReg(CCxxx0_PKTCTRL0, 0x05); //Packet Automation Control
	TI_CC_SPIWriteReg(CCxxx0_FSCTRL1, 0x06); //Frequency Synthesizer Control
	TI_CC_SPIWriteReg(CCxxx0_FREQ2, 0x10); //Frequency Control Word, High Byte
	TI_CC_SPIWriteReg(CCxxx0_FREQ1, 0xB1); //Frequency Control Word, Middle Byte
	TI_CC_SPIWriteReg(CCxxx0_FREQ0, 0x3B); //Frequency Control Word, Low Byte
	TI_CC_SPIWriteReg(CCxxx0_MDMCFG4, 0xF6); //Modem Configuration
	TI_CC_SPIWriteReg(CCxxx0_MDMCFG3, 0x83); //Modem Configuration
	TI_CC_SPIWriteReg(CCxxx0_MDMCFG2, 0x13); //Modem Configuration
	TI_CC_SPIWriteReg(CCxxx0_DEVIATN, 0x15); //Modem Deviation Setting
	TI_CC_SPIWriteReg(CCxxx0_MCSM0, 0x18); //Main Radio Control State Machine Configuration
	TI_CC_SPIWriteReg(CCxxx0_FOCCFG, 0x16); //Frequency Offset Compensation Configuration
	TI_CC_SPIWriteReg(CCxxx0_WORCTRL, 0xFB); //Wake On Radio Control
	TI_CC_SPIWriteReg(CCxxx0_FSCAL3, 0xE9); //Frequency Synthesizer Calibration
	TI_CC_SPIWriteReg(CCxxx0_FSCAL2, 0x2A); //Frequency Synthesizer Calibration
	TI_CC_SPIWriteReg(CCxxx0_FSCAL1, 0x00); //Frequency Synthesizer Calibration
	TI_CC_SPIWriteReg(CCxxx0_FSCAL0, 0x1F); //Frequency Synthesizer Calibration
	TI_CC_SPIWriteReg(CCxxx0_TEST2, 0x81); //Various Test Settings
	TI_CC_SPIWriteReg(CCxxx0_TEST1, 0x35); //Various Test Settings
	TI_CC_SPIWriteReg(CCxxx0_TEST0, 0x09); //Various Test Settings

}

/*
 ================================================================================
 Function : CC1101WriteCmd( )
 Write a command byte to the device
 INPUT    : command, the byte you want to write
 OUTPUT   : None
 ================================================================================
 */
void CC1101WriteCmd(u8 command)
{
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(command);
	CC_CSN_HIGH( );
}
/*
 ================================================================================
 Function : CC1101ReadReg( )
 read a byte from the specified register
 INPUT    : addr, The address of the register
 OUTPUT   : the byte read from the rigister
 ================================================================================
 */
u8 CC1101ReadReg(u8 addr)
{
	u8 i;
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(addr | READ_SINGLE);
	i = SPI_ExchangeByte(0xFF);
	CC_CSN_HIGH( );
	return i;
}
/*
 ================================================================================
 Function : CC1101ReadMultiReg( )
 Read some bytes from the rigisters continously
 INPUT    : addr, The address of the register
 buff, The buffer stores the data
 size, How many bytes should be read
 OUTPUT   : None
 ================================================================================
 */
void CC1101ReadMultiReg(u8 addr, u8 *buff, u8 size)
{
	u8 i, j;
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(addr | READ_BURST);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 20; j++)
			;
		*(buff + i) = SPI_ExchangeByte(0xFF);
	}
	CC_CSN_HIGH( );
}
/*
 ================================================================================
 Function : CC1101ReadStatus( )
 Read a status register
 INPUT    : addr, The address of the register
 OUTPUT   : the value read from the status register
 ================================================================================
 */
u8 CC1101ReadStatus(u8 addr)
{
	u8 i;
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(addr | READ_BURST);
	i = SPI_ExchangeByte(0xFF);
	CC_CSN_HIGH( );
	return i;
}
/*
 ================================================================================
 Function : CC1101SetTRMode( )
 Set the device as TX mode or RX mode
 INPUT    : mode selection
 OUTPUT   : None
 ================================================================================
 */
void CC1101SetTRMode(TRMODE mode)
{
	if (mode == TX_MODE)
	{
		CC1101WriteCmd( CCxxx0_STX);
	}
	else if (mode == RX_MODE)
	{
		CC1101WriteCmd( CCxxx0_SRX);
	}
}
/*
 ================================================================================
 Function : CC1101WriteReg( )
 Write a byte to the specified register
 INPUT    : addr, The address of the register
 value, the byte you want to write
 OUTPUT   : None
 ================================================================================
 */
void CC1101WriteReg(u8 addr, u8 value)
{
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(addr);
	SPI_ExchangeByte(value);
	CC_CSN_HIGH( );
}
/*
 ================================================================================
 Function : CC1101WriteMultiReg( )
 Write some bytes to the specified register
 INPUT    : addr, The address of the register
 buff, a buffer stores the values
 size, How many byte should be written
 OUTPUT   : None
 ================================================================================
 */
void CC1101WriteMultiReg(u8 addr, u8 *buff, u8 size)
{
	u8 i;
	CC_CSN_LOW( )
	;
	SPI_ExchangeByte(addr | WRITE_BURST);
	for (i = 0; i < size; i++)
	{
		SPI_ExchangeByte(*(buff + i));
	}
	CC_CSN_HIGH( );
}

/*
 ================================================================================
 Function : CC1101Reset( )
 Reset the CC1101 device
 INPUT    : None
 OUTPUT   : None
 ================================================================================
 */
void CC1101Reset(void)
{
	u8 x;

	CC_CSN_HIGH( );
	CC_CSN_LOW( )
	;
	CC_CSN_HIGH( );
	for (x = 0; x < 100; x++)
		;
	CC1101WriteCmd( CCxxx0_SRES);
}
/*
 ================================================================================
 Function : CC1101SetIdle( )
 Set the CC1101 into IDLE mode
 INPUT    : None
 OUTPUT   : None
 ================================================================================
 */
void CC1101SetIdle(void)
{
	CC1101WriteCmd(CCxxx0_SIDLE);
}
/*
 ================================================================================
 Function : CC1101ClrTXBuff( )
 Flush the TX buffer of CC1101
 INPUT    : None
 OUTPUT   : None
 ================================================================================
 */
void CC1101ClrTXBuff(void)
{
	CC1101SetIdle(); //!!������Idle״̬
	CC1101WriteCmd( CCxxx0_SFTX);
}
/*
 ================================================================================
 Function : CC1101ClrRXBuff( )
 Flush the RX buffer of CC1101
 INPUT    : None
 OUTPUT   : None
 ================================================================================
 */
void CC1101ClrRXBuff(void)
{
	CC1101SetIdle(); //!!������Idle״̬
	CC1101WriteCmd( CCxxx0_SFRX);
}
/*
 ================================================================================
 Function : CC1101SendPacket( )
 Send a packet
 INPUT    : txbuffer, The buffer stores data to be sent
 size, How many bytes should be sent
 OUTPUT   : None
 ================================================================================
 */
void CC2500SendPacket(u8 *txbuffer, u8 size)
{
	CC1101ClrTXBuff();
	CC1101WriteReg( CCxxx0_TXFIFO, size);
	CC1101WriteMultiReg( CCxxx0_TXFIFO, txbuffer, size);
	CC1101SetTRMode(TX_MODE);
	//while( ...... );
	while (GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_0) == 0)
		;
	while (GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_0) != 0)
		;
	CC1101ClrTXBuff();
}
/*
 ================================================================================
 Function : CC1101GetRXCnt( )
 Get received count of CC1101
 INPUT    : None
 OUTPUT   : How many bytes hae been received
 ================================================================================
 */
u8 CC1101GetRXCnt(void)
{
	return (CC1101ReadStatus( CCxxx0_RXBYTES) & BYTES_IN_RXFIFO);
}
/*
 ================================================================================
 Function : CC1101RecPacket( )
 Receive a packet
 INPUT    : rxBuffer, A buffer store the received data
 size, How many bytes should be received
 OUTPUT   : 1:received, 0:no data
 ================================================================================
 */
u8 CC1101RecPacket(u8 *rxBuffer, u8 *length)
{
	printf("CC1101RecPacket------------------------------\n");
	char status[2];
	char pktLen;
	u16 x, j = 0;

	CC1101SetTRMode(RX_MODE);
	while (GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_0) != 0)
	{
		for (x = 0; x < 10; x++)
			;
		if (++j >= 20)
			return 0;
	}

	if (CC1101GetRXCnt() != 0)
	{
		for (x = 0; x < 200; x++)
			;
		pktLen = CC1101ReadReg(CCxxx0_RXFIFO); // Read length byte

		if (pktLen <= *length) // If pktLen size <= rxBuffer
		{
			CC1101ReadMultiReg(CCxxx0_RXFIFO, rxBuffer, pktLen); // Pull data
			*length = pktLen; // Return the actual size
			CC1101ReadMultiReg(CCxxx0_RXFIFO, status, 2); // Read  status bytes

			CC1101ClrRXBuff();
			if (status[1] & CRC_OK)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		} // Return CRC_OK bit
		else
		{
			*length = pktLen; // Return the large size
			CC1101ClrRXBuff(); // Flush RXFIFO
			return 0; // Error
		}
	}
	else
	{
		return 0;
	} // Error
}

void CC1101Init(void)
{
	u8 PaTabel[] = { 0xc0 }; //10dBm
	volatile u8 i;

	CC1101Reset();
	halRfWriteRfSettings();
	CC1101WriteMultiReg(CCxxx0_PATABLE, PaTabel, 1);

	i = CC1101ReadStatus( CCxxx0_PARTNUM); //for test, must be 0x80
	i = CC1101ReadStatus( CCxxx0_VERSION); //for test, refer to the datasheet
}

u8 SPI_ExchangeByte(u8 input)
{
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) != RESET)
		;
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET)
		;
	SPI_I2S_SendData(SPI2, input);

	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET)
		;
	return SPI_I2S_ReceiveData(SPI2);
}

/*
 ================================================================================
 ------------------------------------THE END-------------------------------------
 ================================================================================
 */
