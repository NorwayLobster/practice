 ///
 /// @file    overload.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 00:22:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//重载实现原理: name mangling 名字改编, 改编的准则，为根据函数的参数的个数，类型，顺序就行，改编名字

#ifdef __cplusplus//保证按照C的方式去编译 //目的，为了实现c和c++的混合编程 ,兼容性

extern "C"{
#endif
//该函数按照C方式进行调用
int add(int a,int b){
	return a+b;
}
#ifdef __cplusplus
}//end of extern 
#endif
int add(int a,int b,int c){
	return a+b+c;
}
int main(){
	int a=	add(1,3);
	int b=	add(1,3,1);
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	return 0;
}

