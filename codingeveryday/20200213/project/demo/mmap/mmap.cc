 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <func.hpp>
#include <sys/mman.h>
int main(int argc, char**argv){
	if(argc!=2){
		perror("args error\n");
		return -1;
	}
	int fd_open;
	int ret;
	int flag=O_RDWR|O_CREAT|O_APPEND;

	fd_open=open(argv[1],flag,0777);
	printf("fd_open:%d\n",fd_open);
	if(-1==fd_open){
		perror("open() error");
		return -1;
	}
	
//1.mmap()
	int len=4096;
	char *p;
	p=(char*)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd_open,0);
	if((char*)-1==p){
		perror("mmap() error");
		return -1;
	}

	printf("p[0]:%c\n",p[0]);
//	char buf[10]="ChengWANG";
	char buf[10]="world";
	strcpy(p,buf);

//1.munmap()
	ret=munmap(p,len);
	if(-1==ret){
		perror("close() error");
		return -1;
	}


	ret=close(fd_open);
	if(-1==ret){
		perror("close() error");
		return -1;
	}


	return 0;
}

