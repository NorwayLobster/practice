 ///
 /// @file    __int128.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-27 20:55:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(){
	__int128 a;//16bytes

	__int128_t b;
	__int64_t int64;

	__uint128_t c;//8bytes

	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<sizeof(c)<<endl;
	cout<<sizeof(int64)<<endl;

	long l;//8bytes
	long long ll;//8bytes

	double d;
	long double ld;
	cout<<sizeof(l)<<endl;
	cout<<sizeof(ll)<<endl;

	cout<<sizeof(d)<<endl;
	cout<<sizeof(ld)<<endl;
	return 0;
}
