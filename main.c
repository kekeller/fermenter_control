#include <msp430g2231.h>
#include "functions.h" 
#include "defines.h"

int main(void) {
	WDTCTL = WDTPW | WDTHOLD; // Turn watchdog timer off, not needed
    initLEDs();
    initADC(); 

	while (ON) {
		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    	__bis_SR_register(CPUOFF + GIE);        // LPM0 with interrupts enabled
	
		// oC = ((A10/1024)*1500mV)-986mV)*1/3.55mV = A10*423/1024 - 278
		temp = ADC10MEM;
		IntDegC = ((temp - 673) * 423) / 1024; // from TI example code
		
		if (IntDegC < TEMPMIN) {
		  	LED_OUT |= (RED_LED + GREEN_LED);	//Turn on both LEDs
			delay(0x1ffff);			
		}

		LED_OUT &= ~(RED_LED + GREEN_LED);	//Turn off both LEDs
		delay(0xfffff);
	}
}
