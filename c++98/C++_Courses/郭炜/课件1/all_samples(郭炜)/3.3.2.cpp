//program 3.3.2.cpp  取出两数使得和是另一个数的因子，有多少种取法
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	int total = 0;  //取法总数
	cin >> n >> m;  //从1...n这n个数中取两个数，和是m因子 
	for( int i = 1; i < n; ++i )  //取第一个数，共n-1种取法
		for( int j = i + 1; j <= n; ++j ) //第二个数要比第一个数大,以免取法重复
			if( m % (i + j) == 0 )
		  		  ++ total ;
     cout << total;  
  	return 0;
}
