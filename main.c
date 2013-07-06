#include <msp430g2231.h>
#include "functions.h" 
#include "defines.h"

// Global Variables
long temp;
long IntDegC;
long wdtCounter;

int main(void) {
	//WDTCTL = WDTPW | WDTHOLD; // Turn watchdog timer off, not needed
	
    WDTCTL = WDT_ADLY_250;                    // WDT 250ms, ACLK, interval timer
	IE1 |= WDTIE;                             // Enable WDT interrupt
	
    initLEDs();
    initADC(); 
    wdtCounter = 0;

	while (ON) {
		START_CONVERSION;             // Sampling and conversion start
    	//(__bis_SR_register(CPUOFF + GIE));        // LPM0 with interrupts enabled
	
		_BIS_SR(LPM3_bits + GIE); 
		
		// oC = ((A10/1024)*1500mV)-986mV)*1/3.55mV = A10*423/1024 - 278
		temp = ADC10MEM;
		IntDegC = ((temp - 673) * 423) / 1024; // from TI example code
		
		/*if (IntDegC < TEMPMIN) {
		  	LED_OUT |= (RED_LED + GREEN_LED);	//Turn on both LEDs
			//timer_delay(4);
			delay(0xffff);			
		}

		LED_OUT &= ~(RED_LED + GREEN_LED);	//Turn off both LEDs
		//timer_delay(4); 
		delay(0xffff); */ 
	}
}
