
#ifndef ACTUATORS_H_
#define ACTUATORS_H_

#include "std_micro_comp_conf.h"
#include "std_types.h"
#include "std_macros.h"

void actuaters_init(void);

void fan_on(void);
void fan_off(void);

//////////////////////////////////////////////////////////////
void heater_on(void);
void heater_off(void);

//////////////////////////////////////////////////////////////
void buzzer_on(void);
void buzzer_off(void);

#endif   /* ACTUATORS_H_ */
