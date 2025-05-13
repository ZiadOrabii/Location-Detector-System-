#include  "UART.h"
#include "TM4C123.h"
#include "GPIO.h"


void UART1_init(void) {
	
		volatile int delay;
    SYSCTL->RCGCUART |= (1 << 1);    // Enable UART1
    SYSCTL->RCGCGPIO |= (1 << 1);    // Enable GPIOB  	// we will work on PORTB
    delay = SYSCTL->RCGCUART;  // Allow clocks to stabilize
    delay = SYSCTL->RCGCGPIO;
    UART1->CTL &= ~(1 << 0);         // Disable UART1 
	  UART1->IBRD = 104;               // 9600 baud rate @ 16MHz
    UART1->FBRD = 11;
		UART1->LCRH = (1 << 4) | (0x3 << 5); // Enable FIFO, 8-bit word length,no parity, 1 stop bit
	  UART1->CC = 0;                   // Use system clock for UART timing cc:clock configuration
    UART1->CTL |= (1 << 0) | (1 << 8) | (1 << 9); // Enable UART1(1), TXE(8), RXE(9)
		UART1_init_GPIO();


}

char UART1_read(void) {
    while (UART1->FR & (1 << 4)); // Wait until not empty flag on fourth bit still in while loop until data ia read
    return UART1->DR;
}
