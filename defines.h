#include <msp430g2231.h>

#define  RED_LED      BIT0
#define  GREEN_LED      BIT6
#define  LED_DIR   P1DIR
#define  LED_OUT   P1OUT
#define  OFF	   0
#define  ON        1
#define  TEMPMIN_C   31

#define START_CONVERSION 			(ADC10CTL0 |= ENC + ADC10SC)    // Start ADC
#define WAIT_UNTIL_WAKE_UP 		_BIS_SR(CPUOFF + GIE);  // LPM3 with interrupts enabled
#define WAKE_UP					    __bic_SR_register_on_exit(CPUOFF);  // Clear CPUOFF bit from 0(SR)

#define  INTERVAL_SEC               2
#define  INTERVAL_32_HZ             (INTERVAL_SEC * 1000 / 32)


// Global Variables
extern long temp;
extern long IntDegC;
extern volatile long wdtCounter;


