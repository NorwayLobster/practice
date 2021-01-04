//program 9.1.3.cpp 取数问题
#include <iostream> 
#include <cmath>
using namespace std;
const int NUMS = 16;
int num[NUMS + 10]; //数组开大点没坏处
inline int Bit(int n,int i) { return ( n & (1 << i)); } //看n的第i位是否非0
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int totalSolutions = 0; //解法总数
		for( int i = 0;i < n; ++ i)
			cin >> num[i];
		int tmp = pow(2.0,n);  //用库函数pow求2的n次方
		for( int i = 0; i < tmp; ++ i ) { //枚举所有的取法
			int sum = 0; //取到的整数的和
			for( int k = 0; k < n; ++ k )
				if(Bit(i,k))  //如果i的第k位为1
					sum += num[k]; //取第k个整数（k从0开始算），
			if( sum % 7 == 0 )
				totalSolutions ++;
		}
		cout << totalSolutions << endl;
	}
	return 0;
}

