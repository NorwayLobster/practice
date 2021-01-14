
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

//要求：不能生成栈对象
class Student{
public:
	Student(){
		cout<<"Student()"<<endl;
	}
	void destory(){
//note:		
//1. 只析构对象
//		this->~Student();//调用析构函数，不等于 delete表达式
//2. delete expression 析构+ 回收对象本身堆内存
		delete this;
	}
	void * operator new(size_t);
	void  operator delete(void *);
private:
	~Student(){
		cout<<"~Student()"<<endl;
	}

};

void * Student::operator new(size_t a){
	cout<<"operator new()"<<endl;
	return malloc(a);
}

void  Student::operator delete(void * p){
	cout<<"operator delete()"<<endl;
	free(p);
}

int main(){
	Student *ps =new Student;
	//Student s;	
//	delete  ps;
	
	ps->destory();

	return 0;
}
