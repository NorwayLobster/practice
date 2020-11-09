 ///
 /// @file    sigprocmask.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-07 13:22:21
 ///
 
#include "func.hpp"
void sig(int signum){
	printf("before sleep,signum %d is comming\n",signum);
	sleep(3);
	printf("before sleep,signum %d is comming\n",signum);
}	
int main(int argc,char**argv){
	sighandler_t rt;
	rt=signal(SIGALRM,sig);
	PERROR((sighandler_t)-1,rt,"signal() ");
	int ret;
	ret=alarm(3); //等待 3 秒之后自动产生 SIGALRM 信号
	PERROR(-1,ret,"alarm() ");
	ret=pause(); //将进程挂起，直到有信号发生才退出挂起状态
	PERROR(-1,ret,"pause() ");
	return 0;
}
