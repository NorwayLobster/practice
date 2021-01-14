 ///
 /// @file    overload.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 20:18:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#ifdef __cplusplus
extern "C"{
printf("using C style, not using Name Mangling");
//原因是C++的编译器会对程序中符号进行修饰，这个过程在编译器中叫符号修饰（Name Decoration）或者符号改编（Name Mangling）
//为了C++能够重载
//cout<<"C"<<endl;
#endif
int add(int a, int b)
{
	return a+b;
}
#ifdef __cplusplus
}
#endif
double add(double a, int b)
{
	return a+b;
}

double add( int a, double b)
{
	return a+b;
}

int main(void )
{
	cout<<add(4,5)<<endl;
	cout<<add(4.9,4)<<endl;
	cout<<add(5,3.4)<<endl;
	return 0;
}
	
