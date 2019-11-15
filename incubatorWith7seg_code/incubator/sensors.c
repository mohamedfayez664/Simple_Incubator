#include "sensors.h"

#include "adc.h"

void sensors_init(){
	ADC_ConfigType myADC_COn={AREF ,Div_Fac_8};
	ADC_init(&myADC_COn);
}
uint8 temp_sensor_read(uint8 ch)
{
	uint8 x= (ADC_readChannel(ch) * 500/1023);
	return x; /// return local
}

uint8 hum_sensor_read(uint8 ch)
{
	uint8 x= (ADC_readChannel(ch) * 500/1023);
	return x; /// return local
}

