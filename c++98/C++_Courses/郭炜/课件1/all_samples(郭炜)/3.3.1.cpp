//program 3.3.1.cpp  输出正整数的所有因子
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for( int i = 1;i <= n; ++i) 
 		if( n % i == 0 )
 			cout << i << endl;
  	return 0;
}

