//program 2.5.2.2.cpp
#include <iostream>
using namespace std;
int main( )
{
 	int m,n;
 	bool b1 = true,b2 = false;
 	m = b1;   //bool类型可以被自动转换成int类型
 	n = b2;
 	cout << m << "," << n << endl; // 输出　1,0
 	return 0;
}
