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
	char buf[5];

	signal(SIGINT,loop_stop);
	
	fd = fopen("/sys/class/gpio/export","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	
	printf("export gpio%d\n",PIN_INT);
	
	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/direction","w");
	fputs("in",fd);
	fclose(fd);

	while(loop_run)
	{
		fd = fopen("/sys/class/gpio/gpio" PIN_STR "/value","r");
		fgets(buf,4,fd);
		fclose(fd);
		printf("GPIO%d = %s",PIN_INT,buf);
		fflush(stdout);
		sleep(1);
	}
	
	fd = fopen("/sys/class/gpio/unexport","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	printf("unexport gpio%d\n",PIN_INT);
	
	return 0;
}
