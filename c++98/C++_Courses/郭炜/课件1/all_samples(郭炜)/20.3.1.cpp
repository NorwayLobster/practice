//program 20.3.1.cpp auto_ptr示例1
#include <iostream>
#include <memory>
using namespace std;
class A 
{
public:
	int i;
	A(int n):i(n) { };
	~A() { cout << i << " " << "destructed" << endl; }
};
int main() 
{
	auto_ptr<A> ptr(new A(2)); // new出来的动态对象的指针，交给ptr托管
   cout << ptr->i << endl;    // 输出 2
	ptr->i = 100;              //动态对象的 i 成员变量变为 100
   	A a(*ptr);                 // * ptr就是前面 new 的动态对象
	cout << a.i << endl;       //输出 100
	a.i = 20;  
	return 0;
}

