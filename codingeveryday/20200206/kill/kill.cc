 ///
 /// @file    sigprocmask.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-07 13:22:21
 ///
 
#include "func.hpp"
int main(int argc,char**argv){

	if(3!=argc){
		perror("args error");
		_exit(0);
	}
	int ret;
	int pid=atoi(argv[2]);
	int sig_no=atoi(argv[1]);
	printf("pid:%d,sig_no:%d\n",pid,sig_no);

	ret=kill(pid,sig_no);
	PERROR(-1,ret,"kill() ");
	return 0;
}
