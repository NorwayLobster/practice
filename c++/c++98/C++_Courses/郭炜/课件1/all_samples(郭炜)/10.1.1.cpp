//program 10.1.1.cpp   全局变量和局部变量
#include <iostream>
using namespace std;
int n1 = 5, n2 = 10;
void Function1()
{
	int n3 =4;
	n2 = 3;
}
void Function2()
{
	int n4;
	n1 = 4;
//	n3 = 5;   //编译出错
}
int main()
{
     n2 = 1;   //这里的n2是全局变量n2
	int n5;
	int n2;   //和全局变量n2同名，在main中起作用的是这里的n2
	if( n1 == 5 ) {
		int n6;
		n6 = 8;
	}
	n1 = 6;
//	n4 = 1;   //编译出错
//	n6 = 9;	 //编译出错
	n2 = 7;
	::n2 = 9;   // :: 指定了要到当前作用域外面去找n2 
	return 0;
}

