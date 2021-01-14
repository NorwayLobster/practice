 ///
 /// @file    nullptr.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 12:46:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int f(void *p){
	cout<<"p:"<<p<<endl;
	return 0;
}
int f(int a){
	cout<<"a:"<<a<<endl;
	return 0;
}
int main(){
//	f(0);
//	f(2345);
//	f(NULL);//ambigious
	f(nullptr);
	return 0;
}
