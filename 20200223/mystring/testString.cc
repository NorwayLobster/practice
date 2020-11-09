///
/// @file    testString.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-23 14:09:40
///

#include <iostream>
#include "string.h"
using std::cout;
using std::endl;

int main(void)
{
	String str1;
//	str1.print();
	cout<<endl;

	String str2 = "Hello,world";//临时对象 生成
	str2.print();

	cout<<endl;

	String str3("wangdao");
	str3.print();


	cout<<endl;
	String str4 = str3;
	str4.print();

	cout<<endl;
	str4 = str2;
	str4.print();
	cout<<endl;

	str4 = str4;
	cout<<endl;

#if 0
#endif
	return 0;
}
