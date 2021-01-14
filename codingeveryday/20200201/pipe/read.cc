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
	int fdr;
	int ret;
	 int flag=O_RDONLY;

	fdr=open(argv[1],flag);
	if(-1==fdr){
		perror("open() error");
		return -1;
	}
	char buf[1024]={0};
	ret=read(fdr,buf, sizeof(buf));
	if(-1==ret){
		perror("read() error");
		return -1;
	}
	puts(buf);
	return 0;
}	
