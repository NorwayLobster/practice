 ///
 /// @file    tcpserver.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-11 00:40:06
 ///
 

#include "func.hpp"
#define MAX_EVENT_NUMBER 1024
#define BUF_SIZE 10
char FILENAME[1024]="file";

typedef struct tag{
	pid_t pid;
	int busy;
	int fd;
}Data,*pData;

typedef struct train_tag{
	int len;
	char buf[4096];
}Train,*pTrain;

int sendn(int fd,char *buf,int len){
	//printf("in sendn,len=%d\n",len);
	int ret=0;
	int sum=0;
	while(sum<len){
		ret=send(fd,buf+sum,len-sum,0);
		//printf("send ret:%d\n",ret);

		if(ret==-1){
			printf("errno:%d\n",errno);
			perror("send()");
			return -1;
		}
	
	//	printf("in sendn: ret:%d,sum=%d\n",ret,sum);
		sum+=ret;
	}
	return len;
}

int send_file(int newfd,char *filename,int len){
//	printf("sendn()\n");
	int ret;
	Train t;

	bzero(t.buf,sizeof(t.buf));
	memcpy(t.buf,filename,len);
	int fd=open(t.buf,O_RDONLY);
	t.len=len;//文件名长度
//	printf("len:%d,%d\n",len,t.len);
//	printf("t.buf:%s\n",t.buf);
	
//	sendn(newfd,(char*)&t,4+sizeof(t.buf));
	sendn(newfd,(char*)&t,4+t.len);

	while(1){
//		printf("in while\n");

		ret=read(fd,t.buf,sizeof(t.buf));
//		printf("in while read ret:%d\n",ret);
		t.len=ret;
		ret=sendn(newfd,(char*)&t,4+ret);
//		printf("in while snedn ret:%d\n",ret);
		if(4==ret){
//			printf("in while break ret:%d\n",ret);
			break;
		}	
		if(-1==ret){
			printf("in while return ret:%d\n",ret);
			return -1;
		}
	}
	return 0;
}
void sig_pipe_handler(int signum){
	printf("%d is coming\n",signum);
//	_exit(0);
}

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

void setNonbloking(int fd){
//int fcntl(int fd, int cmd, ... /* arg */ );
//先get 后set
		int old_option=fcntl(fd,F_GETFL);
		assert(-1!=old_option);
		int new_option=old_option|O_NONBLOCK;

		int ret=fcntl(fd,F_SETFL,new_option);
		assert(-1!=ret);
}
void delFd(int epfd,int fd){
			struct epoll_event event;
			event.events=EPOLLIN;
			event.data.fd=fd;
			int ret=epoll_ctl(epfd,EPOLL_CTL_DEL,fd,&event);//目前用来监控可写，但其也可以监控可读
			assert(-1!=ret);

}

void addFd(int epfd,int fd,bool enableET){
			struct epoll_event event;
			event.events=EPOLLIN;
			if(enableET){
				event.events=event.events|EPOLLET;
				setNonbloking(fd);
			}

			event.data.fd=fd;
			int op=EPOLL_CTL_ADD;
			int ret=epoll_ctl(epfd,op,fd,&event);//目前用来监控可写，但其也可以监控可读
			assert(-1!=ret);
}

void recv_onceforall(int epfd,int sockfd,set<int> &fdset,char *buf){
//buf:”退化”成指向首元素的指针
		while(1){
			memset(buf,0,BUF_SIZE);
//			memset(buf,0,sizeof(buf));
			int ret=recv(sockfd,buf, BUF_SIZE-1,0);//这里少接收一个是为了print buf的时候有字符串结束符
//			ret=recv(sockfd,buf, sizeof(buf)-1,0);
			if(ret<0){
				if(EAGAIN==errno||EWOULDBLOCK==errno){
					printf("---finish recv-ing---\n");
					break;	
				}
				else{//什么情景???
					PERROR(-1,ret,"recv()");
					printf("recv() error\n");
					_exit(-1);//recv出错，服务器挂掉???
				}
			} //退出机制 对端ctrl+c退出，或ctrl+d退出
		   else if(ret==0){//水平触发，触发了表示有数据，ret应该大于0，但ret=0，表示sockfd关闭了
				fdset.erase(sockfd);
				delFd(epfd,sockfd);
				close(sockfd);//关闭后，不解除注册，是否一直使epollwait触发？？
				printf("bye %d\n",sockfd);
		//						continue;
				break;
			}else{
				printf("from client:%s\n",buf);
			}
		}
}

