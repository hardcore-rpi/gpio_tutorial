#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define BCM2835_BLOCK_SIZE	(4*1024)
#define GPIO_BASE	0x20200000
#define GPFSEL1	0x0004
#define GPSET0	0x001c

int main()
{
	int mem_fd=0;
	volatile int * pin_fselp=MAP_FAILED;
	volatile int * pin_setp=MAP_FAILED;

	if( (memfd = open("/dev/mem", O_RDWR | O_SYNC)) < 0 )
	{
		printf("/dev/mem open ERROR: %s\n",strerror(errno));
		return 1;
	}

	pin_fselp = mapmem("fsel", BCM2835_BLOCK_SIZE, memfd, GPIO_BASE+GPFSEL1);
	pin_setp = mapmem("set", BCM2835_BLOCK_SIZE, memfd, GPIO_BASE+GPSET0);
	if(pin_fselp==MAP_FAILED || pin_setp==MAP_FAILED)
	{
		printf("map failed\n");
		close(mem_fd);
		return 1;
	}

	// GPFSEL1 ^ [29...27] = 001
	*pin_fselp &= 0xE3FFFFFF;
	*pin_fselp |= 1<<27;

	*pin_setp = 1<<17;

	sleep(1);

	unmapmem((void**) &pin_fselp, BCM2835_BLOCK_SIZE);
	unmapmem((void**) &pin_setp, BCM2835_BLOCK_SIZE);

	return 0;
}
