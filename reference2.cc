 ///
 /// @file    reference2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 19:35:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
	int a=10;
	//error:定义引用时,就必须初始化; 
//	int &b;
//	b=a;
	int &b=a;
	cout<<"b="<<b<<endl;
	return 0;
}
