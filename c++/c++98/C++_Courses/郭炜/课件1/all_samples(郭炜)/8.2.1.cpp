//program 8.2.1.cpp  联合的示例程序
#include <iostream>
using namespace std;
union UTest
{
	int a;
	short b;
	char s[16];
	char c;
};
int main()
{
	UTest u;
	cout << sizeof(u) << endl; //输出 16
	memset(&u, 0,sizeof(u));  //u变成全0
	u.a = 0x61626364;
	cout << hex << u.a << "," << u.b << "," << u.c <<  "," << u.s;
     //hex告诉cout,此后整数均以十六进制形式输出。输出 61626364,6364,d,dcba
}

