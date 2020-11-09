 ///
 /// @file    class.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 12:38:34
 ///
 
#include <iostream>
#include <cstring>
#include "Computer.h"
using std::cout;
using std::endl;
//0. 委托构造函数
Computer::Computer(const char * brand, double price):
	Computer(brand,price,0)
{
		cout<<"Computer(,,)"<<endl;
}

#if 0
//error: delegating ctor 必须单独在初始化列表使用
Computer::Computer(const char * brand, double price,double weight, double age):
	Computer(brand,price,weight),
	_age(age)
{
		cout<<"Computer(,,,,)"<<endl;
}
#endif
//1.在.cc文件的函数写inline中，会报无定义;写在类的函数即为内联函数; 无论哪种inline,只是对编译器的建议
//inline
Computer::Computer(const char * brand, double price,double weight):
//2.根据定义的顺利初始化，和初始化顺序无关
	_weight(weight),//
	_price(_weight),
//3. 指针， new 内存
	_brand(new char[strlen(brand)+1]())
	{
		strcpy(_brand,brand);
		cout<<"Computer(,,,)"<<endl;
	}
//inline
void Computer::print(){
	cout<<_weight<<" "<<_price<<endl;
}

//10. const,不能删；当形参传过来一个临时对象，或rvalue对象是，无法正常使用 
Computer::Computer(const Computer & c):
	//8. 引用& 防止 copy ctor的调用死循环
//6.深拷贝
	Computer(c._brand,c._price,c._weight)
//	7.浅拷贝 error, double free
//	_brand(c._brand)
{
		cout<<"copy ctor, Computer()"<<endl;
}
Computer::~Computer(){
//4.析构堆内存 delete [] 指针
		delete [] _brand;
//5. 指针=NULL
		_brand=NULL;
		cout<<"~Computer()"<<endl;
}

