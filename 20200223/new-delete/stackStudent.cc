
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

//要求：不能生成堆对象
class Student{
public:
	Student(){
		cout<<"Student()"<<endl;
	}
	~Student(){
		cout<<"~Student()"<<endl;
	}
private:
	void * operator new(size_t);
	void  operator delete(void *);

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
	Student s;	
//	Student *ps =new Student;
//	delete  ps;
	

	return 0;
}
