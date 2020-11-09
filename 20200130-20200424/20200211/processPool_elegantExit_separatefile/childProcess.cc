 ///
 /// @file    childProcess.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:11:31
 ///
 
#include "head.hpp"
char FILENAME[1024]="file";

void child_handler(int sockpairfd){
	printf("child_handler\n");
	signal(SIGPIPE,sig_pipe_handler);
	int ret;
	int minfd=open("file",O_RDWR);
	printf("child min free fd:%d\n",minfd);
	int newfd;
	int exit_flag=0;
	while(1){
		printf("child %d, i am waiting for new fd\n",getpid());
		recv_fd(sockpairfd,&newfd,&exit_flag);
		printf("exit_flag=%d\n",exit_flag);
		if(exit_flag){
			printf("gonna exit,exit_flag=%d\n",exit_flag);
			_exit(0);
		}

		char buf[100]={0};
		
		printf("send_file\n");
		ret=send_file(newfd,FILENAME,strlen(FILENAME));

		//ret=recv(newfd,buf,sizeof(buf)-1,0);
		if(-1==ret){
			printf("client abort unexpectedly:%d\n",ret);
			close(newfd);//客户端异常退出
		}else{
			close(newfd);//客户端异常退出
			printf("finish jobs, close client's fd:%d\n",ret);
		}
		sleep(10);




		printf("buf:%s\n",buf);
		printf("pid:%d,buf:%s\n",getpid(),buf);
		memset(buf,0,sizeof(buf));
		int pid=getpid();
		printf("pid:%d\n",pid);
		memcpy(buf,&pid,sizeof(pid));
		ret=send(sockpairfd,buf,sizeof(int),0);//i am not busy
		assert(-1!=ret);
	}
	_exit(0);//非常关键 
}

void createChildProcesses(pData p_Data_array,int processNum){
	pid_t pid;
	int fd[2];
	int ret;
	for(int i=0;i<processNum;++i){
		ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fd);
		assert(-1!=ret);
		pid=fork();	
		if(0==pid){
			for(int i=3;i<fd[1];++i){
			   close(i);
			}
		   //close(fd[0]);
			printf("child fd:%d\n",fd[1]);
			child_handler(fd[1]);
		}
		else{
			close(fd[1]);
			p_Data_array[i].pid=pid;
			p_Data_array[i].busy=0;
			p_Data_array[i].fd=fd[0];
			printf("parent fd:%d----------------\n",fd[0]);
		}
	}
//	wait(NULL);
}

void sig_pipe_handler(int signum){
	printf("%d is coming\n",signum);
//	_exit(0);
}


