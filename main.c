#include <msp430g2231.h>
#include "functions.h" 
#include "defines.h"

// Global Variables
long temp;
long IntDegC;
volatile unsigned int wdtCounter = 0;

int main(void) {
	//WDTCTL = WDTPW | WDTHOLD; // Turn watchdog timer off, not needed
	
	// The watchdog is set in watchdog interrupt. Not working as expected. 
    WDTCTL = WDT_ADLY_250;                    // WDT 250ms, ACLK, interval timer
	IE1 |= WDTIE;                             // Enable WDT interrupt
	
    initLEDs();
    initADC(); 

	while (ON) {
		START_CONVERSION;             // Sampling and conversion start
    	LOW_POWER_INTERRUPTS;        // LPM3 with interrupts enabled
	
		//_BIS_SR(LPM3_bits + GIE); 
		
		// oC = ((A10/1024)*1500mV)-986mV)*1/3.55mV = A10*423/1024 - 278
		temp = ADC10MEM;
		IntDegC = ((temp - 673) * 423) / 1024; // from TI example code
		
		if (IntDegC < TEMPMIN) {
			LED_OUT |= (RED_LED + GREEN_LED);	//Turn on both LEDs
			delay(0xfffff);			
		}

		LED_OUT &= ~(RED_LED + GREEN_LED);	//Turn off both LEDs
		delay(0xfffff); 
	}
}
