#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

void SysTick_Init(void);
void SysTick_Wait1ms(uint32_t delay);

#endif
