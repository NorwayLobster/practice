//program 12.6.3.cpp  封闭类的复制构造函数
#include <iostream>
using namespace std;
class A
{
public:
		A() { cout << "default" << endl; }
		A(A & a) { cout << "copy" << endl;}
};
class B
{
		A a;
};
int main()
{
		B b1,b2(b1);
		return 0;
}
