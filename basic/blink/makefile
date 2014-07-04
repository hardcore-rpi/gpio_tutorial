CC = gcc
CFLAGS = -Wall -g
lib = ../../lib
bin_name = blink_run.exe

default: blink.c main.c ../../lib/bcm2835.c
	$(CC) $(CFLAGS) $^ -I $(lib) -L $(lib) -o $(bin_name)

clean:
	$(RM) $(bin_name) *.o
