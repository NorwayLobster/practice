 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <func.hpp>
#include <sys/mman.h>
#include <cstring>

typedef struct tag {
	long int stu_no;
	int score;
	char name[1024];
}stu,*p_stu;

void print(const shared_ptr<stu> &p){
	printf("stu_no:%ld,score:%d,name:%s\n",p->stu_no,p->score,p->name);
}
int main(int argc, char**argv){
	if(argc!=5){
		perror("args error\n");
		return -1;
	}
	int ret;
//1.init struct
	p_stu _p=(p_stu)new stu;
	shared_ptr<stu> p(_p);
	p->stu_no=atoi(argv[2]);
	p->score=atoi(argv[3]);
	strcpy(p->name,argv[4]);
	print(p);
//2.create file and open it
	int fd=open(argv[1],O_RDWR|O_CREAT|O_APPEND,0777);


	char buf[1024];
	printf("buf size:%ld\n",sizeof(buf));
	memset(buf,0,sizeof(buf));

//3. convert struct to string 
//note:把结构体转成字符串
	sprintf(buf,"%ld %d %s",p->stu_no,p->score,p->name);
	puts(buf);

//4.  write it to file
//note:write() 只能写字符流, int,long 等不能写入
//note:区别 
//	ret=write(fd,buf,sizeof(buf));//很多00000
	ret=write(fd,buf,strlen(buf));
	if(-1==ret){
		perror("write error\n");
		return -1;
	}


//5.  empty it 
	 memset(_p,0,sizeof(stu));
	 memset(buf,0,sizeof(buf));
	 print(p);

//6.   lseek 
	 lseek(fd,0,SEEK_SET);
//7.  read from file to buf
	 read(fd,buf,sizeof(buf));

//8.  scanf from string to struct 
	 sscanf(buf,"%ld%d %s",&p->stu_no,&p->score,p->name);
	
//9.  print
	print(p);
	
	return 0;
}
