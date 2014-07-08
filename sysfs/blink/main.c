#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define PIN 17

int loop_run = 1;

void loop_stop(int sig)
{
	loop_run = 0;
}

int main()
{
	FILE fd=NULL;
	
	fd = open("/sys/class/gpio/export",'w');
	fputs(#PIN,fd);
	fclose(fd);
	
	printf("export gpio%d\n",PIN);
	
	fd = open("/sys/class/gpio/gpio" #PIN,'w');
	while(loop_run)
	{
		fputs("1",fd);
		printf("\rGPIO%d = 1",PIN);
		sleep(1);
		fputs("0",fd);
		printf("\rGPIO%d = 0",PIN);
		sleep(1);
	}
	fclose(fd);
	
	fd = open("/sys/class/gpio/unexport",'w');
	fputs(#PIN,fd);
	fclose(fd);
	printf("unexport gpio%d\n",PIN);
	
	return 0;
}