int pfd[2];
void sig(int signum){
	printf("%d is coming\n",signum);
	int ret;
	ret=write(pfd[1],&signum,4);
	assert(-1!=ret);
}
int main(int argc,char**argv){
	int ret;
	if(4!=argc){
		perror("args error");
		_exit(-1);
	}

	int processNum=atoi(argv[3]);
	printf("processNum:%d\n",processNum);

	pData p_Data_array=(pData)calloc(processNum,sizeof(Data));
	createChildProcesses(p_Data_array,processNum);


//1.	 int socket(int domain, int type, int protocol);
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	PERROR(-1,sfd,"socket()");
//int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
	int resue=1;	
	ret=setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&resue,sizeof(int));
	assert(-1!=ret);

//2.	int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
//	struct sockaddr addr;
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;

	struct in_addr h_addr;	
	h_addr.s_addr=inet_addr(argv[1]);
	addr.sin_addr=h_addr;

	short int h_port=atoi(argv[2]);
	addr.sin_port=htons(h_port);

	ret=bind(sfd,(struct sockaddr*)&addr,sizeof(struct sockaddr));//all is right
//	ret=bind(sfd,(struct sockaddr*)&addr,sizeof(struct sockaddr_in));
	PERROR(-1,ret,"bind()");

	int maxNoListen=processNum+1;//监听sockpair，sfd,和新的网络连接//????????????????????????????????????

//3.	int listen(int sockfd, int backlog);
	ret=listen(sfd,maxNoListen);
	PERROR(-1,ret,"listen()");


	char buf[BUF_SIZE]={0};


	int epfd;
	epfd=epoll_create(1);
	assert(-1!=epfd);

	ret=pipe(pfd);
	assert(-1!=ret);
	printf("pfd[0]:%d\n",pfd[0]);
	printf("pfd[1]:%d\n",pfd[1]);
