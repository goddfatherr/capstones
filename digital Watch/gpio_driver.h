#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "gpio_structures_and_defines.h"

/**
@brief:
	turns on CLK signal for the specified port
@params:
	port    -> port to turn on CLK for. 
@return:
	void
**/
void enable_gpio_CLK(uint8_t port);
/**
@brief:
	initializes the specified GPIO port with info in config table
@params:
	addr   -> 32-bit address of the GPIO port to be initialized
	table  -> configuration table where config info is stored
	pin    -> pin to be initialized
@return:
	void
**/
void initialize_gpio(GPIOx_addr addr, GPIOx_config_table *table, uint8_t pin);


/**
@brief:
	writes a  state to the a given port
@params:
	addr   -> 32-bit address of the GPIO port to be written
	val    -> state to write
	pin    -> pin to write
@return:
	void
**/
void write_ODR(GPIOx_addr addr, uint8_t state, uint8_t pin);


/**
@brief:
	reads state of a pin
@params:
	addr   -> 32-bit address of the GPIO port to be read
	pin    -> pin to read
@return:
	state of pin
**/
uint8_t read_IDR(GPIOx_addr addr, uint8_t pin);


/**
@brief:
	enables the specified alternate function on a pin
@params:
	addr   -> 32-bit address of the GPIO port 
	pin    -> pin to enable alternate function
@return:
	void
**/
void enable_alt_function(GPIOx_addr addr, uint8_t pin);



#endif