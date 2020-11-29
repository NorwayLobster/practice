 ///
 /// @file    namespace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 01:44:25
 ///
 
#include <iostream>
using namespace std;

extern int num = 0;				//外部变量num的定义性声明
//命名空间中的函数的定义和实现的分离
namespace B						//创建名称空间B
{
	int num = 2;				//B中声明的num
	void dispB();
}

namespace A						//创建名称空间A
{
	int num = 1;				//A中声明的num
	void dispA()
	{
		int num = 3;
		cout << "dispA函数中的num: " << num << endl;
		cout << "A中的num: " << A::num << endl;
		cout << "B中的num: " << B::num << endl;
		cout << "外部的num: " << ::num << endl;
	}
}

namespace B						//创建名称空间B
{
	void dispB()
	{
		A::dispA();
	}
}

int main()
{
	A::dispA();
	B::dispB();
	return 0;
}

