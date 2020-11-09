 ///
 /// @file    cd.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 01:13:19
 ///
 
#include <head.hpp>
int delete_end_dir_name(char *p_cur_full_dir);
int add_end_dir_name(char *p_cur_full_dir,char * arg1);
#if 1
int cd(int newfd,struct UserCurrentInfo * p_user_cur_info,char * arg1){
	Train t;
	int ret;
	char query[300]={0};
	char *query_result[128]={0};//查询结果最多支持128条记录
	if(0==strcmp("..",arg1)){
		if(0==p_user_cur_info->pre_dir_code){
			printf("sorry, it is root dir\n");
			send_train(newfd,&t,"sorry, it is root dir");
			return 0;
		}else{
			strcpy(query,"select pre_dir_code from virtual_filesystem where username=");
			sprintf(query,"%s'%s' and cur_dir_code=%d",query,p_user_cur_info->username,p_user_cur_info->pre_dir_code);
			mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
			if(NULL==query_result[0]) {
				printf("sorry, mysql_query_my \n");
				send_train(newfd,&t,"sorry, mysql_query_my error");
				return 0;
			}
			puts(query_result[0]);
			p_user_cur_info->cur_dir_code=p_user_cur_info->pre_dir_code;
			sscanf(query_result[0],"%d",&p_user_cur_info->pre_dir_code);
			free(query_result[0]);//
			delete_end_dir_name(p_user_cur_info->cur_full_dir);
		}
	}else{
		memset(query,0,sizeof(query));
		strcpy(query,"select cur_dir_code from virtual_filesystem where username=");
		sprintf(query,"%s'%s' and pre_dir_code=%d and filename='%s'",query,p_user_cur_info->username,p_user_cur_info->cur_dir_code,arg1);
		puts(query);
		mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
		p_user_cur_info->pre_dir_code=p_user_cur_info->cur_dir_code;
		if(NULL==query_result[0]) {
			printf("sorry, the dir not exists\n");
			send_train(newfd,&t,"sorry, the dir does not exist");
			return 0;
		}
		sscanf(query_result[0],"%d",&p_user_cur_info->cur_dir_code);
		free(query_result[0]);//存在,则在free
		add_end_dir_name(p_user_cur_info->cur_full_dir,arg1);
	}
	printf("cd success\n");
	send_train(newfd,&t,"cd success");
	return ret;
}

#endif 

int add_end_dir_name(char *p_cur_full_dir,char * arg1){
	if(0!=strcmp(p_cur_full_dir,"/"))
		strcat(p_cur_full_dir,"/");
	strcat(p_cur_full_dir,arg1);
	//puts(p_cur_full_dir);
	return 0;
}

int delete_end_dir_name(char *p_cur_full_dir){
	int len=strlen(p_cur_full_dir);
	for(int i=len-1;i>0;--i){
		if(p_cur_full_dir[i]=='/'){
		//	puts(p_cur_full_dir);
			p_cur_full_dir[i]='\0';
			break;
		}
		p_cur_full_dir[i]='\0';
	}
	return 0;
}
#ifdef __MAIN__
int main(){
	char dir[230]={0};
	strcpy(dir,"/cheng/wang/hello");
	puts(dir);
	delete_end_dir_name(dir);
	puts(dir);
	add_end_dir_name(dir,"world");
	puts(dir);
	return 0;
}	
#endif
