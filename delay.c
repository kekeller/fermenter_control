#include <msp430g2231.h>
#include "functions.h"

/** Delay function. **/
void delay(unsigned int d) {
  int i;
  for (i = 0; i<d; i++) {
    nop();
  }
}
