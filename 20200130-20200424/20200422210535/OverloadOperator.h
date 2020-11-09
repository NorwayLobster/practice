 ///
 /// @file    OverloadOperator.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 21:07:57
 ///
 
#ifndef _Overload_Operator_H_
#define _Overload_Operator_H_
#include <iostream>
using std::cout;
using std::endl;
namespace wc{
class Complex{
public:
	//Complex();
//	note: 默认值
	Complex(int x=0,int y=0);//
	Complex(const Complex&);
	Complex &operator=(const Complex&);
	~Complex();
	void display();
	Complex & operator+=(const Complex&lhs);
	Complex  operator+(const Complex&lhs);
	Complex &operator++();//++a
	Complex  operator++(int);//a++
//	friend Complex operator+(const Complex&lhs,const Complex &rhs);
private:
	int _x;
	int _y;
};
}
#endif
