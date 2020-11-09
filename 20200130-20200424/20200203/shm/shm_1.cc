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
#if 1
	shmflag=IPC_CREAT|0666;
	shmid=shmget(key,size,shmflag);
	PERROR(-1,shmid,"shmget()");
	printf("shmid:%d\n",shmid);

#endif
	char *p;
	p=(char*)shmat(shmid,NULL,0);
	printf("p:%p\n",p);

	puts(p);
	while(1);
	return 0;
}
