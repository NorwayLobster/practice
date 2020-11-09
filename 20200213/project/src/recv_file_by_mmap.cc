 ///
 /// @file    recv_file_by_mmap.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-18 04:34:40
 ///
 
#include <head.hpp>
int recv_file_by_mmap(int newfd,char * file_real_full_path,int file_len_bytes ){
 
	int fd_open;
	int ret;
	int flag=O_RDWR|O_CREAT|O_APPEND;

	fd_open=open(file_real_full_path,flag,0777);
	printf("fd_open:%d\n",fd_open);
	if(-1==fd_open){
		perror("open() error");
		return -1;
	}
	struct stat st;
	fstat(fd_open,&st);
	int offset_mmap=0;//只能是pagesize的整数倍
	int offset_file=st.st_size;//文件现在有的大小，是断点的文件；非断点文件，即为0

	int len=file_len_bytes+offset_file;//总大小
	
	ret=ftruncate(fd_open,len);
	if(-1==ret){
		perror("ftruncate() error");
		return -1;
	}
//1.mmap()
	
	char *p;
//	len是从起始映射点开始，映射len个字节
	p=(char*)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd_open,offset_mmap);//offset从文件的开始，偏移多少作文mmap的起始映射点，
	if((char*)-1==p){
		perror("mmap() error");
		return -1;
	}

	printf("p[0]:%c\n",p[0]);
	printf("p[0]:%c\n",p[0]);
	printf("p[4096]:%c\n",p[4095]);

//send(newfd,p,...);可以吗？ 不可以
//sendn可以，把p想象成一个很大很大的buf
	ret=recvn(newfd,p+offset_file,len);//从文件尾部开始写入

//还需要用火车一节一节吗？  不需要了
//	Train t;	
//	int total=0;
//	while(total<file_size_byte){
//		memset(t,0,sizeof(Train));
//		t.len=4092; 
//		memcpy(t.buf,p,t.len);
//		ret=sendn(newfd,(char*)&t,4+t.len);
//		if(-1==ret) return -1;
//		p=p+4092;
//		total=+4092;
//	}

	ret=munmap(p,len);
	close(fd_open);
	return 0;
}

	

