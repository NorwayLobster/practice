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
	if(argc!=4){
		perror("args error\n");
		return -1;
	}
	int fd_open,fd_open1;
	int ret;
//1.open()
	 int flag=O_RDWR|O_CREAT;
	 int flag1=O_RDWR|O_CREAT;
	 int flag2=O_RDWR|O_CREAT|O_EXCL;
	 int flag3=O_RDWR|O_CREAT|O_APPEND;
	 printf("flag:%x\n",flag);
	 printf("flag1:%x\n",flag1);
	 printf("flag2:%x\n",flag2);
	 printf("flag3:%x\n",flag3);

	fd_open=open(argv[1],flag2);
	if(-1==fd_open){
		perror("open() 1 error");
		return -1;
	}
	
	fd_open1=open(argv[2],flag1,0755);
	if(-1==fd_open1){
		perror("open() error");
		return -1;
	}
//2.creat()
//不常用	
//3.read()
	char buf[128];
	memset(buf,0,sizeof(buf));
	printf("buf:%s$\n",buf);
	ret=read(fd_open,buf,sizeof(buf)-1);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("read() error");
		return -1;
	}

	printf("buf:%s$\n",buf);


//9.close()
	close(fd_open);
	if(-1==ret){
		perror("close() error");
		return -1;
	}

//4.write()
	printf("-------------------\n");
//	fd_open=open(argv[1],flag);
	fd_open=open(argv[1],flag3);
	int ret_read;
	while(memset(buf,0,sizeof(buf)),ret_read=read(fd_open,buf,sizeof(buf)-1)){
		printf("in while loop,ret_read:%d\n",ret_read);
		ret=write(fd_open1,buf,sizeof(buf)-1);
		if(-1==ret)
		{
			perror("write() error");
			return -1;
		}
	}
	printf("ret_read:%d\n",ret_read);
	close(fd_open1);
	

//
//5.lseek()
	int fd_seek=open(argv[3],flag,0777);
	off_t offset=1024;
	int whence=SEEK_SET;	
	int whence1=SEEK_CUR;	
	int whence2=SEEK_END;	
	off_t off=lseek(fd_seek,offset,whence);
	printf("off:%ld\n",off);
//	bzero(buf,sizeof(buf));
	char a[10]="chengwang";
	ret=write(fd_seek,a,sizeof(a)-1);

//6.ftruncate()
	off_t len=10;
	ret=ftruncate(fd_seek,len);
	if(-1==ret)
	{
		perror("ftruncate() error");
		return -1;
	}
//7.truncate()
	len=20;
	ret=truncate(argv[1],len);
	if(-1==ret)
	{
		perror("truncate() error");
		return -1;
	}

//8.fstat()
#if 1
	struct stat * p_st=static_cast<struct stat*>(malloc(sizeof(struct stat)));
	shared_ptr<struct stat> shared_ptr(p_st);
#endif
//	shared_ptr<struct stat> shared_ptr(static_cast<struct stat>(malloc(sizeof(struct stat))));
	ret=fstat(fd_seek,p_st);
	if(-1==ret)
	{
		perror("fstat() error");
		return -1;
	}
	printf("%ld,%ld,%x,%ld,%d,%d\n",\
shared_ptr->st_dev,shared_ptr->st_ino,shared_ptr->st_mode,shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid);
//9.stat()
	memset(p_st,0,sizeof(struct stat));
	bzero(p_st,sizeof(struct stat));
	ret=stat(argv[2],p_st);
	if(-1==ret)
	{
		perror("stat() error");
		return -1;
	}
	printf("%ld,%ld,%x,%ld,%d,%d\n",\
shared_ptr->st_dev,shared_ptr->st_ino,shared_ptr->st_mode,shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid);
//10.S_ISLNK()
	printf("st_mode,is link or not:%d\n",S_ISLNK(shared_ptr->st_mode));
//11.S_ISDIR()
	printf("st_mode,is dir or not:%d\n",S_ISDIR(shared_ptr->st_mode));
//12.S_ISREG()
	printf("st_mode,is normal file or not:%d\n",S_ISREG(shared_ptr->st_mode));
//13.S_ISFIFO()
	printf("st_mode,is fifo or not:%d\n",S_ISFIFO(shared_ptr->st_mode));

	close(fd_seek);
	return 0;
}
