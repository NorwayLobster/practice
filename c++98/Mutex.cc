 ///
 //
 /// @file    Mutex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-01 17:31:51
 ///
 
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

class MutexLock
{
public:
//	Mutex()
//	{
//		pthread_mutex_init(&mutex, NULL);
//	}
// revising:
	pthread_mutex_t * getMutexPtr()
	{
		return &mutex;
	}
//
	int inti(const pthread_mutexattr_t * attr)
	{
		int ret = pthread_mutex_init(&this->mutex, attr);
		if(-1==ret)
		{ 
			cout<<"init error"<<endl;
		}
		return ret;
	}
	int unlock()
	{
		int ret = pthread_mutex_unlock(&mutex);
		return ret;
	}
	int	lock()
	{	
		int ret = pthread_mutex_lock(&this->mutex);
		return ret;
	}
//	int destory()
//	{
//		int ret = pthread_mutex_destroy(&this->mutex);
//		//error: int ret = pthread_mutex_destory(&this->mutex);
//		//int ret = pthread_mutex_destory(&mutex);
//		return ret;
//	}
	~Mutex()
	{
		pthread_mutex_destroy(&mutex);
	}
private:
	pthread_mutex_t mutex;
	//const pthread_mutexattr_t attr;

};

class Condition
{
public:
//	Cond()
//	{}
	int init(const pthread_condattr_t * attr)
	{
		int ret = pthread_cond_init(&this->cond, attr);
		return ret;
	}
//	~Cond()
//	{
//		pthread_cond_dedtory();
//	}
	int	signal()
	{
		int ret = pthread_cond_signal(&this->cond);
		return ret;
	}

	int notify()
//	{}
//	int	notifyall()
	{
		int ret = pthread_cond_broadcast(&this->cond);
		return ret;
	}
	int wait(MutexLock &mutex)
	//error:锁不能复制,只能引用 int wait(MutexLock &mutex)
	{
		int ret = pthread_wait(&cond, mutex.getMutexPtr());
//error:
//	int	wait(pthread_mutex_t * mutex)
//	{
//		int ret = pthread_cond_wait(&this->cond, &mutex);
//		return ret;
//	}
//
//	int notifyall()
//	{}
private:
	pthread_cond_t cond;
	//pthread_condattr_t attr;
};


int main(void)
{
	MutexLock m1;
	MutexLock m2;
	m1.inti(NULL);
	m2.inti(NULL);
	Condition c1;
	c1.init(NULL);
	
}
