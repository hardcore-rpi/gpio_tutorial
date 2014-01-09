#include <string.h>
#include <bcm2835.h>
#include "ds1307.h"

#define debug 1

#if debug
#include <stdio.h>
#endif

int pow(int a,int b)
{
	int ret=1;
	while(b--)
		ret *= a;
	return ret;
}

int ds1307_init(void)
{
	if(!bcm2835_init())
		return 0;
	bcm2835_i2c_begin();
	bcm2835_i2c_setSlaveAddress(DS1307_ADDR);
	#if debug
	printf("ds1307 init done\n");
	#endif
	return 1;
}

void ds1307_end(void)
{
	bcm2835_i2c_end();
	#if debug
	printf("ds1307 end\n");
	#endif
}

char ds1307_read_byte(int addr)
{
	char addr_str[1] = {(char)addr};
	char buf[1];
	
	bcm2835_i2c_read_register_rs(addr_str,buf,1);
	#if debug
	printf("read %xH -> 0x%x\n",(char)addr,buf[0]);
	#endif
	return buf[0];
}

void ds1307_write_byte(int addr, char dat)
{
	;
}

int byte_join(char byt, int a,int b)
{
	unsigned char mask = 0;
	byt >>= b;
	mask = pow(2,a-b+1) - 1;
	return (int)(byt&mask);
}

int ds1307_get_ch(void)
{
	char byte = ds1307_read_byte(0);
	return byte_join(byte,7,7);
}

int ds1307_get_sec(void)
{
	char byte = ds1307_read_byte(0);
	return byte_join(byte,6,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_min(void)
{
	char byte = ds1307_read_byte(1);
	return byte_join(byte,6,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_hour_mode(void)
{
	char byte = ds1307_read_byte(2);
	return byte_join(byte,6,6);
}

int ds1307_get_hour(void)
{
	char byte = ds1307_read_byte(2);
	return byte_join(byte,5,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_day(void)
{
	char byte = ds1307_read_byte(3);
	return byte_join(byte,2,0);
}

int ds1307_get_date(void)
{
	char byte = ds1307_read_byte(4);
	return byte_join(byte,5,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_mon(void)
{
	char byte = ds1307_read_byte(5);
	return byte_join(byte,4,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_year(void)
{
	char byte = ds1307_read_byte(6);
	return byte_join(byte,7,4)*10 + byte_join(byte,3,0);
}

void ds1307_set_ch(int x)
{
	char last=0;
	last = ds1307_read_byte(0);
	if(x)
		last |= 0x80;
	else
		last &= ~0x80;
	ds1307_write_byte(0,last);
}

void ds1307_set_sec(int sec)
{
	char last=0;
	last = ds1307_read_byte(0);
	last &= 0x80;
	last += (unsigned char)sec;
	ds1307_write_byte(0,last);
}

void ds1307_set_min(int min)
{
	ds1307_write_byte(1,(unsigned char)min);
}

void ds1307_set_hour_mode(int x)
{
	char last=0;
	last = ds1307_read_byte(2);
	if(x)
		last |= 0x40;
	else
		last &= ~0x40;
	ds1307_write_byte(2,last);
}

void ds1307_set_hour(int hour)
{
	char last=0;
	last = ds1307_read_byte(2);
	last &= 0x40;
	last += (unsigned char)hour;
	ds1307_write_byte(3,last);
}

void ds1307_set_day(int day)
{
	ds1307_write_byte(4,(unsigned char)day);
}

void ds1307_set_date(int date)
{
	ds1307_write_byte(5,(unsigned char)date);
}

void ds1307_set_mon(int mon)
{
	ds1307_write_byte(6,(unsigned char)mon);
}

void ds1307_set_year(int year)
{
	ds1307_write_byte(7,(unsigned char)year);
}
