#include "TM4C123.h"
#include "Switch.h"
#include <string.h>
#include "SysTick.h"

volatile char displayMode[10] = "Default";  // Global definition

void updateDisplayState(void) {
    static uint8_t lastState = 1;
    uint8_t currentState = (GPIOF->DATA & 0x10) >> 4; // SW1 on PF4

    if (lastState == 1 && currentState == 0) { // Falling edge detected (button press)
        if (strcmp((char *)displayMode, "Default") == 0) {
            strcpy((char *)displayMode, "Distance");
        } else {
            strcpy((char *)displayMode, "Default");
        }
        SysTick_Wait1ms(200); // Debounce
    }

    lastState = currentState;
}
