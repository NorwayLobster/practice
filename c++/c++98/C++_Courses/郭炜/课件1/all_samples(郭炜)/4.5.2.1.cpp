	//program 4.5.3.1.cpp  引用作为函数返回值
#include <iostream>
using namespace std;
int n = 4;
int & SetValue()  
{	
    return n;  //返回对n的引用
}
int main() 
{
	SetValue() = 40;   //返回值是引用的函数调用表达式，可以作为左值使用
	cout << n << endl; //输出 40
    int & r = SetValue();
	cout << r << endl; //输出 40
	return 0; 
}

