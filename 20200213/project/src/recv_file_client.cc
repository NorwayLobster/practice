 ///
 /// @file    recv_upload_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 04:55:45
 ///
 
#include <head.hpp>
#if 1
int recv_file_client(int newfd,char *arg1){
	char md5sum_code[128]={0};
	char md5sum_code_server[128]={0};
	int fd;
	Train t;
	char file_real_full_path[128]={0};
	strcpy(file_real_full_path,"./");
	strcat(file_real_full_path,arg1);
	puts(file_real_full_path);
	fd=open(file_real_full_path, O_RDWR);
	printf("fd:%d\n",fd);
	off_t offset;	
	if(-1==fd){
		printf("no this file in client\n");
		offset=0;	
		fd=open(file_real_full_path, O_RDWR|O_CREAT|O_APPEND);
		printf(" below re-open fd:%d\n",fd);
		assert(-1!=fd);
		umask(0);
//		fchmod(fd,0754);
	}else{
		printf("file regetting\n");
		struct stat st;
		fstat(fd,&st);
		offset=st.st_size;	
		printf("st.st_size:%ld\n",offset);
		lseek(fd,offset,SEEK_SET);//偏移到文件尾，准备接收文件
		printf(" below lseek fd:%d\n",fd);
	}
	
	printf(" below if-else fd:%d\n",fd);
	char text[32]={0};
	strcpy(text,"gets ");
	strcat(text,arg1);
	sprintf(text,"%s %ld",text,offset);
	puts(text);
	send_train(newfd,&t,text);	
	printf(" below send_train fd:%d\n",fd);
		
	memset(text,0,sizeof(text));
	puts(text);
	recv_train(newfd,&t,text);
	printf(" below recv_train fd:%d\n",fd);
	if(0==strcmp("no",text)){
		printf("sorry, no this file in our server\n");
		close(fd);
	}else{
		printf(" below else fd:%d\n",fd);
		int left_len=0;
		printf(" before left_len recv_train fd:%d\n",fd);
//fatal error:		recv_train(newfd,&t,(char*)&left_len);
		recvn(newfd,(char*)&left_len,4);
		printf(" before left_len recv_train fd:%d\n",fd);
		printf("left_len:%d\n",left_len);
		printf(" below left_len recv_train fd:%d\n",fd);
		if(left_len>100*1024*1024){
			printf(" >100M fd:%d\n",fd);
			recv_file_by_mmap(newfd,file_real_full_path,left_len);
//			send_file_by_sendfile(newfd,file_real_full_path,0);
		}else{
			printf("before recv_file fd:%d\n",fd);
			recv_file(newfd,fd,0);//lseek() 断点下载// 此处的fd为已经为断点偏移好了
		}
		close(fd);
		printf(" below close fd:%d\n",fd);

		recv_train(newfd,&t,md5sum_code_server);
		puts(md5sum_code_server);
		md5sum(file_real_full_path,md5sum_code);
	}

	if(0==strcmp(md5sum_code,md5sum_code_server)){
		printf("this file download success, finish gets\n");
	}else{
		printf("md5sum is not equal, upload error\n");
	}
	return 0;

}
#endif


