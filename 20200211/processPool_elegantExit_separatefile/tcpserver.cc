 ///
 /// @file    tcpserver.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-11 00:40:06
 ///
 

#include "head.hpp"


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
	free(p_Data_array);

	return 0;
}
