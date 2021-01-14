 ///
 /// @file    sendn.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:10:06
 ///
 

#include <head.hpp>
int sendn(int fd,char *buf,int len){
	//printf("in sendn,len=%d\n",len);
	int ret=0;
	int sum=0;
	while(sum<len){
		ret=send(fd,buf+sum,len-sum,0);//对端断开，在send，
		//printf("send ret:%d\n",ret);
		if(0==ret)  return 0;//有没有可能，发送缓冲区正好满了，本次发送0个字节？？？
		if(ret<0){
			if(ret==-1 and EINTR==errno){//被信号打断，
				printf("errno:%d\n",errno);
				continue;
			}else{
				perror("send()");
				return -1;//出错
			}
		}
	
	//	printf("in sendn: ret:%d,sum=%d\n",ret,sum);
		sum+=ret;
	}
	return len;
}
