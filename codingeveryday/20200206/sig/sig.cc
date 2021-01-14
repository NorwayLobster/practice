 ///
 /// @file    sig.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-06 22:07:07
 ///
 
#include "func.hpp"

void sig(int signum){
	printf("signum %d is comming\n",signum);
	_exit(0);
}
	
int main(){
	sighandler_t ret;
	ret=signal(SIGINT,sig);
	PERROR(SIG_ERR,ret,"signal()");

//	while(1);
	sleep(10);//信号过来 唤醒

	return 0;
}
