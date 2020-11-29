//program 4.5.5.1.cpp  参数传引用
#include <iostream>
using namespace std;
void Swap( int & a, int & b)
{ //交换a,b的值
	int tmp;
	tmp = a; a = b; b = tmp;
}
int main()
{
	int n1 = 100, n2 = 50;
	Swap(n1,n2) ; // n1,n2的值被交换
	cout << n1 << " " << n2 << endl; //输出 50 100
}

