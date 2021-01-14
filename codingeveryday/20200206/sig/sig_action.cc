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

//	while(1);
	sleep(10);//信号过来 唤醒
//1. 默认相同信号，不会打断自身的 信号处理流程
//
//2. 默认不同信号，会打断当前的 信号处理流程
//
//3. 2号 3号 2号， 信号压栈，最后的2号信号 忽略
//
//4. 2号 2号 2号 2号....，  最多执行两边 ：pcb结构体存储原因

	return 0;
}
