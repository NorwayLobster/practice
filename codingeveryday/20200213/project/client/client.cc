 ///
 /// @file    tcpserver.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-09 14:17:21
 ///
 
#include <head.hpp>



int main(int argc,char**argv){
	int ret;
	if(3!=argc){
		perror("args error");
		_exit(-1);
	}


#if 1
//1.	 int socket(int domain, int type, int protocol);
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	PERROR(-1,sfd,"socket()");


	struct sockaddr_in addr;
	addr.sin_family=AF_INET;

	struct in_addr h_addr;	
	h_addr.s_addr=inet_addr(argv[1]);//想要连接的server的地址
	addr.sin_addr=h_addr;

	short int h_port=atoi(argv[2]);
	addr.sin_port=htons(h_port);

	socklen_t len;//传入参数？？ NO
	len=sizeof(struct sockaddr_in);
	len=sizeof(struct sockaddr);//??
//2.int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	ret=connect(sfd,(struct sockaddr*)&addr,len);
	PERROR(-1,ret,"connect()");
#if 0 
	ret=send(sfd,"hello",5,0);
	PERROR(-1,ret,"send()");
	char buf[1024]={0};

	ret=recv(sfd,buf,sizeof(buf),0);
	PERROR(-1,ret,"recv()");
	puts(buf);


	//select 内部实现机制
	int select(int maxfd,fd_set* p,,,,)
	{
		fd_set tmpset;

		memcpy(&tmpset,p,sizeof(fd_set));
		FD_ZERO(p);
		FD_SET(0,p);//若0可读
		FD_SET(fdr,p);//若fdr可读
	}
#endif 

	while(1){			
		ret=login_or_signup_authentication_client(sfd);
		if(0==ret){
			break;
		}
	}

	char buf[1024]={0};
	int maxfd=sfd+1;
//	int maxfd=max(sfd,sfd)+1;
	fd_set fdSet;//传入传出参数
	struct timeval timeout;
	Train t;
	while(1){
		FD_ZERO(&fdSet);
		FD_SET(0,&fdSet);
		FD_SET(sfd,&fdSet);
		timeout.tv_sec=20;
//		ret=select(maxfd,&fdSet,NULL,NULL,NULL);//目前用来监控可写，但其也可以监控可读
		ret=select(maxfd,&fdSet,NULL,NULL,&timeout);//目前用来监控可写，但其也可以监控可读
		if(ret>0){
			if(FD_ISSET(0,&fdSet)){
				char cmd[8]={0};
				char arg1[8]={0};

				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				puts(buf);
				PERROR(-1,ret,"read()");

				//退出机制 本端ctrl+d退出 ; ctrl+c进程退出,本段bye不打印
				if(ret==0){ 
					printf("bye\n");
					break;
				}
				sscanf(buf,"%s %s",cmd,arg1);
				puts(cmd);
				puts(arg1);
				if(0==strcmp("puts",cmd)){
					send_file_client(sfd,arg1);
				}else if(0==strcmp("gets",cmd)){
					recv_file_client(sfd,arg1);
				}else{
					ret=send_train(sfd,&t,buf);
	//				memset(&t,0,sizeof(Train));
	//				t.len=ret;
	//				memcpy(t.buf,buf,t.len);
	//				ret=sendn(sfd,(char*)&t,4+t.len);
	//				//ret=send(sfd,buf, strlen(buf)-1,0);
	//				PERROR(-1,ret,"send()");
				}
			}
			if(FD_ISSET(sfd,&fdSet)){
				memset(&t,0,sizeof(Train));
				//ret=recv_file(sfd);
//				ret=recv(sfd,buf, sizeof(buf),0);
				ret=recvn(sfd,(char*)&t,4);
				PERROR(-1,ret,"recv()");
				ret=recvn(sfd,t.buf,t.len);
				//ret=write(fd,t.buf,t.len);
				PERROR(-1,ret,"recv()");

				//退出机制 对端ctrl+c退出，或ctrl+d退出
				if(ret==0){
					printf("bye\n");
					break;
				}
				printf("from server:%s\n",t.buf);
			}
		}
		else {
			printf("do other job\n");
		}
	}
	close(sfd);

#endif
	return 0;
}
