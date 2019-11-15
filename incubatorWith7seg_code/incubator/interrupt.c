#include "interrupt.h"

static volatile void (*g_INT0_CallBackPtr)(void) = NULL;
static volatile void (*g_INT1_CallBackPtr)(void) = NULL;
static volatile void (*g_INT2_CallBackPtr)(void) = NULL;

void INT0_Init(INTERRUPT_Config *Config_Ptr)
{
	DDRD &= ~(1<<2);  //enable external interrupt 0
	PORTD |= (Config_Ptr->pull<<2); //enable pull up for interrupt 0

	MCUCR=(MCUCR&0xfc)|(Config_Ptr->edge&0x03); //edge for rising or falling edge
	GICR |=(1<<INT0); //enable interrupt 0 module
}
void INT0_CallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_INT0_CallBackPtr = a_ptr;
}
ISR(INT0_vect)
{
	if(g_INT0_CallBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_INT0_CallBackPtr)(); /* another method to call the function using pointer to function g_TIMER0_OVF_callBackPtr(); */
	}
}

////////////////////////////////////////////////////
void INT1_Init(INTERRUPT_Config *Config_Ptr)
{
	DDRD &= ~(1<<3);   // pin
	PORTD |= (Config_Ptr->pull<<3);   //enable pull up for interrupt 1

	//flags
    MCUCR=(MCUCR&0xf3)|((Config_Ptr->edge&0x03)<<2);
    GICR |=(1<<INT1);  //module
}
void INT1_CallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_INT1_CallBackPtr = a_ptr;
}
ISR(INT1_vect)
{
	if(g_INT1_CallBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_INT1_CallBackPtr)(); /* another method to call the function using pointer to function g_TIMER0_OVF_callBackPtr(); */
	}
}
////////////////////////////////////////////////////
void INT2_Init(INTERRUPT_Config *Config_Ptr)
{
	DDRB &= ~(1<<2);
	PORTB|=  (Config_Ptr->pull<<2);

    MCUCSR=(MCUCSR&0xbf)|((Config_Ptr->edge&0x01)<<ISC2); //<<6
    GICR |=(1<<INT2);
}
void INT2_CallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_INT2_CallBackPtr = a_ptr;
}
ISR(INT2_vect)
{
	if(g_INT2_CallBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_INT2_CallBackPtr)(); /* another method to call the function using pointer to function g_TIMER0_OVF_callBackPtr(); */
	}
}

////////////////////////////////////////////////////
void INT_Deinit(uint8 interrupts_det)
{
    /*clear specified interrupts*/    
	GICR &=~(interrupts_det<<5);
}
