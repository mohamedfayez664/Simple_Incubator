/*
 * internal_eeprom.h
 * Created: 4/10/2019 3:02:41 AM
 *  Author: M Fayez
 */ 
#ifndef IN_EEPROM_H_
#define IN_EEPROM_H_

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"

void  IN_EEPROM_WriteByte(uint16 addr ,uint8 data );
uint8 IN_EEPROM_ReadByte (uint16 addr );

void IN_EEPROM_WriteBytes(uint16 addr ,uint8 *data ,uint8 data_size );
void IN_EEPROM_ReadBytes(uint16 addr, uint8_t *data, uint8 data_size);

void EEPROM_Erase();


#endif
