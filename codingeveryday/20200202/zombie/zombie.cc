 ///
 /// @file    fork_malloc.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 14:41:59
 ///
 
#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(-1==pid){
		perror("fork()");
		return -1;
	}
	if(0==pid){
		printf("i am child,pid:%d,ppid:%d\n",getpid(),getppid());
	}
	else{
		printf("i am parent,pid:%d,ppid:%d\n",getpid(),getppid());
		while(1);
	
	return 0;
	}
}
