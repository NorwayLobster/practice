 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <func.hpp>
#include<pwd.h>
#include<time.h>
#include<grp.h>
int main(int argc, char**argv){
	if(argc!=5){
		perror("args error\n");
		return -1;
	}
	int fd_open,fd_open1;
	int ret;
	 int flag=O_RDWR|O_CREAT|O_APPEND;

	fd_open=open(argv[1],flag,0777);
	printf("fd_open:%d\n",fd_open);
	if(-1==fd_open){
		perror("open() error");
		return -1;
	}
	
	ret=write(fd_open,"chengwang",10);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("write() error");
		return -1;
	}
//1.dup():自动分配未使用fd中最小的描述符
	int fd_dup=dup(fd_open);	
	printf("fd_dup:%d\n",fd_dup);
	close(fd_open);
	
//2.dup2():指定new_fd,若new_fd已经被使用，则内核为1.关闭new_fd，2.执行复制
//// attention: 必须刷新该new_fd的内核缓冲区
    ret=dup2(fd_dup,1);	
	if(-1==ret){
		perror("dup2() error");
		return -1;
	}
//	ret=write(fd_open,"chengwang",10);
//	ret=write(fd_dup,"chengwang",10);
	ret=write(1,"chengwang",10);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("write() error");
		return -1;
	}
	close(1);
	close(fd_dup);

//3.fsync()
//4.unlink():删除文件
	ret=unlink(argv[2]);
	if(-1==ret){
		perror("unlink() error");
		return -1;
	}
//5.rename():重命名文件
	char newPath[1024]={0};
	strcpy(newPath,argv[4]);

	ret=rename(argv[3],newPath);
	if(-1==ret){
		perror("rename() error");
		return -1;
	}
	return 0;
}
