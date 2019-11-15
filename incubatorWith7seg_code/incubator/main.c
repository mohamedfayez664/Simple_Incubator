/*
 *  Name:       incubator
 *  Created on: 22,10, 2019
 *  Author:     Mohamed and Hosam
 */

#include "switches.h"
#include "actuators.h"
#include "sensors.h"
#include "delay.h"

#ifdef LCD_DIS
#include "lcd.h"
#else
#include "sev_segment.h"
#endif

//#include "DHT22.h"
#include "dht.h"

#define temp_sense  1  //to make alarms or turn actuators
#define hum_sense   1

volatile uint8  actual_temp=0,    actual_humidity=0;
volatile uint8  const_temp=37,    const_hum=50 ;

//flags to avoid overflow by press the buttons in constant temperature and humidity
volatile uint8 in_t_flag=0 ,de_t_flag=0 ,in_h_flag=0 ,de_h_flag=0;


int main(void)
{
	////Configurations////
	DELAY_init();
#ifdef LCD_DIS
	LCD_init();
#else
	seven_seg_init();     //initialize 7 segments
#endif
	switches_init();      //initialize switches
	actuaters_init();     //initialize fan ,heater and buzzer
	sensors_init();       //from temperature library
	/*
	uint8 I_RH,   D_RH;
	uint8 I_TEMP, D_TEMP,    Check_Sum;
	/*
	 /*
	uint8 temperature = 0;
	uint8 humidity    = 0;
	*/
	while(1){
		/*
		        uint16 h=0 ,t = 0;
				DHT22_Request(); 	DHT22_Response();

				I_RH=DHT22_Receive_Data(); D_RH=DHT22_Receive_Data();
				I_TEMP=DHT22_Receive_Data(); D_TEMP=DHT22_Receive_Data();
				Check_Sum = DHT22_Receive_Data();
                //prefer to check data with check_sum
				h = (I_RH<<8) | (D_RH);    //	t = (I_TEMP<<8)|(D_TEMP);
				actual_humidity= h;        //   actual_temp= t;
		 */

		/*
		if( dht_gettemperaturehumidity (&temperature, &humidity) != -1) {
			seg_display4( humidity,  const_hum,temperature , const_temp );
		}
		else {
			seg_display4( 88,  88,88 , 88 );
		}
		DELAY_ms(500);
		*/
		actual_temp =    temp_sensor_read(0);
		actual_humidity= hum_sensor_read(1);

		////////////////////////////////////////
		if(set_temp_pres){
			if(PIND&(1<<0)){
				DELAY_ms(30);
				if(PIND&(1<<0)){      //increase temperature pin
					if(in_t_flag==0){ // to avoid overflow
						const_temp++;  //increase constant temperature
						in_t_flag=1;
					}
				}
			}
			else in_t_flag=0;
			if(PIND&(1<<1)){ 		//decrease temperature pin
				DELAY_ms(30);
				if(PIND&(1<<1)){
					if(de_t_flag==0){
						const_temp--;  //decrease constant temperature
						de_t_flag=1;
					}
				}
			}
			else de_t_flag=0;
		}
		//////////////////////////////
		if(set_hum_pres){
			if(PIND&(1<<4)){   //increase humidity pin
				DELAY_ms(30);
				if(PIND&(1<<4)){
					if(in_h_flag==0){
						const_hum++;   //increase constant humidity
						in_h_flag=1;
					}
				}
			}
			else in_h_flag=0;

			if(PIND&(1<<5)){    //decrease humidity pin
				DELAY_ms(30);
				if(PIND&(1<<5)){
					if(de_h_flag==0){
						const_hum--;   //decrease constant humidity
						de_h_flag=1;
					}
				}
			}
			else de_h_flag=0;
		}
#ifdef LCD_DIS
		LCD_displayNumber(actual_humidity);  LCD_displayNumber(const_hum);
		LCD_displayNumber(actual_temp);      LCD_displayNumber(const_temp);
#else
		seg_display4(const_temp ,actual_temp, const_hum ,actual_humidity );
#endif



		//////////////////////////////
		/*if((actual_temp>(const_temp+(temp_sense+1)))|(actual_temp<(const_temp-(temp_sense+1)))){
			buzzer_on();
		}else{
			buzzer_off();
		}
		////////////////
		if  (actual_temp < (const_temp-temp_sense)){
			heater_on();
			fan_off();
		}else if(actual_temp > (const_temp+temp_sense)){
			heater_off();
			fan_on();
		}
		else{
			heater_off();
			fan_off();
		}
		 *////////////////////////////


		/*
		/////////////////////////////////////////////////////////////
		if((actual_temp>(const_temp+(temp_sense+1)))|(actual_humidity>(const_hum+(hum_sense+1)))|
				(actual_temp<(const_temp-(temp_sense+1)))|(actual_humidity<(const_hum-(hum_sense+1)))){
			buzzer_on();
		}else{
			buzzer_off();
		}
		////////////////
		if(actual_temp < (const_temp-temp_sense)){
			heater_on();

		}else{
			heater_off();
		}
		if(actual_humidity < (const_hum-hum_sense)){
			fan_on();
		}else{

			fan_off();
		}
		 */
	}
}
