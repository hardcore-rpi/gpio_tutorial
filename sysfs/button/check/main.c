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
	fputs("in",fd);
	fclose(fd);

	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/value","r");
	while(loop_run)
	{
		printf("\rGPIO%d = %s",PIN_INT,fgets(fd));
		fflush(stdout);
		sleep(1);
	}
	fclose(fd);
	
	fd = fopen("/sys/class/gpio/unexport","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	printf("unexport gpio%d\n",PIN_INT);
	
	return 0;
}
