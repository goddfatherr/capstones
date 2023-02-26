#include "rg1602A_driver.h"
#include "keypad_driver.h"

extern volatile uint8_t KeyPressed;
//extern volatile char tst1;
//static int key = 0;
int main(){
	keypad_gpio_init();
	EXTI_init();
	
	LCD_configPins();
	LCD_initDisplay();
	//keyPressed = get_key();
	uint8_t ky;
	while(1){
		if(KeyPressed){
			//key = get_key();
			ky = KeyPressed;
			LCD_sendByte(KeyPressed);
			LCD_sendByte('D');
			KeyPressed = 0;
		}
	}
	/**
	LCD_configPins();
	LCD_initDisplay();
	char str[] = "Hello World!";
	LCD_sendString(str);
	**/
	//while(1);
	

}