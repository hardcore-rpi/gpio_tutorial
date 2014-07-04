#include <stdio.h>
#include <signal.h>
#include "button.h"

int loop_run = 1;

void loop_stop(void)
{
	loop_run = 0;
}

int main()
{
	if(!button_init())
		return 1;
		
	// Set the signal
	signal(SIGINT,loop_stop); // Ctrl-C
	signal(SIGTERM,loop_stop); // Ctrl-D
	
	printf("Check button...\n");
	while(loop_run)
		printf("btn = %d\n",button_value());
	
	button_end();
}
