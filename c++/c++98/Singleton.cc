 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-29 01:44:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
private:
	Singleton()
	{}
public:
	Singleton * get_instance()
	{
		if(!=p_instance)
		{
			p_instance =new Singleton();
		}
		return p_instance;
	}
	~Singleton();

private:
	static Singleton * p_instance;
	int data;
}
