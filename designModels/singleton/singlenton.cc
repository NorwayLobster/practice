 ///
 /// @file    singlenton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-04 11:34:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class singleton
{
public:
	~singleton()
	{
		cout<<"deconstructor"<<endl;
	}

	static singleton * getInstance()
	{
		cout<<"getInstance"<<endl;
		if(NULL==p)
		{
			 p = new singleton();
			 //error: singleton *p = new singleton();
		}
		return p;
	}
	static void destroy()
	{
		delete p;
	}
private:
	singleton()
	{
		cout<<"constructor"<<endl;
	}
	static singleton * p;

};
singleton * singleton::p = NULL ;

void test0()
{
	singleton *p =singleton::getInstance();
	singleton *p1 =singleton::getInstance();
	singleton::destroy();
}


int main ()
{
	test0();

	return 0;
}
