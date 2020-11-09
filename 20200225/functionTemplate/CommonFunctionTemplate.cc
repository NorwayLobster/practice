 ///
 /// @file    add.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 16:27:02
 ///
 
#include <iostream>
#include <cstring>
#if 0
#include "add"
#endif
using std::cout;
using std::endl;
#if 1
//0. 函数模板,类型参数化，i.e. 代码生成器;
//
//<>里面是函数模板参数列表
//
//		  实例化
//函数模板----->模板函数
template<typename T> T add(T x, T y);
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

//3.函数模板参数列表中，
//   1> 类型参数:typename或class设置类型参数
//   2> 非类型参数:就是常量表达式(整型数据)
//bool/char/short/int/long(与平台有关)/long long/
//template<typename T,int K> T add(T x, T y, T z){

//4.c++11,函数模板参数整型数据,可以设置默认值，
template<typename T,int K=-1> T add(T x, T y, T z){
	cout<<"K, T add(T,T,T)"<<endl;
	return (x+y+z)*K;
}

//
//8. 模板特化, 且其不能独立于通用模板而存在
template<> 
const char* add<const char*>(const char* x, const char* y){
	cout<<"T add(T,T)"<<endl;
	char * p= new char[strlen(x)+strlen(y)+1]();
	strcpy(p,x);
	strcat(p,y);
	return p;
}
//8 可以重载,但最好选择特化
#if 0
const char * add(const char * x, const char * y){
	cout<<"T add(T,T)"<<endl;
	char * p= new char[strlen(x)+strlen(y)+1];
	strcpy(p,x);
	strcat(p,y);
	return p;
}
#endif

//1.函数模板与普通函数重载时，函数模板优先

#endif

int main(){
	int a=1,b=2,c=3;
	double d1=2.1,d2=1.2;
	float f1=23.3,f2=12.3;
//6. 隐式实例化
	cout<<"add(int,int):"<<add(a,b)<<endl;
//7. 显式实例化
	cout<<"add(int,int):"<<add<int>(a,b)<<endl;
//	cout<<"add(int,int,int):"<<add<int>(a,b,c)<<endl;
	cout<<"K,add(int,int,int):"<<add(a,b,c)<<endl;//note:
	cout<<"K,add(int,int,int):"<<add<int,10>(a,b,c)<<endl;
//8. 模板特化
	cout<<"add(const char *,const char *):"<<add("hello ","world")<<endl;


	cout<<"add(double,double):"<<add(d1,d2)<<endl;
//error:	cout<<"add(double,float):"<<add(d1,f2)<<endl;
	cout<<"add(float,float):"<<add<float>(f1,f2)<<endl;

	return 0;
}
