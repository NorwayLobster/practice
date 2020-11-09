 ///
 /// @file    fork_malloc.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 14:41:59
 ///
 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
int main(){
	pid_t pid;
	char * p =(char*) malloc(20);
	strcpy(p,"hello");
	printf("main,p:%p,%s\n",p,p);
	pid=fork();
	if(-1==pid){
		perror("fork()");
		return -1;
	}
	if(0==pid){
		printf("i am child\n");
		printf("child,p:%p,%s\n",p,p);
	}
	else{
		printf("i am parent\n");
		printf("parent,p:%p,%s\n",p,p);
		strcpy(p,"world");
		printf("parent,p:%p,%s\n",p,p);
	}
	return 0;
}
