#include "gpio_structures_and_defines.h"

void enable_gpio_CLK(char port){
	RCC->AHB1ENR |= 1UL<<(port - 'A'); 
}

void initialize_gpio(GPIOx_addr addr, GPIOx_config_table *table, uint8_t pin){
	
	GPIO_TypeDef * GPIO_obj = (GPIO_TypeDef  *) addr;
	GPIO_obj->MODER   &= ~(3UL<<(2*pin));
	GPIO_obj->MODER   |= (table->mode*1UL)<<(2*pin);
	
	GPIO_obj->OTYPER  |= table->output_type<<pin;
	
	GPIO_obj->OSPEEDR &= ~(3UL<<(2*pin));
	GPIO_obj->OSPEEDR |= table->output_speed<<(2*pin);
	
	GPIO_obj->PUPDR   &= ~(3UL<<(2*pin));
	GPIO_obj->PUPDR   |= table->pupdr<<(2*pin);
	
	//GPIO_obj->MODER |= 1UL<<4;
}

void write_ODR(GPIOx_addr addr, uint8_t state, uint8_t pin){
	GPIO_TypeDef * GPIO_obj = (GPIO_TypeDef  *) addr;
	GPIO_obj->ODR &= ~(1UL<<pin);
	GPIO_obj->ODR |= state<<pin;
}

uint8_t read_IDR(GPIOx_addr addr, uint8_t pin){
	GPIO_TypeDef * GPIO_obj = (GPIO_TypeDef  *) addr;
	return (GPIO_obj->IDR & (1UL<<pin)) > 0;
}

void enable_alt_function(GPIOx_addr addr, uint8_t pin){
	GPIO_TypeDef * GPIO_obj = (GPIO_TypeDef  *) addr;
	GPIO_obj->MODER    &= ~(3UL<<(2*pin));
	GPIO_obj->MODER    |=  2<<(2*pin);
	if (pin<8){
		GPIO_obj->AFR[0] &= ~(15UL<<(4*pin)); 
		GPIO_obj->AFR[0] |=   pin<<(4*pin); 
	}
	else {
		GPIO_obj->AFR[1] &= ~(15UL<<(4*pin)); 
		GPIO_obj->AFR[1] |=   pin<<(4*pin); 
	}
		
}