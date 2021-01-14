 ///
 /// @file    taskhandler.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 12:58:33
 ///
 
#include "head.hpp"
char FILENAME[1024]="file";

void *task_handler(int newfd,void*p){
	int ret;
	int minfd=open("file",O_RDWR);
	printf("child min free fd:%d\n",minfd);
	
	printf("send_file\n");
	ret=send_file(newfd,FILENAME,strlen(FILENAME));

	//ret=recv(newfd,buf,sizeof(buf)-1,0);
	if(-1==ret){
		printf("client abort unexpectedly:%d\n",ret);
		close(newfd);//客户端异常退出
	}else{
		close(newfd);//客户端异常退出
		printf("finish jobs, close client's fd:%d\n",ret);
	}
	return 0;
}


