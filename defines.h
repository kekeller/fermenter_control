#include <msp430g2231.h>

#define  RED_LED      BIT0
#define  GREEN_LED      BIT6
#define  LED_DIR   P1DIR
#define  LED_OUT   P1OUT
#define  OFF	   0
#define  ON        1
#define  TEMPMIN   31

#define START_CONVERSION (ADC10CTL0 |= ENC + ADC10SC)
#define LOW_POWER_INTERRUPTS _BIS_SR(LPM3_bits + GIE); 


// Global Variables
extern long temp;
extern long IntDegC;
extern volatile unsigned int wdtCounter;


//(__bis_SR_register(CPUOFF + GIE)) -- old setting
