 ///
 /// @file    delete.cc
/// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-29 09:54:28
 ///
 
#include <cstring>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
class student
{
public:
	student()
	{
		cout<<"constructor"<<endl;
	}
	void  release()
	{
		cout<<"release()"<<endl;
	//error	this.~student();
		delete this;//delete表达式会 1.调析构函数,(此时在类内), 2.调operator delete
	}
	void  releaseArray()
	{
		cout<<"releaseArray()"<<endl;
	//error	this.~student();
		delete [] this;//delete表达式会 1.调析构函数,(此时在类内), 2.调operator delete
	}
private:
	~student()
	{
		cout<<"deconstructor"<<endl;
	} public:
	void * operator new(size_t sz)
	{
		cout<<"operator new"<<endl;
		void * p = malloc(sz);
		//student * p = static_cast<student*>(malloc(sizeof(student)*sz));
		return p;
	}
	void * operator new[](size_t sz)
	{
		cout<<"operator new[]"<<endl;
		void * p = malloc(sz);
		//student * p = static_cast<student*>(malloc(sizeof(student)*sz));
		return p;
	}
public:
	void  operator delete(void *p)
	{
		cout<<"operator delete"<<endl;
		free(p);
	}

	void operator delete[](void *p)
	{
		free(p);
		cout<<"operator delete[]"<<endl;
	}
		
private:
	int data;
};

int main(void)
{
//student s;
//	student *p = new student();
	student *p1 = new student[2]();
//	delete[2] p1;
	//delete p
	cout<<"----------"<<endl;
	//delete [] p1;
	//p1->release();
	p1->releaseArray();
	return 0;
}
