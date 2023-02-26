#include "gpio_api.h"
#include "systick_delay.h"

//Port E
#define D7 14
#define D6 12
#define D5 10
#define D4 8
//Port B
#define EN 10
#define RW -1  //Grounded
#define RS 12

void LCD_configPins(){
	pinMode('E',D7,OUT);
	pinMode('E',D6,OUT);
	pinMode('E',D5,OUT);
	pinMode('E',D4,OUT);
	pinMode('B',EN,OUT);
	//pinMode('B',RW,OUT);
	pinMode('B',RS,OUT);
	digitalWrite('B',RS,HIGH); //default -> Data mode
}

static void LCD_ClkPulse(){
	digitalWrite('B', EN, HIGH);
	delay_us(10);
	digitalWrite('B',EN, LOW);
	delay_us(10);
}
static void LCD_putNibble(uint8_t nib){
	if(nib & 0x8)
		digitalWrite('E',D7,HIGH);
	else
		digitalWrite('E',D7,LOW);
	if(nib & 0x4)
		digitalWrite('E',D6,HIGH);
	else
		digitalWrite('E',D6,LOW);
	if(nib & 0x2)
		digitalWrite('E',D5,HIGH);
	else
		digitalWrite('E',D5,LOW);
	if(nib & 0x1)
		digitalWrite('E',D4,HIGH);
	else
		digitalWrite('E',D4,LOW);
}
static void LCD_sendCmd(uint8_t cmd){
	digitalWrite('B',RS,LOW);
	LCD_putNibble(cmd >>4 );
	LCD_ClkPulse();
	LCD_putNibble(cmd & 0xF);
	LCD_ClkPulse();
	digitalWrite('B',RS,HIGH);
	delay_us(100);
}

void LCD_sendByte(uint8_t byt){
	LCD_putNibble(byt >> 4);
	LCD_ClkPulse();
	LCD_putNibble(byt & 0xF);
	LCD_ClkPulse();
	delay_us(100);
}

void LCD_sendString(char *str){
	while(*str)
		LCD_sendByte(*str++);
}

void LCD_initDisplay(){
	//4-bit mode, 2 lines, 5x8 dots
	LCD_sendCmd(0x02);
	delay_us(40);
	
	LCD_sendCmd(0x28);
	delay_us(40);
	
	//Clear display and cursor home
	LCD_sendCmd(0x01);
	delay_us(1500);
	
	//Entry mode set
	LCD_sendCmd(0x06);
	delay_us(40);
	
	//Turn on display, cursor off, blink off
	LCD_sendCmd(0x0C);
	delay_us(40);

}




