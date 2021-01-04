//
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
void * thread_func(void *p1){
	memcpy(p1,"hello",5);
	printf("i am child thread:%s\n",(char*)p1);
	pthread_exit(NULL);
			//return NULL;
}
			

int main(){
	pthread_t pid;
//	char *p;
	char *p=(char*)malloc(2048);//共享堆空间
	pthread_create(&pid,NULL,thread_func,p);
	//pthread_create(&pid,NULL,thread_func,(void*)1);
	printf("i am main thread:%s\n",p);
	sleep(3);
	
	int * retval;
	
//	pthread_join(pid,&retval);
	return 0;
}
