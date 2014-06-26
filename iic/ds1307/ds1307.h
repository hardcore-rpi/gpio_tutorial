#ifndef __ds1307__
#define __ds1307__

struct ds1307_regs
{
	unsigned char regs[8];
	unsigned char ram[0x3f-0x08+1];
};

extern void ds1307_init(void);
extern int ds1307_get_ch(void);
extern int ds1307_get_sec(void);
extern int ds1307_get_min(void);
extern int ds1307_get_hour_mode(void);
extern int ds1307_get_hour(void);
extern int ds1307_get_day(void);
extern int ds1307_get_date(void);
extern int ds1307_get_mon(void);
extern int ds1307_get_year(void);
extern void ds1307_set_ch(int x);
extern void ds1307_set_sec(int sec);
extern void ds1307_set_min(int min);
extern void ds1307_set_hour_mode(int x);
extern void ds1307_set_hour(int hour);
extern void ds1307_set_day(int day);
extern void ds1307_set_date(int date);
extern void ds1307_set_mon(int mon);
extern void ds1307_set_year(int year);

#endif