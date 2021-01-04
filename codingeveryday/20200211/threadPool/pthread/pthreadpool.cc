///
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
void * thread_func(void *){
			printf("i am child thread \n");
			pthread_exit(NULL);
			//return NULL;
}
			

int main(){
	pthread_t pid;
	for(int i=0;i<10;++i){
		pthread_create(&pid,NULL,thread_func,NULL);
	}
	printf("i am main thread\n");
	return 0;
}
