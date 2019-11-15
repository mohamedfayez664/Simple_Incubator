/*
DHT Library 0x03
*/
#ifndef DHT_H_
#define DHT_H_

#define F_CPU 8000000
#include <stdio.h>
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

//setup port
#define DHT_DDR DDRD
#define DHT_PORT PORTD
#define DHT_PIN PIND
#define DHT_INPUTPIN PD7

//sensor type
#define DHT_DHT22 2
#define DHT_TYPE DHT_DHT22

//enable decimal precision (float)

#define DHT_FLOAT 0

//timeout retries
#define DHT_TIMEOUT 200

//functions
#if DHT_FLOAT == 1
extern int8_t dht_gettemperature(float *temperature);
extern int8_t dht_gethumidity(float *humidity);
extern int8_t dht_gettemperaturehumidity(float *temperature, float *humidity);

#elif DHT_FLOAT == 0
extern int8_t dht_gettemperature(int8_t *temperature);
extern int8_t dht_gethumidity(int8_t *humidity);
extern int8_t dht_gettemperaturehumidity(int8_t *temperature, int8_t *humidity);
#endif

#endif
