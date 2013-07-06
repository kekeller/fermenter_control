#include <msp430g2231.h>

void delay (unsigned long d); 

void timer_delay (unsigned int time);

void initLEDs (void);

void initADC (void);

void ADC10_ISR (void);

void ta0_isr(void);

void watchdog_timer(void);
