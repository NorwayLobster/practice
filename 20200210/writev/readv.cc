///
/// @file    tcpserver.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-09 14:17:21
///

#include "func.hpp"
#define scatter_NUM 2
int main(int argc,char**argv){
	int ret;
	if(1!=argc){
		perror("args error");
		_exit(-1);
	}

	struct iovec iov[scatter_NUM];
//struct iovec {
//	void  *iov_base;    /* Starting address */
//	size_t iov_len;     /* Number of bytes to transfer */
//};
	char buf[10]={0};
	char buf1[10]={0};
	int fd=open("file",O_RDWR);	
	assert(-1!=fd);


	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=5;

	ret=readv(fd,iov,scatter_NUM);
	assert(-1!=ret);
	puts(buf);
	puts(buf1);
	return 0;
}
