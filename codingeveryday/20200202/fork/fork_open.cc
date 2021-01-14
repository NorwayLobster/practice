 ///
 /// @file    fork_malloc.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 14:41:59
 ///
 
#include "func.hpp"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#define 	PERROR(val,ret,name)\
{	 char buf[1024]={0};sprintf(buf,"%s error",name); if((val)==(ret)){ perror(buf); return -1; }}

int k=5;
int main(int argc,char** argv){
	if(2!=argc){
		perror("args error");
		return -1;
	}
	pid_t pid;
	int k=open(argv[1],O_RDWR);
	PERROR(-1,k,"open()")
	printf("main,&k:%p,%d\n",&k,k);
	pid=fork();
	if(-1==pid){
		char s[1024]="for()";
		perror(s);
//		perror("fork()");
		return -1;
	}

	off_t off=1;
	if(0==pid){
		printf("i am child\n");
		write(k,"world",5);
		printf("child,&fd:%p,%d\n",&k,k);

	}
	else{
		printf("i am parent\n");
		write(k,"hello",5);
		sleep(5);
		char buf[2014]={0};
		lseek(k,off,SEEK_SET);
		read(k,buf,sizeof(buf));
		puts(buf);
		printf("parent,&k:%p,%d\n",&k,k);
	}
	return 0;
}
