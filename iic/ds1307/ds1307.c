#include <stdlib.h>
#include "ds1307.h"

struct ds1307_regs dregs;

void ds1307_regs_init(struct ds1307_regs * dp)
{
	memset(dp, 0, sizeof(ds1307_regs) );
}

void ds1307_init(void)
{
	;
}

char ds1307_read_byte(int n)
{
	;
}

void ds1307_write_byte(int n, char dat)
{
	;
}

void ds1307_read_all(struct ds1307_regs * dp)
{
	;
}

void ds1307_write_all(struct ds1307_regs * dp)
{
	;
}

int byte_join(char byt, int a,int b)
{
	unsigned char mask = 0;
	byt >>= b;
	mask = 2^(a-b+1) - 1;
	return (int)(byt&mask);
}

int ds1307_get_ch(void)
{
	char byte = dregs->regs[0];
	return byte_join(byte,7,7);
}

int ds1307_get_sec(void)
{
	char byte = dregs->regs[0];
	return byte_join(byte,6,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_min(void)
{
	char byte = dregs->regs[1];
	return byte_join(byte,6,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_hour_mode(void)
{
	char byte = dregs->regs[2];
	return byte_join(byte,6,6);
}

int ds1307_get_hour(void)
{
	char byte = dregs->regs[2];
	return byte_join(byte,5,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_day(void)
{
	char byte = dregs->regs[3];
	return byte_join(byte,2,0);
}

int ds1307_get_date(void)
{
	char byte = dregs->regs[4];
	return byte_join(byte,5,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_mon(void)
{
	char byte = dregs->regs[5];
	return byte_join(byte,4,4)*10 + byte_join(byte,3,0);
}

int ds1307_get_year(void)
{
	char byte = dregs->regs[6];
	return byte_join(byte,7,4)*10 + byte_join(byte,3,0);
}

void ds1307_set_ch(int x)
{
	if(x)
		dregs->regs[0] |= 0x80;
	else
		dregs->regs[0] &= ~0x80;
	ds1307_write_byte(dregs->regs[0]);
}

void ds1307_set_sec(int sec)
{
	dregs->regs[0] &= 0x80;
	dregs->regs[0] += (unsigned char)sec;
	ds1307_write_byte(dregs->regs[0]);
}

void ds1307_set_min(int min)
{
	dregs->regs[1] = (unsigned char)min;
	ds1307_write_byte(dregs->regs[1]);
}

void ds1307_set_hour_mode(int x)
{
	if(x)
		dregs->regs[2] |= 0x40;
	else
		dregs->regs[2] &= ~0x40;
	ds1307_write_byte(dregs->regs[2]);
}

void ds1307_set_hour(int hour)
{
	dregs->regs[2] &= 0x40;
	dregs->regs[2] += (unsigned char)hour;
	ds1307_write_byte(dregs->regs[2]);
}

void ds1307_set_day(int day)
{
	dregs->regs[3] = (unsigned char)day;
	ds1307_write_byte(dregs->regs[3]);
}

void ds1307_set_date(int date)
{
	dregs->regs[4] = (unsigned char)date;
	ds1307_write_byte(dregs->regs[4]);
}

void ds1307_set_mon(int mon)
{
	dregs->regs[5] = (unsigned char)mon;
	ds1307_write_byte(dregs->regs[5]);
}

void ds1307_set_year(int year)
{
	dregs->regs[6] = (unsigned char)year;
	ds1307_write_byte(dregs->regs[6]);
}