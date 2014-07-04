#include <stdio.h>
#include "blink.h"

#define BLINK_PIN	RPI_V2_GPIO_P1_11
#define DELAY_MS	500

int loop_run = 1;

void loop_stop(int sig)
{
	loop_run = 0;
}

int main()
{
	if(!bcm2835_init())
	{
		printf("GPIO init ERROR!\n");
		return 1;
	}
	
	// Set the signal
	signal(SIGINT,loop_stop); // Ctrl-C
	
	// Set the GPIO function
	bcm2835_gpio_fsel(BLINK_PIN, BCM2835_GPIO_FSEL_OUTP);
	
	printf("blinking at %fHz, press Ctrl-C to exit...\n",1000.0/DELAY_MS);
	
	while(loop_run)
	{
		bcm2835_gpio_write(BLINK_PIN,1);
		bcm2835_delay(DELAY_MS);
		bcm2835_gpio_write(BLINK_PIN,0);
		bcm2835_delay(DELAY_MS);
	}
	
	bcm2835_close();
	printf("Exit\n");
	return 0;
}
