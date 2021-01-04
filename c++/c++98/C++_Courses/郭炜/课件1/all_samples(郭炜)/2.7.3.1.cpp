//program 2.7.3.1.cpp  关系运算符
#include <iostream>
using namespace std;
int main()
{
	int n1 = 4,  n2 = 5,  n3;
	n3 = ( n1 > n2 );   // n3 的值变为 0
	cout << n3 << ",";  // 输出 0,
	n3 = ( n1 < n2);    // n3 的值变为某非0值
	cout << n3 << ",";	 // 输出 1,
	n3 = (n1 == 4);     // n3 的值变为某非 0 值
	cout << n3 << ",";	 // 输出 1,
	n3 = (n1 != 4);     // n3 的值变为0
	cout << n3 << ",";	 // 输出 0,
	n3 = (n1 == 5);     // n3 的值变为0 
	cout << n3 ;	      // 输出 0,
	return 0;
}

