///
/// @file    sig.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-06 22:07:07
///

#include "func.hpp"

void sig(int signum,siginfo_t* p,void *p1){
	printf("before sleep,signum %d is comming\n",signum);
	sleep(2);
	printf("after sleep,signum %d is comming\n",signum);
}

int main(){
//	sighandler_t ret;
	int ret;
	struct sigaction sigac;
	memset(&sigac,0,sizeof(sigac));
//	struct sigaction {
//		void     (*sa_handler)(int);
//		void     (*sa_sigaction)(int, siginfo_t *, void *);
//		sigset_t   sa_mask;
//		int        sa_flags;
//		void     (*sa_restorer)(void);
//	};
//
	sigac.sa_sigaction=sig;
	sigac.sa_flags=SA_SIGINFO;

	sigemptyset(&sigac.sa_mask);
	sigaddset(&sigac.sa_mask,SIGQUIT);//2号执行完，在执行3号
//	sigac.sa_mask=;

	ret=sigaction(SIGINT,&sigac,NULL);
	PERROR(-1,ret,"sigaction()");

	ret=sigaction(SIGQUIT,&sigac,NULL);
	PERROR(-1,ret,"sigaction()");
	
	sleep(4);


	return 0;
}
