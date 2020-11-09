 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include "func.hpp"
int main(int argc, char**argv){
	if(argc!=2){
		perror("args error\n");
		return -1;
	}
	int fdw;
	int ret;
	 int flag=O_WRONLY;

	fdw=open(argv[1],flag);
	if(-1==fdw){
		perror("open() error");
		return -1;
	}
#if 1
	char buf[10]={0};
//	while(memset(buf,0,sizeof(buf),read(0,buf,sizeof(buf))){
	strcpy(buf,"chengwang");
	ret=write(fdw,buf, sizeof(buf));
	if(-1==ret){
		perror("write() error");
		return -1;
	}
//	}
	while(1);
#endif
	return 0;
}	
