 ///
 /// @file    send_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:09:15
 ///
 
#include "head.hpp"


int send_file(int newfd,char *filename,int len){
//	printf("sendn()\n");
	int ret;
	Train t;

	bzero(t.buf,sizeof(t.buf));
	memcpy(t.buf,filename,len);
	int fd=open(t.buf,O_RDONLY);
	t.len=len;//文件名长度
//	printf("len:%d,%d\n",len,t.len);
//	printf("t.buf:%s\n",t.buf);
	
//	sendn(newfd,(char*)&t,4+sizeof(t.buf));
	sendn(newfd,(char*)&t,4+t.len);

	while(1){
//		printf("in while\n");

		ret=read(fd,t.buf,sizeof(t.buf));
//		printf("in while read ret:%d\n",ret);
		t.len=ret;
		ret=sendn(newfd,(char*)&t,4+ret);
//		printf("in while snedn ret:%d\n",ret);
		if(4==ret){
//			printf("in while break ret:%d\n",ret);
			break;
		}	
		if(-1==ret){
			printf("in while return ret:%d\n",ret);
			return -1;
		}
	}
	return 0;
}
