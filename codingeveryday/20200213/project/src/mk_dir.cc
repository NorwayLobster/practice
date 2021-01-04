 ///
 /// @file    mk_dir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 00:59:21
 ///
 
#include <head.hpp>
int mk_dir(int newfd,struct UserCurrentInfo * p_user_cur_info,char * arg1){
	Train t;
	int ret;
	char query[300]={0};
	strcpy(query,"insert into virtual_filesystem(pre_dir_code, username, filename,filetype,md5sum) values(");
	sprintf(query,"%s%d,'%s','%s','d','')",query,p_user_cur_info->cur_dir_code,p_user_cur_info->username,arg1);
	puts(query);
	ret=mysql_insert(query);
	printf("mkdir success\n");
	send_train(newfd,&t,"mkdir success");
	return ret;
}
