//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
int sum=0;//
#define N 20000000

typedef struct tag{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}data;

void * thread_func(void *p1){
	printf("i am child thread:%s\n",(char*)p1);


	data* p=(data*)p1;
	pthread_mutex_lock(&p->mutex);
	printf("lock\n");
	pthread_cond_wait(&p->cond,&p->mutex);
	printf("wake up\n");
	pthread_mutex_unlock(&p->mutex);
	printf("unlock\n");

	//sleep(2);
	pthread_exit((void*)1);
	//pthread_exit(NULL);
			//return NULL;
}
			
int main(){
	int ret;
	pthread_t pid;
//	char *p;
	char *p=(char*)malloc(2048);//共享堆空间
	
//	pthread_mutex_t mutex;
//	pthread_mutex_init(&mutex,NULL);

	//pthread_cond_t cond;
	//pthread_mutex_t* pmutex=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));

	data* pdata=(data *)malloc(sizeof(data));
	pthread_mutex_t* pmutex=&pdata->mutex;

	pthread_mutex_init(&pdata->mutex,NULL);
	pthread_cond_init(&pdata->cond,NULL);


	ret=pthread_create(&pid,NULL,thread_func,pdata);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}
	//pthread_create(&pid,NULL,thread_func,(void*)1);
	printf("i am main thread:%s\n",p);



//note:
	usleep(2000);
	pthread_cond_signal(&pdata->cond);
	


	int retval=0;
	ret=pthread_join(pid,(void**)&retval);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}

	//pthread_join(pid,(void**)retval);
	printf("i am main thread:%p\n",&retval);
	printf("i am main thread:%d\n",retval);
	printf("sum:%d\n",sum);







	ret=pthread_mutex_destroy(pmutex);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}
	ret=pthread_cond_destroy(&pdata->cond);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}

	free(pmutex);
	free(p);
	return 0;
}
