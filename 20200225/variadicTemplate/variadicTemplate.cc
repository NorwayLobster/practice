 ///
 /// @file    variadicTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 19:05:39
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::endl;
using std::string;
//1.出口函数
void print(){
	cout<<":end"<<endl;
}
#if 0
//2.出口函数
template<typename T, typename ... Args> void print(T x){
	cout<<x<<" "<<endl;
	cout<<":end"<<endl;
}
#endif
//3.Args:模板参数包
//4.args:函数参数包
//5. 递归形式使用
template<typename T, typename ... Args> void print(T x, Args ... args){
	cout<<x<<" "<<endl;
	cout<<"size...of(Args):"<<sizeof ... (Args)<<endl;
	cout<<"size...of(args):"<<sizeof ... (args)<<endl;
//递归展开:	print(args ...);// ...放右边叫参数包展开
	print(args...);// ...放右边叫参数包展开
	//???? print(args)...;// ...放右边叫参数包展开

}
int main(){
//	cout<<"hello"<<endl;
	print(2,5,6,"hello",string("c"));
	return 0;
}
