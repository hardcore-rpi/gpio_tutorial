#include <stdio.h>
#include "button.h"
#include <unistd.h>

int main()
{
	if(!button_init())
	{
		printf("button init ERROR!\n");
		return 1;
	}
	
	printf("Waiting button...\n");
	while(1)
	{
		if(button_event())
			break;
		printf(".");
		fflush(stdout);
		sleep(1);
	}

	printf("\n");
	
	printf("Get button = %d\nExit\n",button_value());
	button_end();
	return 0;
}
