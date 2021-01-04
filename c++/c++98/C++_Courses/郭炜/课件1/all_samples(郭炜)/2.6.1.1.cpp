//program 2.6.1.1.cpp
#include <iostream>
using namespace std;
int main()
{
		int a ,b = 100;
		unsigned int c;
		a = 0xffffffff; //a有符号，因此赋值后其值为-1
		c = 0xffffffff; //c是无符号整数，因此赋值后其值为 4294967295
		cout << a << "," << c << endl; //输出  -1, 4294967295
		cout << a - b << "," << c - b << endl; //输出 -101,4294967195
		return 0;
}

