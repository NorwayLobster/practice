 ///
 /// @file    add.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 16:27:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//0. 函数模板，代码生成器; <>里面是函数模板参数列表
//5.函数模板声明和实现和可以分离, 但不跨文件，实现也可以写在.txx中，但需在模本头文件add(注意没有.h后缀)中#include "add.txx"
template<typename T> T add(T x, T y){
	cout<<"T add(T,T)"<<endl;
	return x+y;
}
//1.函数模板与普通函数重载时，函数模板优先
int add(int x,int y){
	cout<<"int add(int,int)"<<endl;
	return x+y;
}

//2.函数模板可以重载
#if 0
template<typename T> T add(T x, T y, T z){
	cout<<"T add(T,T,T)"<<endl;
	return x+y+z;
}
#endif

//3.函数模板参数可以是整型类型
//bool/char/short/int/long(与平台有关)/long long/
//template<typename T,int K> T add(T x, T y, T z){

//4.c++11,函数模板参数可以是整型类型,可以设置默认值，
template<typename T,int K=-1> T add(T x, T y, T z){
	cout<<"K, T add(T,T,T)"<<endl;
	return (x+y+z)*K;
}
