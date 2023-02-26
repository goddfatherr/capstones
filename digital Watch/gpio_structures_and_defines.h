#ifndef GPIO_STRUCTURES_AND_DEFINES_H
#define GPIO_STRUCTURES_AND_DEFINES_H

#include "stm32f429xx.h"

typedef enum{
	IN  = 0b00,
	OUT = 0b01
}Dir;

typedef enum{
	LOW  = 0,
	HIGH = 1
}State;

typedef enum{
	gpioA = GPIOA_BASE,
	gpioB = GPIOB_BASE,
	gpioC = GPIOC_BASE,
	gpioD = GPIOD_BASE,
	gpioE = GPIOE_BASE,
	gpioF = GPIOF_BASE,
	gpioG = GPIOG_BASE,
	gpioH = GPIOH_BASE,
	gpioI = GPIOI_BASE,
	gpioJ = GPIOJ_BASE,
	gpioK = GPIOK_BASE
}GPIOx_addr;

typedef struct{
	uint8_t mode;
	uint8_t output_type;
	uint8_t output_speed;
	uint8_t pupdr;
	uint8_t alt_function;
}GPIOx_config_table;

#endif