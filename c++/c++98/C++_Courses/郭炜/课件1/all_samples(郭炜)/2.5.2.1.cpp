#include <iostream>
using namespace std;
int main()
{
	int n1 = 1378;  //1378的十六进制形式是 0x562
	short n2;
	char c = 'a';
	double d1 = 7.809;
	double d2;
	n2 = c;		//n2变为97 , 97是'a'的ASCII码
	cout << "c=" << c << ",n2=" << n2 << endl; //输出 c=a,n2=97
	c = n1;		// n1是0x562, 0x62被当做ASCII码赋值给c,c变为 'b'
	cout << "c=" << c << ",n1=" << n1 << endl; //输出 c=b,n1=1378
	n1 = d1;		// d1=7.809, 去掉小数部分后赋值给n1,n1变为7
	cout << "n1=" << n1 << endl;   //输出 n1=7
	d2 = n1;		//d2变为7
	cout << d2 << endl;  //输出 d2=7.000000
    return 0;
}
