 ///
 /// @file    specialMemberInit.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 16:15:55
 ///
 
#include <iostream>
#include "specialMemberInit.h"
using std::cout;
using std::endl;
//2. static  must在类外
int Point::_num=0;

Point::Point():
//3.无参数ctor必须为const，ref初始化
Point(0,0)
{
	  cout<<"Point()"<<endl;
}

Point::Point(int x,int y):
_x(x),
_y(y),
_ref(_y)
{
//1. cosnt， 引用 must在初始化列表
//	_x=x;
//	_y=y;
//	ref=x;
	cout<<"Point(,,)"<<endl;
}
Point::~Point(){
	cout<<"~Point()"<<endl;
}


void Point::print(/*Point const * const this */) const {
	cout<<"const print()"<<endl;
//5. 不能调用非const成员 和成员函数
//erro	_x=1000;
//自调用	Point::print();
	cout<<"_x:"<<_x<<endl;
	cout<<"_y:"<<_y<<endl;
	cout<<"_ref:"<<_ref<<endl;

}
void Point::print(){
	cout<<"not const print()"<<endl;
	cout<<"_x:"<<_x<<endl;
	cout<<"_y:"<<_y<<endl;
	cout<<"_ref:"<<_ref<<endl;
}

void Point::print_num(){
	cout<<"_num:"<<_num++<<endl;
//	1. 不能调用非静态成员
//	cout<<"_x:"<<_x<<endl;
//	2. 不能调用非静态成员函数
//	print();
	
}
