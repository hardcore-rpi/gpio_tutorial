#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define PIN_STR "17"
#define PIN_INT 17

int loop_run = 1;

void loop_stop(int sig)
{
	loop_run = 0;
}

int main()
{
	FILE * fd;

	signal(SIGINT,loop_stop);
	
	fd = fopen("/sys/class/gpio/export","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	
	printf("export gpio%d\n",PIN_INT);
	
	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/direction","w");
	fputs("out",fd);
	fclose(fd);

	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/value","w");
	while(loop_run)
	{
		fputs("1",fd);
		printf("\rGPIO%d = 1",PIN_INT);
		fflush(stdout);
		fflush(fd);
		sleep(1);
		fputs("0",fd);
		printf("\rGPIO%d = 0",PIN_INT);
		fflush(stdout);
		fflush(fd);
		sleep(1);
	}
	fclose(fd);
	
	fd = fopen("/sys/class/gpio/unexport","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	printf("unexport gpio%d\n",PIN_INT);
	
	return 0;
}
