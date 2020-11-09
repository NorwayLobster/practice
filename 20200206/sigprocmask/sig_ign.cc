 ///
 /// @file    sig.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-06 22:07:07
 ///
 
#include "func.hpp"

int main(){
	sighandler_t ret;
	ret=signal(SIGINT,SIG_IGN);//忽略sigint
	PERROR(SIG_ERR,ret,"signal()");
	sleep(4);
	ret=signal(SIGINT,SIG_DFL);//回复默认
	PERROR(SIG_ERR,ret,"signal()");

//	while(1);
//	sleep(10);//信号过来 唤醒

	return 0;
}
