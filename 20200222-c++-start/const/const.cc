 ///
 /// @file    const.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-22 23:30:23
 ///
 
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;
//int (*arr)[] vs int *arr[]
//数组指针 vs 指针数组
//int (*pfunc)(int ,int )   vs int * func(int,int)
//函数指针 vs 指针函数
//指针常量 vs 常量指针



//宏定义 与 const 差别?
#define MAX 100//预处理时替换, 无类型检测，
//const 编译阶段处理，有类型检查， 更安全，建议使用
int main(){
	int a=10;//必须定义时初始化
	int b=1;
//1. const int or int const
//	const int *pa=&a;//pointer to const 常量指针
	int const  *pa=&a;//效果和上一行一样
//	*pa=100;	// 不能通过pa改a
	pa=&b;//pa自己可以变动

//2. int* const 
	int *const pb=&b;//const pointer  指针常量
//	pb=&a;//erorr: pa执行不能变动
	int c=11;
	const int *const pc=&c;//const pointer  指针常量

	cout<<"MAX:"<<MAX<<endl;
	cout<<"a:"<<a<<endl;
//	a=100;//error 
	
//3. int & ref
	 int & ref=a;//定义及初始化
//	 int &ref1;
//	 ref1=a;//error
	 ref=12;
	 cout<<"a:"<<a<<endl;
//4. 值传递 引用传递
void swap(int a,int b);
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	swap(a,b);
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	void swap1(int& a,int &b);
	swap1(a,b);
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
//5. a的引用的地址  与a的地址相同
	 printf("a:%p\n",&a);
	 printf("ref:%p\n",&ref);
	return 0;
}
void swap(int a,int b){
	std::swap(a,b);
}
void swap1(int& a,int &b){
	std::swap(a,b);
}
