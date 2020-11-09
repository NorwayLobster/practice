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
	if(1!=argc){
		perror("args error");
		return -1;
	}
	system("ls -l");
	sleep(15);
	printf("can you come here");
	return -1;
}
