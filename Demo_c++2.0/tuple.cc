 ///
 /// @file    tuple.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 13:19:55
 ///
 
#include <iostream>
#include <tuple>
using std::cout;
using std::endl;
int main(){
	std::tuple<int,float,double> a{1,23.3,23.232};
	auto t=std::make_tuple(1,23.3,23.232);

//	cout<<a.head<<endl;
//	cout<<a.tail<<endl;
	cout<<std::get<1>(a)<<endl;
	cout<<std::get<2>(a)<<endl;

	cout<<endl;
	cout<<std::get<2>(t)<<endl;

	return 0;

}
