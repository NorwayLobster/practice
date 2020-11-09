///
/// @file    fork_malloc.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-02 14:41:59
///

#include "func.hpp"
#include <cstdlib>
#include <limits.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#define N (10000000)
int add(int,int);
int main(int argc,char** argv){
	if(2!=argc){
		perror("args error");
		return -1;
	}
	int ret;
	//1.ftok()
	int proj_id=2;
	key_t key;
	key=ftok(argv[1],proj_id);
	PERROR(-1,key,"ftok()");
	printf("key:%d\n",key);

	size_t size=4096;
	int shmid;
	//2.shmget()
	int shmflag;
	shmflag=IPC_CREAT|0666;
	shmid=shmget(key,size,shmflag);
	PERROR(-1,shmid,"shmget()");
	printf("shmid:%d\n",shmid);

	int *p=(int *)shmat(shmid,NULL,0);
//note:一定初始化
	p[0]=0;
	PERROR((int*)-1,p,"shmat()");

	pid_t pid=fork();
	PERROR(-1,pid,"fork()");
	
	if(0==pid){
		printf("child\n");
		for(int i=0;i<N;++i)
//			p[0]+=1;
			p[0]=p[0]+1;
		return 0;//if else 之后的不会执行了
	}else {
		printf("parent\n");
		for(int i=0;i<N;++i)
			p[0]=p[0]+1;
		int status;
		waitpid(pid,&status,0);
		printf("INT_MAX:%d\n",INT_MAX);
		printf("p[0]:%d\n",p[0]);
	}



	return 0;
}
