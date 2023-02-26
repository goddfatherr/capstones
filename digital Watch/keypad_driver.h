#ifndef KEYPAD_DRIVER_H
#define KEYPAD_DRIVER_H


void keypad_gpio_init(void);

void EXTI_init(void);

char get_key(void);

#endif

	