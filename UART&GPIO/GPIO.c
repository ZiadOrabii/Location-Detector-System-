#include "GPIO.h"

void GPIO_init_Switch(void) {
    SYSCTL->RCGCGPIO |= (1 << 5);   // Enable clock for Port F
    GPIOF->DIR &= ~(1 << 4);        // PF4 as input (SW4)
    GPIOF->DEN |= (1 << 4);         // Digital enable
    GPIOF->PUR |= (1 << 4);         // Pull-up resistor
}

void RGB_Init_GPIO(void)
 {
	  SYSCTL_RCGCGPIO_R |=0x20;
	 while((SYSCTL_PRGPIO_R &0X20)==0); //DELAY
	 GPIO_PORTF_LOCK_R =0x4C4F434B ; // unlock
	 GPIO_PORTF_AMSEL_R &=~0X0E ; //0001 0000 //disable analog
	 GPIO_PORTF_CR_R |=0X0E ; //enable
	 GPIO_PORTF_PCTL_R &=~0x000FFF0 ; //enable digital 
	 GPIO_PORTF_AFSEL_R &=~0x0E ;
	 GPIO_PORTF_DIR_R |=0x0E ;//input=0 output=1
	 GPIO_PORTF_DEN_R |=0x0E;
	 GPIO_PORTF_DATA_R &=	~0x0E ; //initialize pf321 to be off=0
}
 
void LCD_Init_GPIO(void) {
	
	SYSCTL->RCGCGPIO |= (1U << 0) | (1U << 1) | (1U << 3) | (1U << 4); // Enable clocks for Port A, B, D, E
    while ((SYSCTL->PRGPIO & ((1U << 0) | (1U << 1) | (1U << 3) | (1U << 4))) == 0);

    // Configure Data Pins
    GPIOA->DIR |= (1U << 7) | (1U << 6) | (1U << 5);
    GPIOA->DEN |= (1U << 7) | (1U << 6) | (1U << 5);

    GPIOB->DIR |= (1U << 4);
    GPIOB->DEN |= (1U << 4);

    GPIOE->DIR |= (1U << 5) | (1U << 4) | (1U << 1);  // Include PE1 (D6)
    GPIOE->DEN |= (1U << 5) | (1U << 4) | (1U << 1);

    // Control Pins PD0, PD1, PD2, and PD3 (D7)
    GPIOD->DIR |= (1U << 0) | (1U << 1) | (1U << 2) | (1U << 3);
    GPIOD->DEN |= (1U << 0) | (1U << 1) | (1U << 2) | (1U << 3);
}
 
void UART1_init_GPIO(void) { 
	
    GPIOB->AFSEL |= (1 << 0) | (1 << 1); // PB0 and PB1 for UART1
    GPIOB->PCTL = (GPIOB->PCTL & 0xFFFFFF00) | 0x00000011; 
    GPIOB->DEN |= (1 << 0) | (1 << 1);   
}



