 ///
 /// @file    login_or_signup_authentication_client.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-15 17:11:59
 ///
 
#include <head.hpp>

int signup_authentication_server(int newfd,struct UserCurrentInfo * p_user_cur_info){
	Train t;
	int unexpectedExitflag=0;
	char username[32]={0};	
	char user_root_dir[64]="/home/cheng/baiduwangpan/";	
	char salt[32]={0};	
	int success;
	char ciphertext[128]={0};	

	generate_salt(salt);
	printf("salt:%s\n",salt);
	
	unexpectedExitflag=recv_train(newfd,&t,username);
	if(-1==unexpectedExitflag) return -1;
	printf("username:%s\n",username);
//检查 是否有相同的username，若有直接返回

	unexpectedExitflag=send_train(newfd,&t,salt);
	if(-1==unexpectedExitflag) return -1;
	unexpectedExitflag=recv_train(newfd,&t,ciphertext);
	if(-1==unexpectedExitflag) return -1;
	printf("ciphertext:%s\n",ciphertext);
	strcat(user_root_dir,username);	

	printf("user_root_dir:%s\n",user_root_dir);
	char query[300]="insert into user_info(username, salt , ciphertext, user_root_dir) values(";
	sprintf(query,"%s'%s','%s','%s','%s')",query,username,salt,ciphertext,user_root_dir);
	success=mysql_insert(query);
	printf("success:%d\n",success);

	memset(query,0,sizeof(query));
	//strcpy(query,"insert into virtual_filesystem(cur_dir_code, pre_dir_code, username, filename,filetype,md5sum) values(");
	//sprintf(query,"%s1,0,'%s','/','d','')",query,username);
	strcpy(query,"insert into virtual_filesystem(pre_dir_code, username, filename,filetype,md5sum) values(");
	sprintf(query,"%s0,'%s','/','d','')",query,username);


	success=mysql_insert(query);

	unexpectedExitflag=send_train(newfd,&t,(char*)&success);
	if(-1==unexpectedExitflag) return -1;

	if(-1==success){
		printf("signup fail\n");
	}else{
		strcpy(p_user_cur_info->username,username);
		strcpy(p_user_cur_info->user_root_dir,user_root_dir);
		strcpy(p_user_cur_info->cur_full_dir,"/");
		p_user_cur_info->login_success_flag=1;
		p_user_cur_info->cur_dir_code=1;
		p_user_cur_info->pre_dir_code=0;
		printf("signup success\n");
	}
	return 0;	
}

