CC = gcc
CFLAGS = -Wall -g
lib = ../../lib
bin_name = ds1307_run

default: ds1307.c main.c ../../lib/bcm2835.c
	$(CC) $(CFLAGS) $^ -I $(lib) -L $(lib) -o $(bin_name)

clean:
	$(RM) $(bin_name) *.o
