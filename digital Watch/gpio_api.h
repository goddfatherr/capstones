#ifndef GPIO_API_H
#define GPIO_API_H

#include "gpio_driver.h"

/**
@brief:
	configures a specified pin as IN or OUT
@params:
	port   -> port to be configured
	pin    -> specific pin 
	dir    -> direction of pin
@return:
  1      -> success
	0      -> failure
**/
uint8_t pinMode(char port, uint8_t pin, Dir dir);

/**
@brief:
	writes state to a given pin
@params:
	port   -> port to be configured
	pin    -> specific pin 
	state  -> state to write
@return:
  1      -> success
	0      -> failure
**/
uint8_t digitalWrite(char port, uint8_t pin, State state);

/**
@brief:
	reads state of a given pin
@params:
	port   -> port to be configured
	pin    -> specific pin 
@return:
  state of pin
**/
uint8_t digitalRead(char port, uint8_t pin);


/**
@brief:
	configures a pin for the specified alternate function
@params:
	port   -> port to be configured 
	pin    -> specific pin to be configured for AF
@return:
	void
**/
uint8_t altFunction(char port, uint8_t pin);
	
	
/**
@brief:
	toggles the state of a pin
@params:
	addr   -> 32-bit address of the GPIO port
	pin    -> pin to be toggled
@return:
	void


void digitalToggle(GPIOx_addr addr, char pin){
}
**/

#endif