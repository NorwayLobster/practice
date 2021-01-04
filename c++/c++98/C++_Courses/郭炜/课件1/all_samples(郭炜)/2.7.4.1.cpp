//program 2.7.4.1.cpp  逻辑运算符
#include <iostream>
using namespace std;
int main()
{
  	int a = 0,b = 1;
	bool n = a ++ && b ++ ;  // b++不被计算 
	cout << a << "," << b << endl; //输出 1,1 
	n =  a ++ && b ++ ;  // a++和b++都要计算 
	cout << a << "," << b << endl; //输出 2,2 
	n =  a ++ || b ++ ;	//b++不被计算 
	cout << a << "," << b << endl; //输出 3,2 
    return 0;
}

