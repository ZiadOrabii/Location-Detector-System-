   #include "LED.h"


void delay(unsigned long time){
    while(time > 0){
        time--;
    }
}

 
 void RGB_output (unsigned char data)
 {
	 GPIO_PORTF_DATA_R &=~0x0E; //initialize DATA_R
	 GPIO_PORTF_DATA_R |=data ;//DATA_R=data
 }

 
 void RGB_Selector( double distance)
 {
	 
	 if(distance>=30)
		 RGB_output(RED_LED );
	 
	 else if(20<=distance && distance<30)
		 RGB_output(BLUE_LED  ); 
	 
	 else if(distance<20)
		  RGB_output(GREEN_LED  ); 

 }
 
