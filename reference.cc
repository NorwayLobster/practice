 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 17:10:33
 ///
#include <cstring> 
#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
int A=19;

//返回时,会复制构造
int func()
{
	int a=10;
	return a;
}

//返回局部变量的指针
int* func1()
{
	int a=10;
	return &a;
}

//返回全局变量的已用
int &func2()
{
	return A;
}

//返回局部变量的已用
int &func3()
{
	int a=10;
	return a;
}

//返回stack中的已用
int &func4()
{
	int* a = new int(10);
	return *a;
}
//
//返回heap中内存的地址
int *func5()
{
	int* a = new int(10);
	return a;
}
int main(int argc, char**argv)
{
	cout<<func()<<endl;
	//error: cout<<*func1()<<endl;
	cout<<func2()<<endl;
	cout<<"A="<<A<<endl;
	int& a2 = func2();
	//func2()=100;
	a2=100;
	cout<<"A="<<A<<endl;
	cout<<"---------"<<endl;
//error:	cout<<"func3="<<func3()<<endl;
	cout<<"---------"<<endl;
	//error: 调用一次,则内存则泄露一次;每一次调用,都申请空间,所以每次调用的返回值都必须有变量去接,并用来释放内存
	//cout<<"func4()="<<func4()<<endl;
	//error :int *p4  = &func4();
	int &a4 = func4();
	cout<<"a4="<<a4<<endl;
	delete &a4;
	//delete &func4();
	//cout<<"func5()="<<func5()<<endl;
	//func5()=23;
	int *p5  = func5();
	//int *p5  = func5();
	cout<<"func5()="<<*p5<<endl;
	delete p5;

	return 0;
}
