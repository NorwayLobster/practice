 ///
 /// @file    send_download_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 04:05:46
 ///
 
#include <head.hpp>
#if 1
int send_file_server(int newfd,struct UserCurrentInfo * p_user_cur_info,char *arg1,int arg2){
	char file_real_full_path[128]={0};
	char md5sum_code[128]={0};
	char md5sum_code_server[128]={0};
	Train t;
	
	char *query_result[128]={0};//查询结果最多支持128条记录
	char query[128]={0};//

	strcpy(query,"select count(*) from virtual_filesystem where username=");
	sprintf(query,"%s'%s' and pre_dir_code=%d and filetype='-' and filename='%s'",query,p_user_cur_info->username,p_user_cur_info->cur_dir_code,arg1);
	mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
	if(0==atoi(query_result[0])) {
		printf("sorry, no this file in this dir\n");
		send_train(newfd,&t,"no");
		free(query_result[0]);
	}else{	
		free(query_result[0]);
		send_train(newfd,&t,"yes");
		strcpy(query,"select md5sum from virtual_filesystem where username=");
		sprintf(query,"%s'%s' and pre_dir_code=%d and filetype='-' and filename='%s'",query,p_user_cur_info->username,p_user_cur_info->cur_dir_code,arg1);
		mysql_query_my(query,query_result);//预期一条记录,返回ret个记录

		puts(query_result[0]);
		sscanf(query_result[0],"%s",md5sum_code_server);
		free(query_result[0]);
		puts(md5sum_code_server);

		strcpy(file_real_full_path,p_user_cur_info->baiduwangpan_root_dir);
		strcat(file_real_full_path,"/");
		strcat(file_real_full_path,md5sum_code_server);
		puts(file_real_full_path);

		int fd=open(file_real_full_path,O_RDONLY);
		struct stat st;
		fstat(fd,&st);
		int left_len=st.st_size-arg2;

//fatal error: send_train(newfd,&t,(char*)&left_len);	
		sendn(newfd,(char*)&left_len,4);	

		if(left_len>100*1024*1024){
			send_file_by_mmap(newfd,file_real_full_path,arg2);
//			send_file_by_sendfile(newfd,file_real_full_path,arg2);
		}else{
			send_file(newfd,fd,arg2);
		}
		close(fd);
		printf("finish send\n");
		send_train(newfd,&t,md5sum_code_server);	
	}
	return 0;
}
#endif
