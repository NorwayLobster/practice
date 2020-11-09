 ///
 /// @file    testComputer.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 12:59:08
 ///
 
#include <iostream>
#include "Computer.h"
using std::cout;
using std::endl;
//9. copyt ctor 调用时机，
// 1. 传参， 
//
Computer func(Computer c){
	c.print();
// 2. return 对象 // -noflide-constructor
	return c;
}

class Empty{
	};

int main(){
	Computer c("Dell",2323);
//	Computer c1(c);
//	Computer c2=c;
	 cout<<endl;
	 //10. copy ctor 中的形参的 const 不能去
//	 &func(c);//返回一个temp对象，是rvalue，不能取地址
//	 int & a=10;//引用不能绑定 rvalue对象
	const  int & a=10;
	Computer c3=func(c); 
	c.print();
//11.
	int f(10);
	cout<<"f:"<<f<<endl;
//12.
	Empty e1;	
	Empty e2;	
	cout<<"sizeof(Empty):"<<sizeof(Empty)<<endl;
	printf("e1:%p\n",e1);
	printf("e2:%p\n",e2);
	//cout<<"e1:"<<(void*)e1<<endl;
	//cout<<"e1:"<<(void*)e2<<endl;
	return 0;
}
