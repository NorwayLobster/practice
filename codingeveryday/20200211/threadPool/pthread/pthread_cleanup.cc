//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
void  cleanup(void * p){

	free((char*)p);
	printf("cleanup\n");
}

void * thread_func(void *p1){

	
	char *p=(char*)malloc(10);

	pthread_cleanup_push(cleanup,p);

	memcpy(p1,"hello",5);
	printf("i am child thread:%s\n",(char*)p1);

	sleep(2);

//	pthread_exit((void*)1);
	return NULL;

	pthread_cleanup_pop(0);//0,1区别？
//	execute 参数表示执行到 pthread_cleanup_pop()时是否在弹出清理函数的同时执行该函数，为 0 表示不执行，非 0 为执行;
//	这个参数并不影响异常终止时清理函数的执行,而且，执行pthread_exit函数也不受到影响,pthread_cancel()也不受影响

//note: 退出函数应该写在push和pop之间,
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
