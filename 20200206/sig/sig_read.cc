 ///
 /// @file    sig.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-06 22:07:07
 ///
 
#include "func.hpp"

void sig(int signum){
	printf("before sleep,signum %d is comming\n",signum);
	sleep(3);
	printf("aftersleep,signum %d is comming\n",signum);
	printf("\n");
}
//信号的使用场景：实现有序退出	
int main(){
	sighandler_t ret;
	ret=signal(SIGINT,sig);
	PERROR(SIG_ERR,ret,"signal()");

	ret=signal(SIGQUIT,sig);
	PERROR(SIG_ERR,ret,"signal()");
	
	char buf[64]={0};
	//read(STDIN,buf,sizeof(buf));
	read(0,buf,sizeof(buf));//打断read，回来后，继续阻塞
	puts(buf);

	return 0;
}
