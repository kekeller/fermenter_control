tempeh
======

MSP 430 Microcontroller to control heat lamp. 

CAUTION: THIS PROJECT USES 120VAC OR (IF YOUR COUNTRY USES IT) 240VAC ELECTRICITY. IT IS DANGEROUS. DO NOT BUILD THE HARDWARE WITHOUT SUITABLE KNOWLEDGE OF CIRCUITS. YOU CAN CAUSE DEATH AND/OR FIRE. 

Tempeh, fermented crushed soybeans, requires fermentation at around 31 degrees until complete (visual inspection). 

This project prepares the MSP 430 with temperature sensor and relay toggle to adjust temperature in the chamber as required. 

The current iteration uses a simple no_operation function to time the light on and off with an ADC to test the temperature. A later edition will use the watchdog timer to turn the light on for the predetermined amount of time required for the box based on the volume. 

The temperaturedecision.m script can be used to determine the appropriate amount of time to heat the box depending on size. Edit the script to input the size in liters and bulb wattage. The box used for my project is only 18 liters so a 40W bulb is sufficient. 

To create the circuit follow the instructions on [url]. A simple SSR relay was used along with an MJE521 NPN BJT. A simple amplifier circuit was built to connect the relay to the MSP 430. An LED output can also be used as GPIO output pin. 

SOFTWARE: 
	For linux install the compiler, linkers, and debuger using "sudo apt-get install binutils-msp430 gcc-msp430 msp430-libc mspdebug"
	Extract the .zip file into an empty directory using "mkdir tempeh" "unzip tempeh-master.zip"
	To create the .elf file run "make" in the newly created directory. 
	Clean the old .o files with "make clean"
	Program the MSP 430 with "make prog" -- the MakeFile has an additional command to run "sudo mspdebug rf2500 "prog main.elf"" to flash the program.
	
	The code has a function timer_delay that is not operational at the moment. It will be updated when the bug is removed. 
	
HARDWARE: 
	Full guide on [url].
	Build small circuit with NPN to amplify the output of the pin to a small relay. 
	Splice an extension cord into the relay. CAUTION: I assume no responsibility. You are dealing with 120VAC; IT IS DANGEROUS. Test the circuit fully before plugging into MSP 430 using a multimeter. Use electrical tape and solder to ensure a clean connection. 
	
	


