//program 20.5.3.cpp  名字空间二义性
#include <iostream>
using namespace std;
class A { };
class B { };
namespace graphics
{
	class A	{ int v; };
	A a0; //graphics名字空间的A
	B b;  //全局名字空间的B 
}
using namespace graphics;	
int main()
{
	A a1;            //二义性错误，不知道是哪个名字空间的A
	graphics::A a2;  //引用graphics名字空间的A
	::A a3;          //引用全局名字空间的A
	return 0;
}

