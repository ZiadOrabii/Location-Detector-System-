#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "TM4C123.h"
#include "UART.h"
#include "GPS_Module.h"
#include "LCD.h"
#include "Calculate_Distance.h"
#include "SysTick.h"
#include "Switch.h"
#include "LED.h"
#include <stdio.h>   
#include "GPIO.h"

int main(void) {
		volatile uint32_t gpsIndex = 0;
		char buffer[20];  // buffer to hold the formatted double
    UART1_init();
    GPIO_init_Switch();
    LCD_Init();
    SysTick_Init();
	  RGB_Init_GPIO (); // 
		RGB_Selector(200);
   


    while (1) {
			
        char c = UART1_read();

        if (c == '$') {
            gpsIndex = 0;
        }

        if (gpsIndex < GPS_BUFFER_SIZE - 1) {
            gpsSentence[gpsIndex++] = c;
            gpsSentence[gpsIndex] = '\0';
        }

        if (c == '\n') {
            if (strncmp((const char *)gpsSentence, "$GPGGA", 6) == 0) {
                processGPSSentence();
                extractLatLong();

                const char* nearest = find_nearest_location(latitudeDecimal, longitudeDecimal);
									if(strcmp(nearest,"Waiting")!=0)
									RGB_Selector(min_distance);
										else
											RGB_Selector(200);
															

                updateDisplayState();  // Use switch to toggle mode

                LCD_Command(0x01);
                SysTick_Wait1ms(2);

                if (strcmp((char *)displayMode, "Default") == 0) {
                    LCD_Command(0x80);
                    LCD_String("ASU FOE");

                    LCD_Command(0xC0);
                    if (nearest && nearest[0] != '\0') {
                        LCD_String((char*)nearest);
                    } else {
                        LCD_String("Waiting for YOU!");
                    }

                }

								else {
                    LCD_Command(0x80);
                    if (nearest && nearest[0] != '\0') {
                        LCD_String((char*)nearest);
                    } else {
                        LCD_String("No Location");
                    }

                    LCD_Command(0xC0) ;
										double distance=haversine(latitudeDecimal, longitudeDecimal, lat, lon);
									// Convert double to string with 2 decimal places
								  int integerPart_min_distance = (int)distance;  // Extract the integer part
									 sprintf(buffer, "%d", integerPart_min_distance);
									 LCD_String(buffer);    // Display the converted number
									LCD_Command(0xC4);
										LCD_String("Meter");
                }  
            }

            gpsIndex = 0;
        }
		
    }
		
		
}


