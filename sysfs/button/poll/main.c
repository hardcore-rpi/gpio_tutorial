#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <poll.h>
#include <string.h>

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
	struct pollfd fds_poll[1];
	int poll_ret=0;

	signal(SIGINT,loop_stop);
	
	fd = fopen("/sys/class/gpio/export","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	
	printf("export gpio%d\n",PIN_INT);
	
	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/direction","w");
	fputs("in",fd);
	fclose(fd);

	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/edge","w");
	fputs("rising",fd);
	fclose(fd);

	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/value","r");
	fds_poll[0].fd = fileno(fd);
	fds_poll[0].events = POLLPRI;

	while(loop_run)
	{
		poll_ret = poll(fds_poll,1,500);
		if(poll_ret<0)
		{
			printf("poll ERROR\n");
			break;
		}
		else if(poll_ret>0)
		{
			if(fds_poll[0].revents & POLLPRI)
			{
				printf("interrupt: GPIO%d rising\n",PIN_INT);
			}
		}
	}
	fclose(fd);
	
	fd = fopen("/sys/class/gpio/unexport","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	printf("unexport gpio%d\n",PIN_INT);
	
	return 0;
}
