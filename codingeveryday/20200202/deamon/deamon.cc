///
/// @file    fork_malloc.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-02 14:41:59
///

#include "func.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(-1==pid){
		perror("fork()");
		return -1;
	}

	if(0<pid){
		exit(4);
	}
	pid_t sid;
	printf("sid:%d,gid:%d\n",getsid(0),getpgid(0));
	sid=setsid();
	printf("new sid:%d\n",sid);
	printf("sid:%d,gid:%d\n",getsid(0),getpgid(0));


	chdir("/");
	umask(0);
	
	close(0);
	close(1);
	close(2);

	//while(1);
	while(1){
		sleep(1);
	}

	return 0;
}
