#include <msp430g2231.h>
#include "functions.h" 

#define  LED0      BIT0
#define  LED1      BIT6
#define  LED_DIR   P1DIR
#define  LED_OUT   P1OUT
#define  OFF	   0
#define  ON        1

int main(void) {
	WDTCTL = WDTPW | WDTHOLD; // Turn watchdog timer off, not needed
    initLEDs();

	while (ON) {
		LED_OUT = ON;
//  	LED_OUT &= (LED0 + LED1);	//Turn on both LEDs
	    delay(0xff);
	    LED_OUT = OFF;
//	LED_OUT &= ~(LED0 + LED1);	//Turn off both LEDs
  }
}
