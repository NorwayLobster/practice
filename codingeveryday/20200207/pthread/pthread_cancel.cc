//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
void * thread_func(void *p1){
	char *p=(char*)malloc(10);
	memcpy(p1,"hello",5);
	printf("i am child thread:%s\n",(char*)p1);
	sleep(2);
	pthread_exit((void*)1);
	//pthread_exit(NULL);
			//return NULL;
}
			

int main(){
	int ret;
	pthread_t pid;
//	char *p;
	char *p=(char*)malloc(2048);//共享堆空间
	ret=pthread_create(&pid,NULL,thread_func,p);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
	}
	//pthread_create(&pid,NULL,thread_func,(void*)1);
	printf("i am main thread:%s\n",p);

	ret=pthread_cancel(pid);
	if(0!=ret){
		printf("ret:%d\n",ret);
		_exit(-1);
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

	return 0;
}
