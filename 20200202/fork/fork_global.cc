 ///
 /// @file    fork_malloc.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 14:41:59
 ///
 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
int k=5;
int main(){
	pid_t pid;
	printf("main,&k:%p,%d\n",&k,k);
	pid=fork();
	if(-1==pid){
		perror("fork()");
		return -1;
	}
	if(0==pid){
		printf("i am child\n");
		printf("child,&k:%p,%d\n",&k,k);
		k=12;
		printf("child,&k:%p,%d\n",&k,k);
	}
	else{
		printf("i am parent\n");
		printf("parent,&k:%p,%d\n",&k,k);
		k=12;
		printf("parent,&k:%p,%d\n",&k,k);
	}
	return 0;
}
