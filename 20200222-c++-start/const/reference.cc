 ///
 /// @file    reference.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 00:03:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//malloc/free vs new/delete 区别
//1. 函数  与 表达式
//2. malloc不负责初始化 ,new初始化
//3.
int *p=	new int(1);
int & test(){
	int *p_arr=	new int[10]();//note: array new cannot initilize
	int *p=	new int(1);
	*p=10;
	delete [] p_arr;
	return p[0]  ;
}
int main(){
	cout<<*p<<endl;
//1. return 引用 //堆 或者 全局 或 静态, 栈不可以
	test()=10;
	cout<<*p<<endl;
	delete p;

	int & ref=test();//调用一次，free一次
	delete &ref;//不够直观，违反常规思维 ref取地址
//2. const int &   const引用可以绑定到rvalue( i.e. 生命周期比较短)
	const int & a=10;
//	int & b=10; error

	return 0;
}

