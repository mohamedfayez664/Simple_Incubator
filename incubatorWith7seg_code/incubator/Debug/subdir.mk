################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../actuators.c \
../adc.c \
../delay.c \
../dht.c \
../dht22.c \
../internal_eeprom.c \
../interrupt.c \
../lcd.c \
../main.c \
../sensors.c \
../sev_segment.c \
../switches.c \
../temp_sensor.c 

OBJS += \
./actuators.o \
./adc.o \
./delay.o \
./dht.o \
./dht22.o \
./internal_eeprom.o \
./interrupt.o \
./lcd.o \
./main.o \
./sensors.o \
./sev_segment.o \
./switches.o \
./temp_sensor.o 

C_DEPS += \
./actuators.d \
./adc.d \
./delay.d \
./dht.d \
./dht22.d \
./internal_eeprom.d \
./interrupt.d \
./lcd.d \
./main.d \
./sensors.d \
./sev_segment.d \
./switches.d \
./temp_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


