 ///
 /// @file    taskhandler.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 12:58:33
 ///
 
#include <head.hpp>
char FILENAME[1024]="file";

void *task_handler(int newfd,void*p){
	mode_t pre_mask=umask(0002);
	printf("pre_mask:%u\n",pre_mask);
	int ret;
	Train t;
	bzero(&t,sizeof(Train));
//	int minfd=open("file",O_RDWR);
//	printf("child min free fd:%d\n",minfd);
	char cmd[16]={0};	
	char arg1[16]={0};	
	char response[4092]={0};	//与小火车中的buf对应
	int arg2=0;	
//	struct UserCurrentInfo{
//		char username[64];	
//		char user_root_dir[64];	// /home/cheng/baiduwangpan/test1
//		char baiduwangpan_root_dir[64];	// /home/cheng/baiduwangpan
//		char cur_full_dir[64];	// / 登陆的时候
//		int pre_dir_code;// 0  0 表示无pre_dir, 自己就是根
//		int cur_dir_code;// 1
//		int login_success_flag;	
//	};


	UserCurrentInfo user_cur_info;
	bzero(&user_cur_info,sizeof(UserCurrentInfo));
	strcpy(user_cur_info.baiduwangpan_root_dir,"/home/cheng/baiduwangpan");
	
	while(1){
		ret=0;
		printf("in while\n");
		puts(user_cur_info.username);
		puts(user_cur_info.user_root_dir);
		puts(user_cur_info.cur_full_dir);
		printf("cur_dir_code:%d,pre_dir_code:%d,login_success_flag:%d\n",user_cur_info.cur_dir_code,user_cur_info.pre_dir_code,user_cur_info.login_success_flag);

		ret=recv_train(newfd,&t,response);//new为阻塞的fd
		sscanf(response,"%s %s %d",cmd,arg1,&arg2);
		printf("cmd:%s,arg1:%s,arg2:%d\n",cmd,arg1,arg2);
		if(0==user_cur_info.login_success_flag&&0!=strcmp(cmd,"signup")&&0!=strcmp(cmd,"login")){
			printf("sorry, you do not login\n");
			continue;
		}

		if(0==strcmp(cmd,"signup")){
			ret=signup_authentication_server(newfd,&user_cur_info);
		}else if(0==strcmp(cmd,"login")){
			ret=login_authentication_server(newfd,&user_cur_info);
		} else if(0==strcmp(cmd,"pwd")){
			ret=pwd(newfd,&user_cur_info);
		} else if(0==strcmp(cmd,"mkdir")){
			ret=mk_dir(newfd,&user_cur_info,arg1);
		} else if(0==strcmp(cmd,"cd")){
			ret=cd(newfd,&user_cur_info,arg1);
		} else if(0==strcmp(cmd,"puts")){
			ret=recv_file_server(newfd,&user_cur_info,arg1,arg2);
		} else if(0==strcmp(cmd,"gets")){
			ret=send_file_server(newfd,&user_cur_info,arg1,arg2);
		}else if(0==strcmp(cmd,"remove")){
//删除文件，删除数据库记录，看引用计数在决定是否文件
		}else if(0==strcmp(cmd,"rmdir")){
//删除文件夹中的文件，在删除文件下的文件夹，递归套用remdir，清空该dir后，删除该文件夹
		}else if(0==strcmp(cmd,"ls")){
			ret=ls_new(newfd,&user_cur_info);
		} else if(0==strcmp(cmd,"quit")||0==strcmp(cmd,"exit")){
			close(newfd);//客户端异常退出
			printf("client quits, close client's fd\n");
			break;
		}

		//ret=recv(newfd,buf,sizeof(buf)-1,0);
		if(-1==ret){
			printf("client abort unexpectedly:%d\n",ret);
			close(newfd);//客户端异常退出
			break;
		}
	}
	return NULL;
}
