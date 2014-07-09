#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <poll.h>

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
	pollfd_t fds_poll[0];
	char buf[5];
	int poll_ret=0;

	signal(SIGINT,loop_stop);
	
	fd = fopen("/sys/class/gpio/export","w");
	fputs(PIN_STR,fd);
	fclose(fd);
	
	printf("export gpio%d\n",PIN_INT);
	
	fd = fopen("/sys/class/gpio/gpio" PIN_STR "/direction","w");
	fputs("in",fd);
	fclose(fd);
	
	fds_poll[0].fd = fopen("/sys/class/gpio/gpio" PIN_STR "/value","r");
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
				int seek_ret=0;
				ret = lseek(fd, 0, SEEK_SET);
				if(ret<0)
				{
					printf("seek ERROR\n");
					break;
				}
				fgets(buf,4,fd);
				printf("interrupt: GPIO%d = %s",PIN_INT,buf);
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
