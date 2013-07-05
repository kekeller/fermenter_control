CC=msp430-gcc 
CFLAGS=-Os -Wall -g -mmcu=msp430g2231 

SOURCES=main.c functions.c
INCLUDES=functions.h defines.h
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o main.elf $(OBJECTS)
	
main.o: $(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) -c -o main.o main.c
		
functions.o: functions.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o functions.o functions.c

cleanall:
	rm -fr main.elf functions.o main.o
	
clean:
	rm -fr functions.o main.o
	
prog: 
	sudo mspdebug rf2500 "prog main.elf"
