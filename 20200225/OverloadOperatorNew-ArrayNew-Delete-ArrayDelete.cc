 ///
 /// @file    OverloadOperatorNew-ArrayNew-Delete-ArrayDelete.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-21 10:27:04
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
class Student{
	public:
		Student();
		~Student();
		void * operator new(size_t);
		void * operator new(size_t,void*);//placement new表达式
		void * operator new[](size_t);
		void  operator delete(void*);
//		void  operator delete[](void*,size_t);
		void  operator delete[](void*);
};
Student::Student(){ 
	cout<<"Student()"<<endl;
}
Student::~Student(){ 
	cout<<"~Student()"<<endl; 
}
void * Student::operator new(size_t){//
	cout<<"operator new(size_t)"<<endl;
	void * pnew=malloc(sizeof(Student));
	return pnew;
}

void * Student::operator new[](size_t size){//
	cout<<"operator new[](size_t)"<<endl;
	void * pnew=malloc(size*sizeof(Student));
	return pnew;
}
//delete expression:
//			1. call dtor 
//			2. call operator delete[]
void Student::operator delete(void*p){//
	cout<<"operator delete(void*)"<<endl;
	Student *tmp=static_cast<Student*>(p);
	free(tmp);
	p=NULL;
}

void Student::operator delete[](void*p){//
//void Student::operator delete[](void*p,size_t size){//
	cout<<"operator delete[](void*)"<<endl;
	Student *tmp=static_cast<Student*>(p);
	free(tmp);
#if 0
	for(int i=0;i<(int)size;++i){
		free(tmp+i);	
	}
#endif
	p=NULL;
}
//new expression:
//		1.call operator new(), to alloc memory
//		2. call ctor to init memory

int main(){
	Student *p=new Student();
	delete p;
	Student *pA=new Student[10]();
	delete [] pA;
//	Student *pA=new Student[10];
	return 0;
}
