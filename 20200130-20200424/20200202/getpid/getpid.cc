 ///
 /// @file    getpid.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 11:40:12
 ///
 
#include "func.hpp"
#include <cstdio>
#include <unistd.h>
int main(int argc,char ** argv){
	if(2!=argc){
		perror("args");
		return -1;
	}

//1.getpid()
	printf("pid:%d,ppid:%d\n", getpid(),getppid());
//2.getuid() 真实用户id
	printf("uid:%d\n", getuid());
//3.getgid()  真实组id
	printf("gid:%d\n", getegid());
//4.geteuid() 有效用户id  内核做事情检测有效id
//通过chmode u+s a.out 当其他用户执行a.out时，他的euid变成a.out的真实uid
	printf("euid:%d\n", geteuid());
//5.getegid()  有效组id
	printf("egid:%d\n", getegid());

	int fd = open(argv[1],O_RDWR);
	if(-1==fd){
		perror("open");
		return -1;
	}
	write(fd,"love you",10);
	close(fd);
	while(1);

	return 0;
}

