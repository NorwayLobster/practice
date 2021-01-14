///
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
//两种时间：秒数
//			字符串时间即格林尼治时间
const char * weekday[]={"Sunday","Monday","Tuesday","Wenesday","Thursday","Friday","Saturday"};
void sig(int signum){
	printf("before,signum %d is coming \n",signum);

	time_t t;
	t=time(NULL);//
	printf("time:%ld\n",t);

	//or time(&t);
	struct tm * p;
	p=gmtime(&t);
	printf("%04d-%02d-%02d, %s, %02d, %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday,weekday[p->tm_wday],p->tm_yday+1,p->tm_hour+8,p->tm_min,p->tm_sec);

	printf("after,signum %d is coming \n",signum);
	printf("\n");
}

//real 真实计时器：用户态+ 内核态+sleep
int main(){
	int ret;
	signal(SIGALRM,sig);

#if 0
	time_t t;
	t=time(NULL);//
	printf("time:%ld\n",t);
	struct tm * p;
	p=gmtime(&t);
	printf("%04d-%02d-%02d, %s, %02d, %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday,weekday[p->tm_wday],p->tm_yday+1,p->tm_hour+8,p->tm_min,p->tm_sec);
	printf("\n");
#endif
	kill(0,SIGALRM);//pid=0时表向自己发信号



	int which=ITIMER_REAL;
	struct itimerval it;
	memset(&it,0,sizeof(struct itimerval));
	
//	struct itimerval {
//		struct timeval it_interval; /* Interval for periodic timer */
//		struct timeval it_value;    /* Time until next expiration *///初始间隔
//	};
//
//	struct timeval {
//		time_t      tv_sec;         /* seconds */
//		suseconds_t tv_usec;        /* microseconds */
//	};

	ret=getitimer(which,&it);

	it.it_interval.tv_sec=3;
	it.it_value.tv_sec=2;//初始间隔时间
	PERROR(-1,ret,"getitimer");

	ret=setitimer(which,&it,NULL);
	PERROR(-1,ret,"setitimer");
	
	while(1){
		pause();
	}
//note:	sleep(1);//note:sleep也用SIGALRM信号
	


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


	return 0;
}
