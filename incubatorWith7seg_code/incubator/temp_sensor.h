#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"

void sensors2_init();
uint8 temp2_sensor_read(uint8);
uint8 hum2_sensor_read(uint8);

#endif /* TEMP_SENSOR_H_ */
