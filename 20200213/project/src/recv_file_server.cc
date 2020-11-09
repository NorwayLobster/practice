 ///
 /// @file    recv_upload_file.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 04:55:45
 ///
 
#include <head.hpp>
int recv_file_server(int newfd,struct UserCurrentInfo * p_user_cur_info,char *arg1,int arg2){
	Train t;
	char file_real_full_path[128]={0};
	int success=0;
	char md5sum_code[128]={0};
	char md5sum_code_server[128]={0};
	recv_train(newfd,&t,md5sum_code);
	puts(md5sum_code);

//需要检测用户在当前目录，是否已经有相同的文件了，如果当前目录已存在该文件，则返回已存在，直接退出
	char query[300]={0};

	strcpy(query,"select count(*) from virtual_filesystem where filetype='-'");
	sprintf(query,"%s and md5sum='%s'",query,md5sum_code);
	char *query_result[128]={0};//查询结果最多支持128条记录
	mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
	

	if(0!=atoi(query_result[0])) {//秒上传成功
		printf("this file already exists in our server, finish puts\n");
		puts(query_result[0]);
		send_train(newfd,&t,"finish");
//fatal error:		send_train(newfd,&t,"finish\n");
		strcpy(md5sum_code_server,md5sum_code);
//		send_train(newfd,&t,"this file already exists in our server, finish puts\n");
		free(query_result[0]);
//fatal error:		return 0;
	}else{	
		send_train(newfd,&t,"not finish\n");
		strcpy(file_real_full_path,p_user_cur_info->baiduwangpan_root_dir);
		strcat(file_real_full_path,"/");
		strcat(file_real_full_path,md5sum_code);
		puts(file_real_full_path);
		if(arg2>100*1024*1024){
			recv_file_by_mmap(newfd,file_real_full_path,arg2);//不考虑断点上传, 上传失败是不可能
		}else{
			recv_file(newfd,file_real_full_path,0);//不考虑断点上传, 上传失败是不可能
		}
			
		chmod(file_real_full_path,0754);
		md5sum(file_real_full_path,md5sum_code_server);
		puts(md5sum_code_server);
	}
	if(0==strcmp(md5sum_code,md5sum_code_server)){
		memset(query,0,sizeof(query));
		strcpy(query,"insert into virtual_filesystem(username,pre_dir_code,filename, filetype, md5sum) values(");
		sprintf(query,"%s'%s','%d','%s', '-' ,'%s')",query,p_user_cur_info->username,p_user_cur_info->cur_dir_code,arg1,md5sum_code);
		puts(query);
		success=mysql_insert(query);
		printf("this file upload success, finish puts\n");
		send_train(newfd,&t,"upload success");
	}else{
		send_train(newfd,&t,"md5sum is not equal, upload error");
	}

	return 0;

}
