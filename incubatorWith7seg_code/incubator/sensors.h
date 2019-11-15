#ifndef SENSORS_H_
#define SENSORS_H_

#include "std_micro_comp_conf.h"
#include "std_types.h"
#include "std_macros.h"


void sensors_init();
uint8 temp_sensor_read(uint8);
uint8 hum_sensor_read(uint8);

#endif /* SENSORS_H_ */
