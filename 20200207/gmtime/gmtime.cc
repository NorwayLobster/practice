///
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include <time.h>
#include <cstdio>
//两种时间：秒数
//			字符串时间即格林尼治时间
int main(){
	time_t t;
	t=time(NULL);//
	printf("time:%ld\n",t);
	//or time(&t);
	struct tm * p;
	p=gmtime(&t);
#if 0
	struct tm {
		int tm_sec;    /* Seconds (0-60) */
		int tm_min;    /* Minutes (0-59) */
		int tm_hour;   /* Hours (0-23) */
		int tm_mday;   /* Day of the month (1-31) */
		int tm_mon;    /* Month (0-11) */
		int tm_year;   /* Year - 1900 */
		int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
		int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
		int tm_isdst;  /* Daylight saving time */
	};

#endif
	const char * weekday[]={"Sunday","Monday","Tuesday","Wenesday","Thursday","Friday","Saturday"};
	printf("%04d-%02d-%02d, %s, %02d, %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday,weekday[p->tm_wday],p->tm_yday+1,p->tm_hour+8,p->tm_min,p->tm_sec);

	return 0;
}
