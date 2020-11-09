 ///
 /// @file    recvn.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-14 04:10:59
 ///
 
#include <head.hpp>
int recvn(int fd,char *buf,int len){
	int ret=0;
	int sum=0;
	while(sum<len){
		ret=recv(fd,buf+sum,len-sum,0);
///		printf("in recvn ret=%d\n",ret);
		if(0==ret){
			return sum;
		}
		if(-1==ret){
			if(EINTR==errno){
				continue;
				printf("errno:%d\n",errno);
			}else{
				printf("errno:%d\n",errno);
				perror("recv()");
					return -1;
				}
		}
		sum+=ret;
	}
	return len;
}
