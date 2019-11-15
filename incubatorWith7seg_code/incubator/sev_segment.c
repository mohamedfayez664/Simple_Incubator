#include "sev_segment.h"
#include "delay.h"


#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
#define SEGMENTS_STATUS  SEGS_PINS
#elif (TYPE_OF_SEGMENTS == COMMON_CATHODE)
#define SEGMENTS_STATUS  (SEGS_PINS^0xff)
#endif

enum {
	seg1,seg2,seg3,seg4,seg5,seg6,seg7,seg8
};

void seven_seg_init(){

	SEG_DATA_PORT_DIR  |= 0x0F;      //set 4pins(0,1,2,3) of data as output
	SEG_DATA_PORT_OUT  &=~0x0F;      //out 0 in the first

	SEG_CTRL_PORT_DIR  |= SEGS_PINS;     //set control port output
#if(TYPE_OF_SEGMENTS== COMMON_ANODE)
	SEG_CTRL_PORT_OUT  &=~SEGS_PINS;      //out 0 in the first
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT  |= SEGS_PINS;      //out 0 in the first  ////
#endif

}

/*display in one segment*/
void seg_display_one(uint8  number , uint8 seg_place )
{
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (SEG_CTRL_PORT_OUT& SEGMENTS_STATUS) | (1<<seg_place);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =  (SEG_CTRL_PORT_OUT|SEGMENTS_STATUS)& (~(1<<seg_place));   //place to display
#endif
	SEG_DATA_PORT_OUT = (SEG_DATA_PORT_OUT&0xf0)|(number&0x0f); //insert num in data port
}

//////////////////////////////////////////////
/*display in multi segment*/
#if (N_OF_SEGMENTS == 8)
void seg_display4(uint8 number1 ,uint8 number2 ,uint8 number3, uint8 number4)
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<< seg2);   //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg2);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	DELAY_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg1);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg1);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	DELAY_ms(delay_between_segments_ms);

	temp = number2 % 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg4);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg4);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number2 / 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg3);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg3);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	////////////////////////////////////////////

	temp = number3 % 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg6);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg6);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number3 / 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg5);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number4 % 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg8);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg8);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number4 / 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg7);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg7);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);
}

#elif (N_OF_SEGMENTS == 6)
void seg_display3(uint8 number1 ,uint8 number2 ,uint8 number3)
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg2);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg1);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	DELAY_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg1);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg1);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	DELAY_ms(delay_between_segments_ms);

	temp = number2 % 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg4);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg4);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number2 / 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg3);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg3);     //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number3 % 10;
	//#if (TOOGLE == 3)
	//	SEG_CTRL_PORT_OUT ^= (1<<seg2);
	//#else
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg6);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg6);     //place to display
#endif
	//#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number3 / 10;
	//#if (TOOGLE == 3)
	//	SEG_CTRL_PORT_OUT ^= (1<<seg1);
	//#else
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
#elif(TYPE_OF_SEGMENTS== COMMON_CATHODE)
	SEG_CTRL_PORT_OUT = ~(1<< seg5);     //place to display
#endif
	//#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);
}

#elif (N_OF_SEGMENTS == 4)
void seg_display2(uint8 number1 ,uint8 number2 )
{
	uint8 temp ;              //just variable
	temp = number1 % 10;   //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg6);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg6);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	DELAY_ms(delay_between_segments_ms);                  //dalay

	temp = number1 / 10;         //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg5);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg5);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	DELAY_ms(delay_between_segments_ms);

	temp = number2 % 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg8);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg8);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);

	temp = number2 / 10;
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg7);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg7);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);
	DELAY_ms(delay_between_segments_ms);
}

#elif (N_OF_SEGMENTS == 2)
void seg_display(uint8  number, start_place, n_of_seg )
{
	uint8 i, temp ;              //just variableS
	for (i=0 ;i<n_of_seg ;i++){

	temp = number % 10;      //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg6);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~ (1<<seg6);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	DELAY_ms(delay_between_segments_ms);                   //dalay
	/////////////////////
	temp = number / 10;                    //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg5);         //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	DELAY_ms(delay_between_segments_ms);

	seg_display_one(temp , seg_place );

}
#endif
/*
 * void seg_display(uint8  number )
{
	uint8 temp ,seg_place;              //just variableS
	temp = number % 10;      //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg6);   //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~ (1<<seg6);   //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f); //insert num in data port
	DELAY_ms(delay_between_segments_ms);                   //dalay
	/////////////////////
	temp = number / 10;                    //to get fist num.
#if (TYPE_OF_SEGMENTS == COMMON_ANODE)
	SEG_CTRL_PORT_OUT = (1<<seg5);         //place to display
#elif(TYPE_OF_SEGMENTS == COMMON_CATHODE)
	SEG_CTRL_PORT_OUT =~(1<<seg5);         //place to display
#endif
	SEG_DATA_PORT_OUT=(SEG_DATA_PORT_OUT&0xf0)|(temp&0x0f);  //insert num in data port
	DELAY_ms(delay_between_segments_ms);

	seg_display_one(temp , seg_place );

}*/
