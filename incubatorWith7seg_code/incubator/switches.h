#ifndef SWITCHES_H
#define SWITCHES_H

#include "std_micro_comp_conf.h"
#include "std_types.h"
#include "std_macros.h"

extern volatile uint8 set_temp_flag , set_humidity_flag;
extern volatile uint8 set_temp_pres ,set_hum_pres ;

void switches_init();

void callBackin0 ();
void callBackin1 ();

#endif 
