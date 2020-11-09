 ///
 /// @file    sigprocmask.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-07 13:22:21
 ///
 
#include "func.hpp"
void sig(int signum){
	printf("before sleep,signum %d is comming\n",signum);
	sleep(3);	
	printf("after sleep,signum %d is comming\n",signum);
}
int main(){

	sigset_t  set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);


	sigset_t pend;
	memset(&pend,0,sizeof(pend));
	int ret;


//1.sigprocmask() //延缓信号处理函数的执行
	sigprocmask(SIG_BLOCK,&set,NULL);
	sleep(4);


	sighandler_t rt;
	rt=signal(SIGINT,sig);
	PERROR((sighandler_t)-1,rt,"signal()");



	ret=sigpending(&pend);
	PERROR(-1,ret,"sigpending()");

	ret=sigismember(&pend,SIGINT);
	PERROR(-1,ret,"sigismember()");
	if(1==ret){
		printf("%d is pending\n",SIGINT);
	}else{
		printf("%d is not pending\n",SIGINT);
	}
	sigprocmask(SIG_UNBLOCK,&set,NULL);

			

	return 0;
}
