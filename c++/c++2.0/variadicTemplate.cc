 ///
 /// @file    variadicTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 13:05:31
 ///
 
#include <iostream>
#include <bitset>
using std::cout;
using std::endl;
void print(){
}//entrance
template<typename T,typename ... Types>
void print(T a,const Types &... args){
	cout<<"sizeof...():"<<sizeof...(args)<<endl;
	cout<<a<<endl;
	print(args...);
}
int main(){
	print(1,"hello",3.9,std::bitset<16>(377));
	return 0;
}
