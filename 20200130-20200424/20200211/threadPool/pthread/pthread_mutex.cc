//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
int sum=0;//
#define N 20000000


void * thread_func(void *p1){
	char *p=(char*)malloc(10);
//	memcpy(p1,"hello",5);
	printf("i am child thread:%s\n",(char*)p1);


	pthread_mutex_t* pmutex=(pthread_mutex_t *)p1;
	for(int i=0;i<N;++i){
		pthread_mutex_lock(pmutex);
		sum+=1;
		pthread_mutex_unlock(pmutex);
	}

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

	pthread_mutex_t* pmutex=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(pmutex,NULL);

//	int sum=0;//栈内存,各自copy on write


	ret=pthread_create(&pid,NULL,thread_func,pmutex);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}
	//pthread_create(&pid,NULL,thread_func,(void*)1);
	printf("i am main thread:%s\n",p);



	for(int i=0;i<N;++i){

		pthread_mutex_lock(pmutex);
		sum+=1;
		pthread_mutex_unlock(pmutex);
	}


	







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

	free(pmutex);
	free(p);
	return 0;
}
