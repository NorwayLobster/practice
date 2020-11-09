 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include "func.hpp"
#include<algorithm>
using std::max;
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
	printf("fdw:%d\n",fdw);
	printf("fdr:%d\n",fdr);

	char buf[1024]={0};

	int maxfd=max(fdr,fdw)+1;
	fd_set fdSet;
	struct timeval timeout;
	while(1){
		FD_ZERO(&fdSet);
		FD_SET(0,&fdSet);
		FD_SET(fdr,&fdSet);
		timeout.tv_sec=6;
//		ret=select(maxfd,&fdSet,NULL,NULL,NULL);//目前用来监控可写，但其也可以监控可读
		ret=select(maxfd,&fdSet,NULL,NULL,&timeout);//目前用来监控可写，但其也可以监控可读
		if(ret>0){
			if(FD_ISSET(0,&fdSet)){
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(0==ret){
					printf("bye");
					break;
				}
				ret=write(fdw,buf, strlen(buf)-1);
				if(-1==ret){
					perror("write() error");
					return -1;
				}
			}
			if(FD_ISSET(fdr,&fdSet)){
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf, sizeof(buf));
				if(-1==ret){
					perror("read() error");
					return -1;
				}
				if(0==ret){
					printf("bye");
					break;
				}
				printf("from chat a:%s\n",buf);
			}
		}
		else{
			printf("do other job\n");
		}
	}
	close(fdr);
	close(fdw);

	return 0;
}	
