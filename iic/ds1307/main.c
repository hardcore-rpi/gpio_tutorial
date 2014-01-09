#include <stdio.h>
#include "ds1307.h"

int main()
{
	int year=0, month=0, date=0, hour=0, minute=0, second=0, day=0;
	printf("----------DS1307----------\n\n");

	if(!ds1307_init())
	{
		printf("ds1307 init ERROR!\n");
		return 1;
	}
	
	year = ds1307_get_year();
	month = ds1307_get_mon();
	date = ds1307_get_date();
	hour = ds1307_get_hour();
	minute = ds1307_get_min();
	second = ds1307_get_sec();
	day = ds1307_get_day();
	
	printf("%d-%d-%d %d:%d:%d day%d \n",year,month,date,hour,minute,second,day);
	
	ds1307_end();

	return 0;
}
