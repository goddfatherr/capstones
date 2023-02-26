#include "gpio_driver.h"
#include <stdlib.h>
uint8_t pinMode(char port, uint8_t pin, Dir dir){
	enable_gpio_CLK(port);
	GPIOx_config_table * table;
	table = (GPIOx_config_table *)malloc(sizeof(GPIOx_config_table)); 
	table->mode         = dir;
	table->output_speed = 0b00;
	table->output_type  = 0b00;
	if(!dir)
		table->pupdr        = 0b10;
	else
		table->pupdr        = 0b00;
	
	switch(port){
		case 'A':
				initialize_gpio(gpioA, table, pin); break;
		case 'B':
				initialize_gpio(gpioB, table, pin); break;
		case 'C':
				initialize_gpio(gpioC, table, pin); break;
		case 'D':
				initialize_gpio(gpioD, table, pin); break;
		case 'E':
				initialize_gpio(gpioE, table, pin); break;
		case 'F':
				initialize_gpio(gpioF, table, pin); break;
		case 'G':
				initialize_gpio(gpioG, table, pin); break;
		case 'H':
				initialize_gpio(gpioH, table, pin); break;
		case 'I':
				initialize_gpio(gpioI, table, pin); break;
		case 'J':
				initialize_gpio(gpioJ, table, pin); break;
		case 'K':
				initialize_gpio(gpioK, table, pin); break;
		default:
			return 0;
	}
	//enable_gpio_CLK(port);
	free(table);
	return 1;
		
}

uint8_t digitalWrite(char port, uint8_t pin, State state){
	if (pin < 0 || pin > 16){
		return 0;
	}
	switch(port){
		case 'A':
				write_ODR(gpioA, state, pin); break;
		case 'B':
				write_ODR(gpioB, state, pin); break;
		case 'C':
				write_ODR(gpioC, state, pin); break;
		case 'D':
				write_ODR(gpioD, state, pin); break;
		case 'E':
				write_ODR(gpioE, state, pin); break;
		case 'F':
				write_ODR(gpioF, state, pin); break;
		case 'G':
				write_ODR(gpioG, state, pin); break;
		case 'H':
				write_ODR(gpioH, state, pin); break;
		case 'I':
				write_ODR(gpioI, state, pin); break;
		case 'J':
				write_ODR(gpioJ, state, pin); break;
		case 'K':
				write_ODR(gpioK, state, pin); break;
		default:
			return 0;
	}
	return 1;
}

uint8_t digitalRead(char port, uint8_t pin){
	if (pin < 0 || pin > 16){
		return 0;
	}
	switch(port){
		case 'A':
				return read_IDR(gpioA, pin);
		case 'B':
				return read_IDR(gpioB, pin); 
		case 'C':
				return read_IDR(gpioC, pin);
		case 'D':
				return read_IDR(gpioD, pin);
		case 'E':
				return read_IDR(gpioE, pin);
		case 'F':
				return read_IDR(gpioF, pin);
		case 'G':
				return read_IDR(gpioG, pin);
		case 'H':
				return read_IDR(gpioH, pin);
		case 'I':
				return read_IDR(gpioI, pin);
		case 'J':
				return read_IDR(gpioJ, pin);
		case 'K':
				return read_IDR(gpioK, pin); 
		default:
			return 0;
	}
	return 1;
}
	
uint8_t altFunction(char port, uint8_t pin){
	enable_gpio_CLK(port);
	if (pin < 0 || pin > 16){
		return 0;
	}
	switch(port){
		case 'A':
				enable_alt_function(gpioA, pin); break;
		case 'B':
				enable_alt_function(gpioB, pin); break;
		case 'C':
				enable_alt_function(gpioC, pin); break;
		case 'D':
				enable_alt_function(gpioD, pin); break;
		case 'E':
				enable_alt_function(gpioE, pin); break;
		case 'F':
				enable_alt_function(gpioF, pin); break;
		case 'G':
				enable_alt_function(gpioG, pin); break;
		case 'H':
				enable_alt_function(gpioH, pin); break;
		case 'I':
				enable_alt_function(gpioI, pin); break;
		case 'J':
				enable_alt_function(gpioJ, pin); break;
		case 'K':
				enable_alt_function(gpioK, pin); break;
		default:
			return 0;
	}
	//enable_gpio_CLK(port);
	return 1;
}

/**
void digitalToggle(GPIOx_addr addr, char pin){
**/

