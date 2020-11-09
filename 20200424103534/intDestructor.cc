 ///
 /// @file    intDestructor.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-24 11:09:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(){
	int a(10);
	int *p=&a;
	p->~int();
	return 0;
}
