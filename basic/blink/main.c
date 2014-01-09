#include <stdio.h>
#include "blink.h"

#define FRE		2
#define TIMES	5

int main()
{
	if(!blink_init())
	{
		printf("blink init ERROR!\n");
		return 1;
	}
	printf("blink at %dHz for %d times...\n",FRE,TIMES);
	blink_start(FRE,TIMES);
	blink_end();
	return 0;
}
