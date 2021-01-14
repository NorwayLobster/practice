//program 2.7.5.2.cpp  左移运算符
#include <iostream>
using namespace std;
int main()
{
	int n1 = 15; 
	short n2 = 15;
	unsigned short n3 = 15;
	n1 <<= 15; 
	cout << "n1=" << hex << n1 << dec << endl;  //输出 n1=78000 
	n2 <<= 15;
	n3 <<= 15;
	cout << "n2=" << n2 << ",n3=" << n3 << endl; //输出 n2=-32768,n3=32768
	unsigned char c = 7;	//c的二进制形式 0000 0111
	cout << "c<<4=" << (c << 4) << endl; //输出 c<<4=112
	c <<= 4;
	cout << "c=" << c ; //输出 c=p
	return 0;
}

