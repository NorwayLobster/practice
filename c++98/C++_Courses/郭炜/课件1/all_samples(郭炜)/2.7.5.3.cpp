//program 2.7.5.3.cpp  右移运算符
#include <iostream>
using namespace std;
int main()
{
	int n1 = 15; 
	short n2 = -15; //n2 二进制形式 1111 1111 1111 0001
	unsigned short n3 = 0xffe0;
	unsigned char c = 15;
	n1 = n1>>2;  //n1的值是0xf，右移2位后，变成0x3
	n2 >>= 3;
	n3 >>= 4;
	c >>= 3; 
	cout << n1 << "," << n2 << "," << hex << n3 << "," << (int)c ;
	return 0;
}

