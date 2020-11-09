 ///
 /// @file    OnlyStackObject.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-21 10:09:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Student{
	public:
	Student(){ cout<<"Student()"<<endl; }
	void destroy(){
//2. call dtor
		 cout<<"destroy()"<<endl; 
		this->~Student();
		//error: ~Student();
	}
	private:
	~Student(){ cout<<"~Student()"<<endl; }
};
int main(){
//1. ctor is public and dtor is private, 可以创建堆对象(需要自定义destroy函数）, 但不能创建stack对象
//	Student s;
	Student *p=new Student();
	
	p->destroy();
	return 0;
}
