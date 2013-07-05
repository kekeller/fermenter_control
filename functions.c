#include <msp430g2231.h>
#include "functions.h"
#include "defines.h" 

/** Delay function. **/
void delay(unsigned int d) {
  int i;
  for (i = 0; i<d; i++) {
    nop();
  }
}

void initLEDs(void) {
	LED_DIR |= RED_LED + GREEN_LED;	//Set LED pins as outputs
	LED_OUT &= ~(RED_LED + GREEN_LED);	//Turn off both LEDs
}
