//program 16.5.1.cpp  用cin判断输入结束
#include <iostream>
using namespace std;
int main()
{
	int n;
	int maxN = 0;
	while( cin >> n)  {//输入没有结束，条件就为真
		if( maxN < n )
			maxN = n;
	}
	cout << maxN;
	return 0;
}
