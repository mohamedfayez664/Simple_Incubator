#ifndef INT_Init_H
#define INT_Init_H

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"


typedef enum
{
   LOGIC_EDGE=1, FALLING_EDGE ,RISING_EDGE
} INTERRUPT_Sence;

typedef enum
{
   NO_PULL ,PULL_UP
} INTERRUPT_PULL;

typedef enum
{
   INTERRUPT2=1, INTERRUPT0, INT2_INT0, INTERRUPT1, INT2_INT1 ,INT1_INT0 ,INT2_INT1_INT0 
} INTERRUPT_DET;

typedef struct
{
	INTERRUPT_Sence edge;
	INTERRUPT_PULL  pull;
}INTERRUPT_Config;

void INT0_Init(INTERRUPT_Config *Config_Ptr);
void INT0_CallBack(void(*a_ptr)(void));

////////////////////////////////////////////////////
void INT1_Init(INTERRUPT_Config *Config_Ptr);
void INT1_CallBack(void(*a_ptr)(void));

////////////////////////////////////////////////////
void INT2_Init(INTERRUPT_Config *Config_Ptr);
void INT2_CallBack(void(*a_ptr)(void));

/////////////////////////////////////////////////
void INT_Deinit(uint8 interrupts_det);

#endif //INT_Init_H
