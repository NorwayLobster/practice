///
/// @file    tcpserver.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-09 14:17:21
///

#include "func.hpp"
#define scatter_NUM 2
void send_fd(int pfd,int fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
	struct iovec iov[2];
	char buf[10]="hello";
	char buf1[10]="world";
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=5;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	*(int*)CMSG_DATA(cmsg)=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=sendmsg(pfd,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return;
	}
}
void recv_fd(int pfd,int *fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
	struct iovec iov[2];
	char buf[10]="hello";
	char buf1[10]="world";
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=5;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=recvmsg(pfd,&msg,0);
	if(-1==ret)
	{
		perror("recvmsg");
		return;
	}
	*fd=*(int*)CMSG_DATA(cmsg);
}

int main(int argc,char**argv){
	int ret;
	if(1!=argc){
		perror("args error");
		_exit(-1);
	}


	//   int socketpair(int domain, int type, int protocol, int sv[2]);
	int fd[2];
	ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fd);
	assert(-1!=ret);

	pid_t pid;
	pid=fork();
	assert(-1!=pid);
	if(0==pid){
		printf("child\n");
		close(fd[0]);
		char buf[1024]={0};
		int newfd;
		recv_fd(fd[1],&newfd);
		assert(-1!=ret);
		printf("newfd:%d\n",newfd);
		
		ret=read(newfd,buf,sizeof(buf));
		assert(-1!=ret);
		printf("buf:%s\n",buf);

	}
	else{
		printf("parent\n");
		close(fd[1]);
		int newfd=open("file1",O_RDWR);
		printf("newfd:%d\n",newfd);
		send_fd(fd[0],newfd);
		assert(-1!=ret);
		wait(NULL);

	}
	return 0; 
}
