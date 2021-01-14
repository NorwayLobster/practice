//program 5.1.2.cpp 筛法求素数
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_NUM = 10000000;
bool isPrime[MAX_NUM + 10]; //最终如果isPrime[i]为true，则表示i是素数
int main()
{
	for( int i = 2;i <= MAX_NUM; ++i) //开始假设所有数都是素数
		isPrime[i] = true;
	for( int i = 2;i <= MAX_NUM; ++i) { //每次将一个素数的所有倍数标记为非素数
		if( isPrime[i])  //只标记素数的倍数
			for( int j = 2 * i; j <= MAX_NUM; j += i)
				isPrime[j] = false; //将素数 i 的倍数标记为非素数
	}
	for( int i = 2;i <= MAX_NUM; ++i) 
		if( isPrime[i])
			cout << i << endl;
	return 0;
}

