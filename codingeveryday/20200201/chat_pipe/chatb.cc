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

	fdw=open(argv[1],flag1);
	fdr=open(argv[2],flag);
	if(-1==fdr){
		perror("open() error");
		return -1;
	}
	if(-1==fdw){
		perror("open() error");
		return -1;
	}

	char buf[1024]={0};

	printf("i am b, a first talk\n");
	while(memset(buf,0,sizeof(buf)),read(fdr,buf,sizeof(buf))){

		printf("from chat a:%s\n",buf);

		memset(buf,0,sizeof(buf));
		read(0,buf,sizeof(buf));
		ret=write(fdw,buf, strlen(buf)-1);
		if(-1==ret){
			perror("write() error");
			return -1;
		}

	}

	return 0;
}	
