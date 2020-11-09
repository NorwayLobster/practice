 ///
 /// @file    OverloadOperator.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 21:06:10
 ///
 
#include <iostream>
#include "OverloadOperator.h"
using std::cout;
using std::endl;

namespace wc{
#if 0
Complex::Complex()
:_x(0)
,_y(0)
{
	cout<<"Complex()"<<endl;
}
#endif

//Complex::Complex(int x=0,int y=0)
Complex::Complex(int x,int y)
:_x(x)
,_y(y)
{
	cout<<"Complex(int,int)"<<endl;
}

Complex::~Complex(){
	cout<<"~Complex()"<<endl;
}
Complex::Complex(const Complex&c)
:_x(c._x)
,_y(c._y)
{
	cout<<"Complex(const Complex&)"<<endl;

}
Complex & Complex::operator=(const Complex&c)
{

	_x=c._x;
	_y=c._y;
	cout<<"Complex &operator=(const Complex&)"<<endl;
	return *this;
}

void Complex::display(){
	cout<<_x<<"+"<<_y<<"i"<<endl;
}
Complex Complex::operator+(const Complex&rhs){
	return Complex(_x+rhs._x,_y+rhs._y);
}

Complex & Complex::operator+=(const Complex&rhs){
	_x+=rhs._x;
	_y+=rhs._y;
	return *this;
}
//friend func
//Complex operator+(const Complex&lhs,const Complex &rhs){
//	return Complex(lhs._x+rhs._x,lhs._y+rhs._y);
//}

//自由函数
Complex operator+(const Complex&lhs,const Complex &rhs){
	Complex tmp(lhs);	
	tmp+=rhs;
	return tmp;
}
Complex& Complex::operator++(){
	_x++;
	_y++;
	return *this;
}

Complex Complex::operator++(int){
	Complex tmp(*this);
	_x++;
	_y++;
	return tmp;
}
}
