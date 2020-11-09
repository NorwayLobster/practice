 ///
 /// @file    static_cast.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 00:43:10
 ///
 
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
int test1(){
	int val=10;
	double b=	static_cast<double> (val);
	int *p=static_cast<int*>(malloc(sizeof(int)));
	cout<<"b:"<<b<<endl;

#if 0
	const_cast<>()//去除const属性
	dynamic_cast<>()// 父子类指针转化，若能转，顺利转，若不能，返回空指针
	reinterpret_cast<>();//任意转换,破坏性最强, 重新解释比特位
#endif
	int a=100;
	const int* pa=&a;
	cout<<"a:"<<a<<endl;
	*const_cast<int*>(pa)=10;
	cout<<"a:"<<a<<endl;
//	*pa=-10;
	cout<<"a:"<<a<<endl;
//  *reinterpret_cast<int*>(pa)=10;//error: 无法用来去除const属性
	



	return 0;
}

int main(){
	test1();
	return 0;
}
