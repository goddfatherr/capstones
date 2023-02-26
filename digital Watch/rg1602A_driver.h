#include <stdint.h>

void LCD_configPins();
static void LCD_ClkPulse();
static void LCD_putNibble(uint8_t nib);
static void LCD_sendCmd(uint8_t cmd);
void LCD_sendByte(uint8_t byt);
void LCD_sendString(char *str);
void LCD_initDisplay();