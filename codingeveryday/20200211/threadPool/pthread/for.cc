 ///
 /// @file    for.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-08 15:20:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int sum=0;
#define N 10000000
int main(){
	for(int i=0;i<N;++i){
		sum+=1;
	}
	cout<<"sum:"<<sum;
	return 0;
}