//	signal(SIGQUIT,sig);//子进程继承信号的注册,但不共享
//	signal(SIGINT,sig);//子进程继承信号的注册,但不共享
//	signal(SIGUSR2,sig);//子进程继承信号的注册,但不共享

	signal(SIGUSR1,sig);//子进程继承信号的注册,但不共享

	addFd(epfd,pfd[0],false);

	addFd(epfd,sfd,false);
	addFd(epfd,0,false);//标准输入为LT
	map<int,pData> map_fd;
	for(int i=0;i<processNum;++i){
		int sockpairfd= p_Data_array[i].fd;
		map_fd.insert(make_pair(sockpairfd,p_Data_array+i));
		addFd(epfd,sockpairfd,false);
	}



	struct epoll_event events[MAX_EVENT_NUMBER];
	int timeOut=5000;//milisecond, -1,永久等待，即epoll_wait阻塞
	set<int> fdset;
	while(1){
//int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
//		int retval=epoll_wait(epfd,events,MAX_EVENT_NUMBER,-1);//超时，ret=0，for进不去
		int retval=epoll_wait(epfd,events,MAX_EVENT_NUMBER,timeOut);//超时，ret=0，for进不去
//		PERROR(-1,retval,"epoll_wait");
//		信号会打断epoll_wait的使其异常返回
		printf("retval=%d,errno:%d\n",retval,errno);
		if(-1==retval && errno==EINTR) { 
			delFd(epfd,sfd);//解除注册，不接新链接
			close(sfd);
			printf("retval=%d,errno:%d\n",retval,errno);
		}else if(-1==retval){
			assert(-1!=retval); 
		}

		for(int i=0;i<retval;++i){
			int sockfd=events[i].data.fd;
			if(sockfd==pfd[0]){
				int signum;
				read(pfd[0],&signum,4);
				printf("got it,exit,signum:%d\n",signum);
				for(auto i=0;i<processNum;++i){
					//暴力退出，发kill给每个进程
					int exit_flag=1;
					printf("before send_fd\n");
					int fd=0;//stdin
					send_fd(p_Data_array[i].fd,fd,exit_flag);
				}
				//等待子进程存盘，完成现有业务等
				for(auto i=0;i<processNum;++i){
					printf("before wait\n");
					wait(NULL);//等待子进程干完活，优雅退出
				}
				_exit(0);
			}
			else if(sfd==sockfd){
				struct sockaddr_in addr_cli;
				memset(&addr_cli,0,sizeof(struct sockaddr_in));
				socklen_t len;//传入参数？？ yes,但是必须initialize
				len=sizeof(struct sockaddr_in);
			//	len=sizeof(struct sockaddr);//all is right
				int newfd=accept(sockfd,(struct sockaddr*)&addr_cli,&len);
				printf("client ip:%s,port:%d\n",inet_ntoa(addr_cli.sin_addr), ntohs(addr_cli.sin_port));

//int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
				int resue=1;	
				ret=setsockopt(newfd,SOL_SOCKET,SO_REUSEADDR,&resue,sizeof(int));
				assert(-1!=ret);

				//fdset.insert(newfd);
				//PERROR(-1,newfd,"accept()");
				//addFd(epfd,newfd,true);
				int stepin_flag=false;
				for(auto i=0;i<processNum;++i){
					Data & tempData=p_Data_array[i];
					if(0==tempData.busy){
						stepin_flag=true;
					//if(0==p_Data_array[i].busy){
						printf("pid:%d,busy:%d,fd:%d\n",tempData.pid,tempData.busy,tempData.fd);
//						send_fd(p_Data_array[i].fd,newfd);
						int exit_flag=0;
						send_fd(p_Data_array[i].fd,newfd,exit_flag);
						p_Data_array[i].busy=1;
						printf("pid:%d,busy:%d,fd:%d\n",tempData.pid,tempData.busy,tempData.fd);
						break;
						
					}
				}
				if(!stepin_flag) 
				{
					printf("no free process,bye\n");
					char bye[100]="sorry, no free process, bye";
					ret=send(newfd,bye,sizeof(bye),0);//读了ret，就send ret个字符
				}
				close(newfd);
						
			}
			else if(0==sockfd){
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				PERROR(-1,ret,"read()");

				//退出机制 本端ctrl+d退出 ; ctrl+c进程退出,本段bye不打印
				if(ret==0){ //目前不适用ctrl+d退出,除非使用goto
					printf("bye\n");
					break;
				}

				for(int e:fdset){
					ret=send(e,buf,ret,0);//读了ret，就send ret个字符
//					ret=send(e,buf, strlen(buf)-1,0);
					PERROR(-1,ret,"send()");
				}

			}
			else if(EPOLLIN&events[i].events){
				char buf[10]={0};
				ret=read(sockfd,buf,sizeof(buf));//把通知信息读空,防止多次触发
				assert(-1!=ret);
				if(0==ret){
					printf("pid %d childe abort,wait it \n",map_fd[sockfd]->pid);
					map_fd[sockfd]->busy=-1;//置成空闲
					delFd(epfd,sockfd);//解除注册，不接新链接
					close(sockfd);
					waitpid(map_fd[sockfd]->pid,NULL,0);
					map_fd.erase(sockfd);//置成空闲
					--processNum;
				}
				else {
					map_fd[sockfd]->busy=0;//置成空闲
					printf("%d is reset to unbusy,pid:%d\n",*(int*)buf,map_fd[sockfd]->pid);
				}


//				recv_onceforall(epfd,sockfd,fdset,buf);
			}
		}//for

		if(0==retval){
			printf("do other job,retval=%d\n",retval);
		}else{
			printf("retval=%d\n",retval);
		}
	}//while
	close(epfd);
	close(sfd);
	for(int e:fdset){
		ret=close(e);
		PERROR(-1,ret,"close()");
	}

	return 0;
}
