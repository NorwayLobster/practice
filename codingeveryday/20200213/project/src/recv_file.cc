 ///
 /// @file    recv_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-13 19:59:52
 ///
 
#include <head.hpp>


int recv_file(int newfd){
//int recv_file(int newfd,char *filename,int len){
	int ret;
	Train t;
	char filename[1024]={0};
	bzero(&t,sizeof(Train));

	recvn(newfd,(char*)&t,4);
	recvn(newfd,t.buf,t.len);
	memcpy(filename,t.buf,t.len);
	puts(filename);
//	printf("t.len:%d\n",t.len);
//	printf("filename:%s\n",filename);
	int fd=open(filename,O_WRONLY|O_CREAT,0754);
	assert(-1!=fd);
	while(1){
		recvn(newfd,(char*)&t,4);
//		ret=recvn(newfd,(char*)&t,4+sizeof(t.buf));
//		printf("t.len:%d\n",t.len);
		if(0==t.len)
			break;
		recvn(newfd,t.buf,t.len);
		ret=write(fd,t.buf,t.len);
		assert(-1!=ret);
	}
	return 0;
}


int recv_file(int newfd,char *filename,int len){//重载
	int ret;
	Train t;
	bzero(&t,sizeof(Train));
	printf("filename:%s\n",filename);

	int fd=open(filename,O_WRONLY|O_CREAT|O_APPEND);
	assert(-1!=fd);
//	lseek(fd,0,SEEK_END);
	while(1){
		recvn(newfd,(char*)&t,4);
//		ret=recvn(newfd,(char*)&t,4+sizeof(t.buf));
//		printf("t.len:%d\n",t.len);
		if(0==t.len)
			break;
		recvn(newfd,t.buf,t.len);
		ret=write(fd,t.buf,t.len);
		assert(-1!=ret);
	}
	return 0;
}

int recv_file(int newfd,int fd,int len){//重载
	int ret;
	Train t;
	bzero(&t,sizeof(Train));

	printf("in recv_file func fd:%d\n",fd);
	printf("newfd:%d\n",newfd);
	while(1){
		recvn(newfd,(char*)&t,4);
//		ret=recvn(newfd,(char*)&t,4+sizeof(t.buf));
//		printf("t.len:%d\n",t.len);
		if(0==t.len)
			break;
		recvn(newfd,t.buf,t.len);

//		printf("t.buf:%s\n",t.buf);
//		printf("strlen(t.buf):%lu\n",strlen(t.buf));
//		printf("before write fd:%d\n",fd);
//		ret=write(fd,"hello",5);
		ret=write(fd,t.buf,t.len);
		assert(-1!=ret);
	}
	return 0;
}
