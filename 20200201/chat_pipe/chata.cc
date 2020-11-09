 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include "func.hpp"
int main(int argc, char**argv){
	if(argc!=3){
		perror("args error\n");
		return -1;
	}
	int fdr,fdw;
	int ret;
	int flag=O_RDONLY;
	int flag1=O_WRONLY;

	fdr=open(argv[1],flag);
	fdw=open(argv[2],flag1);
	if(-1==fdr){
		perror("open() error");
		return -1;
	}
	if(-1==fdw){
		perror("open() error");
		return -1;
	}

	char buf[1024]={0};

	printf("i am a, me first talk\n");
	while(memset(buf,0,sizeof(buf)),read(0,buf,sizeof(buf))){

		ret=write(fdw,buf, strlen(buf)-1);
		if(-1==ret){
			perror("write() error");
			return -1;
		}

		memset(buf,0,sizeof(buf));
		ret=read(fdr,buf, sizeof(buf));
		if(-1==ret){
			perror("read() error");
			return -1;
		}
//c标准库IO，stdout为行缓冲		printf("from chat b:%s",buf);
		printf("from chat b:%s\n",buf);
	}

	return 0;
}	
