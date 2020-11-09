 ///
 /// @file    send_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:09:15
 ///
 
#include <head.hpp>


int send_file(int newfd,int fd,int offset){
//	printf("sendn()\n");
	printf("send_file()\n");
	int ret;
	Train t;

	lseek(fd,offset,SEEK_SET);
//	printf("len:%d,%d\n",len,t.len);
//	printf("t.buf:%s\n",t.buf);
	
//	sendn(newfd,(char*)&t,4+sizeof(t.buf));
//	sendn(newfd,(char*)&t,4+t.len);

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
