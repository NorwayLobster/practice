 ///
 /// @file    std-thread.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-10-21 12:22:07
 ///
 
#include <iostream>
#include <thread>
using namespace std;

void hello(){
	std::thread::id thread_id=std::this_thread::get_id();
	cout<<"hello world,thread_id:"<<thread_id<<endl;
}
int main(){
	cout<<"main()"<<endl;
	std::thread::id thread_id=std::this_thread::get_id();
	cout<<"main(), thread_id:"<<thread_id<<endl;
//	shared_ptr<std::thread> sp(new std::thread(hello));
	shared_ptr<std::thread> sp=make_shared<std::thread>(hello);
	sp->join();
	return 0;
}
