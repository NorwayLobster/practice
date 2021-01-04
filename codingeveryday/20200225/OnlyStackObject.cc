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
	~Student(){ cout<<"~Student()"<<endl; }
	private:
	static void* operator new(unsigned long int/*size_t*/);
	static void* operator new[](size_t);
};
int main(){
	Student s;
//1. operator new() and operator new[]()  both are private:
//	Student *p=new Student();
//	Student *p=new Student[10]();
	
	return 0;
}
