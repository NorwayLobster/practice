 ///
 /// @file    TaskQueue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-17 11:57:01
 ///
 
#include "TaskQueue.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

TaskQueue::TaskQueue(int queSize)
: _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _queSize(queSize)
{}

bool TaskQueue::full() const
{
	return _queSize == _que.size();
}

bool TaskQueue::empty() const
{
	return _que.size() == 0;
}

void TaskQueue::push(TaskQueue::Product product)
{
	MutexLockGuard mlg(_mutex);
	if(full())	
	//while(full()) // 使用while是为了防止异常唤醒的情况
	{
		cout<<"sleep on condtion _notFull"<<endl;
		_notFull.wait();
		cout<<"wakeup on condtion _notFull"<<endl;
	}

	cout<<"before _que.push(product)"<<endl;
	_que.push(product);
	cout<<"before _notEmpty.notify()"<<endl;
	_notEmpty.notify();
	cout<<"after _notEmpty.notify()"<<endl;
}

TaskQueue::Product TaskQueue::pop()
{
	MutexLockGuard mlg(_mutex);	
	if(empty())
	//while(empty())
	{
		cout<<"sleep on condtion _notEmpty"<<endl;
		_notEmpty.wait();
		cout<<"wakeup on condtion _notEmpty"<<endl;
	}


	Product product = _que.front();
	_que.pop();
	_notFull.notify();

	return product;
}

}//end of namespace wd
