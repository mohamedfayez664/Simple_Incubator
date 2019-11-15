#ifndef DHT22_H_
#define DHT22_H_

#include "std_micro_comp_conf.h"
#include "std_types.h"
#include "std_macros.h"

#define DHT22_PORT_DIR  DDRD
#define DHT22_PORT_OUT  PORTD
#define DHT22_PORT_IN   PIND

#define DHT22_PIN       PD7

void  DHT22_Request (void);
void  DHT22_Response(void);
uint8 DHT22_Receive_Data(void);


#endif /* DHT22_H_ */
