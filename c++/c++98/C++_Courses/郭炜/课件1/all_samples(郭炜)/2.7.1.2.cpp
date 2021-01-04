//program 2.7.1.2.cpp  除法运算
#include <iostream>
using namespace std;
int main() 
{
	int a = 10;
	int b = 3;
	double d = a/b; //由于a、b都是整型，所以表达式a/b 的值也是整型，其值是3
	cout << d << endl;  //输出 3
	d = 5/2;            //d的值变为2.0
    cout << d << endl; //输出 2
	d = 5/2.0;          
	cout << d << endl; //输出 2.5
	d = (double)a/b;
	cout << d << endl; //输出 3.33333
    return 0;
}

