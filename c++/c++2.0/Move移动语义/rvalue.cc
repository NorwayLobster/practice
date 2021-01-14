 ///
 /// @file    rvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-11 21:52:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int test0()
{
	int a=9;

	int && m = 1;
	const int &m1 =1;
	cout<<&m<<endl;
	cout<<&a<<endl;
	m=10;
//	m1=10;
	int b = std::move(a);
	//int b = std::move(m);
	cout<<"b="<<b<<endl;
	cout<<"a="<<a<<endl;
	cout<<m<<endl;
	cout<<"&m="<<&m<<endl;
	cout<<m1<<endl;
}

int test1()
{
	string a("hello");
	cout<<"a="<<a<<endl;
	string b=std::move(a);
	cout<<"b="<<b<<endl;
	cout<<"a="<<a<<endl;

}
int main()
{
	test1();
	return 0;
}
