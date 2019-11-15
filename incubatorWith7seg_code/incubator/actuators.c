#include "actuators.h"

void actuaters_init()
{
	DDRC|=(1<<PC5)|(1<<PC6)|(1<<PC7);
	PORTC&=~((1<<PC5)|(1<<PC6)|(1<<PC7));  //initial 0 as out
}
void fan_on()
{
	PORTC|=(1<<PC5);
}
void fan_off()
{
	PORTC&=~(1<<PC5);
}
/////////////////////////////////////////////////////////////////////////
void heater_on()
{
	PORTC|=(1<<PC6);
}
void heater_off()
{
	PORTC&=~(1<<PC6);
}
//////////////////////////////////////////////////////////////////////////////
void buzzer_on()
{
	PORTC|=(1<<PC7);
}
void buzzer_off()
{
	PORTC&=~(1<<PC7);
}
