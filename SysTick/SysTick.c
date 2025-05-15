#include "SysTick.h"
#include "TM4C123.h"
// SysTick functions

void SysTick_Init(void) {
    SysTick->CTRL = 0;
    SysTick->LOAD = 16000 - 1; // 1ms delay for 16MHz clock
    SysTick->VAL = 0;
    SysTick->CTRL = 0x5; // Enable SysTick with system clock
}

void SysTick_Wait1ms(uint32_t delay) {
    for (uint32_t i = 0; i < delay; i++) {
        while ((SysTick->CTRL & 0x10000) == 0); // Wait for COUNT flag
    }
}

void delay_ms(uint32_t ms) {
    SysTick_Wait1ms(ms);
}
