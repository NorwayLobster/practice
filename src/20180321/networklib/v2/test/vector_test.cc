 ///
 /// @file    vector_test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-21 21:07:37
 ///
 
#include <iostream>
#include <vector>
#include <sys/epoll.h>
using std::vector;
using std::cout;
using std::endl;
int main(void)
{
	typedef vector<struct epoll_event> EventVector;
	EventVector event_vec;
	//error: event_vec(1024);
	struct epoll_event event1;
	event_vec.push_back(event1);
	return 0;
}

