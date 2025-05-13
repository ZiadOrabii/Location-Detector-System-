#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "TM4C123.h"
#include "LED.h"
#include "LCD.h"

// Initializes GPIO for button SW4 (PF4)
void GPIO_init_Switch(void);
void RGB_Init_GPIO(void);
void UART1_init_GPIO(void);
void LCD_Init_GPIO(void);

#endif
