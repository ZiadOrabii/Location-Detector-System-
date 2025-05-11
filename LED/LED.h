#ifndef LED_H
#define LED_H
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <string.h>
#include "GPIO.h"

#define RED_LED   0x02
#define BLUE_LED  0x04
#define GREEN_LED 0x08
void delay(unsigned long time);
void RGB_Init(void);
void RGB_output (unsigned char data);
void RGB_Selector( double  min_distance);
#endif
