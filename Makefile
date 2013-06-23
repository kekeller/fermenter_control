CC=msp430-gcc 
CFLAGS=-Os -Wall -g -mmcu=msp430g2231 

SOURCES=led.c delay.c
INCLUDES=functions.h
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o led.elf $(OBJECTS)
	
led.o: $(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) -c -o led.o led.c
		
delay.o: delay.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o delay.o delay.c

cleanall:
	rm -fr led.elf delay.o led.o
	
clean:
	rm -fr delay.o led.o
