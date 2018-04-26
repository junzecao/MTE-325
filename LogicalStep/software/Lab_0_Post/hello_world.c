/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
  printf("Hello from Nios II!\n");
  alt_u8 switches, buttons, leds;
  while(1){
	  // read the switches PIO (8 bits wide) and then shift the result by 4 bits left into variable "switches".
	  switches = (IORD(SWITCH_PIO_BASE,0))<<4;
	  // read the buttons PIO (only 4 bits wide), invert the value, mask off the highest 4 bits of the byte and
	  // copy the 8 bit result into the variable "buttons".
	  buttons = 0x0F & ~(IORD(BUTTON_PIO_BASE,0));
	  // write the 8 bit quantity of 4 lowest switches and 4 Pbuttonsto the LEDs PIO.
	  leds= (switches | buttons);
	  IOWR(LED_PIO_BASE,0,leds);

  	  }

  return 0;
}
