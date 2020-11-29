//program 2.7.1.3.cpp  自增自减运算符
#include <iostream>
using namespace std;
int main()
{
	int n1 ,  n2 = 5;
	n2 ++;  // n2变成6
	++ n2;  // n2变成 7
	n1 = n2 ++;  // n2变成8,n1变成7
	cout << n1 << "," << n2 << endl;  //输出 7,8
	n1 = ++ n2;  //n1和n2都变成9
	cout << n1 << "," << n1 << endl;  //输出 9,9
	return 0;
}

