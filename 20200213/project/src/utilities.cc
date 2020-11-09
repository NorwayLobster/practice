 ///
 /// @file    fd_utilities.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:13:09
 ///
 //
#include <head.hpp> 

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


void threadPool_init(ThreadPool *pTp,threadFunc f,int threadNum,int capacity){

//	memset(pTp,0,sizeof(ThreadPool));
	pthread_mutex_init(&pTp->mutex,NULL);
	pthread_cond_init(&pTp->cond,NULL);
	pTp->pNodeArr =(pThreadNode)calloc(threadNum,sizeof(ThreadNode));
	pTp->exit_flag=0;
	pTp->taskfunc=f;
	pTp->taskqueue.capacity=capacity;
	pTp->thead_num=threadNum;
	//printf("%p\n",pTp->pNodeArr);

		
}

void threadPool_destroy(ThreadPool *pTp){
	free(pTp->pNodeArr);
}






