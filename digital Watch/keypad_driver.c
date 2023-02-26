#include <stdlib.h>
//#include "core_cm4.h"
#include "gpio_api.h"
#include "systick_delay.h"

volatile uint8_t KeyPressed = 1;
//volatile char tst1 = 0;
static uint8_t ColPressed = 0;
static uint8_t RowPressed = 0;

//IRQn
// Define the keypad-GPIO pin mappings
#define COL_PORT     'G'
#define COL_PORT_ADDR GPIOG_BASE
#define COL1          15
#define COL2          13
#define COL3          11
#define COL4          9

#define ROW_PORT     'D'
#define ROW_PORT_ADDR GPIOD_BASE
#define ROW1          7
#define ROW2          5
#define ROW3          3
#define ROW4          1

void keypad_gpio_init(void){
	GPIOx_config_table *table = (GPIOx_config_table *)malloc(sizeof(GPIOx_config_table));
	
	enable_gpio_CLK(COL_PORT);
	enable_gpio_CLK(ROW_PORT);
	
	table->mode         = 0b00;  //Input 
	table->output_speed = 0b00;  //Low speed
	table->output_type  = 0b00;  //Push-Pull;
	table->pupdr        = 0b01;  //Pull-Up 
	
	initialize_gpio(COL_PORT_ADDR, table, COL1);
	initialize_gpio(COL_PORT_ADDR, table, COL2);
	initialize_gpio(COL_PORT_ADDR, table, COL3);
	initialize_gpio(COL_PORT_ADDR, table, COL4);
	
	table->mode         = 0b01;  //Output 
	table->output_speed = 0b00;  //Low speed
	table->output_type  = 0b01;  //Open-Drain;
	table->pupdr        = 0b01;  //Pull-up
	
	initialize_gpio(ROW_PORT_ADDR, table, ROW1);
	initialize_gpio(ROW_PORT_ADDR, table, ROW2);
	initialize_gpio(ROW_PORT_ADDR, table, ROW3);
	initialize_gpio(ROW_PORT_ADDR, table, ROW4);
	
	free(table);
}
static void enable_SYSCFG_Clk(void){
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  while (!(RCC->APB2ENR & RCC_APB2ENR_SYSCFGEN));
}

void EXTI_init(void){
	enable_SYSCFG_Clk();
	
	//Select trigger source of PG[2k+1], k = 4 to 7
	SYSCFG->EXTICR[2] &= ~SYSCFG_EXTICR3_EXTI9;
	SYSCFG->EXTICR[2] |=  SYSCFG_EXTICR3_EXTI9_PG;
	EXTI->RTSR        &= ~EXTI_RTSR_TR9;
	EXTI->FTSR        |=  EXTI_RTSR_TR9;
	EXTI->IMR         |=  EXTI_IMR_IM9;
	NVIC_SetPriority(EXTI9_5_IRQn,1);              //Enable EXTI9 Interrupt
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	SYSCFG->EXTICR[2] &= ~SYSCFG_EXTICR3_EXTI11;
	SYSCFG->EXTICR[2] |=  SYSCFG_EXTICR3_EXTI11_PG;
	EXTI->RTSR        &= ~EXTI_RTSR_TR11;
	EXTI->FTSR        |=  EXTI_RTSR_TR11;
	EXTI->IMR         |=  EXTI_IMR_IM11;
	
	SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13;
	SYSCFG->EXTICR[3] |=  SYSCFG_EXTICR4_EXTI13_PG;
	EXTI->RTSR        &= ~EXTI_RTSR_TR13;
	EXTI->FTSR        |=  EXTI_RTSR_TR13;
	EXTI->IMR         |=  EXTI_IMR_IM13;
	
	SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI15;
	SYSCFG->EXTICR[3] |=  SYSCFG_EXTICR4_EXTI15_PG;
	EXTI->RTSR        &= ~EXTI_RTSR_TR15;
	EXTI->FTSR        |=  EXTI_RTSR_TR15;
	EXTI->IMR         |=  EXTI_IMR_IM15;
	
	NVIC_SetPriority(EXTI15_10_IRQn,1);              //Enable EXTIx, x = 10 - 15 Interrupts
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

static void keypad_gnd_rows(void){
	digitalWrite(ROW_PORT,ROW1,LOW);
	digitalWrite(ROW_PORT,ROW2,LOW);
	digitalWrite(ROW_PORT,ROW3,LOW);
	digitalWrite(ROW_PORT,ROW4,LOW);
}

static void keyad_scan(void){            //Keypad Scanning Alogrithm
	digitalWrite(ROW_PORT,ROW1,LOW);
	digitalWrite(ROW_PORT,ROW2,HIGH);
	digitalWrite(ROW_PORT,ROW3,HIGH);
	digitalWrite(ROW_PORT,ROW4,HIGH);
	delay_us(100);
	if(!digitalRead(COL_PORT,COL1)){
			RowPressed = 0;
			keypad_gnd_rows();
			return;
	}
	
	digitalWrite(ROW_PORT,ROW1,HIGH);
	digitalWrite(ROW_PORT,ROW2,LOW);
	digitalWrite(ROW_PORT,ROW3,HIGH);
	digitalWrite(ROW_PORT,ROW4,HIGH);
	delay_us(100);
	if(!digitalRead(COL_PORT,COL2)){
			RowPressed = 1;
			keypad_gnd_rows();
			return;
	}
	
	digitalWrite(ROW_PORT,ROW1,HIGH);
	digitalWrite(ROW_PORT,ROW2,HIGH);
	digitalWrite(ROW_PORT,ROW3,LOW);
	digitalWrite(ROW_PORT,ROW4,HIGH);
	delay_us(100);
	if(!digitalRead(COL_PORT,COL3)){
			RowPressed = 2;
			keypad_gnd_rows();
			return;
	}
	
	digitalWrite(ROW_PORT,ROW1,HIGH);
	digitalWrite(ROW_PORT,ROW2,HIGH);
	digitalWrite(ROW_PORT,ROW3,HIGH);
	digitalWrite(ROW_PORT,ROW4,LOW);
	delay_us(100);
	if(!digitalRead(COL_PORT,COL4)){
			RowPressed = 3;
			keypad_gnd_rows();
			return;
	}
}

char get_key(void){
	char key_map[4][4] =   {
	{'1', '2', '3','A'},
	{'4', '5', '6','B'},
	{'7', '8', '9','C'},
	{'*', '0', '#','D'},
	};
	
	keyad_scan();
	return key_map[RowPressed][ColPressed];
}


//IRQ_Handlers
void EXTI9_IRQHandler(void){
	ColPressed = 0;
	KeyPressed = get_key();
	NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
}
void EXTI11_IRQHandler(void){
	ColPressed = 1;
	KeyPressed = get_key();
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
}
void EXTI13_IRQHandler(void){
	ColPressed = 2;
	KeyPressed = get_key();
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
}
void EXTI15_IRQHandler(void){
	ColPressed = 3;
	KeyPressed = get_key();
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
}

