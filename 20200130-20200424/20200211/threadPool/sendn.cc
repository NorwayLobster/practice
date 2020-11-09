 ///
 /// @file    sendn.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:10:06
 ///
 

#include "head.hpp"
int sendn(int fd,char *buf,int len){
	//printf("in sendn,len=%d\n",len);
	int ret=0;
	int sum=0;
	while(sum<len){
		ret=send(fd,buf+sum,len-sum,0);
		//printf("send ret:%d\n",ret);

		if(ret==-1){
			printf("errno:%d\n",errno);
			perror("send()");
			return -1;
		}
	
	//	printf("in sendn: ret:%d,sum=%d\n",ret,sum);
		sum+=ret;
	}
	return len;
}
