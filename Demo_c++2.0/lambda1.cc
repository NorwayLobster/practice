 ///
 /// @file    lambda1.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 16:40:22
 ///
 
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
int main(){
	auto f=[](int a,int b)->int{ return a+b;};
	cout<<f(1,11)<<endl;
	std::function<int(int,int)> f1=f;
	cout<<f1(1,11)<<endl;

//	auto f3=std::bind(f1,11,std::placeholders::_2);
	auto f3=std::bind(f1,11,_1);
	cout<<f3(12)<<endl;
	//auto f4=std::bind(f3,11);
	//f4();
//	f4(10);
	return 0;
}
