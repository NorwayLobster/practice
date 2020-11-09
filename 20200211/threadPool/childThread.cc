 ///
 /// @file    childProcess.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:11:31
 ///
 
#include "head.hpp"

void * thread_func(void *ptp){
	signal(SIGPIPE,sig_pipe_handler);
	printf("i am child thread \n");
	ThreadPool *pTp=(pThreadPool)ptp;
	 while(1){
		printf("child %ld, i am waiting for new fd\n",pthread_self());
		 printf("lock\n");
		 int ret=pthread_mutex_lock(&pTp->mutex);
		 printf("ret:%d\n",ret);
		 printf("size:%lu\n", pTp->taskqueue.sockfdqueue.size());
		 if(0==pTp->taskqueue.sockfdqueue.size()){
			 printf("wait\n");
			 pthread_cond_wait(&pTp->cond,&pTp->mutex);
		 }
		 if(1==pTp->exit_flag){
			 printf("gonna exit,exit_flag=%d\n",pTp->exit_flag);
			 pthread_mutex_unlock(&pTp->mutex);//把资源释放
			 pthread_cond_signal(&pTp->cond);//并发cond信号
			 pthread_exit(NULL);
		 }
		 int sockfd=pTp->taskqueue.sockfdqueue.front();
		 pTp->taskqueue.sockfdqueue.pop();

		 printf("unlock\n");
		 pthread_mutex_unlock(&pTp->mutex);
//doTask
//		
		 sleep(10);
		 pTp->taskfunc(sockfd,NULL);


		 printf("finish job\n");
	 }
}

void createChildThreads(ThreadPool * pTp,int threadNum){
	int ret;
	printf("i am main thread\n");
	for(int i=0;i<threadNum;++i){
		ret=pthread_create(&(pTp->pNodeArr+i)->pid,NULL,thread_func,pTp);
		assert(-1!=ret); 
	}
}

void sig_pipe_handler(int signum){
	printf("%d is coming\n",signum);
//	_exit(0);
}


