//program 2.7.6.1.cpp  条件运算符
#include <iostream>
using namespace std;
int main()  
{  		
	int a = 4;
	int b = 5;
	int c = a>b ? a:b; // c = b
	cout << c << endl; //输出5
	c = a<b ? a:b;     // c = a  
	cout << c << endl; //输出4
	c = 3<5 ? ++a:++b; //++a计算并作为返回值，++b不计算，c = 5
	cout << a << "," << b << "," << c << endl; //输出5,5,5
	b = 8;
	c = 3>5 ? ++a:++b; //++b计算并作为返回值，++a不计算, c = 9
	cout << a << "," << b << "," << c << endl; //输出5,9,9
	return 0;
}

