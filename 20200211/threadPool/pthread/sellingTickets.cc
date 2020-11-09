//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
typedef struct tag{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int no_window0;
	int no_window1;
	int no_window2;
	int no_window;
	int no_ticket;
	int sum;
}Data;

void * thread_func_sellingTickets(void *p1){
	Data *p=(Data*)p1;
	printf("i am child thread,selling window no %d,%p\n",p->no_window,p);
	printf("pthread id=%ld\n",pthread_self());

	while(1){
		pthread_mutex_lock(&p->mutex);
		printf("window %d,got mutex\n",p->no_window);
		if(p->no_ticket>0){
			printf("window %d,one ticket is selling out, and after then, there exist %d tickets,sum=%d\n",p->no_window,p->no_ticket,p->sum);
			--p->no_ticket;
			++p->sum;
			sleep(1);
			if(0==p->no_ticket){
				printf("sending signal, there exist %d tickets\n",p->no_ticket);
				pthread_cond_signal(&p->cond);
			}
		}
		pthread_mutex_unlock(&p->mutex);
		usleep(10);
	}

	pthread_exit((void*)1);
}
			
void * thread_func_setTicketsNo(void *p1){
	Data *p=(Data*)p1;
	printf("i am set tickets child thread, window no %d,%p\n",p->no_window,p);
	printf("pthread id=%ld\n",pthread_self());

	while(1){
		pthread_mutex_lock(&p->mutex);
		printf("window %d,got mutex\n",p->no_window);
		pthread_cond_wait(&p->cond,&p->mutex);
		printf("got signal, reset 10 tickets\n");
		p->no_ticket=10;
		pthread_mutex_unlock(&p->mutex);
	}


}
int main(){
	printf("i am main thread\n");
	printf("pthread id=%ld\n",pthread_self());

	pthread_t pid[3];
	Data *p=(Data*)malloc(sizeof(Data));//共享堆空间
	memset(p,0,sizeof(Data));
	pthread_mutex_init(&p->mutex,NULL);	
	pthread_cond_init(&p->cond,NULL);	
	p->sum=0;	
	p->no_ticket=10;	

	p->no_window0=0;	
	pthread_create(pid,NULL,thread_func_setTicketsNo,p);
	usleep(100);

	p->no_window1=1;	
	pthread_create(pid+1,NULL,thread_func_sellingTickets,p);

	sleep(1);
	p->no_window2=2;	
	pthread_create(pid+2,NULL,thread_func_sellingTickets,p);



	//pthread_create(&pid,NULL,thread_func,(void*)1);
	
	int retval=0;
	
	pthread_join(pid[0],(void**)&retval);
	pthread_join(pid[1],(void**)&retval);
	pthread_join(pid[2],(void**)&retval);
	printf("i am main thread:%d\n",retval);

	return 0;
}
