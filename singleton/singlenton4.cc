 ///
 /// @file    singlenton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-04 11:34:29
 ///
 
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
//using pthread_once;
//
class singleton
{
public:
	~singleton()
	{
		cout<<"deconstructor"<<endl;
	}
	//::pthread_once(once_control, &atexit);
	static void destroy()
	{
		delete p;
	}
	static singleton * getInstance()
	{
		cout<<"getInstance"<<endl;
		if(NULL==p)
		{
			atexit(&destroy);
			 p = new singleton();
			 //error: singleton *p = new singleton();
		}
		return p;
	}
private:
	singleton()
	{
		cout<<"constructor"<<endl;
	}
	static singleton * p;
	pthread_once_t once_control = PTHREAD_ONCE_INIT;
	//pthread_once_t control =

};
singleton * singleton::p = NULL ;

void * func(void*)
{
	cout<<"in child thread"<<endl;
	pthread_once(NULL, &atexit);
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

//	singleton::destroy();
}


//error: singleton *p = getInstance();
//singleton *p1 =singleton::getInstance();
int main ()
{
	test0();

	return 0;
}
