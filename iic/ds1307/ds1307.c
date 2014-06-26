#include <stdio.h>
#include <stdlib.h>
#include "ds1307.h"

struct ds1307_regs
{
	char regs[8];
	char ram[0x3f-0x08+1];
};

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

int ch_splite(struct ds1307_regs * dp, int * chp)
{
	char byte = dp->regs[0];
	chp = byte_join(byte,7,7);
	return 1;
}

int sec_splite(struct ds1307_regs * dp, int * sec10p, int * secp)
{
	char byte = dp->regs[0];
	
	sec10p = byte_join(byte,6,4);
	secp = byte_join(byte,3,0);
	
	return 2;
}

int min_splite(struct ds1307_regs * dp, int * min10p, int * minp)
{
	char byte = dp->regs[1];
	
	min10p = byte_join(byte,6,4);
	minp = byte_join(byte,3,0);
	
	return 2;
}

int hour_splite(struct ds1307_regs * dp, int * flag2p, int * flag1p, int * flag0p, int * hp)
{
	char byte = dp->regs[2];
	
	flag2p = byte_join(byte,6,6);
	flag1p = byte_join(byte,5,5);
	flag0p = byte_join(byte,4,4);
	flag0p = byte_join(byte,4,4);
	hp = byte_join(byte,3,0);
	
	return 5;
}

int day_splite(struct ds1307_regs * dp, int * dayp)
{
	char byte = dp->regs[3];
	dayp = byte_join(byte,2,0);
	return 1;
}

int date_splite(struct ds1307_regs * dp, int * date10p, int * datep)
{
	char byte = dp->regs[4];
	
	min10p = byte_join(byte,6,4);
	minp = byte_join(byte,3,0);
	
	return 2;
}

int mon_splite(struct ds1307_regs * dp, int * mon10p, int * monp)
{
	char byte = dp->regs[5];
	
	mon10p = byte_join(byte,4,4);
	monp = byte_join(byte,3,0);
	
	return 2;
}

int year_splite(struct ds1307_regs * dp, int * year10p, int * yearp)
{
	char byte = dp->regs[6];
	
	year10p = byte_join(byte,7,4);
	yearp = byte_join(byte,3,0);
	
	return 2;
}

