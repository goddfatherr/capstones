#include "gpio_api.h"
#include "core_cm4.h"

volatile uint32_t  delay = 0;

void sysClkSwitch_HSE(){
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	RCC->CFGR &= RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
	SystemCoreClockUpdate();
}

void delay_us(uint32_t us) {
    // Assuming a 168MHz clock frequency
    volatile uint32_t delay_cycles = us * (SystemCoreClock / 1000000) / 5;
    while(delay_cycles--);
}

// Delays for the specified number of milliseconds
void delay_ms(uint32_t ms) {
    // Assuming a 168MHz clock frequency
    volatile uint32_t delay_cycles = ms * (SystemCoreClock / 1000) / 5;
    while(delay_cycles--);
}
//ticks  = SYSCLK freq * Interrupt Period
/**
void delay_ms(uint32_t ms){
	SysTick_Config(SystemCoreClock/1000);
	delay = ms;
	while(delay > 0);
}
void delay_us(uint32_t us){
	SysTick_Config(SystemCoreClock/(1000*1000));
	delay = us;
	while(delay > 0);
}

void SysTick_Handler(void){
	if (delay >0)
		delay--;
}
**/