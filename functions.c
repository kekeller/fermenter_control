#include <msp430g2231.h>
#include "functions.h"
#include "defines.h" 

void initLEDs(void) {
	LED_DIR |= RED_LED + GREEN_LED;	//Set LED pins as outputs
	LED_OUT &= ~(RED_LED + GREEN_LED);	//Turn off both LEDs
}

void initADC (void) {
	ADC10CTL1 = INCH_10 + ADC10DIV_3;         // Temp Sensor ADC10CLK/4
	ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON + ADC10IE;
	__enable_interrupt();                     // Enable interrupts.
	TACCR0 = 30;                              // Delay to allow Ref to settle
	TACCTL0 |= CCIE;                          // Compare-mode interrupt.
	TACTL = TASSEL_2 | MC_1;                  // TACLK = SMCLK, Up mode.
	LPM0;                                     // Wait for delay.
	TACCTL0 &= ~CCIE;                         // Disable timer Interrupt
	__disable_interrupt();
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
	WAKE_UP;        
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void ta0_isr (void)
{
	TACTL = 0;
	WAKE_UP;                      // Exit LPM0 on return
}

// Watchdog Timer interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer (void)
{
	wdtCounter--;
	
	if (wdtCounter < 0) {
		wdtCounter = INTERVAL_32_HZ;
		WAKE_UP; 	
	}
}
