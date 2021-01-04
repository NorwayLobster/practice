 ///
 /// @file    send_download_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 04:05:46
 ///
 
#include <head.hpp>
int send_file_client(int newfd,char *arg1){
	int ret;
	char file_real_full_path[16]={0};
	char text[16]={0};
	char md5sum_code[128]={0};
	Train t;
	strcpy(file_real_full_path,"./");
	strcat(file_real_full_path,arg1);
	puts(file_real_full_path);
	int file_size_byte=0;
	struct stat st;
	stat(file_real_full_path,&st);
	file_size_byte=st.st_size;

	int fd=open(file_real_full_path,O_RDONLY);
	strcpy(text,"puts ");
	strcat(text,arg1);
	sprintf(text,"%s %d ",text,file_size_byte);
	puts(text);
	send_train(newfd,&t,text);

	ret=md5sum(file_real_full_path,md5sum_code);
	puts(md5sum_code);
	send_train(newfd,&t,md5sum_code);

	memset(text,0,sizeof(text));
	recv_train(newfd,&t,text);
	puts(text);
//	spleep(4);
	off_t offset=0;
	if(0==strcmp(text,"finish")){
		printf("this file already exists in our server, finish puts\n");
		close(fd);
	}else{
		if(file_size_byte>100*1024*1024){//100M
//			send_file_by_mmap(newfd,file_real_full_path,offset);//不考虑断点上传, 上传失败是不可能
			send_file_by_sendfile(newfd,file_real_full_path,offset);//不考虑断点上传, 上传失败是不可能
		}else{
			send_file(newfd,fd,0);
		}
		memset(text,0,sizeof(text));
		recv_train(newfd,&t,text);
		puts(text);
	}
	return 0;
}
