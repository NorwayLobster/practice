 ///
 /// @file    inline.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 01:05:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int f1(int a,int b=2);//默认参数值,声明处和第一处只能写一处
int f1(int a,int b){
	cout<<"b:"<<b<<endl;
	return 0;
}
int main(){
	f1(10);
	return 0;
}

