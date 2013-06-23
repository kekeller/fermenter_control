/* Blink LED example */

#include <msp430g2231.h>
#include "functions.h" 

int main(void) {
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR = 0xFF;
  P1OUT = 0x01;

  for (;;) {
    P1OUT = ~P1OUT;
    delay(0x4fff);
  }
}
