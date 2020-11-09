 ///
 /// @file    send_file_by_mmap.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-18 04:00:56
 ///
 
#include <head.hpp>
int send_file_by_sendfile(int newfd,char * file_real_full_path,int _offset){
 
	int fd_open;
	int ret;
	int flag=O_RDWR|O_CREAT|O_APPEND;

	fd_open=open(file_real_full_path,flag,0777);
	printf("fd_open:%d\n",fd_open);
	if(-1==fd_open){
		perror("open() error");
		return -1;
	}
	
//1.sendfile()
	struct stat st;	
	fstat(fd_open,&st);
	int len=st.st_size;
	int sum=0;
	off_t offset=_offset;
	while(sum<len){
		ret=sendfile(newfd,fd_open,&offset,len-sum);//对端断开，在send，
		if(0==ret){
			printf("errno:%d,ret:%d\n",errno,ret);
			return 0;//有没有可能，发送缓冲区正好满了，本次发送0个字节？？？
		}
		if(ret<0){
			if(ret==-1 and EINTR==errno){//被信号打断，
				printf("errno:%d\n",errno);
				continue;
			}else{
				perror("send()");
				return -1;//出错
			}
		}
	
		sum+=ret;
	}

	close(fd_open);
	return 0;
}

	

