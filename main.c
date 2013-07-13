#include <msp430g2231.h>
#include "functions.h" 
#include "defines.h"

// Global Variables
long temp;
long IntDegC;
volatile long wdtCounter = 0;

int main(void) {
    WDTCTL = WDT_MDLY_32;                    // WDT 32ms, ACLK, interval timer
	IE1 |= WDTIE;                             // Enable WDT interrupt
	
    initLEDs();
    initADC(); 

	while (ON) {
		WAIT_UNTIL_WAKE_UP;        
		START_CONVERSION;             
    			
		temp = ADC10MEM; // oC = ((A10/1024)*1500mV)-986mV)*1/3.55mV = A10*423/1024 - 278
		IntDegC = ((temp - 673) * 423) / 1024; 
		
		if (IntDegC < TEMPMIN_C) {
			LED_OUT |= (RED_LED + GREEN_LED);	// LED PINS ON
		} else {
			LED_OUT &= ~(RED_LED + GREEN_LED);	
		}
	}
}
