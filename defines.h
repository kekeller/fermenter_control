#include <msp430g2231.h>

#define  RED_LED      BIT0
#define  GREEN_LED      BIT6
#define  LED_DIR   P1DIR
#define  LED_OUT   P1OUT
#define  OFF	   0x00
#define  ON        0xff
#define  TEMPMIN   31

// Global Variables
long temp;
long IntDegC;


