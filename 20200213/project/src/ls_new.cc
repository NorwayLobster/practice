 ///
 /// @file    ls_new.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 03:41:16
 ///
 
#include <head.hpp>
int ls_new(int newfd,struct UserCurrentInfo * p_user_cur_info){
	Train t;
	int ret;
	char query[300]={0};
	char *query_result[128]={0};//查询结果最多支持128条记录
	strcpy(query,"select filetype, username, filename from virtual_filesystem where username=");
	sprintf(query,"%s'%s' and pre_dir_code=%d",query,p_user_cur_info->username,p_user_cur_info->cur_dir_code);
	mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
	if(NULL==query_result[0]) {
		printf("sorry, no file or dir in this dir\n");
		send_train(newfd,&t,"sorry, no file or dir in this dir");
		return 0;
	}
	int i=0;
	while(NULL!=query_result[i]) {
		puts(query_result[i]);
		send_train(newfd,&t,query_result[i]);
		free(query_result[i]);
		printf("addr:%p\n",query_result[i]);
		++i;
	}
	printf("ls success\n");
	return ret;
}


