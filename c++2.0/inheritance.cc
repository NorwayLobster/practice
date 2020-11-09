 ///
 /// @file    inheritance.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-08-14 00:22:33
 ///
 
#include <iostream>
using namespace std;
struct A{};
struct B:A{};// 默认public继承// c++ primer Ch15.6
struct C:public A{};
struct D:private A{};

class AA{};
class BB:AA{};// 默认private继承
class CC:public AA{};

int main(){
	B b;
	C c;
	D d;
	BB bb;
	CC cc;
	return 0;
}
