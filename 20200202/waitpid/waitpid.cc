///
/// @file    fork_malloc.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-02 14:41:59
///

#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(-1==pid){
		perror("fork()");
		return -1;
	}
	char *p=NULL;

	if(0==pid){
		printf("i am child,pid:%d,ppid:%d\n",getpid(),getppid());
		printf("i am child,pid:%d,ppid:%d,pgid:%d,sid:%d\n",getpid(),getppid(),getpgid(0),getsid(0));
		pid_t gpid;
		gpid=getpgid(0);//获得本进程的group id
		printf("in child group pid:%d\n",gpid);	
		//		*p=23;



//0.setpgid():创建进程组; or 加入同一session的其他group 
//如果已经是session leader，则setsid() 会出错
//如果已经是group leader，则setpgid() 会出错
		pid_t sid,newsid;	
		pid_t id=setpgid(0,0);
		printf("new group pid:%d\n",id);	
//00.getsid():session id
		printf("session pid:%d\n",sid);	
		newsid=setsid();
		printf("new session pid:%d\n",newsid);	
//0.setpgid():创建进程组; or 加入同一session的其他group
		sid=getsid(0);//获得本进程的group id
		printf("session pid:%d\n",sid);	
		printf("new:i am child,pid:%d,ppid:%d,pgid:%d,sid:%d\n",getpid(),getppid(),getpgid(0),getsid(0));
//1.getpgid()
		gpid=getpgid(getpid());
		gpid=getpgid(0);//获得本进程的group id
		printf("group pid:%d\n",gpid);	
	}
	else{
		int status;
		printf("i am parent,pid:%d,ppid:%d\n",getpid(),getppid());
		pid_t childpid=pid;
		printf("i am parent,pid:%d,ppid:%d,pgid:%d,sid:%d\n",getpid(),getppid(),getpgid(0),getsid(0));
		pid_t wpid;
		pid_t gpid;
		gpid=getpgid(0);//获得本进程的group id
//2.waitpid()
//		wpid=waitpid(-gpid,&status,0);//WNOHANG表立即返回
		wpid=waitpid(0,&status,WNOHANG);//WNOHANG表立即返回
		//		pid_t wpid=waitpid(childpid,&status,0);//WNOHANG表立即返回
		//		pid_t wpid=waitpid(childpid,&status,WNOHANG);//WNOHANG表立即返回
		//		wait(&status);
		//		wait(NULL);
		//		sleep(4);
		//
		//
//		The value of pid can be:
//			pid_t wpid=waitpid(pid,&status,0);//WNOHANG表立即返回
//			< -1   meaning wait for any child process whose process group ID is equal to the absolute value of pid.
//			-1     meaning wait for any child process.
//			0      meaning wait for any child process whose process group ID is equal to that of the calling process.
//			> 0    meaning wait for the child whose process ID is equal to the value of pid.
//
			//wait和waitpid只能回收处于Z状态的进程	
			//		pid_t wpid=waitpid(-1,&status,0);//WNOHANG表立即返回
			//
		if(wpid<0){
			printf("wpid:%d\n",wpid);	
			return 0;
		}

		printf("wpid:%d\n",wpid);	
	//note:		wpid>0,看status才有意义
		printf("status:%d\n",status);	
//3.wait()
//4.WIFEXITED
		if(WIFEXITED(status)){
//5.WEXITSTATUS
			printf("return normally,%d\n",WEXITSTATUS(status));
		}
		else{
			printf("return abnormally\n");
		}
		printf("parent is sleeping for 10s\n");
		while(1);
	//		sleep(10);
	}
	return 0;
}
