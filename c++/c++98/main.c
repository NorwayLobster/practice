 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-01 18:39:59
 ///
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>



int main(int args, char**argv)
{

	int sfd = socket(PF_INET,SOCK_STREAM,);
	struct sockaddr addr;
	addr.sa_len=strlen(&addr);
	addr.sa_data = atoh(arv[1]);
	int ret	 = bind(sfd,&addr, );
	//bind ip and port
	//...
	//
	//create thread pool
	//in the subthread function, the threads sleep and wait on the conditon 
	//
	//
	//accept()
	//...
	//create epoll()
	//register fd 
	//epoll_wait()
	//
	//when the task comes, cond_signal, wake the unbusy thread up
	//assign tasks
	
