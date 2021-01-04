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
	sigac.sa_flags=SA_SIGINFO|SA_NODEFER;//nodefer 可打断包括同样信号,即不断重入
//	sigac.sa_mask=;

	ret=sigaction(SIGINT,&sigac,NULL);
	PERROR(-1,ret,"sigaction() 1");
//error:	ret=sigaction(SIGSTOP,&sigac,NULL);
	ret=sigaction(SIGQUIT,&sigac,NULL);
	PERROR(-1,ret,"sigaction() 2");

    while(1);

	return 0;
}
