///
/// @file    Thread.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-17 09:57:57
///

#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

	Thread::Thread()
		: _pthId(0)
		  , _isRunning(false)
	{
	}

	void Thread::start()
	{
		cout<<"before pthread_create"<<endl;
		pthread_create(&_pthId, NULL, threadFunc, this);
		cout<<"after pthread_create"<<endl;
		_isRunning = true;
	}

	void * Thread::threadFunc(void * arg)
	{
		Thread * pThread = static_cast<Thread *>(arg);
		if(pThread)
			pThread->run();

		return NULL;
	}

#if 0
	void Thread::join()
	{
		cout<<"before pthread_join"<<endl;
		pthread_join(_pthId, NULL);
		cout<<"after pthread_join"<<endl;
		_isRunning = false;
	}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning = false;
		}
	}
#endif
	void Thread::join()
	{
		cout<<"before pthread_join in Thread::join()"<<endl;
		pthread_join(_pthId, NULL);
		cout<<"after pthread_join in Thread::join()"<<endl;
		_isRunning = false;
	}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			cout<<"before pthread_detach(_pthId)"<<endl;
			pthread_detach(_pthId);
			cout<<"after pthread_detach(_pthId)"<<endl;
			_isRunning = false;
		}
	 }


}// end of namespace wd
