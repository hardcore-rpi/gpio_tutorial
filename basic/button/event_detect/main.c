#include <stdio.h>
#include "button.h"

int main()
{
	if(!button_init())
		return 1;
	
	printf("Waiting button...\n");
	while(!button_event());
	
	printf("Get button = %d\nExit\n",button_value());
	button_end();
}
