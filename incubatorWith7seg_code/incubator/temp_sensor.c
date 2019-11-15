#include "temp_sensor.h"
#include "adc.h"

void sensors2_init(){
	ADC_ConfigType myADC_COn={AREF ,Div_Fac_8};
	ADC_init(&myADC_COn);
}

uint8 temp2_sensor_read(uint8 ch)
{
	uint8 x= (ADC_readChannel(ch) * 500/1023);
	return x; /// return local
}

uint8 hum2_sensor_read(uint8 ch)
{
	uint8 x= (ADC_readChannel(ch) * 500/1023);
	return x; /// return local
}

#if 0
    uint16 adc_value1 ,adc_value2;
	float32 temp1,    temp2, temp  ;

	//for every 10 mili_volt is 1 c
	ADC_ConfigType my_config={IN2_25,Div_Fac_64};
	ADC_init(&my_config);   //initialize ADC driver 
	
	while(1)
	{
		adc_value1 = ADC_readChannel(0) ; /* read channel two where the temp sensor is connect */
		adc_value2 = ADC_readChannel(1) ; /* read channel two where the temp sensor is connect */

		temp1 = (adc_value1*((float32)150/306.9)); //in this case v ref must be 5v
		                                           // adc * 150 /(1.5*1023/vref.)
												   //edit it to run on vref 1.5 v 
												   //>> 1.466 ml sense >>/0.1466 c sense
		temp2 = (adc_value2*((float32)150/306).9);

		temp=(temp1-temp2);
	}

#endif
