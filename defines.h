#include <msp430g2231.h>

#define  RED_LED      BIT0
#define  GREEN_LED      BIT6
#define  LED_DIR   P1DIR
#define  LED_OUT   P1OUT
#define  OFF	   0x00
#define  ON        0xff
#define  TEMPMIN   31

#define START_CONVERSION (ADC10CTL0 |= ENC + ADC10SC)
#define LOW_POWER_INTERRUPTS (__bis_SR_register(CPUOFF + GIE))

// Global Variables
extern long temp;
extern long IntDegC;
extern long wdtCounter;


