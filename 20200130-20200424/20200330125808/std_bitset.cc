 ///
 /// @file    std_bitset.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-30 13:00:55
 ///
 
//#include <bits/stdc++.h>
#include <bitset>
#include <iostream>

using namespace std;
void print(const int N){
	bitset<N> bs;///N必须为常数
	cout<<bs[0]<<endl;
}
int main(){
//	int N=10;
	const int N=10;
	print(N);
	return 0;
}
