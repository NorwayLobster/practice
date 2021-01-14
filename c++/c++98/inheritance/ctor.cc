 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-12 13:06:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	A(){}
	A(int a)
	:_a(a)
	{ cout<<"A ctor"<<endl;}
	~A()
	{cout<<"A dtor"<<endl;}
	void print(){cout<<_a<<endl;}
private:
	int _a;
};

class B
:public A
{
public:
	B(int x)
	:A(x)
	{
	cout<<"B ctor"<<endl;
	}
	~B()
	{cout<<"B dtor"<<endl;}
	//error: cuz _a is a private in B's parent A  void diplay() { cout<<_a<<endl;}
	void display()
	{
		print();
	}
};

int main()
{
	B b(100);
	b.print();

	return 0;
}
