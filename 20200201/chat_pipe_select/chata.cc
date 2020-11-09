 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include "func.hpp"
#include <sys/select.h>
#include <algorithm>
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
	printf("fdw:%d\n",fdw);
	printf("fdr:%d\n",fdr);

	char buf[1024]={0};
	int maxfd=max(fdw,fdr)+1;
#if 0 
	//select 内部实现机制
	int select(int maxfd,fd_set* p,,,,)
	{
		fd_set tmpset;

		memcpy(&tmpset,p,sizeof(fd_set));
		FD_ZERO(p);
		FD_SET(0,p);//若0可读
		FD_SET(fdr,p);//若fdr可读
	}
#endif 
	fd_set fdSet;//传入传出参数
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
				if(-1==ret){
					perror("write() error");
					return -1;
				}
				//退出机制 本端ctrl+d退出 ; ctrl+c进程退出,本段bye不打印
				if(ret==0){ 
					printf("bye\n");
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
				//退出机制 对端ctrl+c退出，或ctrl+d退出
				if(ret==0){
					printf("bye\n");
					break;
				}
				printf("from chat b:%s\n",buf);
			}
		}
		else {
			printf("do other job\n");
		}
	}
	close(fdr);
	close(fdw);

	return 0;
}	
