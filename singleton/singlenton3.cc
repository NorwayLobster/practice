 ///
 /// @file    singlenton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-04 11:34:29
 ///
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
//using pthread_once to guarantee calling only once in mutiple threads environment
//or use mutex to protect pInstance i.e. p

//use atexit to destory automatically
class singleton
{
public:
	~singleton()
	{
		cout<<"deconstructor"<<endl;
	}
	static void destroy()
	{
		delete p;
	}
	static singleton * getInstance()
	{
		cout<<"getInstance"<<endl;
		pthread_once(&_once_control, init);
		return p;
	}
	static	void init()
	{
		p= new singleton();	
		::atexit(destroy);
	}

private:
	singleton()
	{
		cout<<"constructor"<<endl;
	}
	static singleton * p;
	static pthread_once_t _once_control ;
	//pthread_once_t control =

};
//singleton * singleton::p = NULL ;
singleton *singleton::p =singleton::getInstance();
pthread_once_t singleton::_once_control = PTHREAD_ONCE_INIT;


void * func(void*)
{
	cout<<"in child thread"<<endl;
	singleton *p1 =singleton::getInstance();
//totally error:	pthread_once(NULL, &atexit);
	cout<<"p1="<<p1<<endl;
//	while(1);
	return (void*)1;
}

void test0()
{
	pthread_t pid1,pid2;
	pthread_create(&pid1,NULL, func,NULL);
	pthread_create(&pid2,NULL, func,NULL);
	int * pa;
	pthread_join(pid1,(void**)(&pa));
	cout<<"pa="<<pa<<endl;
	pthread_join(pid2,(void**)(&pa));
//error:	pthread_join(NULL);

}


//error: singleton *p = getInstance();
int main ()
{
	test0();

	return 0;
}
