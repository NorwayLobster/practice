 ///
 /// @file    login_or_signup_authentication_client.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-15 17:11:59
 ///
 
#include <head.hpp>
int login_authentication_server(int newfd,struct UserCurrentInfo * p_user_cur_info){
	Train t;
	int ret;
	char username[32]={0};	
	char user_root_dir[64]={0};	
	strcpy(user_root_dir, "/home/cheng/baiduwangpan/");
	char salt[32]={0};	
	int success;
	char ciphertext[128]={0};	
	char ciphertext_db[128]={0};	//SHA-521 86个字符
	char query[300]={0};
	strcpy(query, "select salt, ciphertext from user_info where username=");

	char *query_result[128]={0};//查询结果最多支持128条记录

	
	ret=recv_train(newfd,&t,username);
	if(-1==ret) return -1;
	printf("username:%s\n",username);

	sprintf(query,"%s'%s'",query,username);
	printf("query:%s\n",query);

	ret=mysql_query_my(query,query_result);//预期一条记录,返回ret个记录
	if(0==ret||-1==ret){
		send_train(newfd,&t,salt);
		printf("sorry, no this username in our db\n");
		p_user_cur_info->login_success_flag=0;
//		*p_login_success_flag=0;
		return 0;
	}

	printf("mysql_query_my ret:%d\n",ret);
	printf("addr:%p\n",query_result[0]);
	puts(query_result[0]);
	sscanf(query_result[0],"%s %s",salt,ciphertext_db);
	free(query_result[0]);//

	printf("salt:%s\n",salt);
	printf("ciphertext_db:%s\n",ciphertext_db);

	ret=send_train(newfd,&t,salt);
	if(-1==ret) return -1;
	if(0==strcmp("",salt)){
		printf("sorry, no this username in our db\n");
		p_user_cur_info->login_success_flag=0;
		return 0;
	}
	ret=recv_train(newfd,&t,ciphertext);
	if(-1==ret) return -1;
	printf("ciphertext:%s\n",ciphertext);
	int	retval=strcmp(ciphertext,ciphertext_db);	
	printf("retval:%d\n",retval);
	success=0==retval?0:-1;	
	printf("success:%d\n",success);
	ret=send_train(newfd,&t,(char*)&success);
	if(-1==ret) return -1;

	if(-1==success){
		printf("login fail\n");
	} else{
		strcpy(p_user_cur_info->username,username);
		strcat(user_root_dir,username);	
		strcpy(p_user_cur_info->user_root_dir,user_root_dir);
		strcpy(p_user_cur_info->cur_full_dir,"/");
		p_user_cur_info->login_success_flag=1;
		p_user_cur_info->cur_dir_code=1;
		p_user_cur_info->pre_dir_code=0;
		printf("login success\n");
	}
	return 0;	
}

