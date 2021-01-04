 ///
 /// @file    atexit.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 18:46:20
 ///
 
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using std::cout;
using std::endl;
void func(){
	cout<<"func"<<endl;
}
void func1(){
	cout<<"func1"<<endl;
}
int main(){

	atexit(func);
	atexit(func);
	pthread_once_t once_control = PTHREAD_ONCE_INIT;
	pthread_once(&once_control ,func1);
	return 0;
}
