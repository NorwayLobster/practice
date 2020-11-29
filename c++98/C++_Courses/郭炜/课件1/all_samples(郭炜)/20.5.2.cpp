//program 20.5.2.cpp  多个名字空间
#include <iostream>
using namespace std;
namespace graphics
{
	class A	{	};
}
using namespace graphics;	//graphics会覆盖后面的内容
int main()
{
	A a;       //编译没问题,graphics已覆盖此处
	return 0;
}

