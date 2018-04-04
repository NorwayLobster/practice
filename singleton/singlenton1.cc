 ///
 /// @file    singlenton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-04 11:34:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//way1:use class inside class to destroy it automatically
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
		if(NULL==_p)
		{
			 _p = new singleton();
			 //error: singleton *p = new singleton();
		}
		return _p;
	}

	class autoRelease
	{
		public://very important
			autoRelease()
			{};
			~autoRelease()
			{
				cout<<"autoRelease deconstructor"<<endl;
				delete _p;
			}
	};
private:
	singleton()
	//already initialization outside of class:_p(NULL)
	{
		cout<<"constructor"<<endl;
	}
	static singleton * _p;
	static autoRelease _auto;


};
//singleton * singleton::_p = NULL ;
singleton* singleton::_p = getInstance();
singleton::autoRelease singleton::_auto;

void test0()
{
	singleton *p =singleton::getInstance();
	singleton *p1 =singleton::getInstance();
	//singleton::destroy();
}


//error: singleton *p1 = singleton::getInstance();
//error: singleton *p1 = getInstance();
int main ()
{
	test0();

	return 0;
}
