#include "internal_eeprom.h"

void IN_EEPROM_WriteByte(uint16 addr ,uint8 data )
{
	while(BIT_IS_SET(EECR,EEWE));//

	EEAR = addr;
	EEDR = data;
	EECR  = (1 << EEMWE);   //EECR=0;
	SET_BIT(EECR,EEWE);
}

uint8 IN_EEPROM_ReadByte(uint16 addr )
{
	while(BIT_IS_SET(EECR,EEWE));

	EEAR = addr;
	EECR = 1 << EERE;  //EECR=0;

	return EEDR;
}
void IN_EEPROM_WriteBytes(uint16 addr ,uint8 *data ,uint8 data_size )
{
	while(data_size !=  0)
	{
		IN_EEPROM_WriteByte(addr,*data);    //Write a byte from RAM to EEPROM
		addr++;				                 //Increment the Eeprom Address
		data++;				                 //Increment the RAM Address
		data_size--;					     //Decrement NoOfBytes after writing each Byte
	}
}
void IN_EEPROM_ReadBytes(uint16 addr, uint8_t *data, uint8 data_size)
{
	while(data_size !=  0)
	{
		*data = IN_EEPROM_ReadByte(addr); //Read a byte from EEPROM to RAM
		addr++;						   //Increment the EEPROM Address
		data++;						   //Increment the RAM Address
		data_size--;				   //Decrement NoOfBytes after Reading each Byte
	}
}

void EEPROM_Erase()
{
	uint16_t addr  , MaxEepromSize_U16 = 1024;

	for(addr=0; addr< MaxEepromSize_U16; addr++)
	{
		IN_EEPROM_WriteByte(addr,0xffu); // Write Each memory location with OxFF
	}
}
